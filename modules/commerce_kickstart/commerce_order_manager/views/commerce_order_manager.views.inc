<?php

function commerce_order_manager_views_data_alter(&$data) {
  $data['message']['type_category'] = array(
    'title' => 'Message category',
    'help' => 'Filter messages per a message type category.',
    'filter' => array(
      'handler' => 'commerce_order_manager_views_filter_type',
      'real field' => 'type',
    )
  );

  $data['message']['add'] = array(
    'title' => t('Add new message'),
    'help' => t('Display a form to add a new message.'),
    'area' => array(
      'handler' => 'commerce_order_manager_area_add_message',
    ),
  );

  $data['commerce_order']['operations_dropbutton'] = array(
    'field' => array(
      'title' => t('Operations links (Dropbutton)'),
      'help' => t('Display the available operations links for the order in a dropbutton.'),
      'handler' => 'commerce_order_manager_handler_field_order_operations',
    ),
  );
}
