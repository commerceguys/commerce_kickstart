<?php
/**
 * @file
 * commerce_kickstart_blog_ui.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function commerce_kickstart_blog_ui_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_secondary_links_source';
  $strongarm->value = 'secondary-navigation';
  $export['menu_secondary_links_source'] = $strongarm;

  return $export;
}
