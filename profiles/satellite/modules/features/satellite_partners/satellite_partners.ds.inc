<?php
/**
 * @file
 * satellite_partners.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function satellite_partners_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|partner|block';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'partner';
  $ds_fieldsetting->view_mode = 'block';
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
  $export['node|partner|block'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|partner|list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'partner';
  $ds_fieldsetting->view_mode = 'list';
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
  $export['node|partner|list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|partner|spotlight';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'partner';
  $ds_fieldsetting->view_mode = 'spotlight';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|partner|spotlight'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function satellite_partners_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|partner|block';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'partner';
  $ds_layout->view_mode = 'block';
  $ds_layout->layout = 'esn_block';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'title',
        2 => 'field_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'title' => 'main_content',
      'field_link' => 'main_content',
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
  );
  $export['node|partner|block'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|partner|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'partner';
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
        2 => 'field_link',
        3 => 'field_file',
        4 => 'service_links_displays_group',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'body' => 'main_content',
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
  $export['node|partner|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|partner|list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'partner';
  $ds_layout->view_mode = 'list';
  $ds_layout->layout = 'esn_list';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'title',
        2 => 'field_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'title' => 'main_content',
      'field_link' => 'main_content',
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
  );
  $export['node|partner|list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|partner|spotlight';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'partner';
  $ds_layout->view_mode = 'spotlight';
  $ds_layout->layout = 'esn_spotlight';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'title',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'title' => 'main_content',
      'body' => 'main_content',
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
  $export['node|partner|spotlight'] = $ds_layout;

  return $export;
}
