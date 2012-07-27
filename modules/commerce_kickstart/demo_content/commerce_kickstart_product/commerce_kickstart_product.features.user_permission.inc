<?php
/**
 * @file
 * commerce_kickstart_product.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commerce_kickstart_product_user_default_permissions() {
  $permissions = array();

  // Exported permission: create bags_cases content.
  $permissions['create bags_cases content'] = array(
    'name' => 'create bags_cases content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create commerce_product entities of bundle bags_cases.
  $permissions['create commerce_product entities of bundle bags_cases'] = array(
    'name' => 'create commerce_product entities of bundle bags_cases',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle drinks.
  $permissions['create commerce_product entities of bundle drinks'] = array(
    'name' => 'create commerce_product entities of bundle drinks',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle hats.
  $permissions['create commerce_product entities of bundle hats'] = array(
    'name' => 'create commerce_product entities of bundle hats',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle shoes.
  $permissions['create commerce_product entities of bundle shoes'] = array(
    'name' => 'create commerce_product entities of bundle shoes',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle storage_devices.
  $permissions['create commerce_product entities of bundle storage_devices'] = array(
    'name' => 'create commerce_product entities of bundle storage_devices',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle tops.
  $permissions['create commerce_product entities of bundle tops'] = array(
    'name' => 'create commerce_product entities of bundle tops',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create drinks content.
  $permissions['create drinks content'] = array(
    'name' => 'create drinks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create hats content.
  $permissions['create hats content'] = array(
    'name' => 'create hats content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create shoes content.
  $permissions['create shoes content'] = array(
    'name' => 'create shoes content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create storage_devices content.
  $permissions['create storage_devices content'] = array(
    'name' => 'create storage_devices content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create tops content.
  $permissions['create tops content'] = array(
    'name' => 'create tops content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any bags_cases content.
  $permissions['delete any bags_cases content'] = array(
    'name' => 'delete any bags_cases content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any drinks content.
  $permissions['delete any drinks content'] = array(
    'name' => 'delete any drinks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hats content.
  $permissions['delete any hats content'] = array(
    'name' => 'delete any hats content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any shoes content.
  $permissions['delete any shoes content'] = array(
    'name' => 'delete any shoes content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any storage_devices content.
  $permissions['delete any storage_devices content'] = array(
    'name' => 'delete any storage_devices content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any tops content.
  $permissions['delete any tops content'] = array(
    'name' => 'delete any tops content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own bags_cases content.
  $permissions['delete own bags_cases content'] = array(
    'name' => 'delete own bags_cases content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own drinks content.
  $permissions['delete own drinks content'] = array(
    'name' => 'delete own drinks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hats content.
  $permissions['delete own hats content'] = array(
    'name' => 'delete own hats content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own shoes content.
  $permissions['delete own shoes content'] = array(
    'name' => 'delete own shoes content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own storage_devices content.
  $permissions['delete own storage_devices content'] = array(
    'name' => 'delete own storage_devices content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own tops content.
  $permissions['delete own tops content'] = array(
    'name' => 'delete own tops content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 10.
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 11.
  $permissions['delete terms in 11'] = array(
    'name' => 'delete terms in 11',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5.
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 6.
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7.
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 8.
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9.
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any bags_cases content.
  $permissions['edit any bags_cases content'] = array(
    'name' => 'edit any bags_cases content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any commerce_product entity of bundle bags_cases.
  $permissions['edit any commerce_product entity of bundle bags_cases'] = array(
    'name' => 'edit any commerce_product entity of bundle bags_cases',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle drinks.
  $permissions['edit any commerce_product entity of bundle drinks'] = array(
    'name' => 'edit any commerce_product entity of bundle drinks',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle hats.
  $permissions['edit any commerce_product entity of bundle hats'] = array(
    'name' => 'edit any commerce_product entity of bundle hats',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle shoes.
  $permissions['edit any commerce_product entity of bundle shoes'] = array(
    'name' => 'edit any commerce_product entity of bundle shoes',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle storage_devices.
  $permissions['edit any commerce_product entity of bundle storage_devices'] = array(
    'name' => 'edit any commerce_product entity of bundle storage_devices',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle tops.
  $permissions['edit any commerce_product entity of bundle tops'] = array(
    'name' => 'edit any commerce_product entity of bundle tops',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any drinks content.
  $permissions['edit any drinks content'] = array(
    'name' => 'edit any drinks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hats content.
  $permissions['edit any hats content'] = array(
    'name' => 'edit any hats content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any shoes content.
  $permissions['edit any shoes content'] = array(
    'name' => 'edit any shoes content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any storage_devices content.
  $permissions['edit any storage_devices content'] = array(
    'name' => 'edit any storage_devices content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any tops content.
  $permissions['edit any tops content'] = array(
    'name' => 'edit any tops content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own bags_cases content.
  $permissions['edit own bags_cases content'] = array(
    'name' => 'edit own bags_cases content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own commerce_product entities of bundle bags_cases.
  $permissions['edit own commerce_product entities of bundle bags_cases'] = array(
    'name' => 'edit own commerce_product entities of bundle bags_cases',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle drinks.
  $permissions['edit own commerce_product entities of bundle drinks'] = array(
    'name' => 'edit own commerce_product entities of bundle drinks',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle hats.
  $permissions['edit own commerce_product entities of bundle hats'] = array(
    'name' => 'edit own commerce_product entities of bundle hats',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle shoes.
  $permissions['edit own commerce_product entities of bundle shoes'] = array(
    'name' => 'edit own commerce_product entities of bundle shoes',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle storage_devices.
  $permissions['edit own commerce_product entities of bundle storage_devices'] = array(
    'name' => 'edit own commerce_product entities of bundle storage_devices',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle tops.
  $permissions['edit own commerce_product entities of bundle tops'] = array(
    'name' => 'edit own commerce_product entities of bundle tops',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own drinks content.
  $permissions['edit own drinks content'] = array(
    'name' => 'edit own drinks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hats content.
  $permissions['edit own hats content'] = array(
    'name' => 'edit own hats content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own shoes content.
  $permissions['edit own shoes content'] = array(
    'name' => 'edit own shoes content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own storage_devices content.
  $permissions['edit own storage_devices content'] = array(
    'name' => 'edit own storage_devices content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own tops content.
  $permissions['edit own tops content'] = array(
    'name' => 'edit own tops content',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 10.
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 11.
  $permissions['edit terms in 11'] = array(
    'name' => 'edit terms in 11',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5.
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 6.
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7.
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 8.
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9.
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: view any commerce_product entity of bundle bags_cases.
  $permissions['view any commerce_product entity of bundle bags_cases'] = array(
    'name' => 'view any commerce_product entity of bundle bags_cases',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle drinks.
  $permissions['view any commerce_product entity of bundle drinks'] = array(
    'name' => 'view any commerce_product entity of bundle drinks',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle hats.
  $permissions['view any commerce_product entity of bundle hats'] = array(
    'name' => 'view any commerce_product entity of bundle hats',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle shoes.
  $permissions['view any commerce_product entity of bundle shoes'] = array(
    'name' => 'view any commerce_product entity of bundle shoes',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle storage_devices.
  $permissions['view any commerce_product entity of bundle storage_devices'] = array(
    'name' => 'view any commerce_product entity of bundle storage_devices',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle tops.
  $permissions['view any commerce_product entity of bundle tops'] = array(
    'name' => 'view any commerce_product entity of bundle tops',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle bags_cases.
  $permissions['view own commerce_product entities of bundle bags_cases'] = array(
    'name' => 'view own commerce_product entities of bundle bags_cases',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle drinks.
  $permissions['view own commerce_product entities of bundle drinks'] = array(
    'name' => 'view own commerce_product entities of bundle drinks',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle hats.
  $permissions['view own commerce_product entities of bundle hats'] = array(
    'name' => 'view own commerce_product entities of bundle hats',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle shoes.
  $permissions['view own commerce_product entities of bundle shoes'] = array(
    'name' => 'view own commerce_product entities of bundle shoes',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle storage_devices.
  $permissions['view own commerce_product entities of bundle storage_devices'] = array(
    'name' => 'view own commerce_product entities of bundle storage_devices',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle tops.
  $permissions['view own commerce_product entities of bundle tops'] = array(
    'name' => 'view own commerce_product entities of bundle tops',
    'roles' => array(
      0 => 'administrator',
      1 => 'store administrator',
    ),
    'module' => 'commerce_product',
  );

  return $permissions;
}
