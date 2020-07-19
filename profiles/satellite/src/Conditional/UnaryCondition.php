<?php

namespace ESN\Conditional;

abstract class UnaryCondition extends Condition {

  use ConditionSearchTrait;

  public function search($type) {
    return $this->searchCondition($type, []);
  }
}
