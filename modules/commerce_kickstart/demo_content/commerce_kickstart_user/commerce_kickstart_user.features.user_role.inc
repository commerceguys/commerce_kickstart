<?php
/**
 * @file
 * commerce_kickstart_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function commerce_kickstart_user_user_default_roles() {
  $roles = array();

  // Exported role: store administrator.
  $roles['store administrator'] = array(
    'name' => 'store administrator',
    'weight' => '3',
  );

  return $roles;
}
