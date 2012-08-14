<?php

/**
 * Implements hook_views_data_alter().
 */
function commerce_backoffice_order_views_data_alter(&$data) {
  $data['message']['add'] = array(
    'title' => t('Add new message'),
    'help' => t('Display a form to add a new message.'),
    'area' => array(
      'handler' => 'commerce_backoffice_order_handler_area_add_message',
    ),
  );
  $data['views_entity_commerce_order']['operations_dropbutton'] = array(
    'field' => array(
      'title' => t('Operations links (Dropbutton)'),
      'help' => t('Display the available operations links for the order in a dropbutton.'),
      'handler' => 'commerce_backoffice_order_handler_field_order_operations',
    ),
  );
}
