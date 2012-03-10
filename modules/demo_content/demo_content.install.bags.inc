<?php

function _commerce_kickstart_example_bags() {
  $taxonomy = taxonomy_vocabulary_machine_name_load('color');
  // Add our terms
  $terms = array('Natural', 'Red', 'Black');

  // Add terms inside.
  foreach ($terms as $term) {
    if (!array_pop(taxonomy_get_term_by_name($term))) {
      taxonomy_term_save((object)array(
        'name' => $term,
        'vid' => $taxonomy->vid,
      ));
    }
  }

  $taxonomy = taxonomy_vocabulary_machine_name_load('bag_size');
  // Add our terms
  $terms = array('One size', '13"', '15"', '17"');

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

  $product_names = _kickstart_parse_csv('bags_cases.csv');
  commerce_product_configure_product_type('bags_cases');

  foreach ($product_names as $item) {
    $product = _kickstart_create_product('bags_cases', $item[1], $item[0], $item[4] * 100);

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
