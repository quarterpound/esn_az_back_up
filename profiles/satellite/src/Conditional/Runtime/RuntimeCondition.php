<?php

namespace ESN\Conditional\Runtime;

use ESN\Conditional\Condition;
use ESN\Conditional\ConditionSearchTrait;

abstract class RuntimeCondition extends Condition {

  use ConditionSearchTrait;

  /** @var string[] */
  private static $knownConditions;

  private $definition;

  public static function init() {
    if (is_null(self::$knownConditions)) {
      self::$knownConditions = [];
    }

    self::$knownConditions['PHP_VERSION'] = PhpVersionCondition::class;
    self::$knownConditions['ROLES'] = RolesCondition::class;
  }

  /**
   * Check if an identifier belongs to a known @see RuntimeCondition.
   *
   * @param string $name Condition identifier
   *
   * @return bool TRUE if the identifier belongs to a known @see RuntimeCondition
   */
  public static function isKnown($name) {
    return !empty($name)
      && array_key_exists(strtoupper($name), self::$knownConditions);
  }

  /**
   * Create a @see RuntimeCondition by it's identifier with the provided definition.
   * @param string $name Condition identifier
   * @param mixed $definition Condition defintion object
   *
   * @return \ESN\Conditional\Runtime\RuntimeCondition|NULL
   */
  public static function create($name, $definition) {
    if (!self::isKnown($name)) {
      return NULL;
    }
    try {
      $class = self::$knownConditions[strtoupper($name)];
      $condition = new $class($definition);
      if (!($condition instanceof RuntimeCondition)) {
        throw new \InvalidArgumentException("'$class' is not a RuntimeCondition.");
      }

      return $condition;
    }catch (\Exception $ex) {
      return NULL;
    }
  }

  /**
   * RuntimeCondition constructor.
   *
   * @param $definition
   */
  public function __construct($definition) {
    $this->initialize($definition);
    $this->definition = $definition;
  }

  protected abstract function initialize($definition);

  public function search($type) {
    return $this->searchCondition($type, []);
  }
}
