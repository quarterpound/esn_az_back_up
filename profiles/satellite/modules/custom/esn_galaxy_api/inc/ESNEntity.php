<?php

abstract class ESNEntity {

  private $website_logo;

  private $website;

  private $code;

  protected $_data;

  public function __construct($code) {
    $this->code = $code;
    $this->website_logo = '';
    $this->_data = [];
  }

  public function __isset($prop) {
    if(property_exists($this, $prop))
      return TRUE;
    return array_key_exists($prop, $this->_data);
  }

  public function __get($prop) {
    if(property_exists($this, $prop))
      return $this->$prop;
    if(array_key_exists($prop, $this->_data))
      return $this->_data[$prop];
  }

  public function __set($prop, $value) {
    if(!property_exists($this, $prop)) {
      $this->_data[$prop] = $value;
      return;
    }
    $this->$prop = $value;
  }

  /**
   * @return string
   */
  function getCode() {
    return $this->code;
  }

  function setWebsiteLogo($logo) {
    if ($logo && isset($this->website) && !empty($this->website)) {
      if (is_string($logo)) {
        $this->website_logo = $logo;
      } elseif (is_callable($logo)) {
        $this->website_logo = $logo($this->website);
      } else {
        $this->website_logo = '';
      }
    } elseif (is_null($logo)) {
      $this->website_logo = '';
    }
  }

  /**
   * @param mixed $website
   */
  public function setWebsite($website) {
    $this->website = $website;
  }

  /**
   * @return mixed
   */
  public function getWebsite() {
    return $this->website;
  }

  /**
   * @param EntityDrupalWrapper $storage
   */
  public function update($storage) {
    $properties = array_intersect_key(
      array_flip(array_keys($storage->getPropertyInfo())),
      $this->getOwnProperties()
    );
    foreach ($properties as $name => $i) {
      $storage->$name = $this->$name;
    }
  }

  private function getOwnProperties() {
    $props = [];
    $class = new ReflectionClass($this);
    do {
      $classProps = $class->getProperties(ReflectionProperty::IS_PRIVATE | ReflectionProperty::IS_PROTECTED);
      foreach ($classProps as $prop) {
        if (!array_key_exists($prop->getName(), $props) && '_data' !== $prop->getName()) {
          $props[$prop->getName()] = TRUE;
        }
      }
    } while ($class = $class->getParentClass());

    $props = array_merge($props, array_flip(array_keys($this->_data)));

    return $props;
  }
}
