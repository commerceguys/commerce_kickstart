<?php
/**
 * @file
 * commerce_kickstart_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commerce_kickstart_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commerce_kickstart_search_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_search_api_sort().
 */
function commerce_kickstart_search_default_search_api_sort() {
  $items = array();
  $items['product_display__created'] = entity_import('search_api_sort', '{
    "index_id" : "product_display",
    "field" : "created",
    "name" : "Latest",
    "enabled" : "1",
    "weight" : "20",
    "identifier" : "product_display__created",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Date created" }
  }');
  $items['product_display__field_product_commerce_price_amount_float_asc'] = entity_import('search_api_sort', '{
    "index_id" : "product_display",
    "field" : "field_product_commerce_price_amount_float_asc",
    "name" : "Price",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "product_display__field_product_commerce_price_amount_float_asc",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Product variations \\u00bb Price \\u00bb Amount (float) (Min)" }
  }');
  $items['product_display__title'] = entity_import('search_api_sort', '{
    "index_id" : "product_display",
    "field" : "title",
    "name" : "Title",
    "enabled" : "1",
    "weight" : "30",
    "identifier" : "product_display__title",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Title" }
  }');
  return $items;
}
