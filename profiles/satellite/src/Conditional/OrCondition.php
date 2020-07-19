<?php

namespace ESN\Conditional;

final class OrCondition extends BinaryCondition {

  public function isOK() {
    if ($this->evalA()) {
      return TRUE;
    }

    return $this->evalB();
  }
}
