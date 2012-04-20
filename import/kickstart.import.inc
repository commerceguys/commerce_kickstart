<?php
/**
 * BatchAPI callback.
 *
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_taxonomy_menu() {
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
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_example_taxes() {
  $commerce_kickstart_example_content = variable_get('commerce_kickstart_example_content', NULL);
  $commerce_kickstart_choose_tax_country = variable_get('commerce_kickstart_choose_tax_country', NULL);
  // Create products if specified.
  if ($commerce_kickstart_example_content == 1) {
    module_enable(array(
      'features',
      'commerce_features',
      'ft_dsc_architecture',
      'commerce_kickstart_homepage',
      'commerce_kickstart_settings'
    ));
    features_rebuild();
    drupal_static_reset();
    module_enable(array('demo'));
  }

  // Create the choosen tax.
  if (!empty($commerce_kickstart_choose_tax_country)) {
    if ($commerce_kickstart_choose_tax_country == 'us') {
      $tax = array(
        'name' => 'sample_californian_sales_tax',
        'title' => 'Sample Californian Sales Tax 7,25%',
        'display_title' => 'Sample Californian Sales Tax 7,25%',
        'description' => '',
        'rate' => 0.0725,
        'type' => 'sales_tax', // vat
        'default_rules_component' => TRUE,
        'tax_component' => '',
        'admin_list' => TRUE,
        'calculation_callback' => 'commerce_tax_rate_calculate',
        'module' => 'commerce_tax_ui',
        'is_new' => TRUE,
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
  variable_del('commerce_kickstart_example_content');
  variable_del('commerce_kickstart_choose_tax_country');
}

/**
 * BatchAPI callback.
 *
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_example_bags() {
  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('Natural', 'Red', 'Black');
  _commerce_kickstart_add_term($terms, $taxonomy->vid);

  $taxonomy = taxonomy_vocabulary_machine_name_load('bag_size');
  // Add our terms
  $terms = array('One size', '13"', '15"', '17"');
  _commerce_kickstart_add_term($terms, $taxonomy->vid, FALSE);

  _commerce_kickstart_add_view_mode('commerce_product', 'bags_cases', 'node_product_list');

  $created_products = array();

  $product_names = _commerce_kickstart_parse_csv('bags_cases.csv');
  commerce_product_configure_product_type('bags_cases');

  foreach ($product_names as $item) {
    $images = $item[5];
    $product = _commerce_kickstart_create_product('bags_cases', $item[1], $item[0], $item[4] * 100);

    // Add the image.
    _commerce_kickstart_add_product_images($product, $images);

    // Add the taxonomy
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[2]));
    $product->field_color[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[3]));
    $product->field_bag_size[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;

    // Save it and retain a copy.
    commerce_product_save($product);
    $created_products[] = $product;

  }
}

/**
 * BatchAPI callback.
 *
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_example_drinks() {

  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('White', 'Black', 'Red', 'Blue');
  _commerce_kickstart_add_term($terms, $taxonomy->vid);

  _commerce_kickstart_add_view_mode('commerce_product', 'drinks', 'node_product_list');

  $created_products = array();
  $product_names = _commerce_kickstart_parse_csv('drinks.csv');

  foreach ($product_names as $sku => $item) {
    $images = $item[4];
    $product = _commerce_kickstart_create_product('drinks', $item[1], $item[0], $item[3] * 100);

    // Add the image
    _commerce_kickstart_add_product_images($product, $images);

    // Add the taxonomy
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[2]));
    $product->field_color[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;

    // Save it and retain a copy.
    commerce_product_save($product);
    $created_products[] = $product;

  }
}

/**
 * BatchAPI callback.
 *
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_example_hats() {

  $taxonomy = taxonomy_vocabulary_machine_name_load('hat_size');
  // Add our terms
  $terms = array('Small', 'Medium', 'Large', 'One Size');
  _commerce_kickstart_add_term($terms, $taxonomy->vid, FALSE);

  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('Black', 'White', 'Navy');
  _commerce_kickstart_add_term($terms, $taxonomy->vid);

  _commerce_kickstart_add_view_mode('commerce_product', 'hats', 'node_product_list');

  $created_products = array();
  $product_names = _commerce_kickstart_parse_csv('hats.csv');

  foreach ($product_names as $sku => $item) {
    $images = $item[5];
    $product = _commerce_kickstart_create_product('hats', $item[1], $item[0], $item[4] * 100);

    // Add the image
    _commerce_kickstart_add_product_images($product, $images);

    // Add the taxonomy
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[2]));
    $product->field_color[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[3]));
    $product->field_hat_size[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;

    // Save it and retain a copy.
    commerce_product_save($product);
    $created_products[] = $product;
  }
}

/**
 * BatchAPI callback.
 *
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_example_shoes() {

  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('White', 'Black', 'Red', 'Blue', 'Purple');
  _commerce_kickstart_add_term($terms, $taxonomy->vid);

  $taxonomy = taxonomy_vocabulary_machine_name_load('shoe_size');
  // Add our terms
  $terms = array('5', '6', '7', '8', '9', '10', '11');
  _commerce_kickstart_add_term($terms, $taxonomy->vid, FALSE);

  _commerce_kickstart_add_view_mode('commerce_product', 'shoes', 'node_product_list');

  $created_products = array();
  $product_names = _commerce_kickstart_parse_csv('shoes.csv');

  foreach ($product_names as $sku => $item) {
    $images = $item[5];
    $product = _commerce_kickstart_create_product('shoes', $item[1], $item[0], $item[4] * 100);

    // Add the image
    _commerce_kickstart_add_product_images($product, $images);

    // Add the taxonomy
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[2]));
    $product->field_color[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
    // Add the taxonomy
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[3]));
    $product->field_shoe_size[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
    // Save it and retain a copy.
    commerce_product_save($product);
    $created_products[] = $product;
  }
}

/**
 * BatchAPI callback.
 *
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_example_tops() {

  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array(
    'White',
    'Black',
    'Gray',
    'Green',
    'Brown',
    'Heather Gray',
    'Purple',
    'Navy',
    'Tan'
  );
  _commerce_kickstart_add_term($terms, $taxonomy->vid);

  $taxonomy = taxonomy_vocabulary_machine_name_load('top_size');
  // Add our terms
  $terms = array('Small', 'Medium', 'Large');
  _commerce_kickstart_add_term($terms, $taxonomy->vid, FALSE);

  _commerce_kickstart_add_view_mode('commerce_product', 'tops', 'node_product_list');

  $created_products = array();
  $product_names = _commerce_kickstart_parse_csv('tops.csv');

  foreach ($product_names as $item) {
    $images = $item[5];
    $product = _commerce_kickstart_create_product('tops', $item[1], $item[0], $item[4] * 100);

    // Add the image
    _commerce_kickstart_add_product_images($product, $images);

    // Add the taxonomy
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[2]));
    $product->field_color[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[3]));
    $product->field_top_size[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;

    // Save it and retain a copy.
    commerce_product_save($product);
    $created_products[] = $product;
  }
}

/**
 * BatchAPI callback.
 *
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_example_storage_device() {

  $taxonomy = taxonomy_vocabulary_machine_name_load('storage_capacity');
  // Add our terms
  $terms = array('8MB', '16MB', '32MB');

  // Add terms inside.
  foreach ($terms as $term) {
    taxonomy_term_save((object) array(
      'name' => $term,
      'vid' => $taxonomy->vid,
    ));
  }

  _commerce_kickstart_add_view_mode('commerce_product', 'storage_devices', 'node_product_list');

  $created_products = array();
  $created_nodes = array();

  $product_names = _commerce_kickstart_parse_csv('storage_devices.csv');

  foreach ($product_names as $item) {
    $sku = $item['1'];
    $images = $item[5];

    $product = _commerce_kickstart_create_product('storage_devices', $sku, $item['0'], $item['4'] * 100);

    // Add the image
    _commerce_kickstart_add_product_images($product, $images);

    // Add the taxonomy
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item['3']));
    $product->field_storage_capacity[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;

    // Save it and retain a copy.
    commerce_product_save($product);
    $created_products[] = $product;
  }
}

/**
 * BatchAPI callback.
 *
 * @file commerce_kickstart_profile.
 * @see commerce_kickstart_import_product.
 */
