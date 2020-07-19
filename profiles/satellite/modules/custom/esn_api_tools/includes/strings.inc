<?php


class Strings {
  static function startsWith($string, $test) {
    if (!$string || !$test) {
      return FALSE;
    }
    if (is_array($test)) {
      foreach ($test as $t) {
        $result = Strings::startsWith($string, $t);
        if ($result === true) {
          return true;
        }
      }
      return false;
    }
    return stripos($string, $test) === 0;
  }

  static function endsWith($string, $test) {
    if (!$string || !$test) {
      return false;
    }
    $strlen = strlen($string);
    $testlen = strlen($test);
    if ($testlen > $strlen) {
      return false;
    }
    return substr_compare($string, $test, $strlen - $testlen, $testlen) === 0;
  }
}
