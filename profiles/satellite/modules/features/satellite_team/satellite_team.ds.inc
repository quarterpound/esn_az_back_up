<?php
/**
 * @file
 * satellite_team.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function satellite_team_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|team_member|account';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'team_member';
  $ds_layout->view_mode = 'account';
  $ds_layout->layout = 'esn_list';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_photo',
      ),
      'main_content' => array(
        1 => 'field_full_name',
        2 => 'field_position',
        3 => 'field_bio',
      ),
    ),
    'fields' => array(
      'field_photo' => 'image',
      'field_full_name' => 'main_content',
      'field_position' => 'main_content',
      'field_bio' => 'main_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'image' => 'div',
      'main_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['profile2|team_member|account'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|team_member|default';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'team_member';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'esn_list';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_photo',
      ),
      'main_content' => array(
        1 => 'field_full_name',
        2 => 'field_position',
        3 => 'field_bio',
      ),
    ),
    'fields' => array(
      'field_photo' => 'image',
      'field_full_name' => 'main_content',
      'field_position' => 'main_content',
      'field_bio' => 'main_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'image' => 'div',
      'main_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['profile2|team_member|default'] = $ds_layout;

  return $export;
}