function _commerce_kickstart_example_display() {

  $taxonomy = taxonomy_vocabulary_machine_name_load('collection');
  // Add our terms
  $terms = array(
    'To wear',
    'To carry',
    'To Drink',
    'To geek out'
  );
  _commerce_kickstart_add_term($terms, $taxonomy->vid, FALSE);

  $taxonomy = taxonomy_vocabulary_machine_name_load('category');
  // Add our terms
  $terms = array(
    'Tshirts',
    'Sweatshirts',
    'Hats',
    'Shoes',
    'Tote Bags',
    'Messenger Bags',
    'Laptop Bags',
    'Coffee Mugs',
    'Travel Mugs',
    'Water Bottles',
    'iPhone Cases',
    'USB Keys',
  );
  _commerce_kickstart_add_term($terms, $taxonomy->vid, FALSE);

  $taxonomy = taxonomy_vocabulary_machine_name_load('gender');
  // Add our terms
  $terms = array(
    'Men',
    'Unisex',
    'Women',
  );
  _commerce_kickstart_add_term($terms, $taxonomy->vid, FALSE);

  $taxonomy = taxonomy_vocabulary_machine_name_load('brand');
  // Add our terms
  $terms = array(
    'Simple Threads',
    'Made well',
    'Toppers',
    'Wonderknits',
    'Foursquare',
    'Acme gear',
    'Bits & Bots',
    'Courtsides',
  );
  _commerce_kickstart_add_term($terms, $taxonomy->vid, FALSE);

  $created_nodes = array();
  $product_display = _commerce_kickstart_parse_csv('product_display.csv');

  foreach ($product_display as $item) {

    // Create the new node.
    $node = (object) array('type' => 'product_display');
    node_object_prepare($node);

    $node->title = $item[0];
    $node->body[LANGUAGE_NONE][0]['value'] = $item[1];
    $node->uid = 1;
    $products_id = array();

    $skus = explode(', ', $item[6]);
    foreach ($skus as $sku) {
      $product = commerce_product_load_by_sku($sku);
      $node->field_product[LANGUAGE_NONE][]['product_id'] = $product->product_id;
    }
    // Add the collection.
    if (!empty($item['2'])) {
      $terms = explode(', ', $item['2']);
      foreach ($terms as $term) {
        $taxonomy_id = array_pop(taxonomy_get_term_by_name($term));
        $node->field_collection[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
      }
    }
    // Add the category.
    if (!empty($item['3'])) {
      $terms = explode(', ', $item['3']);
      foreach ($terms as $term) {
        $taxonomy_id = array_pop(taxonomy_get_term_by_name($term));
        $node->field_category[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
      }
    }
    // Add the gender.
    if (!empty($item['4'])) {
      $terms = explode(', ', $item['4']);
      foreach ($terms as $term) {
        $taxonomy_id = array_pop(taxonomy_get_term_by_name($term));
        $node->field_gender[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
      }
    }
    // Add the brand.
    if (!empty($item['5'])) {
      $taxonomy_id = array_pop(taxonomy_get_term_by_name($item['5']));
      if (!empty($taxonomy_id)) {
        $node->field_brand[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;
      }
    }
    // Make sure we set the default language
    $node->language = LANGUAGE_NONE;

    // Save it and retain a copy.
    node_save($node);
    $created_nodes[] = $node;
  }
}

/**
 * Helper function to quickly create a basic structure of a commerce product.
 *
 * @param $product_type
 * @param $sku
 * @param $product_title
 * @param $product_price
 * @return mixed
 */
function _commerce_kickstart_create_product($product_type, $sku, $product_title, $product_price) {
  // Create the new product.
  $product = commerce_product_new($product_type);
  $product->sku = $sku;
  $product->title = $product_title;
  $product->language = LANGUAGE_NONE;
  $product->uid = 1;

  // Set the price options
  if (variable_get('import_choosen_tax', 'us') == 'europe') {
    // Only add this is we use an "include tax". (ie. europe tax)
    $product->commerce_price[LANGUAGE_NONE][0]['data']['include_tax'] = 'sample_french_vat_tax';
  }
  $currency_code = variable_get('commerce_default_currency', 'USD');
  $product->commerce_price[LANGUAGE_NONE][0]['amount'] = $product_price;
  $product->commerce_price[LANGUAGE_NONE][0]['currency_code'] = $currency_code;

  return $product;
}

/**
 * Helper function to easily add images to a commerce product object
 *
 * @param $product
 *   The fully prepared product object that will get the images.
 * @param array $images
 *   An array containing the images' filenames.
 */
function _commerce_kickstart_add_product_images(&$product, $images) {
  if (isset($images) && !empty($images)) {
    $image_files = explode(', ', $images);
    foreach ($image_files as $image_file) {
      $file_temp = file_get_contents(drupal_get_path('profile', 'commerce_kickstart') . '/import/images/' . $image_file);
      $file_temp = file_save_data($file_temp, 'public://' . $image_file, FILE_EXISTS_REPLACE);
      $product->field_images[LANGUAGE_NONE][]['fid'] = $file_temp->fid;
    }
  }
}

/**
 * Helper function to add terms to a vocabulary.
 *
 * @param $terms
 *   Terms to add.
 * @param $vid
 *   The vid of the vocabulary to add terms in.
 * @param bool $check
 *   Set it to FALSE to bypass term exist test. Default to TRUE.
 */
function _commerce_kickstart_add_term($terms, $vid, $check = TRUE) {
  foreach($terms as $term) {
    $exist = FALSE;
    if ($check) {
      // Check if term already exist.
      $exist = (bool) array_pop(taxonomy_get_term_by_name($term));
    }

    // Add term inside vocabulary.
    if (!$exist) {
      taxonomy_term_save((object) array(
        'name' => $term,
        'vid' => $vid,
      ));
    }
  }
}

/**
 * Helper function to enable a view mode on a bundle.
 *
 * @param $entity_type
 *   Entity type name.
 * @param $bundle
 *   Bundle name.
 * @param $view_mode_name
 *   View mode name.
 */
function _commerce_kickstart_add_view_mode($entity_type, $bundle, $view_mode_name) {
  module_load_include('inc', 'field_ui', 'field_ui.admin');
  $bundle_settings = field_bundle_settings($entity_type, $bundle);
  _field_ui_add_default_view_mode_settings($entity_type, $bundle, $view_mode_name, $bundle_settings);
  $bundle_settings['view_modes'][$view_mode_name]['custom_settings'] = TRUE;
  field_bundle_settings($entity_type, $bundle, $bundle_settings);
}
