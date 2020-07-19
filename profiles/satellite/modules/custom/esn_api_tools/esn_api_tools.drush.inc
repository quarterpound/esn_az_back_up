<?php
/**
 * @file
 *  Drush integration
 */

/**
 * Implements hook_drush_help()
 *
 * @param $command
 *  The command for which help has been requested
 */
function esn_api_tools_drush_help($command){
  switch ($command) {
    case 'drush:esnapi-generate-key':
      return dt('Generate new RSA public private key pair for ESN API');
  }
}

/**
 * Implements hook_drush_command()
 */
function esn_api_tools_drush_command() {
  $items = array();
  $items['esnapi-generate-key'] = array(
    'description' => esn_api_tools_drush_help('drush:esnapi-generate-key'),
    'arguments' => array(),
    'options' => array(
      'public-keyfile' => array(
        'description' => dt('An alternate file to store the public keys instead of esn_api_tools/esn_api_keys.php'),
        'example_value' => '/home/iss/esn_api_public_keys.php',
        'value' => 'required',
      ),
      'export-private-keys' => array(
        'description' => dt('Export all stored private API keys into the specified file. Caution! Security Risk!'),
        'example_value' => '/home/iss/esn_api_private_keys.php',
        'value' => 'required',
      ),
    ),
    'examples' => array(
      'Standard example' => 'drush esnapi-generate-key',
    ),
    'drupal dependencies' => array(
      'esn_api_tools',
    ),
    'aliases' => array('esnapigk'),
  );
  return $items;
}

function _resolve_path($path = null) {
  if (!$path) {
    return null;
  }
  if (stripos($path, '~/') === 0) {
    $path = getenv('HOME') . substr($path, 1);
    drush_log("Path is in home directory, rewrite to $path", 'notice');
  }
  return $path;
}

function _check_file($filename) {
  drush_log("Preparing alternate public key file: $filename", 'notice');
  if (!$filename) {
    return false;
  }
  $ok = true;
  if (!file_exists($filename)) {
    if ($ok && file_put_contents($filename, "<?php\n\n")) {
      drush_log("Alternate public keys file has been initialized: $filename", 'ok');
    } else {
      $ok = false;
      drush_set_error('ESN_API_ERROR', "Could not write PHP header to $filename");
    }
    if ($ok && chmod($filename, 0664)) {
      drush_log("Alternate public keys file permissions set to 0664.", 'ok');
    } else {
      $ok = false;
      drush_set_error('ESN_API_ERROR', "Could not apply permissions 0664 to $filename");
    }
  }
  return $ok;
}

/**
 * Callback function for drush esnapi-generate-key
 */
function drush_esn_api_tools_esnapi_generate_key() {
  drush_print('ESN API Tools - Generate new RSA public private key pair.');
  $export_private_keys = _resolve_path(drush_get_option('export-private-keys'));
  if (isset($export_private_keys) && realpath(dirname($export_private_keys))){
    $data = "<?php\n\n";
    foreach (esn_api_tools_export_private_keys() as $id => $key){
      $data .= "// Key $id added at ${key['created']}\n";
      $data .= '$esn_api_public_keys["' . $id . '"] = "' . $key['key'] . '";' . "\n";
    }
    if (file_put_contents($export_private_keys, $data)){
      return drush_log("Private keys have been exported to $export_private_keys.", 'ok');
    } else {
      return drush_set_error('ESN_API_ERROR', "Could not export public key to $export_private_keys");
    }
  }
  $publickey = null;
  $privatekey = null;
  $id = null;
  $key = esn_api_tools_create_key_pair();
  extract($key);
  drush_log('A new RSA public private key pair has been generated and assigned to id: ' . $id, 'ok');
  drush_print("Public Key:\n\n$publickey\n\n");
  $public_keyfile = drush_get_option('public-keyfile');
  $alt_public_keyfile = !empty($public_keyfile);
  if ($alt_public_keyfile) {
    $public_keyfile = _resolve_path($public_keyfile);
  } else {
    $public_keyfile = variable_get('esn_api_public_keyfile', null);
    $alt_public_keyfile = !empty($public_keyfile);
    if ($alt_public_keyfile) {
      $public_keyfile = _resolve_path($public_keyfile);
    } else {
      $public_keyfile = 'esn_api_keys.php';
    }
  }
  $continue = drush_confirm("Are you sure you want to add the public key to the '$public_keyfile' file and register the private key to this site?");
  if (!$continue) {
    return drush_user_abort();
  }
  if ($alt_public_keyfile) {
    if (!_check_file($public_keyfile)) {
      return drupal_set_error('ESN_API_ERROR', 'Could not write public key to alternate key file');
    }
    $alt_public_keyfile = $public_keyfile;
  } else {
    $public_keyfile = null;
    $alt_public_keyfile = 'esn_api_keys.php';
  }
  if (esn_api_tools_write_public_key($id, $publickey, $public_keyfile)) {
    drush_log("Public key added to $alt_public_keyfile", 'ok');
  } else {
    return drush_set_error('ESN_API_ERROR', "Could not add public key to $alt_public_keyfile");
  }
  if (esn_api_tools_write_private_key($id, $privatekey)){
    drush_log('Private key has been stored.', 'ok');
    drush_print("\nDon't forget to increase module version number of esn_api_tools before committing added API key!");
  }
}