<?php

/**
 * @file
 * Contains Batch API callbacks used during installation.
 */

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_install_additional_modules()
 */
function _commerce_kickstart_enable_module($module, $module_name, &$context) {
  module_enable(array($module), FALSE);
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_install_additional_modules()
 */
function _commerce_kickstart_flush_caches($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));
  drupal_flush_all_caches();
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_content()
 */
function _commerce_kickstart_example_taxes($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  $commerce_kickstart_choose_tax_country = variable_get('commerce_kickstart_choose_tax_country', NULL);

  // Create the choosen tax.
  if (!empty($commerce_kickstart_choose_tax_country)) {
    if ($commerce_kickstart_choose_tax_country == 'us') {
      $tax = array(
        'name' => 'sample_michigan_sales_tax',
        'title' => 'Sample Michigan Sales Tax 6%',
        'display_title' => 'Sample Michigan Sales Tax 6%',
        'description' => '',
        'rate' => 0.06,
        'type' => 'sales_tax', // vat
        'rules_component' => '',
        'default_rules_component' => FALSE,
        'tax_component' => '',
        'admin_list' => TRUE,
        'calculation_callback' => 'commerce_tax_rate_calculate',
        'module' => 'commerce_tax_ui',
        'is_new' => TRUE,
      );
      commerce_tax_ui_tax_rate_save($tax);

      $rule = '{ "commerce_tax_rate_sample_michigan_sales_tax" : {
        "LABEL" : "Calculate Sample Michigan Sales Tax 6%",
        "PLUGIN" : "rule",
        "REQUIRES" : [ "commerce_order", "commerce_tax" ],
        "USES VARIABLES" : {
          "commerce_line_item" : {
            "label" : "Line item",
            "type" : "commerce_line_item"
          }
        },
        "IF" : [{
          "commerce_order_compare_address" : {
            "commerce_order" : [ "commerce-line-item:order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "administrative_area",
            "value" : "MI"
          }
        }],
        "DO" : [{
          "commerce_tax_rate_apply" : {
            "USING" : {
              "commerce_line_item" : [ "commerce-line-item" ],
              "tax_rate_name" : "sample_michigan_sales_tax"},
              "PROVIDE" : {
                "applied_tax" : {
                  "applied_tax" : "Applied tax"
                }
              }
            }
          }
        ]}
      }';
      $rules_config = rules_import($rule);
      $rules_config->save();

      $tax = array(
        'name' => 'sample_michigan_sales_tax',
        'rules_component' => 'commerce_tax_rate_sample_michigan_sales_tax',
        'is_new' => FALSE,
      );
      commerce_tax_ui_tax_rate_save($tax);
    }

    if ($commerce_kickstart_choose_tax_country == 'europe') {
      variable_set('import_choosen_tax', 'europe');
      $tax = array(
        'name' => 'sample_french_vat_tax',
        'title' => 'Sample French VAT 19,6%',
        'display_title' => 'Sample French VAT 19,6%',
        'description' => '',
        'rate' => 0.196,
        'type' => 'vat', // vat
        'default_rules_component' => TRUE,
        'tax_component' => '',
        'admin_list' => TRUE,
        'calculation_callback' => 'commerce_tax_rate_calculate',
        'module' => 'commerce_tax_ui',
        'is_new' => TRUE,
      );
      commerce_tax_ui_tax_rate_save($tax);
    }
  }
  // delete the variables we used during this task.
  variable_del('commerce_kickstart_choose_tax_country');
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_content()
 */
