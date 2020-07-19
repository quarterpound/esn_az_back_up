<?php

class HttpUtility {
  static function getUrlStatus($url) {
    if (!$url || empty($url)) {
      return false;
    }
    try{
      if (!Strings::startsWith($url, array('http://', 'https://'))) {
        $url = 'http://' . $url;
      }
      $result = drupal_http_request($url, array('method' => 'HEAD'));
      switch ($result->code) {
        case 200:
        case 301:
        case 302:
        case 303:
        case 307:
        case 308:
          return true;
        default:
          return false;
      }
    }catch (Exception $ex) {

    }
    return false;
  }
}