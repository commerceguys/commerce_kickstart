<?php
/**
 * @file
 * commerce_kickstart_products.features.inc
 */

/**
 * Implements hook_views_api().
 */
function commerce_kickstart_products_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
