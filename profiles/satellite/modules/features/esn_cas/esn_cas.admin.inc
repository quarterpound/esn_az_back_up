<?php

/**
 * @file
 * Provides settings pages for the CAS Attributes module.
 */

/**
 * Administrative settings form.
 */
function esn_cas_admin_settings() {
  
  if (!function_exists('remote_stream_wrapper_file_load_by_uri')) {
    return array('esn_cas_remote_stream_wrapper' => array(
      '#markup' => t('The module <em><a href="http://drupal.org/project/remote_stream_wrapper" target="_blank">remote_stream_wrapper</a></em> has to be enabled to fetch Galaxy pictures.'),
    ));
  }
  
  $form['esn_cas_sync_every_login'] = array(
    '#type' => 'radios',
    '#title' => t('Update user picture'),
    '#default_value' => variable_get('esn_cas_sync_every_login'),
    '#options' => array(
      0 => t('only when a CAS account is created (i.e., the first login of a CAS user).'),
      1 => t('every time a CAS user logs in.'),
    ),
    '#weight' => -10,
  );

  $picture_field_options = array('' => t('- No picture -'));
  if (variable_get('user_pictures', 0)) {
    $picture_field_options['picture'] = t('user picture');
  }
  // get all image fields attached to the user
  foreach (field_info_field_map() as $field_name => $field_map) {
    if (isset($field_map['bundles']['user']) && $field_map['type'] == 'image') {
      $picture_field_options[$field_name] = $field_name;
    }
  }

  $form['esn_cas_picture_field'] = array(
    '#type' => 'select',
    '#title' => t('Picture field'),
    '#default_value' => variable_get('esn_cas_picture_field', ''),
    '#options' => $picture_field_options,
    '#description' => t('Set which user field the Galaxy profile picture should be synced to.'),
    '#weight' => -9,
  );
  
  return system_settings_form($form);
}


