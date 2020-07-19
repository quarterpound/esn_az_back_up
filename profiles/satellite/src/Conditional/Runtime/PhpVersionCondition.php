<?php

namespace ESN\Conditional\Runtime;

use ESN\Conditional\Condition;
use PharIo\Version\Version;
use PharIo\Version\VersionConstraint;
use PharIo\Version\VersionConstraintParser;

class PhpVersionCondition extends RuntimeCondition {

  /** @var VersionConstraint */
  private $constraint;

  /**
   * @return Version
   */
  public function getPhpVersion() {
    return new Version(PHP_MAJOR_VERSION . '.' . PHP_MINOR_VERSION . '.' . PHP_RELEASE_VERSION);
  }

  public function isOK() {
    return $this->constraint->complies($this->getPhpVersion());
  }

  public function getReplacements() {
    $replacements = [
      'php_version' => $this->getPhpVersion()->getVersionString(),
    ];

    return $replacements;
  }

  protected function initialize($definition) {
    $parser = new VersionConstraintParser();
    $this->constraint = $parser->parse($definition);
  }
}
