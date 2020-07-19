<?php

namespace ESN\Conditional\Tests;

use ESN\Conditional\AllCondition;

class AllConditionTest extends ConditionalTestCase {

  public function testConditionsEmpty() {
    $condition = new AllCondition([]);
    $this->assertFalse($condition->isOK());
  }

  public function testOnlyTrue() {
    $true = $this->mockTrue(3);
    $condition = new AllCondition([$true, $true, $true]);
    $this->assertTrue($condition->isOK());
  }

  public function testFalseThenTrue() {
    $true = $this->mockTrue(0);
    $false = $this->mockFalse(1);
    $condition = new AllCondition([$false, $true, $true]);
    $this->assertFalse($condition->isOK());
  }

  public function testTrueThenFalseThenTrue() {
    $true = $this->mockTrue(1);
    $false = $this->mockFalse(1);
    $condition = new AllCondition([$true, $false, $true]);
    $this->assertFalse($condition->isOK());
  }

  public function testOnlyFalse() {
    $false = $this->mockFalse(1);
    $condition = new AllCondition([$false, $false, $false]);
    $this->assertFalse($condition->isOK());
  }
}
