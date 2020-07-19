<?php

/**
 * @file
 * satellite_blog.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function satellite_blog_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:blog.
  $config['node:blog'] = array(
    'instance' => 'node:blog',
    'disabled' => FALSE,
    'config' => array(
      'itemtype' => array(
        'value' => 'Blog',
      ),
      'og:type' => array(
        'value' => 'blog',
      ),
    ),
  );

  return $config;
}
