<?php

function _commerce_kickstart_example_hats() {
  $taxonomy = taxonomy_vocabulary_machine_name_load('hat_size');
  // Add our terms
  $terms = array('Small', 'Medium', 'Large', 'One Size');

  // Add terms inside.
  foreach ($terms as $term) {
    if (!array_pop(taxonomy_get_term_by_name($term))) {
      taxonomy_term_save((object)array(
        'name' => $term,
        'vid' => $taxonomy->vid,
      ));
    }
  }

  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('Black', 'White', 'Navy');

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

  $product_names = _kickstart_parse_csv('hats.csv');

  foreach ($product_names as $sku => $item) {
    $product = _kickstart_create_product('hats', $item[1], $item[0], $item[4] * 100);


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
