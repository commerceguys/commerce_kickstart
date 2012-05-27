<?php

/**
 * Implements hook_views_data_alter().
 */
function commerce_kickstart_content_ui_views_data_alter(&$data) {
  $data['node']['product_display'] = array(
    'title' => t('Product Display type'),
    'help' => t('Whether or not the content is one of product displays.'),
    'real field' => 'type',
    'filter' => array(
      'handler' => 'views_handler_filter_product_type',
    ),
  );
}
