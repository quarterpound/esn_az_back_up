<?php
/**
 * @file
 * satellite_pages.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function satellite_pages_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|spotlight';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'spotlight';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|page|spotlight'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function satellite_pages_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'esn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'body',
      ),
      'secondary' => array(
        2 => 'field_image_gallery',
        3 => 'field_link',
        4 => 'field_file',
        5 => 'service_links_displays_group',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'body' => 'main_content',
      'field_image_gallery' => 'secondary',
      'field_link' => 'secondary',
      'field_file' => 'secondary',
      'service_links_displays_group' => 'secondary',
    ),
    'classes' => array(),
    'wrappers' => array(
      'image' => 'div',
      'main_content' => 'div',
      'secondary' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|page|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|spotlight';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'spotlight';
  $ds_layout->layout = 'esn_spotlight';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image_spotlight',
      ),
      'main_content' => array(
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_image_spotlight' => 'image',
      'title' => 'main_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'image' => 'div',
      'main_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|page|spotlight'] = $ds_layout;

  return $export;
}
