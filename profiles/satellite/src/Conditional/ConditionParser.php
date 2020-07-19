<?php

namespace ESN\Conditional;

use ESN\Conditional\Runtime\RolesCondition;
use ESN\Conditional\Runtime\RuntimeCondition;

class ConditionParser extends Condition implements \JsonSerializable {

  use ConditionSearchTrait;

  /** @var string */
  private $json;

  /** @var \ESN\Conditional\Condition */
  private $conditions;

  public function __construct($json = '{}') {
    RuntimeCondition::init();

    if ($json instanceof \stdClass && isset($json->scalar)) {
      $json = $json->scalar;
    }

    $this->json = is_string($json)
      ? json_decode($json)
      : $json;
    $this->parse();
  }

  public function parse() {
    $this->conditions = NULL;

    list($count, $props) = $this->getProperties($this->json);
    switch ($count) {
      case 0:
        $this->conditions = Condition::true();
        break;
      case 1:
        $this->conditions = array_pop($props);
        break;
      case 2:
        $this->conditions = new AndCondition(array_pop($props), array_pop($props));
        break;
      default:
        $this->conditions = new AllCondition($props);
        break;
    }
  }

  private function getProperties($object) {
    $count = 0;
    $props = [];
    if (is_string($object)) {
      switch (strtoupper($object)) {
        case "TRUE":
          $count = 1;
          $props[] = Condition::true();
          break;
        case "FALSE":
        default:
          $count = 1;
          $props[] = Condition::false();
          break;
      }
    }
    elseif (is_null($object)) {
      $count = 1;
      $props[] = Condition::true();
    }
    else {
      foreach ($object as $key => $value) {
        $args = [];
        $argCount = 0;
        switch (strtoupper($key)) {
          case "AND":
            $class = AndCondition::class;
            $argCount = 2;
            break;
          case "OR":
            $class = OrCondition::class;
            $argCount = 2;
            break;
          case "ANY":
            $class = AnyCondition::class;
            $argCount = -1;
            break;
          case "ALL":
            $class = AllCondition::class;
            $argCount = -1;
            break;
          default:
            if (is_string($value)) {
              $children = $this->getProperties($value);
              $argCount += $children[0];
              $args = array_merge($children[1]);
              $class = AllCondition::class;
              break;
            }
            $class = FalseCondition::class;
            break;
        }
        if (is_array($value) || is_object($value)) {
          foreach ($value as $vKey => $vObject) {
            if (RuntimeCondition::isKnown($vKey)) {
              $condition  = RuntimeCondition::create($vKey, $vObject);
              $args[$vKey] = $condition;
              continue;
            }
            list($vCount, $vProps) = $this->getProperties($vObject);
            $args[$vKey] = $vCount ? $vProps[0] : Condition::false();
          }
        }
        if ($argCount === 1) { // multiple arguments as array
          $class = new \ReflectionClass($class);
          $condition = $class->newInstance($args);
        }
        elseif ($argCount > 0) {
          $class = new \ReflectionClass($class);
          $condition = $class->newInstanceArgs($args);
        }
        elseif ($argCount === -1) { // multiple arguments as array
          $class = new \ReflectionClass($class);
          $condition = $class->newInstance($args);
        }
        elseif (is_null($condition)) {
          $condition = new $class();
        }
        $props[$key] = $condition;
        $count++;
      }
    }

    return [$count, $props];
  }

  public function isOK() {
    return $this->conditions->isOK();
  }

  public function getReplacements() {
    $replacements = $this->conditions->getReplacements();
    $keys = array_keys($replacements);
    array_walk($keys, function(&$key) {
      $key = '@' . $key;
    });

    return array_combine($keys, array_values($replacements));
  }

  public function search($type) {
    return $this->conditions->search($type);
  }

  /**
   * @return string
   */
  public function jsonSerialize() {
    return json_encode($this->json);
  }
}
