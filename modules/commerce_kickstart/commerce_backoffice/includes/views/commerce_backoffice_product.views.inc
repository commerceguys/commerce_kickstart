<?php

/**
 * Implements hook_views_data_alter().
 */
function commerce_backoffice_product_views_data_alter(&$data) {
  $data['commerce_product']['quick_edit_form'] = array(
    'field' => array(
      'title' => t('Quick Edit Form'),
      'help' => t('Display a form for editing the price and status of a variation.'),
      'handler' => 'commerce_backoffice_product_handler_field_product_quick_edit_form',
    ),
  );
  $data['views_entity_node']['operations_dropbutton'] = array(
    'field' => array(
      'title' => t('Operations links (Dropbutton)'),
      'help' => t('Display the available operations links for the node in a dropbutton.'),
      'handler' => 'commerce_backoffice_product_handler_field_node_operations',
    ),
  );
  $data['node']['term_node_tid_multiple_vocabularies'] = array(
    'title' => 'Has taxonomy terms (from Multiple Vocabularies)',
    'help' => 'Display content if it has the selected taxonomy terms from Multiple Vocabularies. It has an option to work as independent filters per vocabulary.',
    'real field' => 'nid',
    'filter' => array(
      'handler' => 'views_handler_filter_term_node_tid_multiple_vocabularies',
      'allow empty' => TRUE,
      )
  );
  $data['node']['product_display_term_node_tid'] = array(
    'title' => 'Product Display Has taxonomy terms (from Multiple Vocabularies)',
    'help' => 'Display content if it has the selected taxonomy terms from Multiple Vocabularies, for Product displays content types ONLY. It has an option to work as independent filters per vocabulary.',
    'real field' => 'nid',
    'filter' => array(
      'handler' => 'commerce_backoffice_handler_filter_product_display_term_node_tid',
      'allow empty' => TRUE,
      )
  );
}
