<?php
/**
 * @file
 * satellite_spotlight.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_spotlight_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function satellite_spotlight_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
