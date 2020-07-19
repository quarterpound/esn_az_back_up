<?php

use ESN\Satellite\Notifications\NotificationManager;

/**
 * Implements hook_drush_help()
 *
 * TODO: Write meaningful function comment
 *
 * @param $command
 *    The Drush command to output help for
 *
 * @return array|mixed|string|null
 */
function satellite_base_drush_help($command) {
  switch ($command) {
    case 'drush:satellite-update-notifications':
      return dt('Update Satellite Notifications from ESN');
  }
  return '';
}

/**
 * Implements hook_drush_command().
 *
 * TODO: Write meaningful function comment
 */
function satellite_base_drush_command() {
  $items = [];

  $items['satellite-update-notifications'] = [
    'description' => satellite_base_drush_help('drush:satellite-update-notifications'),
    'callback' => 'satellite_base_update_notifications',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => [
      'filesystem' => dt('Drupal file system to sanitize'),
    ],
    'options' => [],
    'drupal_dependencies' => [
      'satellite',
      'file',
    ],
    'aliases' => [
      'upnot',
    ],
  ];

  return $items;
}

function satellite_base_update_notifications() {
  NotificationManager::update();
}
