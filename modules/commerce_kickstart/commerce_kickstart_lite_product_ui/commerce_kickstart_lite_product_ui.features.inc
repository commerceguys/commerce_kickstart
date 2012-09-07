<?php
/**
 * @file
 * commerce_kickstart_lite_product_ui.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commerce_kickstart_lite_product_ui_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commerce_kickstart_lite_product_ui_views_api() {
  return array("version" => "3.0");
}
