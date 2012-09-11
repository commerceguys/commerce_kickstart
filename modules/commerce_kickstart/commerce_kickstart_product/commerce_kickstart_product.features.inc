<?php
/**
 * @file
 * commerce_kickstart_product.features.inc
 */

/**
 * Implements hook_commerce_flat_rate_default_services().
 */
function commerce_kickstart_product_commerce_flat_rate_default_services() {
  $items = array(
    'express_shipping' => array(
      'name' => 'express_shipping',
      'base' => 'express_shipping',
      'display_title' => 'Express shipping: 1 business day',
      'description' => 'An express shipping service with additional fee.',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_express_shipping',
      'weight' => 0,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'express_shipping_details_form',
        'details_form_validate' => 'express_shipping_details_form_validate',
        'details_form_submit' => 'express_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Express Shipping',
      'base_rate' => array(
        'amount' => '1500',
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'free_shipping' => array(
      'name' => 'free_shipping',
      'base' => 'free_shipping',
      'display_title' => 'Free shipping: 5 - 8 business days',
      'description' => 'A free shipping service for an order over a certain amount.',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_free_shipping',
      'weight' => 1,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'free_shipping_details_form',
        'details_form_validate' => 'free_shipping_details_form_validate',
        'details_form_submit' => 'free_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Free Shipping',
      'base_rate' => array(
        'amount' => '0',
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'standard_shipping' => array(
      'name' => 'standard_shipping',
      'base' => 'standard_shipping',
      'display_title' => 'Standard shipping: 3 - 5 business days',
      'description' => 'A standard shipping service.',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_standard_shipping',
      'weight' => 2,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'standard_shipping_details_form',
        'details_form_validate' => 'standard_shipping_details_form_validate',
        'details_form_submit' => 'standard_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Standard Shipping',
      'base_rate' => array(
        'amount' => '800',
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function commerce_kickstart_product_commerce_product_default_types() {
  $items = array(
    'bags_cases' => array(
      'type' => 'bags_cases',
      'name' => 'Bags & Cases',
      'description' => '<em>Bags & Cases</em> are products which contain a size and a color.',
      'help' => '',
      'revision' => '1',
    ),
    'drinks' => array(
      'type' => 'drinks',
      'name' => 'Drinks',
      'description' => '<em>Drinks</em> are products which contain a color.',
      'help' => '',
      'revision' => '1',
    ),
    'hats' => array(
      'type' => 'hats',
      'name' => 'Hats',
      'description' => '<em>Hats</em> are products which contain a size and a color.',
      'help' => '',
      'revision' => '1',
    ),
    'shoes' => array(
      'type' => 'shoes',
      'name' => 'Shoes',
      'description' => '<em>Shoes</em> are products which contain a size and a color.',
      'help' => '',
      'revision' => '1',
    ),
    'storage_devices' => array(
      'type' => 'storage_devices',
      'name' => 'Storage Devices',
      'description' => '<em>Storage devices</em> are products which contain a capacity.',
      'help' => '',
      'revision' => '1',
    ),
    'tops' => array(
      'type' => 'tops',
      'name' => 'Tops',
      'description' => '<em>Tops</em> are products which contain a size and a color.',
      'help' => '',
      'revision' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function commerce_kickstart_product_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function commerce_kickstart_product_image_default_styles() {
  $styles = array();

  // Exported image style: product_full.
  $styles['product_full'] = array(
    'name' => 'product_full',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '400',
          'height' => '550',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: product_medium.
  $styles['product_medium'] = array(
    'name' => 'product_medium',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '230',
          'height' => '260',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: product_thumbnail.
  $styles['product_thumbnail'] = array(
    'name' => 'product_thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '110',
          'height' => '130',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function commerce_kickstart_product_node_info() {
  $items = array(
    'bags_cases' => array(
      'name' => t('Bags & Cases'),
      'base' => 'node_content',
      'description' => t('A <em>Bags & Cases</em> is a content type which contain product variations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'drinks' => array(
      'name' => t('Drinks'),
      'base' => 'node_content',
      'description' => t('A <em>Drinks</em> is a content type which contain product variations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'hats' => array(
      'name' => t('Hats'),
      'base' => 'node_content',
      'description' => t('A <em>Hats</em> is a content type which contain product variations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'shoes' => array(
      'name' => t('Shoes'),
      'base' => 'node_content',
      'description' => t('A <em>Shoes</em> is a content type which contain product variations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'storage_devices' => array(
      'name' => t('Storage Devices'),
      'base' => 'node_content',
      'description' => t('A <em>Storage Devices</em> is a content type which contain product variations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'tops' => array(
      'name' => t('Tops'),
      'base' => 'node_content',
      'description' => t('A <em>Tops</em> is a content type which contain product variations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function commerce_kickstart_product_default_search_api_index() {
  $items = array();
  $items['product_display'] = entity_import('search_api_index', '{
    "name" : "Product Display",
    "machine_name" : "product_display",
    "description" : "Used for the frontend product listings and search pages.",
    "server" : "frontend",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "string" },
        "created" : { "type" : "date" },
        "field_brand" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_collection" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_gender" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "field_product_commerce_price_amount_float_asc" : { "type" : "decimal" },
        "field_product_commerce_price_amount_float_desc" : { "type" : "decimal" },
        "body:value" : { "type" : "text" },
        "field_brand:name" : { "type" : "text" },
        "field_brand:description" : { "type" : "text" },
        "field_collection:name" : { "type" : "text" },
        "field_collection:description" : { "type" : "text" },
        "field_gender:name" : { "type" : "text" },
        "field_gender:description" : { "type" : "text" },
        "field_product:field_bag_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_color" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_hat_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_shoe_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_storage_capacity" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:field_top_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product:commerce_price:amount_float" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_product:field_color:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_product:field_color:description" : { "type" : "list\\u003Ctext\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : { "field_product:commerce_price:amount_float" : "field_product:commerce_price:amount_float" } }
        },
        "commerce_kickstart_search_bundle_filter" : { "status" : 1, "weight" : "-10", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title (Fulltext)",
                "type" : "fulltext",
                "fields" : [ "title" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              }
            }
          }
        },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "default" : "1", "bundles" : [] }
        },
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
    "read_only" : "0"
  }');
  return $items;
}
