<?php

namespace ESN\Conditional\Tests\Parser;

use ESN\Conditional\ConditionParser;
use ESN\Conditional\Tests\ConditionalTestCase;

class ObjectConditionParserTest extends ConditionalTestCase {

  public function testTrueIsTrue() {
    $json = ["TRUE"];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());
  }

  public function testFalseIsFalse() {
    $json = ["FALSE"];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());
  }

  public function testAndTrueTrueIsTrue() {
    $json = [
      "AND" => [
        "TRUE",
        "TRUE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());

  }

  public function testAndTrueFalseIsFalse() {
    $json = [
      "AND" => [
        "TRUE",
        "FALSE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());

  }

  public function testAndFalseTrueIsFalse() {
    $json = [
      "AND" => [
        "FALSE",
        "TRUE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());

  }

  public function testAndFalseFalseIsFalse() {
    $json = [
      "AND" => [
        "FALSE",
        "FALSE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());

  }

  public function testOrTrueTrueIsTrue() {
    $json = [
      "OR" => [
        "TRUE",
        "TRUE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());

  }

  public function testOrTrueFalseIsTrue() {
    $json = [
      "OR" => [
        "TRUE",
        "FALSE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());

  }

  public function testOrFalseTrueIsTrue() {
    $json = [
      "OR" => [
        "FALSE",
        "TRUE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());

  }

  public function testOrFalseFalseIsFalse() {
    $json = [
      "OR" => [
        "FALSE",
        "FALSE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());

  }

  public function testAnyOnlyTrueIsTrue() {
    $json = [
      "ANY" => [
        "TRUE",
        "TRUE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());

  }

  public function testAnyTrueFalseIsTrue() {
    $json = [
      "ANY" => [
        "TRUE",
        "FALSE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());

  }

  public function testAnyFalseTrueIsTrue() {
    $json = [
      "ANY" => [
        "FALSE",
        "TRUE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());

  }

  public function testAnyFalseFalseIsFalse() {
    $json = [
      "ANY" => [
        "FALSE",
        "FALSE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());

  }

  public function testAllOnlyTrueIsTrue() {
    $json = [
      "ALL" => [
        "TRUE",
        "TRUE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertTrue($parser->isOK());

  }

  public function testAllTrueFalseIsFalse() {
    $json = [
      "ALL" => [
        "TRUE",
        "FALSE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());

  }

  public function testAllFalseTrueIsFalse() {
    $json = [
      "ALL" => [
        "FALSE",
        "TRUE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());

  }

  public function testAllFalseFalseIsFalse() {
    $json = [
      "ALL" => [
        "FALSE",
        "FALSE",
      ],
    ];
    $parser = new ConditionParser($json);
    $this->assertFalse($parser->isOK());

  }
}