function _commerce_kickstart_taxonomy_menu($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  // Set up taxonomy main menu.
  $collection = taxonomy_vocabulary_machine_name_load('collection');
  $variable_name = _taxonomy_menu_build_variable('vocab_menu', $collection->vid);
  variable_set($variable_name, 'main-menu');
  $variable_name = _taxonomy_menu_build_variable('vocab_parent', $collection->vid);
  variable_set($variable_name, '0');
  $variable_name = _taxonomy_menu_build_variable('path', $collection->vid);
  variable_set($variable_name, 'taxonomy_menu_path_default');
  $variable_name = _taxonomy_menu_build_variable('rebuild', $collection->vid);
  variable_set($variable_name, 1);
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_content()
 */
function _commerce_kickstart_import($operation, $type, &$context) {
  $context['message'] = t('@operation', array('@operation' => $type));
  $migration =  Migration::getInstance($operation);
  $migration->processImport();
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_content()
 */
function _commerce_kickstart_example_user($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  // Create a sample user.
  $user = array(
    'name' => 'Sample Customer',
    'mail' => 'customer@example.com',
    'pass' => 'customer',
    'status' => 1,
  );
  $user = user_save(NULL, $user);

  // Create a bIlling customer profile.
  $billing_profile = commerce_customer_profile_new('billing', $user->uid);
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample Customer';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'US';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = '16 Hampton Ct';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = 'Visalia';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['administrative_area'] = 'CA';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = '93277-8329';
  commerce_customer_profile_save($billing_profile);
  commerce_addressbook_set_default_profile($billing_profile);

  // Create two shipping customer profile samples.
  $shipping_profile = commerce_customer_profile_new('shipping', $user->uid);
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample Customer';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'US';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = '2843 Sherman Ave';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = 'Camden';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['administrative_area'] = 'NJ';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = '08105-442';
  commerce_customer_profile_save($shipping_profile);
  commerce_addressbook_set_default_profile($shipping_profile);

  $shipping_profile = commerce_customer_profile_new('shipping', $user->uid);
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample Customer';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'FR';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = '27 rue des sapins';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = 'Paris';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = '75004';
  commerce_customer_profile_save($shipping_profile);

  // Create 3 order samples.
  _commerce_kickstart_create_order($user->uid, 'cart', 2);
  _commerce_kickstart_create_order($user->uid, 'completed', 5);
  _commerce_kickstart_create_order($user->uid, 'completed', 3);
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_content()
 */
function _commerce_kickstart_post_import($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  $install_demo_store = variable_get('commerce_kickstart_demo_store', FALSE);
  if (!$install_demo_store) {
    _commerce_kickstart_setup_omega_theme();
  }

  features_rebuild();
  drupal_static_reset();
}

/**
 * Configures blocks for the theme during base install (no demo store).
 */
function _commerce_kickstart_setup_omega_theme() {
  $default_theme = 'omega';
  $admin_theme = 'commerce_kickstart_admin';
  theme_enable(array($default_theme, $admin_theme));
  variable_set('theme_default', $default_theme);
  variable_set('admin_theme', $admin_theme);
  variable_set('node_admin_theme', '1');
  // Don't show the grid by default.
  $omega_settings = array(
    'alpha_debug_grid_active' => FALSE,
  );
  variable_set('theme_omega_settings', $omega_settings);

  $blocks = array(
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '<front>', // Do not show the block on front.
      'visibility' => 0,
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'navigation',
      'theme' => $default_theme,
      'status' => 0, // Do not enable the navigation menu block.
      'weight' => 0,
      'region' => 'sidebar_first',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'preface_first',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'help',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'user',
      'delta' => 'login',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 10,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
    // Connector.
    array(
      'module' => 'connector',
      'delta' => 'one_click_block',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 1,
      'region' => 'content',
      'pages' => "user\r\nuser/login",
      'visibility' => BLOCK_VISIBILITY_LISTED,
      'cache' => -1,
    ),
    // Search sorting.
    array(
      'module' => 'search_api_sorts',
      'delta' => 'search-sorts',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => -30,
      'region' => 'content',
      'pages' => '',
      'visibility' => 0,
      'cache' => -1,
    ),
  );

  drupal_static_reset();
  _block_rehash($admin_theme);
  _block_rehash($default_theme);
  foreach ($blocks as $record) {
    $module = array_shift($record);
    $delta = array_shift($record);
    $theme = array_shift($record);
    db_update('block')
      ->fields($record)
      ->condition('module', $module)
      ->condition('delta', $delta)
      ->condition('theme', $theme)
      ->execute();
  }
}

/*
 * Helper function to create a sample order.
 *
 * @param $uid
 * @param $order_state
 * @param $items_number
 */
function _commerce_kickstart_create_order($uid, $order_state, $items_number) {
  $order = commerce_order_new($uid, $order_state);
  commerce_order_save($order);

  $line_items = array();
  $products = entity_load('commerce_product');
  $products_key = array_keys($products);
  $products_number = count($products_key);
  $count = $products_number < $items_number ? $products_number: $items_number;
  for($i = 0; $i < $count; $i++) {
    $product = $products[$products_key[rand(0, $products_number - 1)]];
    $line_item = commerce_product_line_item_new($product, 1, $order->order_id);
    commerce_line_item_save($line_item);
    $line_items[] = array('line_item_id' => $line_item->line_item_id);
  }
  $order->commerce_line_items[LANGUAGE_NONE] = $line_items;
  commerce_order_save($order);
}
