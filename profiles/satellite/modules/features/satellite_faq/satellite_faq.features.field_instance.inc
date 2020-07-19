<?php
/**
 * @file
 * satellite_faq.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function satellite_faq_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_faq-field_faq_answer'
  $field_instances['field_collection_item-field_faq-field_faq_answer'] = array(
    'bundle' => 'field_faq',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The answer or detailed information.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_faq_answer',
    'label' => 'Answer',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_faq-field_faq_question'
  $field_instances['field_collection_item-field_faq-field_faq_question'] = array(
    'bundle' => 'field_faq',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The question or headline. Text should be short and make clear what the following text is about (max 60 characters).',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_faq_question',
    'label' => 'Question',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-event-field_faq'
  $field_instances['node-event-field_faq'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'You can add a list of frequent questions and answers (FAQ) which will be rendered as a collapsible list at the bottom of the event page. You can add as many items as you want and reorder them.',
    'display' => array(
      'block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'satellite_faq',
        'settings' => array(),
        'type' => 'satellite_faq_faqlist_collapsible',
        'weight' => 4,
      ),
      'list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'spotlight' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_faq',
    'label' => 'FAQ',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 20,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Answer');
  t('FAQ');
  t('Question');
  t('The answer or detailed information.');
  t('The question or headline. Text should be short and make clear what the following text is about (max 60 characters).');
  t('You can add a list of frequent questions and answers (FAQ) which will be rendered as a collapsible list at the bottom of the event page. You can add as many items as you want and reorder them.');

  return $field_instances;
}
