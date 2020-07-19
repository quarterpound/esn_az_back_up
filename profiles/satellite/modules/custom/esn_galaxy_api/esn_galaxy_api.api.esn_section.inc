<?php

/**
 * @file
 */

/**
 *
 */
function _esn_section_info() {
  $esn_section = array(
    'esn_section' => array(
      'label' => t('ESN Section'),
      'plural label' => t('ESN Sections'),
      'entity class' => 'Entity',
      'controller class' => 'EntityAPIController',
      'module' => 'esn_galaxy_api',
      'base table' => 'esn_section',
      'load hook' => 'esn_section_load',
      'fieldable' => FALSE,
      'entity keys' => array(
        'id' => 'section_id',
        'label' => 'name',
      ),
      'access callback' => 'esn_section_entity_access',
    ),
  );
  return $esn_section;
}

/**
 *
 */
function esn_section_entity_access($op = 'view', $entity = NULL, $account = NULL, $entity_type = '') {
  if ($op = 'view') {
    return TRUE;
  }
  return user_access($op, $account);
}

/**
 *
 */
function _esn_section_property_info_alter(&$section) {
  _esn_galaxy_api_set_property_callbacks($section);
  $section['properties']['section_id']['label'] = t('Drupal entity ID');
  $section['properties']['code']['label'] = t('ESN Section code');
  $section['properties']['country_code']['label'] = t('ESN Country code');
  $section['properties']['name']['label'] = t('ESN Section name');
  $section['properties']['city']['label'] = t('City');
  $section['properties']['street']['label'] = t('Street');
  $section['properties']['postaladdress']['label'] = t('Postal address of the ESN Section');
  $section['properties']['website']['label'] = t('Website of the ESN Section');
  $country['properties']['site_logo']['label'] = t('Logo url of the ESN Section');
  $section['properties']['latitude']['label'] = t('Latitude of the ESN Section');
  $section['properties']['latitude']['type'] = 'decimal';
  $section['properties']['longitude']['label'] = t('Longitude of the ESN Section');
  $section['properties']['longitude']['type'] = 'decimal';
  $section['properties']['last_updated']['type'] = 'date';
  $section['properties']['last_updated']['label'] = t('Last updated');

  // Country reference.
  $section['properties']['country'] = array(
    'label' => t('ESN Country'),
    'description' => t('Country in which this section is. The country entity described by the \'ESN Country code\''),
    'type' => 'esn_country',
    'getter callback' => '_esn_galaxy_api_get_properties',
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'country_id',
    'required' => TRUE,
  );
}

/**
 * Loads an ESN Section entity by it's ID.
 *
 * @param $id
 *   The ID of the section.
 * @param bool $reset
 *   Whether to reset the node_load_multiple cache.
 *
 * @return
 *  The ESN Country entity or FALSE if not found.
 */
function esn_section_load($id, $reset = FALSE) {
  $sections = esn_section_load_multiple(array($id), TRUE);
  return reset($sections);
}

/**
 * Loads ESN Section entities by it's IDs.
 *
 * @param array $ids
 *   The IDs of the ESN sections to load.
 * @param bool $resetWhether
 *   to reset the esn_section_load_multiple cache.
 *   Whether to reset the esn_section_load_multiple cache.
 *
 * @return mixed
 *  Array of ESN Section entities
 */
function esn_section_load_multiple($ids = array(), $reset = FALSE) {
  if (is_array($ids) && count($ids) == 0) {
    return esn_section_load_all($reset);
  }
  $result = entity_load('esn_section', $ids, array(), TRUE);
  array_walk($result, '_esn_galaxy_api_wrap_entity', array('type' => 'esn_section'));
  return _esn_galaxy_api_map_array_to_code($result);
}

/**
 * Loads all ESN Section entities.
 *
 * @param bool $resetWhether
 *   to reset the esn_section_load_multiple cache.
 *   Whether to reset the esn_section_load_multiple cache.
 *
 * @return mixed
 *  Array of ESN Section entities
 */
