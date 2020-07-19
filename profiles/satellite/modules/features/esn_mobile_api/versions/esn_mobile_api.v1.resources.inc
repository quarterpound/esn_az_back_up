<?php

function _esn_mobile_api_v1_register_app($code, $data) {
  $invalid_request = array(
    'status' => 'invalid',
    'time'   => time(),
  );
  $my_code = satellite_settings_get_code();
  if (!isset($my_code) || $my_code != $code) {
    return $invalid_request;
  }
  $location_token = esn_api_tools_uuid();
  if ($location_token == null) {
    return $invalid_request;
  }
  $key = esn_api_tools_get_public_key();
  $key_id = array_shift($key);
  $key = array_shift($key);

  $data = array(
    'code' => $my_code,
    'location_token' => $location_token,
    'mobile_api_token' => esn_mobile_api_token(),
    'client' => $data,
  );
  // encrypt
  $data = array(
    'status' => 'ok',
    'time'   => time(),
    'key' => $key_id,
    'payload' => esn_api_tools_encrypt($key, $data),
  );
  return $data;
}
