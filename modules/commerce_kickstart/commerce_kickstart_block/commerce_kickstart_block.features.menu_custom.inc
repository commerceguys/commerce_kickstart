<?php
/**
 * @file
 * commerce_kickstart_block.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function commerce_kickstart_block_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-payment-methods.
  $menus['menu-payment-methods'] = array(
    'menu_name' => 'menu-payment-methods',
    'title' => 'Payment methods',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Payment methods');


  return $menus;
}
