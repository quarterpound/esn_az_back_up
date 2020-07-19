<?php

use ESN\Satellite\Notifications\NotificationManager;

require_once 'satellite.const.inc';

function satellite_register_autoloader() {
  static $registered = FALSE;
  $autoloader = DRUPAL_ROOT . '/vendor/autoload.php';

  if (!$registered) {
    if (!file_exists($autoloader)) {
      $message = t('Autoloader not found: @file', array('@file' => $autoloader));
      watchdog('satellite', $message, WATCHDOG_CRITICAL);
    }
    $registered = TRUE;
  }

  return require $autoloader;
}

include_once 'satellite.api.inc';

function satellite_menu() {
  $items = [];

  $items['admin/settings/satellite/notifications/update'] = array(
    'title'            => 'Galaxy integration',
    'description'      => 'Configure your country, section, and permissions',
    'page callback'    => 'satellite_notifications_update',
    'access arguments' => array('administer satellite settings'),
    'type'             => MENU_CALLBACK,
  );

  return $items;
}

function satellite_notifications_update() {
  \ESN\Satellite\Notifications\NotificationManager::update();
  drupal_goto('admin/reports/status');
}

function satellite_install_tasks_alter(&$tasks, $install_state) {
  // Hide the profile and language selection
  $tasks['install_select_profile']['display'] = false;
  $tasks['install_select_locale']['display'] = false;
  $tasks['install_select_locale']['function'] = 'esn_set_en_default_lang';
  
  // change the theme
  _satellite_set_theme('install');
  
}

function satellite_cron() {
  \ESN\Satellite\Notifications\NotificationManager::update();
}

function satellite_init() {
  satellite_register_autoloader();
  // Don't execute the Notification manager during site installation as it might not been fully initialized yet.
  if (FALSE === variable_get('satellite_notification_initializing', FALSE)) {
    $manager = NotificationManager::load();
    if ($manager) {
      $manager->renderMessages();
    }
  }
}

function satellite_preprocess_html(&$variables) {
  $manager = NotificationManager::load();
  if ($manager) {
    $classes = [];
    foreach ($manager->getMessages() as $message) {
      $class = $message->getBodyClass();
      if (!empty($class)) {
        array_push($classes, $class);
      }
    }
    $variables['classes_array'] = array_merge($variables['classes_array'], $classes);
  }
}

function esn_set_en_default_lang(&$install_state) {
  $install_state['parameters']['locale'] = 'en';
}

/**
 * Force-set a theme at any point during the execution of the request.
 *
 * Drupal doesn't give us the option to set the theme during the installation
 * process and forces enable the maintenance theme too early in the request
 * for us to modify it in a clean way.
 */
function _satellite_set_theme($target_theme) {
  if ($GLOBALS['theme'] != $target_theme) {
    unset($GLOBALS['theme']);

    drupal_static_reset();
    $GLOBALS['conf']['maintenance_theme'] = $target_theme;
    _drupal_maintenance_theme();
  }
}

/**
 * Returns a filtered list of _country_get_predefined_list().
 */
function _satellite_get_supported_countries(){
	include_once DRUPAL_ROOT . '/includes/iso.inc';

	$supported_countries = array_keys(esn_galaxy_api_countries());
	$supported_countries = array_fill_keys($supported_countries, 1);
	$all_countries = _country_get_predefined_list();
	$all_countries = array_intersect_key($all_countries, $supported_countries);
	return $all_countries;
}
