<?php

namespace ESN\Conditional;

abstract class MultiCondition extends Condition {

  use ConditionSearchTrait;

  /** @var Condition[] */
  private $conditions;

  public function __construct(array $conditions) {
    if (empty($conditions)) {
      $conditions = [Condition::false()];
    }
    else {
      $conditions = array_filter($conditions, function ($c) {
        return $c instanceof Condition;
      });
      if (empty($conditions)) {
        $conditions = [Condition::false()];
      }
    }
    $this->conditions = $conditions;
  }

  public function isOK() {
    $isOk = $this->getIsOkResult();
    foreach ($this->conditions as $condition) {
      if ($condition->isOK() === $isOk) {
        return $isOk;
      }
    }

    return !$isOk;
  }

  public function getReplacements() {
    $replacements = [];
    $isOk = $this->getIsOkResult();

    foreach ($this->conditions as $condition) {
      if ($condition->isOK() != $isOk) {
        $replacements += $condition->getReplacements();
      }
    }

    return $replacements;
  }

  protected abstract function getIsOkResult();

  public function search($type) {
    return $this->searchCondition($type, $this->conditions);
  }
}
