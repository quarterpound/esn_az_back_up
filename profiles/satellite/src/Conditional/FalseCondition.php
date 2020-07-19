<?php

namespace ESN\Conditional;

class FalseCondition extends UnaryCondition {

  public function isOK() {
    return FALSE;
  }
}
