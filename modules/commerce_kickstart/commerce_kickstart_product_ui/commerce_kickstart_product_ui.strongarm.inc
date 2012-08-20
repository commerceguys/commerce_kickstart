<?php
/**
 * @file
 * commerce_kickstart_product_ui.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function commerce_kickstart_product_ui_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_breadcrumb_home';
  $strongarm->value = 'Home';
  $export['taxonomy_breadcrumb_home'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_breadcrumb_include_nodes';
  $strongarm->value = '1';
  $export['taxonomy_breadcrumb_include_nodes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_breadcrumb_include_node_title';
  $strongarm->value = 1;
  $export['taxonomy_breadcrumb_include_node_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_breadcrumb_node_types';
  $strongarm->value = array(
    'bags_cases' => 'bags_cases',
    'drinks' => 'drinks',
    'hats' => 'hats',
    'shoes' => 'shoes',
    'storage_devices' => 'storage_devices',
    'tops' => 'tops',
    'ad_push' => 0,
    'page' => 0,
    'blog_post' => 0,
    'slideshow' => 0,
  );
  $export['taxonomy_breadcrumb_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_breadcrumb_selected_vid';
  $strongarm->value = '6';
  $export['taxonomy_breadcrumb_selected_vid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_breadcrumb_show_current_term';
  $strongarm->value = 1;
  $export['taxonomy_breadcrumb_show_current_term'] = $strongarm;

  return $export;
}
