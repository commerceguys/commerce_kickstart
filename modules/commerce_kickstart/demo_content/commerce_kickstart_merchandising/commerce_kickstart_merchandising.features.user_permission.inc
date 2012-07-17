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

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
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

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
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

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
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

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any ad_push content.
  $permissions['delete any ad_push content'] = array(
    'module' => 'node',
    'name' => 'delete any ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'module' => 'node',
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
  );

  // Exported permission: delete own ad_push content.
  $permissions['delete own ad_push content'] = array(
    'module' => 'node',
    'name' => 'delete own ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'module' => 'node',
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
  );

  // Exported permission: edit any ad_push content.
  $permissions['edit any ad_push content'] = array(
    'module' => 'node',
    'name' => 'edit any ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'module' => 'node',
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
  );

  // Exported permission: edit own ad_push content.
  $permissions['edit own ad_push content'] = array(
    'module' => 'node',
    'name' => 'edit own ad_push content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'module' => 'node',
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
  );

  return $permissions;
}
