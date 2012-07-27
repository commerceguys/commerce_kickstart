<?php
/**
 * @file
 * commerce_kickstart_blog.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commerce_kickstart_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog_post content.
  $permissions['create blog_post content'] = array(
    'name' => 'create blog_post content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any blog_post content.
  $permissions['delete any blog_post content'] = array(
    'name' => 'delete any blog_post content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own blog_post content.
  $permissions['delete own blog_post content'] = array(
    'name' => 'delete own blog_post content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any blog_post content.
  $permissions['edit any blog_post content'] = array(
    'name' => 'edit any blog_post content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own blog_post content.
  $permissions['edit own blog_post content'] = array(
    'name' => 'edit own blog_post content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