function esn_section_load_all($reset = FALSE) {
  $result = entity_load('esn_section', FALSE, array(), TRUE);
  array_walk($result, '_esn_galaxy_api_wrap_entity', array('type' => 'esn_section'));
  return _esn_galaxy_api_map_array_to_code($result);
}

/**
 * Loads an ESN Section entity by it's ID.
 *
 * @param $code
 *   The ESN Section code of the country.
 * @param bool $reset
 *   Whether to reset the node_load_multiple cache.
 *
 * @return
 *  The ESN Section entity or FALSE if not found.
 */
function esn_section_load_by_code($code, $reset = FALSE) {
  $sections = esn_section_load_multiple_by_code(array($code), $reset);
  $section = reset($sections);
  return $section;
}

/**
 * Loads ESN Section entities by it's section codes.
 *
 * @param array $codes
 *   The country codes of the ESN sections to load.
 * @param bool $resetWhether
 *   to reset the esn_section_load_multiple cache.
 *   Whether to reset the esn_section_load_multiple cache.
 *
 * @return mixed
 *  Array of ESN Section entities
 */
function esn_section_load_multiple_by_code($codes = array(), $reset = FALSE) {
  try {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'esn_section')
      ->propertyCondition('code', $codes, 'IN')
      ->propertyOrderBy('name');

    $result = $query->execute();
    $result = array_keys($result['esn_section']);
    return esn_section_load_multiple($result, $reset);
  } catch (Exception $ex) {
    return array();
  }
}

/**
 * Loads ESN Section entities of a specific country..
 *
 * @param mixed $country
 *   The (wrapped) ESN Country entity or country code of the country to load sections..
 * @param bool $resetWhether
 *   to reset the esn_section_load_multiple cache.
 *   Whether to reset the esn_section_load_multiple cache.
 *
 * @return mixed
 *  Array of ESN Section entities
 */
function esn_section_load_multiple_by_country($country, $reset = FALSE) {
  try {
    if (is_subclass_of($country, 'Entity')) {
      $country = entity_metadata_wrapper('esn_country', $country);
    }
    if (is_subclass_of($country, 'EntityDrupalWrapper')) {
      $country = $country->code->value();
    }
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'esn_section')
      ->propertyCondition('country_code', $country, '=')
      ->propertyOrderBy('name');

    $result = $query->execute();
    $result = array_keys($result['esn_section']);
    return esn_section_load_multiple($result, $reset);
  } catch (Exception $ex) {
    return array();
  }
}

/**
 * Create a new ESN Section entity.
 *
 * @param array $data
 *   The properties of the ESN Section
 *
 * @return bool
 *  The entity object created
 */
function esn_section_create($data) {
  $section = entity_create('esn_section', array());
  $section = entity_metadata_wrapper('esn_section', $section);
  foreach ($data as $key => $value) {
    $section->$key->set($value);
  }
  return $section;
}

/**
 * Saves an ESN Section.
 *
 * @param $section
 *   THe ESN Section entity to save
 *
 * @return bool
 *  SAVED_NEW if the entity has been created, SAVED_UPDATED if it has been updated.
 */
function esn_section_save($section) {
  return entity_save('esn_section', $section);
}

/**
 * Deletes an ESN Section.
 *
 * @param $section
 *   The ESN Section entity to delete.
 */
function esn_section_delete($section) {
  entity_delete('esn_section', $section->getIdentifier());
}

/**
 * Deletes ESN Sections.
 *
 * @param $section_ids
 *   The ESN Sections to delete.
 */
function esn_section_delete_multiple($section_ids) {
  entity_delete_multiple('esn_section', $section_ids);
}

/**
 * Count the numbers of ESN Sections.
 */

function esn_section_count() {
  try {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'esn_section')
      ->count();

    $result = (int) $query->execute();
    return $result;
  } catch (Exception $ex) {
    return 0;
  }
}
