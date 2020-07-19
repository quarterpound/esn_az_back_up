<?php
/**
 * @file
 * esn_base.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function esn_base_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'base-menu';
  $context->description = 'The main menu placed in the primary navigation';
  $context->tag = 'DON\'T TOUCH';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => '1',
          'region' => 'nav_primary',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('DON\'T TOUCH');
  t('The main menu placed in the primary navigation');
  $export['base-menu'] = $context;

  return $export;
}
