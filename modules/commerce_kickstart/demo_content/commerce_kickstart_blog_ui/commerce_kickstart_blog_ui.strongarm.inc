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
  $strongarm->name = 'custom_breadcrumbs_exclude_list';
  $strongarm->value = '<front>';
  $export['custom_breadcrumbs_exclude_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_force_active_trail';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_force_active_trail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_use_exclude_list';
  $strongarm->value = 1;
  $export['custom_breadcrumbs_use_exclude_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumb_home';
  $strongarm->value = 'Home';
  $export['custom_breadcrumb_home'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_secondary_links_source';
  $strongarm->value = 'secondary-navigation';
  $export['menu_secondary_links_source'] = $strongarm;

  return $export;
}
