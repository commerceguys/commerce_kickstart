<?php

function _commerce_kickstart_example_display() {


  $created_products = array();
  $created_nodes = array();

  $lorem = 'Lorem ipsum dolor sit amet, consectetuer adipiscing elit . Sed eu dui . Phasellus eget orci volutpat sem accumsan condimentum . Etiam lobortis facilisis sem . Aliquam pede erat, sagittis sed, bibendum ac, consequat sed, arcu . Fusce placerat bibendum risus . Maecenas semper adipiscing purus . Lorem ipsum dolor sit amet, consectetuer adipiscing elit . Vestibulum eget leo . Suspendisse nonummy dolor in pede ullamcorper venenatis . Vivamus sapien .';
  // First create products if specified.
  $product_names = array(
     array('title' => 'Tshirt 1',
       'description' => 'Product Description for Tshirt 1 -' . $lorem,
       'collection' => 'To wear',
       'category' => 'Tshirts',
       'gender' => 'Men',
       'brand' => 'Simple Threads',
       'sku' => 'TSH1-WHT-SM, TSH1-WHT-MD, TSH1-WHT-LG, TSH1-BLK-SM, TSH1-BLK-MD, TSH1-BLK-LG, TSH1-GRY-SM, TSH1-GRY-MD, TSH1-GRY-LG'),
    array('title' => 'Tshirt 2',
      'description' => 'Product Description for Tshirt 2 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Tshirts',
      'gender' => 'Men',
      'brand' => 'Simple Threads',
      'sku' => 'TSH2-TAN-SM, TSH2-TAN-MD, TSH2-TAN-LG, TSH2-GRN-SM, TSH2-GRN-MD, TSH2-GRN-LG, TSH2-BWN-SM, TSH2-BWN-MD, TSH2-BWN-LG'),
    array('title' => 'Tshirt 3',
      'description' => 'Product Description for Tshirt 3 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Tshirts',
      'gender' => 'Men',
      'brand' => 'Made well',
      'sku' => 'TSH3-WHT-SM, TSH3-WHT-MD, TSH3-WHT-LG, TSH3-HGY-SM, TSH3-HGY-MD, TSH3-HGY-LG, TSH3-PRL-SM, TSH3-PRL-MD, TSH3-PRL-LG'),
    array('title' => 'Tshirt 4',
      'description' => 'Product Description for Tshirt 4 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Tshirts',
      'gender' => 'Men',
      'brand' => 'Made well',
      'sku' => 'TSH4-WHT-SM, TSH4-WHT-MD, TSH4-WHT-LG, TSH4-BLK-SM, TSH4-BLK-MD, TSH4-BLK-LG'),
    array('title' => 'Tshirt 5',
      'description' => 'Product Description for Tshirt 5 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Tshirts',
      'gender' => 'Women',
      'brand' => 'Simple Threads',
      'sku' => 'TSH5-WHT-SM, TSH5-WHT-MD, TSH5-WHT-LG, TSH5-BLK-SM, TSH5-BLK-MD, TSH5-BLK-LG'),
    array('title' => 'Tshirt 6',
      'description' => 'Product Description for Tshirt 6 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Tshirts',
      'gender' => 'Women',
      'brand' => 'Simple Threads',
      'sku' => 'TSH6-WHT-SM, TSH6-WHT-MD, TSH6-WHT-LG, TSH6-GRY-SM, TSH6-GRY-MD, TSH6-GRY-LG'),

    array('title' => 'Sweatshirt 1',
      'description' => 'Product Description for Sweatshirt 1 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Sweatshirts',
      'gender' => 'Unisex',
      'brand' => 'Made well',
      'sku' => 'SWT1-BLK-SM, SWT1-BLK-MD, SWT1-BLK-LG, SWT1-GRY-SM, SWT1-GRY-MD, SWT1-GRY-LG'),
    array('title' => 'Sweatshirt 2',
      'description' => 'Product Description for Sweatshirt 2 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Sweatshirts',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'SWT2-BLK-SM, SWT2-BLK-MD, SWT2-BLK-LG'),

    array('title' => 'Hat 1',
      'description' => 'Product Description for Hat 1 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Hats',
      'gender' => 'Men',
      'brand' => 'Simple Threads',
      'sku' => 'HAT1-BLK-SM, HAT1-BLK-MD, HAT1-BLK-LG, HAT1-WHT-SM, HAT1-WHT-MD, HAT1-WHT-LG'),
    array('title' => 'Hat 2',
      'description' => 'Product Description for Hat 2 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Hats',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'HAT2-BLK-OS, HAT2-NVY-OS'),

    array('title' => 'Shoe 1',
      'description' => 'Product Description for Shoe 1 -' . $lorem,
      'collection' => 'To wear',
      'category' => 'Shoes',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'SHO1-BLK-05, SHO1-BLK-06, SHO1-BLK-07, SHO1-BLK-08, SHO1-BLK-09, SHO1-BLK-10, SHO1-BLK-11, SHO1-WHT-05, SHO1-WHT-06, SHO1-WHT-07, SHO1-WHT-08, SHO1-WHT-09, SHO1-WHT-10, SHO1-WHT-11, SHO1-BLU-05, SHO1-BLU-06, SHO1-BLU-07, SHO1-BLU-08, SHO1-BLU-09, SHO1-BLU-10, SHO1-BLU-11, SHO1-RED-05, SHO1-RED-06, SHO1-RED-07, SHO1-RED-08, SHO1-RED-09, SHO1-RED-10, SHO1-RED-11, SHO1-PRL-05, SHO1-PRL-06, SHO1-PRL-07, SHO1-PRL-08, SHO1-PRL-09, SHO1-PRL-10, SHO1-PRL-11'),

    array('title' => 'Messenger Bag 1',
      'description' => 'Product Description for Messenger Bag 1 -' . $lorem,
      'collection' => 'To carry',
      'category' => 'Messenger Bags',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'MES1-RED-OS'),

    array('title' => 'Laptop Bag 1',
      'description' => 'Product Description for Laptop Bag 1 -' . $lorem,
      'collection' => 'To carry',
      'category' => 'Laptop Bags',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'LAP1-BLK-13, LAP1-BLK-15, LAP1-BLK-17'),

    array('title' => 'Coffee Mug 1',
      'description' => 'Product Description for Coffee Mug 1 -' . $lorem,
      'collection' => 'To carry',
      'category' => 'Coffee Mugs',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'CMG-WHT-OS, CMG-BLK-OS'),

    array('title' => 'Travel Mug 1',
      'description' => 'Product Description for Travel Mug 1 -' . $lorem,
      'collection' => 'To carry',
      'category' => 'Travel Mugs',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'TMG-RED-OS'),

    array('title' => 'Water Bottle 1',
      'description' => 'Product Description for Water Bottle 1 -' . $lorem,
      'collection' => 'To carry',
      'category' => 'Water Bottles',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'WTR-BLU-OS'),

    array('title' => 'iPhone Case 1',
      'description' => 'Product Description for iPhone Case 1 -' . $lorem,
      'collection' => 'To geek out',
      'category' => 'iPhone Cases',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'IPH1-BLK-OS'),

    array('title' => 'Storage 1',
      'description' => 'Product Description for Storage 1 -' . $lorem,
      'collection' => 'To geek out',
      'category' => 'USB Keys',
      'gender' => 'Unisex',
      'brand' => 'Simple Threads',
      'sku' => 'USB-GRY-08, USB-GRY-16, USB-GRY-32'),
  );


  foreach ($product_names as $item) {

    // Create the new node.
    $node = (object)array('type' => 'product_display');
    node_object_prepare($node);
    $node->title = $item['title'];
    $node->uid = 1;

    $products_id = array();
    $skus = explode(', ', $item['sku']);

    foreach($skus as $sku) {
      $product = commerce_product_load_by_sku($sku);
      $node->field_product[LANGUAGE_NONE][]['product_id'] = $product->product_id;;

    }

    // Make sure we set the default language
    $node->language = LANGUAGE_NONE;

    // Save it and retain a copy.
    node_save($node);
    $created_nodes[] = $node;
  }
}
