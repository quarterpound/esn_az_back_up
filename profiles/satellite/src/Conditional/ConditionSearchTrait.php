<?php

namespace ESN\Conditional;

trait ConditionSearchTrait {

  /**
   * @param string $type Condition type (class name)
   * @param \ESN\Conditional\Condition[] $children
   *
   * @return $this|bool
   */
  private function searchCondition($type, $children) {
    if ($this instanceof $type) {
      return $this;
    }

    foreach ($children as $child) {
      $result = $child->search($type);
      if (FALSE !== $result) {
        return $result;
      }
    }

    return FALSE;
  }
}
