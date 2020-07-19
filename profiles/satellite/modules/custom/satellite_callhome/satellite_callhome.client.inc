<?php

function satellite_callhome_call() {
  $key = esn_api_tools_get_public_key();
  $key_id = array_shift($key);
  $key = array_shift($key);
  $client = esn_api_tools_connect(satellite_callhome_url(), 'callhome/api');
  $url = $GLOBALS['base_url'];
  $host = parse_url($url, PHP_URL_HOST);
  if ($host) {
    $host = implode('.', array_reverse(explode('.', $host)));
  } else {
    $host = 'INVALID';
  }
  $code = satellite_settings_get_code();
  $mobile_api_version = '0';
  $is_mobile_api_source = false;
  if (module_exists('esn_mobile_api')) {
    $is_mobile_api_source = esn_mobile_api_is_mobile_api_source();
    $mobile_api_version = $is_mobile_api_source ? esn_mobile_api_version() : '0';
  }

  $data = array(
    'code' => $code,
    'uuid' => $client->getApiKey(),
    'version' => satellite_callhome_version(),
    'is_mobile_api_source' => $is_mobile_api_source, //variable_get('esn_mobile_api_is_source', false),
    'mobile_api_version' => $mobile_api_version, // TODO: Must be returned bey esn_mobile_api if $is_mobile_api_source
    'has_clean_urls' => variable_get('clean_url') == '1' ? true : false,
    'url' => $url,
    'hostname' => $host,
    'mail' => variable_get('site_mail', ''),
    'default_content' => variable_get('satellite_install_default_content', ''),
    'ip' => $_SERVER['SERVER_ADDR'],
  );

  $configuration = array();
  if (variable_get('satellite_callhome_extdata', FALSE)) {
    $data['cas_roles_relations'] = variable_get('cas_roles_relations', array());
    $phpinfo                        = _satellite_callhome_get_php_info();
    $configuration['server']['OS']  = $phpinfo['uname'];
    $configuration['server']['PHP'] = $phpinfo['version'];
    foreach (_satellite_callhome_get_module_versions() as $name => $version) {
      $configuration['drupal'][$name] = $version;
    }
    foreach ($phpinfo['extensions'] as $name => $value) {
      $configuration['PHP'][$name] = $version;
    }
  }
  $data['configuration'] = $configuration;

  // encrypt
  $data = array(
    'key' => $key_id,
    'payload' => esn_api_tools_encrypt($key, $data),
  );

  $result = $client->Update('satellite', array($code, $client->getApiKey()), $data);

  if ($result->code == 200) {
    watchdog('satellite_callhome', 'Satellite called home successfully to %url.', array('%url' => $client->getGeteway()), WATCHDOG_INFO);
    drupal_set_message(t('Satellite called home successfully to %url.', array('%url' => $client->getGeteway())), 'status');
    if (isset($result->data->api_token) && !empty($result->data->api_token)) {
      variable_set('esn_callhome_api_token', $result->data->api_token);
    }
  }
  else {
    watchdog('satellite_callhome', 'Satellite failed to call home to %url. Code %code. Error: %error', array('%url' => $client->getGeteway(), '%code' => $result->code, '%error' => $result->data), WATCHDOG_ERROR);
    drupal_set_message(t('Satellite failed to call home to %url. Code %code. Error: %error', array('%url' => $client->getGeteway(), '%code' => $result->code, '%error' => $result->data)), 'error');
  }
  variable_set('satellite_callhome_lastcall', time() );
}

function satellite_callhome_report_satellite_update(&$session, $trigger) {
  if ($session !== NULL && $trigger != NULL) {
    if (isset($session[__FUNCTION__])) {
      $callee = $session[__FUNCTION__];
    }
    else {
      $callee = $session[__FUNCTION__] = $trigger;
    }
    if ($callee == $trigger) {
      try {
        satellite_callhome_call();
      } catch (Exception $err) {
        // Don't do anything, callhome will be done during next cron.
      }
    }
  }
}
