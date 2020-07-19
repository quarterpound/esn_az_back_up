<?php

namespace ESN\Conditional\Runtime;

use ESN\Conditional\AndCondition;
use ESN\Conditional\Condition;

class RolesCondition extends RuntimeCondition implements \JsonSerializable {

  /** @var int[] Role IDs */
  private $roles = [];

  private $administrator = FALSE;

  /**
   * @return bool
   */
  public function isOK() {
    global $user;
    if ($this->administrator && $user->uid == 1) {
      return TRUE;
    }
    foreach ($this->roles as $role) {
      if (user_has_role($role, $user)) {
        return TRUE;
      }
    }

    return FALSE;
  }

  protected function initialize($definition) {
    if (is_string($definition)) {
      $definition = [$definition];
    }
    elseif (is_null($definition)) {
      $definition = [];
    }

    if (empty($definition)) {
      $definition = ['administrator'];
    }

    $this->roles = array_filter(array_map(function ($name) {
      $role = user_role_load_by_name($name);
      if ($role) {
        return (int) $role->rid;
      }
      return FALSE;
    }, $definition));
    $this->administrator = in_array('administrator', $definition);
  }

  /**
   * @param Condition $condition
   *
   * @return \ESN\Conditional\Condition
   */
  public static function ensureRolesCondition($condition) {
    $admin_role = new RolesCondition(NULL);

    if (is_null($condition)) {
      return $admin_role;
    }

    $result = $condition->search(RolesCondition::class);
    if (!$result) {
      $condition = new AndCondition($admin_role, $condition);
    }

    return $condition;
  }

  /**
   * Specify data which should be serialized to JSON
   *
   * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
   * @return mixed data which can be serialized by <b>json_encode</b>,
   * which is a value of any type other than a resource.
   * @since 5.4.0
   */
  public function jsonSerialize() {
    return $this->roles;
  }
}
