<?php
// *****************************************************************************************
// defines an object for working with the remote API, using the Drupal API
class ServicesAPIClient {
  public $gateway;
  public $endpoint;
  private $api_key;
  private $timeout;
  private $httpformatter = null;
  private $debug = false;

  const API_Key_Header = 'X-ESN-API-KEY';

  // *****************************************************************************
  public function __construct( $gateway, $endpoint ) {
    $this->gateway    = $gateway;
    $this->endpoint = $endpoint;

    $this->session = '';
    $this->sessid  = '';

    $this->httpformatter = new JsonHttpFormatter();
    $this->setTimeout();
    $this->debug = esn_api_tools_debug();
  }

  public function setApiKey($id) {
    $this->api_key = $id;
  }

  public function getApiKey() {
    return $this->api_key;
  }

  public function getGeteway() {
    $url = $this->gateway.$this->endpoint.'/';
    return $url;
  }

  public function setTimeout(float $timeout = null){
    if (!isset($timeout) || $timeout <= 0) {
      $timeout = 30;
    }
    $this->timeout = $timeout;
  }

  public function setHttpFormatter(IHttpFormatter $formatter) {
    if (isset($formatter)) {
      $this->httpformatter = $formatter;
    } else {
      $this->httpformatter = new JsonHttpFormatter();
    }
  }

  protected function addHeaders(&$headers){
    if (isset($this->api_key)){
      $headers[self::API_Key_Header] = $this->api_key;
    }
    $path = drupal_get_path('module', 'esn_api_tools') . '/esn_api_tools.info';
    $info = drupal_parse_info_file($path);

    if ( !isset($info['version']) ) {
      $info['version'] = 'unknown';
    }
    $headers['User-Agent'] = 'ESN API Tools ' . $info['version'] . ' Drupal (+http://drupal.org/)';
  }


  // *****************************************************************************
  // Perform the common logic for performing an HTTP request with the Drupal API
  public function DrupalHttpRequest($url, $method, $data ) {

    $headers = array();
    $headers['Content-Type'] = $this->httpformatter->getContentType();
    $this->addHeaders($headers);

    if ($data) {
      $data = $this->httpformatter->getRequestData($data);
    }
    $request = array(
      'headers' => $headers,
      'method' => $method,
      'data' => $data,
      'timeout' => $this->timeout,
    );

    if ($this->debug) {
      watchdog('esn_api_tools', "HTTP request: %method %url\n\n%headers\n\n%data",
        array('%method' => $method, '%url' => $url,
          '%headers' => print_r($headers, true), '%data' => print_r($data, true)), WATCHDOG_DEBUG);
    }
    $response = drupal_http_request($url, $request);
    if ($response->code != 200) {
      watchdog('esn_api_tools', "HTTP %code %message: %method %url\n\n%raw",
        array('%method' => $method, '%url' => $url,
              '%code' => $response->code,
              '%message' => isset($response->status_message) ? $response->status_message : 'unknown',
              '%raw' => print_r($response, true)),
        WATCHDOG_ERROR);
    } else if ($this->debug) {
      watchdog('esn_api_tools', "HTTP %code %message: %method %url\n\n%raw",
        array('%method' => $method, '%url' => $url,
              '%code' => $response->code,
              '%message' => $response->status_message),
        WATCHDOG_DEBUG);
    }

    return $this->buildResponse($response);
  }


  // **************************************************************************
  // perform an 'Index' operation on a resource type using Drupal API.
  // Return an array of resource descriptions, or NULL if an error occurs
  public function Index( $resourceType ) {
   $url = $this->getGeteway() . $resourceType;
    return $this->DrupalHttpRequest($url, 'GET', NULL, true);
  }

  // *****************************************************************************
  // create a new resource of the named type given an array of data, using Drupal API
  public function Create( $resourceType, $resourceData ) {
    $url = $this->getGeteway() . $resourceType;
    return $this->DrupalHttpRequest($url, 'POST', $resourceData, true);
  }

  // **************************************************************************
  // perform a 'GET' operation on the named resource type and id using Drupal API
  public function Get( $resourceType, $resourceId ) {
    if (is_array($resourceId)) {
      $resourceId = implode('/', $resourceId);
    }
    $url = $this->getGeteway() . $resourceType.'/'.$resourceId;

    return $this->DrupalHttpRequest($url, 'GET', NULL, true);
  }
  // **************************************************************************
  // perform a 'POST' operation on the named resource type and id using Drupal API
  public function Post( $resourceType, $resourceId, $resourceAction, $resourceData) {
    if ($resourceId == NULL) {
      $resourceId = $resourceAction;
    } else if (!empty($resourceAction)) {
      $resourceId .= '/' . $resourceAction;
    }
    $url = $this->getGeteway() . $resourceType.'/'.$resourceId;

    return $this->DrupalHttpRequest($url, 'POST', $resourceData, true);
  }

// *****************************************************************************
  // update a resource given the resource type and updating array, using Drupal API
  public function Update( $resourceType, $resourceId, $resourceData ) {

    if (!isset($resourceId)) {
      if ( !isset($resourceData['data']['id'])) {
        _devReport('missing referencing ID of update resource!');
        return NULL;
      }
      $resourceId = $resourceData['data']['id'];
    } else {
      if (is_array($resourceId)) {
        $resourceId = implode('/', $resourceId);
      }
    }

    $url = $this->getGeteway() . $resourceType.'/'.$resourceId;
    return $this->DrupalHttpRequest($url, 'PUT', $resourceData, true);
  }

  private function buildResponse($raw) {
    $result = new stdClass();
    $result->code = (int)$raw->code;
    $result->ok = $raw->code == 200;
    $result->data = $this->httpformatter->getResponseData(isset($raw->data) ? $raw->data : null);
    if (!$result->ok && !isset($result->data) && !empty($raw->error)) {
      $result->data = $raw->error;
    }
    return $result;
  }

  // *****************************************************************************
  // perform a 'DELETE' operation on the named resource type and id using Drupal API
  public function Delete( $resourceType, $resourceId ) {

    $url = $this->gateway.$this->endpoint.'/'.$resourceType.'/'.$resourceId;
    $response = $this->DrupalHttpRequest($url, 'DELETE', NULL, true);
    return $response->data; // if failed, this is NULL, if success, this is an object holding response data
  }

} // end of ServicesAPIClient object definition

interface IHttpFormatter {
  function getContentType();
  function getRequestData($data);
  function getResponseData($data);
}

class JsonHttpFormatter implements IHttpFormatter {

  function getContentType() {
    return 'application/json';
  }

  function getRequestData($data) {
    return json_encode($data);
  }

  function getResponseData($data) {
    return json_decode($data);
  }
}
