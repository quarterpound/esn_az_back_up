<?php
/**
 * @file
 * satellite_partners.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function satellite_partners_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_level'
  $field_bases['field_level'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_level',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Local' => 'Local',
        'National' => 'National',
        'International' => 'International',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
