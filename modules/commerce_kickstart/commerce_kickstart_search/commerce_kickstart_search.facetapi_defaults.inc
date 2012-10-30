<?php
/**
 * @file
 * commerce_kickstart_search.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function commerce_kickstart_search_facetapi_default_facet_settings() {
  return commerce_kickstart_search_generate_facets('product_display');
}
