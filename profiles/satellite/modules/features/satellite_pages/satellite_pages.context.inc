<?php
/**
 * @file
 * satellite_pages.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function satellite_pages_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pages';
  $context->description = '';
  $context->tag = 'Sections';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'activity' => 'activity',
        'event' => 'event',
        'news' => 'news',
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'news-events' => 'news-events',
        'activities' => 'activities',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'left',
          'weight' => '-10',
        ),
      ),
      'layout' => 'left_sidebar',
    ),
    'theme_regions' => array(
      'region_secondary_navigation' => '',
      'region_branding' => '',
      'region_toggle' => '',
      'region_content' => 'size-70',
      'region_featured' => '',
      'region_featured_left' => '',
      'region_featured_right' => '',
      'region_help' => '',
      'region_left' => 'size-30',
      'region_page_top' => '',
      'region_page_bottom' => '',
      'region_right' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sections');
  $export['pages'] = $context;

  return $export;
}
