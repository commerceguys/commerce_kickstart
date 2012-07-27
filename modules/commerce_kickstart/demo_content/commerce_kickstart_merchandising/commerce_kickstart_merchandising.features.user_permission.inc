<?php
/**
 * @file
 * commerce_kickstart_merchandising.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commerce_kickstart_merchandising_user_default_permissions() {
  $permissions = array();

  // Exported permission: create ad_push content.
  $permissions['create ad_push content'] = array(
    'name' => 'create ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any ad_push content.
  $permissions['delete any ad_push content'] = array(
    'name' => 'delete any ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own ad_push content.
  $permissions['delete own ad_push content'] = array(
    'name' => 'delete own ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any ad_push content.
  $permissions['edit any ad_push content'] = array(
    'name' => 'edit any ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own ad_push content.
  $permissions['edit own ad_push content'] = array(
    'name' => 'edit own ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
