<?php
/**
 * @file
 * commerce_kickstart_homepage.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function commerce_kickstart_homepage_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: secondary-navigation
  $menus['secondary-navigation'] = array(
    'menu_name' => 'secondary-navigation',
    'title' => 'Secondary navigation',
    'description' => '',
  );
  // Exported menu: menu-footer-navigation
  $menus['menu-footer-navigation'] = array(
    'menu_name' => 'menu-footer-navigation',
    'title' => 'Footer navigation',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer navigation');
  t('Main menu');
  t('Secondary navigation');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
