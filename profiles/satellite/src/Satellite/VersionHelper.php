<?php

namespace ESN\Satellite;


use PharIo\Version\Version;

class VersionHelper {
  public static function getSemVer($version) {
    if (is_string($version) && !empty($version)) {
      // Remove Drupal version prefix
      $version = str_replace('7.x-', NULL, $version);

      // RC must be uppercase in the version String
      if (FALSE !== strpos($version, '-rc')) {
        $version = str_replace('-rc', '-RC', $version);
      } elseif ('dev' == $version) {
        $version = SATELLITE_BASE_VERSION . '-dev';
      }

      return new Version($version);
    }

    return NULL;
  }
}
