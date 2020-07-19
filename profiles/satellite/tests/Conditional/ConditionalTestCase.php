<?php

namespace ESN\Conditional\Tests;

use ESN\Conditional\Condition;
use ESN\Conditional\FalseCondition;
use ESN\Conditional\TrueCondition;
use PHPUnit\Framework\TestCase;

abstract class ConditionalTestCase extends TestCase {

  /**
   * @param $isOkCallCount
   *
   * @return Condition
   */
  protected function mockTrue($isOkCallCount) {
    $callback = function () {
      return TRUE;
    };
    return $this->mockCondition(TrueCondition::class, $isOkCallCount, $callback);
  }

  /**
   * @param $class
   * @param $isOkCallCount
   *
   * @return \PHPUnit\Framework\MockObject\MockObject
   */
  private function mockCondition($class, $isOkCallCount, $callback) {
    $mock = $this->getMockBuilder($class)
      ->setMethods(['isOK'])
      ->getMock();
    $mock->expects($isOkCallCount === 0 || $isOkCallCount === FALSE
      ? $this->never()
      : ($isOkCallCount === 1 || $isOkCallCount === TRUE
        ? $this->once()
        : $this->exactly($isOkCallCount)))
      ->method('isOK')
      ->will($this->returnCallback($callback));

    return $mock;
  }

  /**
   * @param $isOkCallCount
   *
   * @return Condition
   */
  protected function mockFalse($isOkCallCount) {
    $callback = function () {
      return FALSE;
    };
    return $this->mockCondition(FalseCondition::class, $isOkCallCount, $callback);
  }
}
