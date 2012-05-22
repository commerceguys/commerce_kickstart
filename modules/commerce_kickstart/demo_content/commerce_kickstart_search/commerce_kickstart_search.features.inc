<?php
/**
 * @file
 * commerce_kickstart_search.features.inc
 */

/**
 * Implements hook_default_search_api_server().
 */
function commerce_kickstart_search_default_search_api_server() {
  $items = array();
  $items['database_search_engine'] = entity_import('search_api_server', '{
    "name" : "Database search engine",
    "machine_name" : "database_search_engine",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "indexes" : {
        "search_commerce_display" : {
          "title" : {
            "table" : "search_api_db_search_commerce_display_title",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_search_commerce_display_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_search_commerce_display_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_product:commerce_price:amount" : {
            "table" : "search_api_db_search_commerce_display_field_product_commerce_pr",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_brand" : {
            "table" : "search_api_db_search_commerce_display_field_brand",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_category" : {
            "table" : "search_api_db_search_commerce_display_field_category",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_collection" : {
            "table" : "search_api_db_search_commerce_display_field_collection",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_gender" : {
            "table" : "search_api_db_search_commerce_display_field_gender",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product:field_bag_size" : {
            "table" : "search_api_db_search_commerce_display_field_product_field_bag_s",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_color" : {
            "table" : "search_api_db_search_commerce_display_field_product_field_color",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_hat_size" : {
            "table" : "search_api_db_search_commerce_display_field_product_field_hat_s",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_shoe_size" : {
            "table" : "search_api_db_search_commerce_display_field_product_field_shoe_",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_storage_capacity" : {
            "table" : "search_api_db_search_commerce_display_field_product_field_stora",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_top_size" : {
            "table" : "search_api_db_search_commerce_display_field_product_field_top_s",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_color:name" : {
            "table" : "search_api_db_search_commerce_display_field_product_field_col_1",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_product:field_color:description" : {
            "table" : "search_api_db_search_commerce_display_field_product_field_col_2",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        },
        "search_commerce_product" : {
          "field_product_node" : {
            "table" : "search_api_db_search_commerce_product_field_product_node",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_search_commerce_product_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "commerce_price:amount" : {
            "table" : "search_api_db_search_commerce_product_commerce_price_amount",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_bag_size" : {
            "table" : "search_api_db_search_commerce_product_field_bag_size",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_color" : {
            "table" : "search_api_db_search_commerce_product_field_color",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_hat_size" : {
            "table" : "search_api_db_search_commerce_product_field_hat_size",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_shoe_size" : {
            "table" : "search_api_db_search_commerce_product_field_shoe_size",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_storage_capacity" : {
            "table" : "search_api_db_search_commerce_product_field_storage_capacity",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_top_size" : {
            "table" : "search_api_db_search_commerce_product_field_top_size",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product_node:field_brand" : {
            "table" : "search_api_db_search_commerce_product_field_product_node_field_",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_node:field_category" : {
            "table" : "search_api_db_search_commerce_product_field_product_node_fiel_1",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_node:field_collection" : {
            "table" : "search_api_db_search_commerce_product_field_product_node_fiel_2",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_product_node:field_gender" : {
            "table" : "search_api_db_search_commerce_product_field_product_node_fiel_3",
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
