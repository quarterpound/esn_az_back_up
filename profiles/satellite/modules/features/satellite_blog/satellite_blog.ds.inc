<?php

/**
 * @file
 * satellite_blog.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function satellite_blog_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submitted_by' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
    'service_links_displays_group' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'sld_group_text',
    ),
  );
  $export['node|blog|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog|list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog';
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
    'submitted_by' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|blog|list'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function satellite_blog_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'esn_page';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image_blog',
      ),
      'main_content' => array(
        1 => 'submitted_by',
        2 => 'body',
        3 => 'field_blog_categories',
        4 => 'service_links_displays_group',
        5 => 'comments',
      ),
    ),
    'fields' => array(
      'field_image_blog' => 'image',
      'submitted_by' => 'main_content',
      'body' => 'main_content',
      'field_blog_categories' => 'main_content',
      'service_links_displays_group' => 'main_content',
      'comments' => 'main_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'image' => 'div',
      'main_content' => 'div',
      'secondary' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|blog|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'list';
  $ds_layout->layout = 'esn_block';
  $ds_layout->settings = array(
    'regions' => array(
      'image' => array(
        0 => 'field_image_blog',
      ),
      'main_content' => array(
        1 => 'title',
        2 => 'submitted_by',
        3 => 'body',
        4 => 'field_blog_categories',
      ),
    ),
    'fields' => array(
      'field_image_blog' => 'image',
      'title' => 'main_content',
      'submitted_by' => 'main_content',
      'body' => 'main_content',
      'field_blog_categories' => 'main_content',
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
  $export['node|blog|list'] = $ds_layout;

  return $export;
}
