<?php

// *****************************************************************************************
// defines an object for working with the remote API, using the Drupal API
class AuthServicesAPIClient extends ServicesAPIClient {
  public $status;
  public $session;    // the session name (obtained at login)
  public $sessid;     // the session id (obtained at login)


  const RemoteAPI_status_unconnected = 0;
  const RemoteAPI_status_loggedin    = 1;

  public function __construct($gateway, $endpoint) {
    parent::__construct($gateway, $endpoint);

    $this->status  = RemoteAPI_status_unconnected;
  }

  // *****************************************************************************
  // after login, the string generated here needs to be included in any http headers,
  // under the key 'Cookie':
  private function GetCookieHeader() {
    return $this->session.'='.$this->sessid;
  }

  protected function addHeaders(&$headers){
    if ($this->VerifyLoggedIn(null)){
      $headers['Cookie']     = $this->GetCookieHeader();
    }
  }

  // *****************************************************************************
  // return false if we're not logged in
  private function VerifyLoggedIn($caller) {
    if ($this->status != RemoteAPI_status_loggedin) {
      return FALSE;
    }
    return TRUE;
  }


  // *****************************************************************************
  // return false if we're logged in
  private function VerifyUnconnected($caller) {
    if ($this->status != RemoteAPI_status_unconnected) {
      return FALSE;
    }
    return TRUE;
  }

  // *****************************************************************************
  public function Login($username, $password) {

    $callerId = 'RemoteAPI_DrupalAPI->Login';
    if (!$this->VerifyUnconnected($callerId)) {
      return NULL; // error
    }

    $url  = $this->gateway . $this->endpoint . '/user/login';
    $data = array('username' => $username, 'password' => $password,);

    $response = $this->DrupalHttpRequest($url, 'POST', $data, FALSE);
    if ($response->code == 200) {
      $this->session = $response->data->session_name;
      $this->sessid  = $response->data->sessid;
      $this->status  = RemoteAPI_status_loggedin;
      return TRUE; // meaning okay
    }

    return NULL; // meaning error
  }

// *****************************************************************************
  public function Logout() {

    $callerId = 'RemoteAPI_DrupalAPI->Logout';
    if (!$this->VerifyLoggedIn($callerId)) {
      return NULL; // error
    }

    $url = $this->gateway . $this->endpoint . '/user/logout';

    $response = $this->DrupalHttpRequest($url, 'POST', NULL, TRUE);
    if ($response->code == 200) {
      $this->status  = RemoteAPI_status_unconnected;
      $this->sessid  = '';
      $this->session = '';
      return TRUE; // success!
    }

    return NULL;
  }

  // **************************************************************************
  // perform an 'Index' operation on a resource type using Drupal API.
  // Return an array of resource descriptions, or NULL if an error occurs
  public function Index($resourceType) {
    $callerId = 'RemoteAPI_DrupalAPI->Index';
    if (!$this->VerifyLoggedIn($callerId)) {
      return NULL; // error
    }
    return parent::Index($resourceType);
  }

  // *****************************************************************************
  // create a new resource of the named type given an array of data, using Drupal API
  public function Create($resourceType, $resourceData) {
    $callerId = 'AuthServicesAPIClient->Create:' . $resourceType;
    if (!$this->VerifyLoggedIn($callerId)) {
      return NULL; // error
    }
    return parent::Create($resourceType, $resourceData);
  }

  // **************************************************************************
  // perform a 'GET' operation on the named resource type and id using Drupal API
  public function Get($resourceType, $resourceId) {
    $callerId = 'AuthServicesAPIClient->Get:' . $resourceType . '/' . $resourceId . '"';
    if (!$this->VerifyLoggedIn($callerId)) {
      return NULL; // error
    }
    return parent::Get($resourceType, $resourceId);
  }

  // *****************************************************************************
  // update a resource given the resource type and updating array, using Drupal API
  public function Update($resourceType, $resourceId, $resourceData) {
    $callerId = 'AuthServicesAPIClient->Update:' . $resourceType;
    if (!$this->VerifyLoggedIn($callerId)) {
      return NULL; // error
    }
    return parent::Update($resourceType, $resourceId, $resourceData);
  }


  // *****************************************************************************
  // perform a 'DELETE' operation on the named resource type and id using Drupal API
  public function Delete($resourceType, $resourceId) {
    $callerId = 'AuthServicesAPIClient->Delete:' . $resourceType;
    if (!$this->VerifyLoggedIn($callerId)) {
      return NULL; // error
    }
    return parent::Delete($resourceType, $resourceId);
  }
}