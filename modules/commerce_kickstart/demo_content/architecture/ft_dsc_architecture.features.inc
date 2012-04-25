<?php
/**
 * @file
 * ft_dsc_architecture.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function ft_dsc_architecture_commerce_product_default_types() {
  $items = array(
    'bags_cases' => array(
      'type' => 'bags_cases',
      'name' => 'Bags & Cases',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
    'drinks' => array(
      'type' => 'drinks',
      'name' => 'Drinks',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
    'hats' => array(
      'type' => 'hats',
      'name' => 'Hats',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
    'shoes' => array(
      'type' => 'shoes',
      'name' => 'Shoes',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
    'storage_devices' => array(
      'type' => 'storage_devices',
      'name' => 'Storage Devices',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
    'tops' => array(
      'type' => 'tops',
      'name' => 'Tops',
      'description' => '',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_dsc_architecture_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ft_dsc_architecture_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ft_dsc_architecture_node_info() {
  $items = array(
    'product_display' => array(
      'name' => t('Product display'),
      'base' => 'node_content',
      'description' => t('Use <em>product displays</em> to present Add to Cart form for products to your customers.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
