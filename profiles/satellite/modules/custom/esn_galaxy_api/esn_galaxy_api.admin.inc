<?php

/**
 * @file
 * Provides settings pages for the CAS Attributes module.
 */

/**
 * Administrative settings form.
 */
function esn_galaxy_api_admin_settings() {

  $form['esn_galaxy_api_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Refresh sections and countries with each cron run'),
    '#default_value' => variable_get('esn_galaxy_api_cron', 0),
    '#return_value' => 1,
    '#weight' => -10,
  );

  $form['esn_galaxy_api_clear'] = array(
    '#type' => 'submit',
    '#value' => t('Refresh ESN Sections'),
    '#name' => 'clear',
    '#submit' => array('esn_galaxy_api_admin_settings_update'),
    '#weight' => -9,
  );

  $form['esn_galaxy_api_webform'] = array(
    '#type' => 'checkbox',
    '#title' => t('Support webform select options'),
    '#default_value' => variable_get('esn_galaxy_api_webform', 0),
    '#return_value' => 1,
    '#weight' => -10,
  );

  return system_settings_form($form);
}

/**
 * Clear caches when the refresh button is pushed.
 */
function esn_galaxy_api_admin_settings_update($form, &$form_state) {

  // Repopulation of tables.
  module_load_include('inc', 'esn_galaxy_api', 'esn_galaxy_api.load');
  _esn_galaxy_api_save_countries();
  _esn_galaxy_api_save_sections();

  drupal_set_message("The section list has been updated.");

}
