<?php

namespace ESN\Satellite\Requirements;


class ComposerRequirements {
  private static $installed_packages = FALSE;

  private function __construct() {
    if (FALSE === self::$installed_packages) {

      self::$installed_packages = [];
      try {
        $json = file_get_contents(DRUPAL_ROOT . '/vendor/composer/installed.json');
        foreach (json_decode($json ? $json : '[]') as $package) {
          self::$installed_packages[$package->name] = new ComposerPackageInfo($package);
        }
      } catch (\Exception $ex) {
      }
    }
  }

  public static function load() {
    return new ComposerRequirements();
  }

  public function getPackage($name) {
    if ($this->isInstalled($name)) {
      return self::$installed_packages[$name];
    }

    return FALSE;
  }

  public function isInstalled($name) {
    return !empty($name)
      && isset(self::$installed_packages[$name])
      && self::$installed_packages[$name] instanceof ComposerPackageInfo;
  }
}
