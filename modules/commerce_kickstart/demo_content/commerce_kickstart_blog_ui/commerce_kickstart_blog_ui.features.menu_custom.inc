<?php
/**
 * @file
 * commerce_kickstart_blog_ui.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function commerce_kickstart_blog_ui_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-navigation.
  $menus['menu-footer-navigation'] = array(
    'menu_name' => 'menu-footer-navigation',
    'title' => 'Footer navigation',
    'description' => '',
  );
  // Exported menu: menu-kickstart-user-menu.
  $menus['menu-kickstart-user-menu'] = array(
    'menu_name' => 'menu-kickstart-user-menu',
    'title' => 'Kickstart user menu',
    'description' => '',
  );
  // Exported menu: secondary-navigation.
  $menus['secondary-navigation'] = array(
    'menu_name' => 'secondary-navigation',
    'title' => 'Secondary navigation',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer navigation');
  t('Kickstart user menu');
  t('Secondary navigation');


  return $menus;
}
