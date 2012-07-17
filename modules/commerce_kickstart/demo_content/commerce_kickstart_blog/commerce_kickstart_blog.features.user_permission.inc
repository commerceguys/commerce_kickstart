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

  // Exported permission: delete any blog_post content.
  $permissions['create blog_post content'] = array(
     'module' => 'node',
     'name' => 'create blog_post content',
     'roles' => array(
       0 => 'administrator',
       1 => 'store administrator',
     ),
  );

  // Exported permission: delete any blog_post content.
  $permissions['delete any blog_post content'] = array(
     'module' => 'node',
     'name' => 'delete any blog_post content',
     'roles' => array(
       0 => 'administrator',
       1 => 'store administrator',
     ),
  );

  // Exported permission: delete own blog_post content.
  $permissions['delete own blog_post content'] = array(
     'module' => 'node',
     'name' => 'delete own blog_post content',
     'roles' => array(
       0 => 'administrator',
       1 => 'store administrator',
     ),
  );

  // Exported permission: edit any blog_post content.
  $permissions['edit any blog_post content'] = array(
     'module' => 'node',
     'name' => 'edit any blog_post content',
     'roles' => array(
       0 => 'administrator',
       1 => 'store administrator',
     ),
  );

  // Exported permission: edit own blog_post content.
  $permissions['edit own blog_post content'] = array(
     'module' => 'node',
     'name' => 'edit own blog_post content',
     'roles' => array(
       0 => 'administrator',
       1 => 'store administrator',
     ),
  );

  return $permissions;
}
