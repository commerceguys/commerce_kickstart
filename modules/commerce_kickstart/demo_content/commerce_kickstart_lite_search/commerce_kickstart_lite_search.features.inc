<?php
/**
 * @file
 * commerce_kickstart_lite_search.features.inc
 */

/**
 * Implements hook_default_search_api_server().
 */
function commerce_kickstart_lite_search_default_search_api_server() {
  $items = array();
  $items['kickstart_product_display'] = entity_import('search_api_server', '{
    "name" : "Kickstart_product_display",
    "machine_name" : "kickstart_product_display",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "indexes" : { "kickstart_product_display" : {
          "title" : {
            "table" : "search_api_db_kickstart_product_display_title",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_kickstart_product_display_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_product_variations:title" : {
            "table" : "search_api_db_kickstart_product_display_field_product_variation",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_product_variations:field_color" : {
            "table" : "search_api_db_kickstart_product_display_field_product_variati_1",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_variations:field_size" : {
            "table" : "search_api_db_kickstart_product_display_field_product_variati_2",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
