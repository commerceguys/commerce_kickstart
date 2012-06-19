<?php

/**
 * @file commerce_kickstart_profile.
 */

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_product()
 */
function _commerce_kickstart_example_nodes($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  $body1  = "<p>Nunc tempor, sapien sed rhoncus vulputate, lectus felis scelerisque dolor, vitae interdum ipsum quam vitae purus.
  Maecenas neque. Donec semper imperdiet libero. Nulla facilisi. Mauris in velit eu nisl dapibus interdum. Fusce vulputate tellus nec risus.</p>";
  $body1 .= "<p>Proin nec metus. Pellentesque mollis, erat non hendrerit tincidunt.</p>";

  $body2  = "<p>Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Sed eu dui.
  Phasellus eget orci volutpat sem accumsan condimentum. Etiam lobortis facilisis sem.
  Aliquam pede erat, sagittis sed, bibendum ac, consequat sed, arcu. Fusce placerat bibendum risus.
  Maecenas semper adipiscing purus. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Vestibulum eget leo.
  Suspendisse nonummy dolor in pede ullamcorper venenatis. Vivamus sapien. Vivamus ante quam, tristique quis, porttitor nec, viverra eget, ante.
  Nulla vitae nunc vel est dignissim dictum. Suspendisse feugiat pellentesque ante.
  Etiam viverra commodo neque. Aenean id mi. Sed lacinia tincidunt purus.
  Maecenas eros quam, feugiat quis, feugiat vel, rutrum in, sem. Pellentesque eu ipsum.
  Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos hymenaeos. Vestibulum mollis molestie elit.</p>";
  $body2 .= "<p>Nunc vulputate ligula a quam. Praesent nec justo. Maecenas vulputate porttitor ipsum. Proin semper turpis quis orci scelerisque congue.
  Sed sit amet ipsum eu augue tempor sollicitudin. Praesent eu velit eu pede tincidunt sagittis. Proin tortor erat, bibendum id, tempor vitae, blandit sit amet, tortor.
  Curabitur tincidunt nisi blandit pede. Pellentesque mi ligula, iaculis sit amet, scelerisque nec, lacinia in, nulla. Nunc in elit nec risus feugiat posuere.
  Duis vitae est. Quisque convallis convallis leo. Vivamus molestie vehicula dui. Donec vulputate, ipsum in porttitor condimentum, nunc felis pellentesque sem,
  interdum pharetra risus sapien eu urna. Morbi nisl. Quisque odio lorem, iaculis vitae, commodo eu, vestibulum elementum, est.
  Etiam tempus cursus risus. Integer luctus dapibus lorem.</p><p>Sed lectus dui, bibendum et, eleifend id, aliquet ac, nulla. Morbi sed lacus nec ipsum sagittis facilisis.
  Sed id nulla nec augue interdum porttitor. Phasellus varius posuere justo. Nunc et est eu metus pharetra posuere. Ut sit amet orci ut nibh aliquet accumsan.
  Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Sed fermentum, velit at porttitor sollicitudin, pede massa feugiat enim, eget volutpat felis leo ut lacus.
  Vestibulum orci orci, gravida eu, scelerisque sit amet, aliquet euismod, ante. Duis nonummy. Sed placerat dolor. Vivamus tempor sapien sit amet felis.</p><p>Nam viverra eleifend metus. Nulla tortor nisl, faucibus ut, convallis eget, malesuada et, velit. Nulla scelerisque molestie enim. Curabitur et orci. Proin mauris neque, laoreet eu, iaculis dapibus, euismod sed, tellus. Aenean viverra quam eu magna. Morbi porttitor semper sem. Fusce a ipsum eu dolor ultrices placerat. Integer nec velit non nulla dictum aliquet. Aenean lorem velit, tincidunt non, auctor at, blandit tristique, ligula. Fusce at nisl in sapien porttitor convallis. Cras lacus. Morbi nec libero a sapien facilisis fringilla. Nulla porta. Praesent at ligula. Aenean erat mauris, nonummy nec, fermentum sit amet, porta ac, magna. Mauris vestibulum. Mauris ut arcu id urna ornare malesuada. Aliquam ut sapien quis nisi rutrum mollis. Aliquam lacus arcu, ultricies a, dignissim vitae, faucibus in, sapien.</p>";
  $body2 .= "<p>Nunc tempor, sapien sed rhoncus vulputate, lectus felis scelerisque dolor, vitae interdum ipsum quam vitae purus. Maecenas neque. Donec semper imperdiet libero. Nulla facilisi. Mauris in velit eu nisl dapibus interdum. Fusce vulputate tellus nec risus.</p>";
  $body2 .= "<p>Proin nec metus. Pellentesque mollis, erat non hendrerit tincidunt.</p>";
  $body2 .= "<p>Massa est egestas est, at laoreet dolor mi at purus. Vivamus dictum, metus in varius dictum, ipsum mi sodales tellus, in egestas lacus metus et enim. Phasellus rhoncus nisl at metus. Ut lobortis cursus velit. Sed risus. Curabitur sed orci nec nibh gravida hendrerit. Phasellus laoreet. Morbi blandit porta orci. Morbi turpis justo, egestas vel, sodales ac, pretium ut, tellus. Aliquam erat volutpat. Curabitur nibh. Nulla facilisi. Proin erat.</p>";

  $body3 = "<p>Proin nec metus. Pellentesque mollis, erat non hendrerit tincidunt.</p>
  <p>Massa est egestas est, at laoreet dolor mi at purus. Vivamus dictum, metus in varius dictum, ipsum mi sodales tellus,
  in egestas lacus metus et enim. Phasellus rhoncus nisl at metus. Ut lobortis cursus velit. Sed risus.
  Curabitur sed orci nec nibh gravida hendrerit. Phasellus laoreet. Morbi blandit porta orci. Morbi turpis justo,
  egestas vel, sodales ac, pretium ut, tellus. Aliquam erat volutpat. Curabitur nibh. Nulla facilisi. Proin erat.</p>";

  // Here we set nid to be able to rely on it when exporting menu links in features.
  $contents[] = array(
    'title' => 'Contact',
    'body' => $body1,
    'nid' => '1',
    'path' => 'contact-us',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => 'About',
    'body' => $body1,
    'nid' => '2',
    'path' => 'about-us',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => 'Terms of Use',
    'body' => $body2,
    'nid' => '3',
    'path' => 'terms-of-use',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => 'Payment',
    'body' => $body2,
    'nid' => '4',
    'path' => 'payment',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => 'Shipping fees',
    'body' => $body3,
    'nid' => '5',
    'path' => 'shipping-fees',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => 'Press links',
    'body' => $body1,
    'nid' => '6',
    'path' => 'press-links',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => 'Service agreements',
    'body' => $body2,
    'nid' => '7',
    'path' => 'service-agreements',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => 'Our security policy',
    'body' => $body3,
    'nid' => '8',
    'path' => 'our-security-policy',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => '403 error',
    'body' => 'Access denied',
    'nid' => '9',
    'path' => '403-error',
    'type' => 'page',
  );
  $contents[] = array(
    'title' => '404 error',
    'body' => 'Not found',
    'nid' => '10',
    'path' => '404-error',
    'type' => 'page',
  );
  foreach ($contents as &$content) {
    _commerce_kickstart_custom_create_content($content);
  }

  $vocabulary = taxonomy_vocabulary_machine_name_load('tags');
  $terms['tag1'] = (object) array(
    'name' => 'Tag 1',
    'vid' => $vocabulary->vid,
  );
  $terms['tag2'] = (object) array(
    'name' => 'Tag 2',
    'vid' => $vocabulary->vid,
  );
  $terms['tag3'] = (object) array(
    'name' => 'Tag 3',
    'vid' => $vocabulary->vid,
  );
  foreach($terms as $term) {
    taxonomy_term_save($term);
  }

  $contents[] = array(
    'title' => "Ad push 1",
    'tagline' => "Your going thirsty",
    'link' => 'collection/drink',
    'type' => 'ad_push',
    'image' => 'ad-push-1.jpg',
  );
  $contents[] = array(
    'title' => "Ad push 2",
    'tagline' => 'Forget the Trees... Hug a Super Model.',
    'link' => 'collection/wear',
    'type' => 'ad_push',
    'image' => 'ad-push-2.jpg',
  );
  $contents[] = array(
    'title' => "Ad push 3",
    'tagline' => "Exclusive Limited Edition Print from Zoo York Available NOW!",
    'link' => 'collection/geek-out',
    'type' => 'ad_push',
    'image' => 'ad-push-3.jpg',
  );
  $contents[] = array(
    'title' => "Blog",
    'body' => "Guess Who's been Rocking our Tees at Winbleton ?",
    'type' => 'blog_post',
    'image' => 'blog-1.jpg',
  );
  $contents[] = array(
    'title' => "Blog post 2",
    'body' => $body1,
    'type' => 'blog_post',
    'image' => 'blog-2.jpg',
  );
  $contents[] = array(
    'title' => "Blog post 3",
    'body' => $body1,
    'type' => 'blog_post',
    'image' => 'blog-3.jpg',
  );
  $contents[] = array(
    'title' => "The latest & greatest what's new",
    'headline' => "What's News",
    'tagline' => "The latest & greatest",
    'link' => 'collection/wear',
    'type' => 'slideshow',
    'image' => 'slideshow-1.jpg',
  );
  $contents[] = array(
    'title' => "get it quick because... it's hot",
    'headline' => "It's hot",
    'tagline' => "get it quick because...",
    'link' => 'products',
    'type' => 'slideshow',
    'image' => 'slideshow-2.jpg',
  );
  $contents[] = array(
    'title' => "Go with one of our staff picks",
    'headline' => "Staff Picks",
    'tagline' => "Go with one of our",
    'link' => 'about-us',
    'type' => 'slideshow',
    'image' => 'slideshow-3.jpg',
  );
  foreach ($contents as &$content) {
    _commerce_kickstart_custom_create_content($content);
  }
  features_rebuild();
  variable_set('menu_rebuild_needed', TRUE);
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_product()
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
  variable_del('commerce_kickstart_example_content');
  variable_del('commerce_kickstart_choose_tax_country');
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_product()
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

  $vocabulary = taxonomy_vocabulary_machine_name_load('collection');

  $terms = array(
    array('To wear', 'collection-banner-to_wear.jpg'),
    array('To carry', 'collection-banner-to_carry.jpg'),
    array('To drink with', 'collection-banner-to_drink_with.jpg'),
    array('To geek out', 'collection-banner-to_geek_out.jpg'),
  );
  foreach($terms as $term) {
    _commerce_kickstart_add_term($term[0], $vocabulary, FALSE, NULL, $term[1]);
  }
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_product()
 */
function _commerce_kickstart_import_example_products($operation, $type, &$context) {
  $context['message'] = t('@operation', array('@operation' => $type));
  $migration =  Migration::getInstance($operation);
  $migration->processImport();
}

/**
 * BatchAPI callback.
 *
 * @see commerce_kickstart_import_product()
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
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample billing address 1';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'US';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = '16 Hampton Ct';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = 'Visalia';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['administrative_area'] = 'CA';
  $billing_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = '93277-8329';
  commerce_customer_profile_save($billing_profile);
  commerce_addressbook_set_default_profile($billing_profile);

  // Create two shipping customer profile samples.
  $shipping_profile = commerce_customer_profile_new('shipping', $user->uid);
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample shipping address 1';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'US';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = '2843 Sherman Ave';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = 'Camden';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['administrative_area'] = 'NJ';
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = '08105-442';
  commerce_customer_profile_save($shipping_profile);
  commerce_addressbook_set_default_profile($shipping_profile);

  $shipping_profile = commerce_customer_profile_new('shipping', $user->uid);
  $shipping_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = 'Sample shipping address 2';
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
 * @see commerce_kickstart_import_product()
 */
function _commerce_kickstart_post_enable_modules($operation, &$context) {
  $context['message'] = t('@operation', array('@operation' => $operation));

  module_enable(array('commerce_kickstart_content'));
  features_rebuild();
  drupal_static_reset();
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
 * @param $name
 *   Term name.
 * @param $vocabulary
 *   The vocabulary to add terms in.
 * @param bool $check
 *   Set it to FALSE to bypass term exist test. Default to TRUE.
 * @param $color
 *   Hexadecimal color code.
 * @param $image
 *   Name of the image file which should be localte in import/images.
 */
function _commerce_kickstart_add_term($name, $vocabulary, $check = TRUE, $color = NULL, $image = NULL, $weight = NULL) {
  $exist = FALSE;
  if ($check) {
    // Check if term already exist.
    $exist = (bool) array_pop(taxonomy_get_term_by_name($name));
  }

  // Add term inside vocabulary.
  if (!$exist) {
    $term = new stdClass();
    $term->name = $name;
    $term->vid = $vocabulary->vid;
    if (isset($weight)) {
      $term->weight = $weight;
    }

    $instance = field_info_instance('taxonomy_term', 'field_category_color', $vocabulary->machine_name);
    if(!empty($instance) && isset($color)) {
      $term->field_category_color[LANGUAGE_NONE][]['value'] = $color;
    }
   $instance = field_info_instance('taxonomy_term', 'field_image', $vocabulary->machine_name);
    if(!empty($instance) && isset($image)) {
      $file_temp = file_get_contents(drupal_get_path('profile', 'commerce_kickstart') . '/import/images/' . $image);
      $file_temp = file_save_data($file_temp, 'public://' . $image, FILE_EXISTS_REPLACE);
      $term->field_image[LANGUAGE_NONE][]['fid'] = $file_temp->fid;
    }
    taxonomy_term_save($term);
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
    $product = $products[$products_key[rand(1, $products_number)]];
    $line_item = commerce_product_line_item_new($product, 1, $order->order_id);
    commerce_line_item_save($line_item);
    $line_items[] = array('line_item_id' => $line_item->line_item_id);
  }
  $order->commerce_line_items[LANGUAGE_NONE] = $line_items;
  commerce_order_save($order);
}
