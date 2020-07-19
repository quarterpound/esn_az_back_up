<?php
/**
 * @file
 * satellite_team.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function satellite_team_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_profile2__team_member';
  $strongarm->value = array(
    'view_modes' => array(
      'account' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'profile' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_profile2__team_member'] = $strongarm;

  return $export;
}
