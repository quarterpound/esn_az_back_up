<?php
/**
 * @file
 */


/**
 * List of all ESN countries.
 */
function esn_galaxy_api_countries($esn = FALSE) {

  _esn_galaxy_api_check_population();
  $countries = array();
  foreach (esn_country_load_all() as $key => $value) {
    $countries[$key] = $value->name->value();
  }
  return $countries;
}

/**
 * List of sections as associative array with country names.
 *
 * A country code can be given to select sections form only one country,
 * The second parameter defines whether the array should be flat or with country names.
 */
function esn_galaxy_api_sections() {
  return esn_galaxy_api_sections_of_counrties(array_keys(esn_galaxy_api_countries()));
}

/**
 * List of sections in a country.
 *
 * A country code can be given to select sections form only one country,
 * The second parameter defines whether the array should be flat or with country names.
 */
function esn_galaxy_api_sections_of_counrty($countrycode) {

  if (strlen($countrycode) != 2) {
    return array();
  }

  $cc = strtoupper($countrycode);

  _esn_galaxy_api_check_population();
  $sections = esn_section_load_multiple_by_country($countrycode);
  return $sections;
}

/**
 * List of sections in countries.
 *
 * A country code can be given to select sections form only one country,
 * The second parameter defines whether the array should be flat or with country names.
 */
function esn_galaxy_api_sections_of_counrties($countrycodes) {
  $countries = esn_galaxy_api_countries();
  $section_list = array();
  foreach ($countrycodes as $countrycode) {
    if (array_key_exists($countrycode, $countries)) {
      $sections = array();
      foreach (esn_galaxy_api_sections_of_counrty($countrycode) as $key => $value) {
        $sections[$key] = $value->name->value();
      }
      $section_list[$countries[$countrycode]] = $sections;
    }
  }
  return $section_list;
}

/**
 * List of all sections as a flat list.
 */
function esn_galaxy_api_sections_all_flat() {

  _esn_galaxy_api_check_population();
  return esn_section_load_all();

}

/**
 * Section Name.
 */
function esn_galaxy_api_section_name($sc) {

  if (!esn_galaxy_api_sectioncode_format($sc)) {
    return '';
  }
  $sc = trim($sc);

  _esn_galaxy_api_check_population();
  $result = esn_section_load_by_code($sc);
  if ($result) {
    return $result->name->value();
  }
  return '';
}

/**
 * Country Name.
 */
function esn_galaxy_api_country_name($cc) {

  if (strlen($cc) != 2) {
    return '';
  }

  _esn_galaxy_api_check_population();
  $country = esn_country_load_by_code($cc);
  if ($country) {
    return $country->name->value();
  }
  return '';
}


/**
 * Validate sectioncode format.
 *
 * @TODO: make stricter after the sectioncodes are normalized.
 */
function esn_galaxy_api_sectioncode_format($sc) {
  return preg_match('/^[A-Z]{2}-[1-9A-Z]{2,4}-[1-9A-Z]{3,4}$/', $sc);
}

/**
 * Count sections .
 *
 * @TODO: make more efficient
 */
function esn_galaxy_api_section_count() {
  return esn_section_count();
}

/**
 * Count sections .
 *
 * @TODO: make more efficient
 */
function esn_galaxy_api_country_count() {
  return esn_country_count();
}

/**
 * Make sure the sections were not cleared with the cache when using them.
 */
function _esn_galaxy_api_check_population() {
  if (esn_country_count() == 0 || esn_section_count() == 0) {
    module_load_include('inc', 'esn_galaxy_api', 'esn_galaxy_api.load');
    _esn_galaxy_api_save_countries();
    _esn_galaxy_api_save_sections();
  }
}
