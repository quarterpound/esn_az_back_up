<?php
/**
 * Created by PhpStorm.
 * User: marco
 * Date: 1/26/19
 * Time: 10:21 PM
 */

class ESNSection extends ESNEntity {
  public function GetCountryCode() {
    return isset($this->country_code)
      ? $this->country_code
      : NULL;
  }
}
