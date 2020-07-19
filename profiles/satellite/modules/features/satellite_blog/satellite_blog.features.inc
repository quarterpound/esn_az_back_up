<?php

/**
 * @file
 * satellite_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function satellite_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function satellite_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => t('Create a blog post on for your website. It contains a title, body and optional image and can be categorized using tags.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function satellite_blog_weight_features_default_settings() {
  $settings = array();

  $settings['blog'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
