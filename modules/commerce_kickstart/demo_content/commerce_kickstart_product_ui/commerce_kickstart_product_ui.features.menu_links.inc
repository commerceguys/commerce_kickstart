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
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All products');
  t('Home');


  return $menu_links;
}
