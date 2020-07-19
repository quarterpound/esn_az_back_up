<?php

/**
 * Determine whether the current user can access a node resource.
 *
 * @param $op
 *   One of view, update, create, delete per node_access().
 * @param $args
 *   Resource arguments passed through from the original request.
 * @return bool
 *
 * @see node_access()
 */
function _satellite_resource_access($op = 'view', $args = array()) {
  // Adds backwards compatability with regression fixed in #1083242
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], 'esn');
  }

  // Make sure we have an object or this all fails, some servers can
  // mess up the types.
  if (is_array($args[0])) {
    $args[0] = (object) $args[0];
  }

  if ($op == 'view') {
    return true; // Give access to Satellite meta information to all users
  }
  else if ($op == 'register_app') {
    return true;
  }
  else {
    return services_error(t('Access to ESN and Satellite information cannot be granted'), 404);
  }
}


/**
 * Implements hook_services_resources().
 */
function esn_mobile_api_services_resources() {
  $resources = array(
    '#api_version' => 3002,
  );
  $resources = array_merge($resources, _esn_mobile_api_v1_resources());
  return $resources;
}

/**
 * Implements hook_default_services_endpoint().
 *
 * To add a new endpoint copy it from the export of
 * the service
 */
function esn_mobile_api_default_services_endpoint(){
  $endpoints = array();
  $endpoints = array_merge_recursive($endpoints, _esn_mobile_api_v1_endpoint());
  return $endpoints;
}

function esn_mobile_api_services_request_postprocess_alter($controller, $args, &$result) {
  drupal_add_http_header("Access-Control-Allow-Origin", "*");
}