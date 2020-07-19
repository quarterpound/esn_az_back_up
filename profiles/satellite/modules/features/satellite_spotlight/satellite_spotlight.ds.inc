<?php
/**
 * @file
 * satellite_spotlight.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function satellite_spotlight_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'spotlight';
  $ds_view_mode->label = 'Spotlight';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['spotlight'] = $ds_view_mode;

  return $export;
}
