<?php

namespace ESN\Conditional\Tests;

use ESN\Conditional\AndCondition;

class AndConditionTest extends ConditionalTestCase {

  public function testTrueTrue() {
    $true = $this->mockTrue(2);

    $condition = new AndCondition($true, $true);
    $this->assertTrue($condition->isOK());
  }

  public function testTrueFalse() {
    $true = $this->mockTrue(TRUE);
    $false = $this->mockFalse(TRUE);
    $condition = new AndCondition($true, $false);
    $this->assertFalse($condition->isOK());
  }

  public function testFalseTrue() {
    $true = $this->mockTrue(FALSE);
    $false = $this->mockFalse(TRUE);
    $condition = new AndCondition($false, $true);
    $this->assertFalse($condition->isOK());
  }

  public function testFalseFalse() {
    $false = $this->mockFalse(1);
    $condition = new AndCondition($false, $false);
    $this->assertFalse($condition->isOK());
  }
}
