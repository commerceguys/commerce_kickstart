<?php

function _commerce_kickstart_example_drinks() {
  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('White', 'Black', 'Red', 'Blue');

  // Add terms inside.
  foreach ($terms as $term) {
    taxonomy_term_save((object)array(
      'name' => $term,
      'vid' => $taxonomy->vid,
    ));
  }

  $created_products = array();
  $created_nodes = array();

  $product_names = _kickstart_parse_csv('drinks.csv');

  foreach ($product_names as $sku => $item) {
    $product = _kickstart_create_product('drinks', $item[1], $item[0], $item[3] * 100);

    // Add the taxonomy
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item[2]));
    $product->field_color[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;

    // Save it and retain a copy.
    commerce_product_save($product);
    $created_products[] = $product;

    }
}
