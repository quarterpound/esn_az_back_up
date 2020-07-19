<?php

namespace ESN\Satellite\Notifications;

use ESN\Satellite\VersionHelper;
use JsonException;

define ('NotificationManager_FILENAME', 'satellite-messages.json');
define ('NotificationManager_MessagesSourceUrl', 'satellite_notification_messages_url');

class NotificationManager {

  /**
   * @var \ESN\Satellite\Notifications\Message[]
   */
  private $messages;
  private $version;

  /**
   * NotificationManager constructor.
   *
   * @param Message[] $messages
   */
  private function __construct($messages, $version) {
    $this->messages = $messages;
    $this->version = $version;
  }

  private static function getInstalledVersion() {
    $profile = system_get_info('module', 'satellite');
    $version = $profile['version'];
    if (!$version) {
      $version = SATELLITE_BASE_VERSION . '-dev';
    }
    // Make version string SemVer compatible (old ones might not be)
    return VersionHelper::getSemVer($version);
  }

  public static function update() {
    $url = variable_get(NotificationManager_MessagesSourceUrl,
      'https://satellite.esn.org/notifications/' . NotificationManager_FILENAME
    );
    $url = url($url, ['absolute' => TRUE]);
    system_retrieve_file($url, 'temporary://' . NotificationManager_FILENAME,
      FALSE,
      FILE_EXISTS_REPLACE
    );

    if (db_table_exists(SATELLITE_NOTIFICATIONS_TABLE)) {
      db_truncate(SATELLITE_NOTIFICATIONS_TABLE)->execute();
    }
    $version = self::getInstalledVersion();
    $imported = new \DateObject();
    foreach (self::parseFile('temporary://' . NotificationManager_FILENAME) as $message) {
      if ($message->verifyVersion($version)) {
        $message->save($imported);
      }
    }

    return self::load();
  }

  public static function load() {
    $version = self::getInstalledVersion();
    $messages = [];
    foreach (Message::loadAll() as $message) {
      if ($message->verifyVersion($version)) {
        $messages[] = $message;
      }
    }

    return new static($messages, $version);
  }

  public static function requirements() {
    $t = get_t();

    $requirements['satellite_notifications'] = [
      'title' => $t('Satellite Notifications'),
      'value' => format_string('<a href="!url">Manually update</a> Satellite notifications ', [
        '!url' => '/admin/settings/satellite/notifications/update',
      ]),
      'severity' => REQUIREMENT_INFO,
    ];

    return $requirements;
  }

  public function getUserMessagesRaw() {
    try {
      $messages = drupal_json_encode($this->messages);
    }catch (\Exception $ex) {
      $messages = '';
    }

    return $messages;
  }

  /**
   * @param $file
   *
   * @return Message[]
   */
  private static function parseFile($file) {
    try {
      if (!file_exists($file)) {
        return [];
      }
      $json = drupal_json_decode(file_get_contents($file));
      if (is_null($json)) {
        $error = json_last_error_msg();
        throw new \Exception($error, json_last_error());
      }
      return self::parse($json);
    }catch (\Exception $ex) {
      return [];
    }
  }

  /**
   * @param $json
   *
   * @return Message[]
   */
  private static function parse($json) {
    try {
      $mapper = new \JsonMapper();
      $mapper->bIgnoreVisibility = TRUE;
      $mapper->bEnforceMapType = false;
      $messages = $mapper->mapArray($json, [], Message::class);
    }catch (\Exception $ex) {
      $messages = [];
    }
    return $messages;
  }

  public function renderMessages() {
    foreach ($this->getMessages() as $message) {
      drupal_set_message($message->render(), $message->getType(), FALSE);
    }
  }

  /**
   * @return \ESN\Satellite\Notifications\Message[]
   */
  public function getMessages() {
    $messages = [];
    foreach ($this->messages as $message) {
      if (!$message->verifyVersion($this->version)) {
        continue;
      }
      if (!$message->getDisplay()->isValid()) {
        continue;
      }
      if (!$message->verifyConditions()) {
        continue;
      }
      $messages[] = $message;
    }
    return $messages;
  }
}
