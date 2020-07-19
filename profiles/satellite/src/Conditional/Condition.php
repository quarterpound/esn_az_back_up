<?php

namespace ESN\Conditional;


abstract class Condition {

  /**
   * @return Condition
   */
  public static function true() {
    return new TrueCondition();
  }

  /**
   * @return Condition
   */
  public static function false() {
    return new FalseCondition();
  }

  public static function any(array ...$conditions) {
    return new AnyCondition($conditions);
  }

  public static function all(array ...$conditions) {
    return new AllCondition($conditions);
  }

  /**
   * @return bool
   */
  public abstract function isOK();

  /**
   * @param string $type Condition type (class name)
   *
   * @return Condition|bool First condition object found or FALSE if not found
   */
  public abstract function search($type);

  /**
   * @return array
   */
  public function getReplacements() {
    return [];
  }
}
