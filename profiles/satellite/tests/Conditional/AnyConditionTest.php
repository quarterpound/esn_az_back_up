<?php

namespace ESN\Conditional\Tests;

use ESN\Conditional\AnyCondition;

class AnyConditionTest extends ConditionalTestCase {

  public function testConditionsEmpty() {
    $condition = new AnyCondition([]);
    $this->assertFalse($condition->isOK());
  }

  public function testOnlyTrue() {
    $true = $this->mockTrue(1);
    $condition = new AnyCondition([$true, $true, $true]);
    $this->assertTrue($condition->isOK());
  }

  public function testFalseThenTrue() {
    $true = $this->mockTrue(1);
    $false = $this->mockFalse(1);
    $condition = new AnyCondition([$false, $true, $true]);
    $this->assertTrue($condition->isOK());
  }

  public function testTrueThenFalseThenTrue() {
    $true = $this->mockTrue(1);
    $false = $this->mockFalse(0);
    $condition = new AnyCondition([$true, $false, $true]);
    $this->assertTrue($condition->isOK());
  }

  public function testOnlyFalse() {
    $false = $this->mockFalse(3);
    $condition = new AnyCondition([$false, $false, $false]);
    $this->assertFalse($condition->isOK());
  }
}
