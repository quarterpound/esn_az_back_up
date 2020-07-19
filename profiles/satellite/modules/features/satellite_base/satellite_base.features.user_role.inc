<?php
/**
 * @file
 * satellite_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function satellite_base_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 5,
  );

  // Exported role: member.
  $roles['member'] = array(
    'name' => 'member',
    'weight' => 6,
  );

  return $roles;
}
