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

  // Exported menu: secondary-navigation
  $menus['secondary-navigation'] = array(
    'menu_name' => 'secondary-navigation',
    'title' => 'Secondary navigation',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Secondary navigation');


  return $menus;
}
