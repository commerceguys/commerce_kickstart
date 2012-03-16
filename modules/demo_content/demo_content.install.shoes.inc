<?php

function _commerce_kickstart_example_shoes() {
  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('White', 'Black', 'Red', 'Blue', 'Purple');

  // Add terms inside.
  foreach ($terms as $term) {
    if (!array_pop(taxonomy_get_term_by_name($term))) {
      taxonomy_term_save((object)array(
        'name' => $term,
        'vid' => $taxonomy->vid,
      ));
    }
  }
  $taxonomy = taxonomy_vocabulary_machine_name_load('shoe_size');
  // Add our terms
  $terms = array('5', '6', '7', '8', '9', '10', '11');

  // Add terms inside.
  foreach ($terms as $term) {
    if (!array_pop(taxonomy_get_term_by_name($term))) {
      taxonomy_term_save((object)array(
        'name' => $term,
        'vid' => $taxonomy->vid,
      ));
    }
  }

  $created_products = array();
  $created_nodes = array();

  $product_names = _kickstart_parse_csv('shoes.csv');

  foreach ($product_names as $sku => $item) {
    $images = $item[5];
    $product = _kickstart_create_product('shoes', $item[1], $item[0], $item[4] * 100);

    // Add the image
    if (isset($images) && !empty($images)) {
      $image_files = explode(', ', $images);
      foreach ($image_files as $image_file) {
        $file_temp = file_get_contents(drupal_get_path('module', 'demo_content') . '/images/' . $image_file);
        $file_temp = file_save_data($file_temp, 'public://' . $image_file, FILE_EXISTS_REPLACE);
        $product->field_image[LANGUAGE_NONE][]['fid'] = $file_temp->fid;
      }
    }

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
