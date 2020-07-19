<?php
/**
 * @file
 * satellite_news.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function satellite_news_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|block';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
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
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|news|block'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
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
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium',
    ),
  );
  $export['node|news|list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|spotlight';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
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
  $export['node|news|spotlight'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function satellite_news_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|block';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'block';
  $ds_layout->layout = 'esn_block';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'post_date',
        2 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'post_date' => 'main_content',
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
  $export['node|news|block'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'esn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'body',
        2 => 'service_links_displays_group',
      ),
      'secondary' => array(
        3 => 'field_image_gallery',
        4 => 'field_link',
        5 => 'field_file',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'body' => 'main_content',
      'service_links_displays_group' => 'main_content',
      'field_image_gallery' => 'secondary',
      'field_link' => 'secondary',
      'field_file' => 'secondary',
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
  $export['node|news|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'list';
  $ds_layout->layout = 'esn_block';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image',
      ),
      'main_content' => array(
        1 => 'post_date',
        2 => 'title',
        3 => 'field_summary',
      ),
    ),
    'fields' => array(
      'field_image' => 'image',
      'post_date' => 'main_content',
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
  );
  $export['node|news|list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|spotlight';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'spotlight';
  $ds_layout->layout = 'esn_spotlight';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image_spotlight',
      ),
      'main_content' => array(
        1 => 'title',
        2 => 'field_summary',
      ),
    ),
    'fields' => array(
      'field_image_spotlight' => 'image',
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
  );
  $export['node|news|spotlight'] = $ds_layout;

  return $export;
}
