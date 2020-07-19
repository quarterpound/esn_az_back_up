<?php
/**
 * @file
 * satellite_news.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function satellite_news_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-list';
  $context->description = '';
  $context->tag = 'Sections';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'news:page' => 'news:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-feature_pages-1' => array(
          'module' => 'menu_block',
          'delta' => 'feature_pages-1',
          'region' => 'left',
          'weight' => '-10',
        ),
      ),
      'layout' => 'left_sidebar',
    ),
    'theme_regions' => array(
      'region_content' => 'size-70',
      'region_left' => 'size-30',
      'region_right' => '',
      'region_featured' => '',
      'region_page_top' => '',
      'region_page_bottom' => '',
      'region_help' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sections');
  $export['news-list'] = $context;

  return $export;
}
