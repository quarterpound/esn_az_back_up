<?php
/**
 * @file
 * satellite_partners.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function satellite_partners_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:partner.
  $config['node:partner'] = array(
    'instance' => 'node:partner',
    'disabled' => FALSE,
    'config' => array(
      'itemtype' => array(
        'value' => 'Organization',
      ),
    ),
  );

  return $config;
}
