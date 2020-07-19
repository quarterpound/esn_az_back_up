<?php
/**
 * @file
 * satellite_base.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function satellite_base_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'block';
  $ds_view_mode->label = 'Block';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['block'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'list';
  $ds_view_mode->label = 'List';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['list'] = $ds_view_mode;

  return $export;
}
