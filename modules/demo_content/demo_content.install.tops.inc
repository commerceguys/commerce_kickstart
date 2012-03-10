<?php

function _commerce_kickstart_example_tops() {
  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('White', 'Black', 'Gray', 'Green', 'Brown', 'Heather Gray', 'Purple', 'Navy', 'Tan');

  // Add terms inside.
  foreach ($terms as $term) {
    if (!array_pop(taxonomy_get_term_by_name($term))) {
      taxonomy_term_save((object)array(
        'name' => $term,
        'vid' => $taxonomy->vid,
      ));
    }
  }

  $taxonomy = taxonomy_vocabulary_machine_name_load('top_size');
    // Add our terms
    $terms = array('Small', 'Medium', 'Large');

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

  $product_names = _kickstart_parse_csv('tops.csv');

  foreach ($product_names as $item) {
    $product = _kickstart_create_product('tops', $item[1], $item[0], $item[4] * 100);

    // Add the image
//    if(isset($item[5]) && !empty($item[5])) {
//      $file_temp = file_get_contents(drupal_get_path('module', 'demo_content') . '/images/' . $item[5]);
//      $file_temp = file_save_data($file_temp, 'public://' . $item[5], FILE_EXISTS_REPLACE);
//      $product->field_image[LANGUAGE_NONE][]['fid'] = $file_temp->fid;
//    }

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
