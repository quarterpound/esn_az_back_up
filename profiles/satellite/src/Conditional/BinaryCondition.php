<?php

namespace ESN\Conditional;

abstract class BinaryCondition extends Condition {

  use ConditionSearchTrait;

  /** @var Condition */
  private $a;

  /** @var Condition */
  private $b;

  /**
   * BinaryCondition constructor.
   *
   * @param Condition $a
   * @param Condition $b
   */
  public function __construct($a, $b) {
    $this->a = $a;
    $this->b = $b;
  }

  protected function evalA() {
    return $this->a && $this->a->isOK();
  }

  protected function evalB() {
    return $this->b && $this->b->isOK();
  }

  public function getReplacements() {
    $replacements = [];

    if ($this->evalA()) {
      $replacements += $this->a->getReplacements();
    }

    if ($this->evalB()) {
      $replacements += $this->b->getReplacements();
    }

    return $replacements;
  }

  public function search($type) {
    return $this->searchCondition($type, [$this->a, $this->b]);
  }
}
