<?php

function commerce_product_manager_views_data_alter(&$data) {
  $data['node']['operations_dropbutton'] = array(
    'field' => array(
      'title' => t('Operations links (Dropbutton)'),
      'help' => t('Display the available operations links for the node in a dropbutton.'),
      'handler' => 'commerce_product_manager_handler_field_node_operations',
    ),
  );
}
