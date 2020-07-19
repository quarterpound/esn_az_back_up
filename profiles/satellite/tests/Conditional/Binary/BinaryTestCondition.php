<?php

namespace ESN\Conditional\Tests\Binary;

use ESN\Conditional\BinaryCondition;
use ESN\Conditional\Condition;

final class BinaryTestCondition extends BinaryCondition {

  /** @var callable */
  private $eval;

  public static function testA(Condition $condition): BinaryTestCondition {
    $test = new BinaryTestCondition($condition, $condition);
    $test->eval = [$test, 'evalA'];
    return $test;
  }

  public static function testB(Condition $condition): BinaryTestCondition {
    $test = new BinaryTestCondition($condition, $condition);
    $test->eval = [$test, 'evalB'];
    return $test;
  }

  public function isOK(): bool {
    return call_user_func($this->eval);
  }
}
