<?php

namespace ESN\Conditional;

final class AnyCondition extends MultiCondition {

  protected function getIsOkResult() {
    return TRUE;
  }
}
