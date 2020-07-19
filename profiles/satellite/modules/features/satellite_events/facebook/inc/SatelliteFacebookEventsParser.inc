<?php
/**
 * @file
 * ESN Satellite Facebook Events feeds parser class.
 */

/**
 * Callback for array_walk().
 */
function _satellite_events_facebook_country_to_code_strtolower(&$word) {
  $word = drupal_strtolower($word);
}

class FacebookImage {
  /** @var \stdClass */
  private $raw;

  public function __construct($raw = null) {
    $this->raw = $raw;
  }

  public function getID() {
    return isset($this->raw->id) ? intval($this->raw->id) : 0;
  }

  public function getUri() {
    return isset($this->raw->source) ? $this->raw->source : '';
  }
}

class FacebookLocation {
  /** @var \stdClass */
  private $raw;

  public function __construct($raw = null) {
    $this->raw = $raw;
  }

  public function getCity() {
    return isset($this->raw->city) ? $this->raw->city : '';
  }

  public function getCountry() {
    return isset($this->raw->country) ? $this->raw->country : '';
  }

  public function getCountryCode() {
    $country = $this->getCountry();
    include_once DRUPAL_ROOT . '/includes/locale.inc';
    static $countries = array();

    if (empty($countries)) {
      $countries = country_get_list();
      array_walk($countries, '_satellite_events_facebook_country_to_code_strtolower');
      $countries = array_flip($countries);
    }

    // If it's already a valid country code, leave it alone.
    if (in_array($country, $countries)) {
      return $countries[$country];
    }

    // Trim whitespace, set to lowercase.
    $country = t(drupal_strtolower(trim($country)));
    if (isset($countries[$country])) {
      return $countries[$country];
    }
    else {
      // If country name cannot be found, return nothing.
      return '';
    }
  }

  public function getStreet() {
    return isset($this->raw->street) ? $this->raw->street : '';
  }

  public function getZipCode() {
    return isset($this->raw->zip) ? $this->raw->zip : '';
  }

  public function getLatitude() {
    return isset($this->raw->latitude) ? floatval($this->raw->latitude) : 0;
  }

  public function getLongitude() {
    return isset($this->raw->longitude) ? floatval($this->raw->longitude) : 0;
  }
}

/**
 * Class definition for ESN Satellite Facebook Events Parser.
 */
class SatelliteFacebookEventsParser extends FeedsParser {

  private function getSummaryMaxLength() {
    return 200;
  }

  public static function getDefaultFieldValue($index) {
    return variable_get("satellite_events_fb_default_$index", NULL);
  }

  public static function updateDefaultFieldValue($index, $value = NULL) {
    variable_set("satellite_events_fb_default_$index", $value);
  }

  private function getValue($entry, $key, $default = '') {
    if (isset($entry, $key, $entry->$key)) {
      return $entry->$key;
    }

    return $default;
  }

  private function getBody($entry, $summary = FALSE) {
    $body = $this->getValue($entry, 'description');

    if ($summary && strlen($body) > $this->getSummaryMaxLength()) {
      // check for a summary delimiter like *********
      $delim = strpos($body, '**********');
      if (0 < $delim) {
        $body = substr($body, 0, $delim);
        return $body;
      }

      $body = trim(substr($body, 0, $this->getSummaryMaxLength()));
      $skipCharacters = ["\n", '.', '?', '!'];
      foreach ($skipCharacters as $skip) {
        $pos = strrpos($body, $skip, -1);
        if (FALSE !== $pos) {
          $body = substr($body, 0, $pos);
          break;
        }
      }
    }
    return trim($body);
  }

  private function getDate($entry, $key) {
    $tz = (new DateObject())->getTimezone()->getName();
    $tz = new DateTimeZone($this->getValue($entry, 'timezone', $tz));
    $value = $this->getValue($entry, $key);

    if (!empty($value)) {
      $value = new DateObject($value, $tz);

    }
    return $value;
  }

  private function getPicture($entry) {
    $picture = $this->getValue($entry, 'cover', null);
    return new FacebookImage($picture);
  }

  private function getEventUrl($entry) {
    return "https://www.facebook.com/events/{$entry->id}/";
  }

  private function getPlace($entry, $key = 'name') {
    $place = $this->getValue($entry, 'place');
    if (isset($place->$key)) {
      return $place->$key;
    }

    return NULL;
  }

