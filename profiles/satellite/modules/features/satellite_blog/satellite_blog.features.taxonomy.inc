<?php

/**
 * @file
 * satellite_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function satellite_blog_taxonomy_default_vocabularies() {
  return array(
    'blog_category' => array(
      'name' => 'Blog Category',
      'machine_name' => 'blog_category',
      'description' => 'Tag your blog posts',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
