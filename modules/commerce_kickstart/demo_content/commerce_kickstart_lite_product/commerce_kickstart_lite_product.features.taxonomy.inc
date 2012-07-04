<?php
/**
 * @file
 * commerce_kickstart_lite_product.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function commerce_kickstart_lite_product_taxonomy_default_vocabularies() {
  return array(
    'colors' => array(
      'name' => 'Colors',
      'machine_name' => 'colors',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'product_category' => array(
      'name' => 'Product category',
      'machine_name' => 'product_category',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'sizes' => array(
      'name' => 'Sizes',
      'machine_name' => 'sizes',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
