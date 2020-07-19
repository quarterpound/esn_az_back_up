<?php

namespace ESN\Conditional\Tests;

use ESN\Conditional\FalseCondition;
use ESN\Conditional\TrueCondition;
use PHPUnit\Framework\TestCase;

class UnaryConditionTest extends TestCase {

  public function testTrue() {
    $condition = new TrueCondition();
    $this->assertTrue($condition->isOK());
  }

  public function testFalse() {
    $condition = new FalseCondition();
    $this->assertFalse($condition->isOK());
  }
}
