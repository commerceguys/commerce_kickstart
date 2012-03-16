<?php

function _commerce_kickstart_example_storage_device() {
  $taxonomy = taxonomy_vocabulary_machine_name_load('storage_capacity');
  // Add our terms
  $terms = array('8MB', '16MB', '32MB');

  // Add terms inside.
  foreach ($terms as $term) {
    taxonomy_term_save((object)array(
      'name' => $term,
      'vid' => $taxonomy->vid,
    ));
  }


  $created_products = array();
  $created_nodes = array();

  $product_names = _kickstart_parse_csv('storage_devices.csv');

  foreach ($product_names as $item) {
    $sku = $item['1'];
    $images = $item[5];

    $product = _kickstart_create_product('storage_devices', $sku, $item['0'], $item['4'] * 100);

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
    $taxonomy_id = array_pop(taxonomy_get_term_by_name($item['3']));
    $product->field_storage_capacity[LANGUAGE_NONE][]['tid'] = $taxonomy_id->tid;

    // Save it and retain a copy.
    commerce_product_save($product);
    $created_products[] = $product;


  }
}
