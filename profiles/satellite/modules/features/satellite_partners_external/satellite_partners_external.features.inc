<?php
/**
 * @file
 * satellite_partners_external.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_partners_external_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function satellite_partners_external_node_info() {
  $items = array(
    'partner_external' => array(
      'name' => t('Partner (External)'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a <em>national</em> (for local sections) or <em>international</em> cooperation partner.<br />
This content type is used for partners imported from external sources like <a href="http://galaxy.esn.org" target="_blank">galaxy.esn.org</a>.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
