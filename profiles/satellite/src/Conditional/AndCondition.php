<?php

namespace ESN\Conditional;

final class AndCondition extends BinaryCondition {

  public function isOK() {
    if ($this->evalA()) {
      return $this->evalB();
    }

    return FALSE;
  }
}
