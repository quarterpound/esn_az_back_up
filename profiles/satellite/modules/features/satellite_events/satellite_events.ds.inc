<?php
/**
 * @file
 * satellite_events.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function satellite_events_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|block';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'block';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|event|block'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|event|list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|spotlight';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
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
  $export['node|event|spotlight'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function satellite_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|block';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'block';
  $ds_layout->layout = 'esn_block';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'field_date',
        2 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'field_date' => 'main_content',
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
  $export['node|event|block'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'esn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'main_content' => array(
        0 => 'service_links_displays_group',
        2 => 'body',
      ),
      'image' => array(
        1 => 'field_image',
      ),
      'secondary' => array(
        3 => 'group_details',
        4 => 'field_image_gallery',
        5 => 'field_file',
        6 => 'field_date',
        7 => 'field_time',
        8 => 'field_place',
        9 => 'field_meetingpoint',
        10 => 'field_address',
        11 => 'field_price',
        12 => 'field_included',
        13 => 'field_contactdetails',
        14 => 'field_link',
        15 => 'field_event_audience',
      ),
    ),
    'fields' => array(
      'service_links_displays_group' => 'main_content',
      'field_image' => 'image',
      'body' => 'main_content',
      'group_details' => 'secondary',
      'field_image_gallery' => 'secondary',
      'field_file' => 'secondary',
      'field_date' => 'secondary',
      'field_time' => 'secondary',
      'field_place' => 'secondary',
      'field_meetingpoint' => 'secondary',
      'field_address' => 'secondary',
      'field_price' => 'secondary',
      'field_included' => 'secondary',
      'field_contactdetails' => 'secondary',
      'field_link' => 'secondary',
      'field_event_audience' => 'secondary',
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
    'layout_disable_css' => 0,
  );
  $export['node|event|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'list';
  $ds_layout->layout = 'esn_list';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'field_date',
        2 => 'title',
        3 => 'field_summary',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'field_date' => 'main_content',
      'title' => 'main_content',
      'field_summary' => 'main_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'image' => 'div',
      'main_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|event|list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|spotlight';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'spotlight';
  $ds_layout->layout = 'esn_spotlight';
  $ds_layout->settings = array(
    'regions' => array(
      'main_content' => array(
        0 => 'title',
        1 => 'field_date',
      ),
      'image' => array(
        2 => 'field_image_spotlight',
      ),
    ),
    'fields' => array(
      'title' => 'main_content',
      'field_date' => 'main_content',
      'field_image_spotlight' => 'image',
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
  $export['node|event|spotlight'] = $ds_layout;

  return $export;
}
