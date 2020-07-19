<?php

namespace ESN\Conditional;

class TrueCondition extends UnaryCondition {

  public function isOK() {
    return TRUE;
  }
}
