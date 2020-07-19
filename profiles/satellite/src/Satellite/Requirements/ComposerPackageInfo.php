<?php
/**
 * Created by PhpStorm.
 * User: marco
 * Date: 1/27/19
 * Time: 11:23 PM
 */

namespace ESN\Satellite\Requirements;

class ComposerPackageInfo {

  /**
   * @var \stdClass
   */
  private $info;

  function __construct(\stdClass $info) {
    $this->info = $info;
  }

  public function getName() {
    if (isset($this->info->name)) {
      return $this->info->name;
      }

      return '';
  }

  public function getVersion() {
    if (isset($this->info->version)) {
      return $this->info->version;
      }

      return '';
  }

  public function __toString() {
    if (isset($this->info->name)) {
      $output = $this->info->name;
      if (isset($this->info->version)) {
        $output .= " ({$this->info->version})";
      }

      return $output;
    }

    return 'Unknown package';
  }
}
