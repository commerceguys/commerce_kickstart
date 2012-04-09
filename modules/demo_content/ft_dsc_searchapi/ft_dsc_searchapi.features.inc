<?php
/**
 * @file
 * ft_dsc_searchapi.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_dsc_searchapi_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ft_dsc_searchapi_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function ft_dsc_searchapi_default_search_api_index() {
  $items = array();
  $items['search_commerce_display'] = entity_import('search_api_index', '{
    "name" : "Search Commerce Display",
    "machine_name" : "search_commerce_display",
    "description" : null,
    "server" : "database_search_engine",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text" },
        "field_brand" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_collection" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_gender" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "field_product:field_bag_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_color" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_hat_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_shoe_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_storage_capacity" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_top_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "product_display" : "product_display" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['search_commerce_product'] = entity_import('search_api_index', '{
    "name" : "Search Commerce Product",
    "machine_name" : "search_commerce_product",
    "description" : null,
    "server" : "database_search_engine",
    "item_type" : "commerce_product",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "field_product_node" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_bag_size" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_color" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_hat_size" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_shoe_size" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_storage_capacity" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_top_size" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "commerce_price:amount" : { "type" : "decimal" },
        "field_product_node:field_brand" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_node:field_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_node:field_collection" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_node:field_gender" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ft_dsc_searchapi_default_search_api_server() {
  $items = array();
  $items['database_search_engine'] = entity_import('search_api_server', '{
    "name" : "database search engine",
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
          "search_api_language" : {
            "table" : "search_api_db_search_commerce_display_search_api_language",
            "type" : "string",
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
          }
        },
        "search_commerce_product" : {
          "field_product_node" : {
            "table" : "search_api_db_search_commerce_product_field_product_node",
            "type" : "list\\u003Cinteger\\u003E",
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
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
