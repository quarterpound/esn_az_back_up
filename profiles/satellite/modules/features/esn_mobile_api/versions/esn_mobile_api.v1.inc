<?php
/**
 * Implementation of version 1
 */

function _esn_mobile_api_v1_resources() {
  $resources_file = array('type' => 'inc', 'module' => 'esn_mobile_api', 'name' => 'versions/esn_mobile_api.v1.resources');

  $resources = array(
    'apiv1' => array(
      'targeted_actions' => array(
        'register' => array(
          'help' => t('Registers an app installation for the use of this satellite and post feedback.'),
          'file' => $resources_file,
          'callback' => '_esn_mobile_api_v1_register_app',
          'args' => array(
            array(
              'name' => 'code',
              'type' => 'string',
              'source' => array('path' => 0),
              'description' => t('ESN section or country code'),
              'optional' => FALSE,
            ),
            array(
              'name' => 'data',
              'type' => 'struct',
              'description' => 'The app and satellite information to register',
              'source' => 'data',
              'optional' => FALSE,
            ),
          ),
          'access callback' => '_satellite_resource_access',
          'access arguments' => array('register_app'),
          'access arguments append' => TRUE,
        ),
      ),
    ),
  );

  return $resources;
}

function _esn_mobile_api_v1_endpoint() {
  $endpoint_v1 = new stdClass();
  $endpoint_v1->disabled = FALSE;
  $endpoint_v1->api_version = 3;
  $endpoint_v1->name = 'esnapi_v1';
  $endpoint_v1->server = 'rest_server';
  $endpoint_v1->path = 'api/v1';
  $endpoint_v1->authentication = array();
  $endpoint_v1->server_settings = array();
  $endpoint_v1->resources = array(
    'country' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'relationships' => array(
        'sections' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'eventsv1' => array(
      'alias' => 'events',
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'newsv1' => array(
      'alias' => 'news',
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'partnersv1' => array(
      'alias' => 'partners',
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'section' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'apiv1' => array(
      'alias' => 'api',
      'targeted_actions' => array(
        'register' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint_v1->debug = 0;
  $endpoint_v1 = array('esnapi_v1' => $endpoint_v1);
  return $endpoint_v1;
}