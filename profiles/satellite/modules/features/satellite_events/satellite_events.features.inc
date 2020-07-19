<?php
/**
 * @file
 * satellite_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function satellite_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function satellite_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Create an event. You can add an image beeing shown in different lists and on the article full view, an image for the spotlight of the front page, further images as a gallery. Also you can attach links or documents. You have to set the start date and can optionally set an end date and/or time for both. The event will be shown in the <a href="calendar" target="_blank">calendar</a>. There are many other options and contents you can add which are specific to events.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
