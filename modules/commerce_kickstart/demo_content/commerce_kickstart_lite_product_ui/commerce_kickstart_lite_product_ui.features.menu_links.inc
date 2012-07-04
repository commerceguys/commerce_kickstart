<?php
/**
 * @file
 * commerce_kickstart_lite_product_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function commerce_kickstart_lite_product_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_all-products:products
  $menu_links['main-menu_all-products:products'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'products',
    'router_path' => 'products',
    'link_title' => 'All products',
    'options' => array(
      'toolbar_expanded' => 0,
      'toolbar_break' => 0,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-products:products',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All products');


  return $menu_links;
}
