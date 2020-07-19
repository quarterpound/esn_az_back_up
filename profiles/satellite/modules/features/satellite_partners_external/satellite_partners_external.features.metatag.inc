<?php
/**
 * @file
 * satellite_partners_external.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function satellite_partners_external_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:partner_external.
  $config['node:partner_external'] = array(
    'instance' => 'node:partner_external',
    'disabled' => FALSE,
    'config' => array(
      'itemtype' => array(
        'value' => 'Organization',
      ),
    ),
  );

  return $config;
}
