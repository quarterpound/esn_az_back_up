<?php
/**
 * @file
 * satellite_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function satellite_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendar';
  $context->description = '';
  $context->tag = 'Sections';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'events_calendar:month' => 'events_calendar:month',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'calendar-calendar_legend' => array(
          'module' => 'calendar',
          'delta' => 'calendar_legend',
          'region' => 'content_sidebar',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sections');
  $export['calendar'] = $context;

  return $export;
}
