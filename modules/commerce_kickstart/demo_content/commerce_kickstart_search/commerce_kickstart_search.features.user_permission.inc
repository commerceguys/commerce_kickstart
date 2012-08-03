<?php
/**
 * @file
 * commerce_kickstart_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commerce_kickstart_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: use search_api_sorts.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search_api_sorts',
  );

  return $permissions;
}
