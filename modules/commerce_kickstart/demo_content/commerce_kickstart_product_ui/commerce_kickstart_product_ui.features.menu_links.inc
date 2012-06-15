<?php
/**
 * @file
 * commerce_kickstart_product_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function commerce_kickstart_product_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_all-products:products
  $menu_links['main-menu_all-products:products'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'products',
    'router_path' => 'products',
    'link_title' => 'All products',
    'options' => array(
      'identifier' => 'main-menu_all-products:products',
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '99',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All products');


  return $menu_links;
}
