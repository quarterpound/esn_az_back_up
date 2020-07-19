<?php

namespace ESN\Conditional\Tests\Parser;

use ESN\Conditional\ConditionParser;
use ESN\Conditional\Tests\ConditionalTestCase;

class ConditionParserTest extends ConditionalTestCase {

  public function testNullIsTrue() {
    $parser = new ConditionParser(NULL);
    $this->assertTrue($parser->isOK());
  }

  public function testEmptyObjectIsTrue() {
    $parser = new ConditionParser(new \stdClass());
    $this->assertTrue($parser->isOK());
  }

  public function testEmptyArrayIsTrue() {
    $parser = new ConditionParser([]);
    $this->assertTrue($parser->isOK());
  }

  public function testEmptyObjectStringIsTrue() {
    $parser = new ConditionParser('{}');
    $this->assertTrue($parser->isOK());
  }

  public function testEmptyArrayStringIsTrue() {
    $parser = new ConditionParser('[]');
    $this->assertTrue($parser->isOK());
  }
}
