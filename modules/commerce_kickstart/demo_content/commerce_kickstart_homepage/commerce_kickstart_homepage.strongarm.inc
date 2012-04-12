<?php
/**
 * @file
 * commerce_kickstart_homepage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function commerce_kickstart_homepage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_article'] = $strongarm;

  return $export;
}
