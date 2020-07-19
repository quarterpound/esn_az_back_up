<?php

namespace ESN\Conditional;

final class AllCondition extends MultiCondition {

  protected function getIsOkResult() {
    return FALSE;
  }
}