  private function getLocation($entry) {
    $location = $this->getPlace($entry, 'location');
    return new FacebookLocation($location);
  }

  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $facebook_feed = $fetcher_result->getRaw();
    $result = new FeedsParserResult();

    $json = json_decode($facebook_feed);

    $items = [];

    foreach ($json->data as $entry) {
      if (!isset($entry->to)) {
        $location = $this->getLocation($entry);
        $item = [
          'event_id' => $entry->id,
          'name' => $this->getValue($entry, 'name'),
          'description' => $this->getBody($entry),
          'short_description' => $this->getBody($entry, TRUE),
          'start_date' => $this->getDate($entry, 'start_time')->getTimestamp(),
          'end_date' => $this->getDate($entry, 'end_time')->getTimestamp(),
          'cover' => $this->getPicture($entry)->getUri(),
          'place_name' => $this->getPlace($entry),
          'place_street' => $location->getStreet(),
          'place_city' => $location->getCity(),
          'place_zip' => $location->getZipCode(),
          'place_country' => $location->getCountry(),
          'place_country_code' => $location->getCountryCode(),
          'link' => $this->getEventUrl($entry),
          'default_value_1' => $this->getDefaultFieldValue(1),
          'default_value_2' => $this->getDefaultFieldValue(1),
          'default_value_3' => $this->getDefaultFieldValue(1),
          'default_value_4' => $this->getDefaultFieldValue(1),
          'default_value_5' => $this->getDefaultFieldValue(1),
        ];
        array_push($items, $item);
      }
    }
    $result->items = $items;
    return $result;
  }

  public function getMappingSources() {
    return parent::getMappingSources() + [
        'event_id' => [
          'name' => t('Event id'),
          'description' => t('Facebook event id'),
        ],
        'name' => [
          'name' => t('Name'),
          'description' => t('Event name'),
        ],
        'description' => [
          'name' => t('Event Description'),
          'description' => t('The full event description ("Details" on facebook)'),
        ],
        'short_description' => [
          'name' => t('Short Event Description'),
          'description' => t('the short description (either that part before a row starting with ********** or the first paragraphs of a maximum length of !length characters', [
            '!length' => $this->getSummaryMaxLength()
          ]),
        ],
        'start_date' => [
          'name' => t('Start date & time'),
          'description' => t('The start date and time of the event'),
        ],
        'end_date' => [
          'name' => t('End date & time'),
          'description' => t('The end date and time of the event'),
        ],
        'cover' => [
          'name' => t('Cover image'),
          'description' => t('The cover image of the Facebook event'),
        ],
        'place_name' => [
          'name' => t('Name of the event location'),
        ],
        'place_street' => [
          'name' => t('Event location: Street'),
          'description' => t('Street and house number of the event location'),
        ],
        'place_city' => [
          'name' => t('Event location: City'),
        ],
        'place_zip' => [
          'name' => t('Event location: Zip code'),
        ],
        'place_country' => [
          'name' => t('Event location: Country'),
        ],
        'place_country_code' => [
          'name' => t('Event location: Country (ISO Code)'),
        ],
        'default_value_1' => [
          'name' => t('Default value 1'),
          'description' => t('Provides a static default value which can be assigned to a target.\nValue: <strong>@value</strong>', [
            '@value' => self::getDefaultFieldValue(1),
          ])
        ],
        'default_value_2' => [
          'name' => t('Default value 2'),
          'description' => t('Provides a static default value which can be assigned to a target.\nValue: <strong>@value</strong>', [
            '@value' => self::getDefaultFieldValue(2),
          ])
        ],
        'default_value_3' => [
          'name' => t('Default value 3'),
          'description' => t('Provides a static default value which can be assigned to a target.\nValue: <strong>@value</strong>', [
            '@value' => self::getDefaultFieldValue(3),
          ])
        ],
        'default_value_4' => [
          'name' => t('Default value 4'),
          'description' => t('Provides a static default value which can be assigned to a target.\nValue: <strong>@value</strong>', [
            '@value' => self::getDefaultFieldValue(4),
          ])
        ],
        'default_value_5' => [
          'name' => t('Default value 5'),
          'description' => t('Provides a static default value which can be assigned to a target.\nValue: <strong>@value</strong>', [
            '@value' => self::getDefaultFieldValue(5),
          ])
        ],
        'link' => [
          'name' => t('Link'),
          'description' => t('Url of the Facebook event'),
        ],
      ];
  }
}
