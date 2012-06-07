<?php

/**
 * Implements hook_views_data_alter().
 */
function commerce_backoffice_views_data_alter(&$data) {
  $data['message']['type_category'] = array(
    'title' => 'Message category',
    'help' => 'Filter messages per a message type category.',
    'filter' => array(
      'handler' => 'commerce_backoffice_handler_filter_message_type',
      'real field' => 'type',
    )
  );

  $data['message']['add'] = array(
    'title' => t('Add new message'),
    'help' => t('Display a form to add a new message.'),
    'area' => array(
      'handler' => 'commerce_backoffice_handler_area_add_message',
    ),
  );

  $data['commerce_order']['operations_dropbutton'] = array(
    'field' => array(
      'title' => t('Operations links (Dropbutton)'),
      'help' => t('Display the available operations links for the order in a dropbutton.'),
      'handler' => 'commerce_backoffice_handler_field_order_operations',
    ),
  );
  $data['node']['operations_dropbutton'] = array(
    'field' => array(
      'title' => t('Operations links (Dropbutton)'),
      'help' => t('Display the available operations links for the node in a dropbutton.'),
      'handler' => 'commerce_backoffice_handler_field_node_operations',
    ),
  );
}
