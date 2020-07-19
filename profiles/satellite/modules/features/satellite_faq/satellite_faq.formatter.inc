<?php
  /**
   * @file
   * satellite_faq.formatter.inc
  */

  /**
   * Implements hook_field_formatter_info().
   */
  function satellite_faq_field_formatter_info() {
    $info = array(
      'satellite_faq_faqlist' => array(
          'label' => t('FAQ list'),
          'field types' => array('field_collection'),
          'description' => t('Displays the FAQ collection as a list of questions and answers.')
          ),
        'satellite_faq_faqlist_collapsible' => array(
          'label' => t('FAQ list (collapsible)'),
          'field types' => array('field_collection'),
          'description' => t('Displays the FAQ collection as a list of questions and answers whcih can be collapsed.')
          )
        );
    return $info; 
  }
  
  /**
  * Implements hook_field_formatter_view().
  */
  function satellite_faq_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
    $elements = array();
    $collapsed = false;
    foreach ($items as $delta => $item) {
      $collapsed = $display['type'] == 'satellite_faq_faqlist_collapsible';
      if ($display['type'] == 'satellite_faq_faqlist' || $collapsed) {
        $field_collection = field_collection_field_get_entity($item);
        if ($field_collection && $field_collection->field_name == 'field_faq') {
          $id = 'faq_' . $item['value'];
          $question = check_plain((isset($field_collection->field_faq_question[$langcode]) ? $field_collection->field_faq_question[$langcode][0]['value'] : ''));
          $answer = check_markup((isset($field_collection->field_faq_answer[$langcode]) ? $field_collection->field_faq_answer[$langcode][0]['value'] : ''), null, $langcode);
          $question = array(
            '#type' => 'html_tag',
            '#tag' => 'h4',
            '#attributes' => array('class' => 'faq-question'),
            '#value' => $question
            );
          if ($collapsed) {
            $question['#attributes']['data-faq'] = $id;
          }
          $answer = array(
            '#type' => 'container',
            '#attributes' => array('class' => 'faq-answer', 'id' => $id),
            '0' => array('#markup' => $answer)
            );
          $elements[$delta] = array('question' => array(
            '#type' => 'container',
            '#attributes' => array('class' => 'faq-list-item' . ($collapsed ? ' faq-list-item-collapsible' : '')),
            '0' => $question,
            '1' => $answer
            ));
        }
      }
    }
    if ($collapsed|| true){
      $elements['#attached']['js'][] = drupal_get_path('module', 'satellite_faq') . '/satellite_faq.js';
      $elements['#attached']['css'][] = drupal_get_path('module', 'satellite_faq') . '/satellite_faq.css';
    }
    return $elements;
}