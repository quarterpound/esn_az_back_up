<?php

namespace ESN\Conditional\Tests\Binary;

use ESN\Conditional\Condition;
use PHPUnit\Framework\TestCase;

class BinaryConditionTest extends TestCase {

  public function testEvalA_True() {
    $condition = BinaryTestCondition::testA(Condition::true());
    $this->assertTrue($condition->isOK());
  }

  public function testEvalA_False() {
    $condition = BinaryTestCondition::testA(Condition::false());
    $this->assertFalse($condition->isOK());
  }

  public function testEvalB_True() {
    $condition = BinaryTestCondition::testB(Condition::true());
    $this->assertTrue($condition->isOK());
  }

  public function testEvalB_False() {
    $condition = BinaryTestCondition::testB(Condition::false());
    $this->assertFalse($condition->isOK());
  }
}
