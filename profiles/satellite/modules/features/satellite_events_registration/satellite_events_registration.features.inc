<?php
/**
 * @file
 * satellite_events_registration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_events_registration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
