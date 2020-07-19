<?php
/**
 * @file
 * satellite_dummy_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_dummy_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
