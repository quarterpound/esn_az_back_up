<?php

/**
 * @file
 */

/**
 *
 */
function _esn_country_info() {
  $esn_country = array(
    'esn_country' => array(
      'label' => t('ESN Country'),
      'plural label' => t('ESN Countries'),
      'entity class' => 'Entity',
      'controller class' => 'EntityAPIController',
      'module' => 'esn_galaxy_api',
      'base table' => 'esn_country',
      'load hook' => 'esn_country_load',
      'fieldable' => FALSE,
      'entity keys' => array(
        'id' => 'country_id',
        'label' => 'country_name',
      ),
      'access callback' => 'esn_country_entity_access',
    ),
  );
  return $esn_country;
}

/**
 *
 */
function esn_country_entity_access($op = 'view', $entity = NULL, $account = NULL, $entity_type = '') {
  if ($op = 'view') {
    return TRUE;
  }
  return user_access($op, $account);
}

/**
 *
 */
function _esn_country_property_info_alter(&$country) {
  _esn_galaxy_api_set_property_callbacks($country);
  $country['properties']['country_id']['label'] = t('Drupal entity ID');
  $country['properties']['code']['label'] = t('ESN Country code');
  $country['properties']['country_name']['label'] = t('Country name');
  $country['properties']['name']['label'] = t('ESN Country name');
  $country['properties']['website']['label'] = t('Website of the ESN Country');
  $country['properties']['site_logo']['label'] = t('Logo url of the ESN Country');
  $country['properties']['latitude']['label'] = t('Latitude of the ESN Country');
  $country['properties']['longitude']['label'] = t('Longitude of the ESN Country');
  $country['properties']['last_updated']['type'] = 'date';
  $country['properties']['last_updated']['label'] = t('Last updated');
}

/**
 * Loads an ESN Country entity by it's ID.
 *
 * @param $id
 *   The ID  of the country.
 * @param bool $reset
 *   Whether to reset the node_load_multiple cache.
 *
 * @return
 *  The ESN Country entity or FALSE if not found.
 */
function esn_country_load($id, $reset = FALSE) {
  $countries = esn_country_load_multiple(array($id), TRUE);
  return reset($countries);
}

/**
 * Loads ESN Country entities by it's IDs.
 *
 * @param array $ids
 *   The IDs of the ESN countries to load.
 * @param bool $resetWhether
 *   to reset the esn_country_load_multiple cache.
 *   Whether to reset the esn_country_load_multiple cache.
 *
 * @return mixed
 *  Array of ESN Country entities
 */
function esn_country_load_multiple($ids = array(), $reset = FALSE) {
  if (is_array($ids) && count($ids) == 0) {
    return esn_country_load_all($reset);
  }
  $result = entity_load('esn_country', $ids, array(), TRUE);
  array_walk($result, '_esn_galaxy_api_wrap_entity', array('type' => 'esn_country'));
  return _esn_galaxy_api_map_array_to_code($result);
}

/**
 * Loads all ESN Country entities.
 *
 * @param bool $resetWhether
 *   to reset the esn_country_load_multiple cache.
 *   Whether to reset the esn_country_load_multiple cache.
 *
 * @return mixed
 *  Array of ESN Country entities
 */
function esn_country_load_all($reset = FALSE) {
  $result = entity_load('esn_country', FALSE, array(), TRUE);
  array_walk($result, '_esn_galaxy_api_wrap_entity', array('type' => 'esn_country'));
  return _esn_galaxy_api_map_array_to_code($result);
}

/**
 * Loads an ESN Country entity by it's ID.
 *
 * @param $code
 *   The ESN Country code of the country.
 * @param bool $reset
 *   Whether to reset the node_load_multiple cache.
 *
 * @return
 *  The ESN Country entity or FALSE if not found.
 */
function esn_country_load_by_code($code, $reset = FALSE) {
  $countries = esn_country_load_multiple_by_code(array($code), $reset);
  $country = reset($countries);
  return $country;
}

/**
 * Loads ESN Country entities by it's country codes.
 *
 * @param array $codes
 *   The country codes of the ESN countries to load.
 * @param bool $resetWhether
 *   to reset the esn_country_load_multiple cache.
 *   Whether to reset the esn_country_load_multiple cache.
 *
 * @return mixed
 *  Array of ESN Country entities
 */
function esn_country_load_multiple_by_code($codes = array(), $reset = FALSE) {
  try {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'esn_country')
      ->propertyCondition('code', $codes, 'IN')
      ->propertyOrderBy('name');

    $result = $query->execute();
    $result = array_keys($result['esn_country']);
    return esn_country_load_multiple($result, $reset);
  } catch (Exception $ex) {
    return array();
  }
}

/**
 * Create a new ESN Country entity.
 *
 * @param array $data
 *   The properties of the ESN Country
 *
 * @return bool
 *  The entity object created
 */
function esn_country_create($data) {
  $country = entity_create('esn_country', array());
  $country = entity_metadata_wrapper('esn_country', $country);
  foreach ($data as $key => $value) {
    $country->$key->set($value);
  }
  return $country;
}

/**
 * Saves an ESN Country.
 *
 * @param $country
 *   THe ESN County entity to save
 *
 * @return bool
 *  SAVED_NEW if the entity has been created, SAVED_UPDATED if it has been updated.
 */
function esn_country_save($country) {
  return entity_save('esn_country', $country);
}

/**
 * Deletes an ESN Country.
 *
 * @param $country
 *   The ESN Country entity to delete.
 */
function esn_country_delete($country) {
  entity_delete('esn_country', $country->getIdentifier());
}

/**
 * Deletes ESN Countries.
 *
 * @param $country_ids
 *   The ESN Countries to delete.
 */
function esn_country_delete_multiple($country_ids) {
  entity_delete_multiple('esn_country', $country_ids);
}

/**
 * Count the numbers of ESN Countries.
 */

function esn_country_count() {
  try {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'esn_country')
      ->count();

    $result = (int) $query->execute();
    return $result;
  } catch (Exception $ex) {
    return 0;
  }
}
