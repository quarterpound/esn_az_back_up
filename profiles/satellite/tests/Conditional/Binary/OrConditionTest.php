<?php

namespace ESN\Conditional\Tests;

use ESN\Conditional\OrCondition;

class OrConditionTest extends ConditionalTestCase {

  public function testTrueTrue() {
    $true = $this->mockTrue(1);

    $condition = new OrCondition($true, $true);
    $this->assertTrue($condition->isOK());
  }

  public function testTrueFalse() {
    $true = $this->mockTrue(TRUE);
    $false = $this->mockFalse(FALSE);
    $condition = new OrCondition($true, $false);
    $this->assertTrue($condition->isOK());
  }

  public function testFalseTrue() {
    $true = $this->mockTrue(TRUE);
    $false = $this->mockFalse(TRUE);
    $condition = new OrCondition($false, $true);
    $this->assertTrue($condition->isOK());
  }

  public function testFalseFalse() {
    $false = $this->mockFalse(2);
    $condition = new OrCondition($false, $false);
    $this->assertFalse($condition->isOK());
  }
}
