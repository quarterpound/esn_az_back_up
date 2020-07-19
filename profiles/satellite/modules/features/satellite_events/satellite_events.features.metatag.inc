<?php
/**
 * @file
 * satellite_events.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function satellite_events_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:event.
  $config['node:event'] = array(
    'instance' => 'node:event',
    'disabled' => FALSE,
    'config' => array(
      'itemtype' => array(
        'value' => 'Event',
      ),
    ),
  );

  return $config;
}
