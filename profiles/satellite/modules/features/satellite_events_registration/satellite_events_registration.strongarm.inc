<?php
/**
 * @file
 * satellite_events_registration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function satellite_events_registration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_node_event';
  $strongarm->value = 1;
  $export['webform_node_event'] = $strongarm;

  return $export;
}
