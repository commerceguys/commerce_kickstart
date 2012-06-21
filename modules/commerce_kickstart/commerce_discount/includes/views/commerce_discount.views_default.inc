<?php

/**
 * @file
 * Views defaults for Commerce discount module.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_discount_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'commerce_discount_overview';
  $view->description = 'Display a list of discounts for store admin.';
  $view->tag = 'default';
  $view->base_table = 'commerce_discount';
  $view->human_name = 'Discounts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'discount_id' => 'discount_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'discount_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No discounts found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Commerce Discount: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'commerce_discount';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Discount';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<span>[type]</span>';
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Commerce Discount: Rendered Commerce Discount */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_commerce_discount';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = 'Offer';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  /* Field: Commerce Discount: Enable / Disable */
  $handler->display->display_options['fields']['enable_disable']['id'] = 'enable_disable';
  $handler->display->display_options['fields']['enable_disable']['table'] = 'commerce_discount';
  $handler->display->display_options['fields']['enable_disable']['field'] = 'enable_disable';
  $handler->display->display_options['fields']['enable_disable']['label'] = 'Status';
  $handler->display->display_options['fields']['enable_disable']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['external'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['enable_disable']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['enable_disable']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['enable_disable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['enable_disable']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['enable_disable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['enable_disable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['enable_disable']['empty_zero'] = 0;
  $handler->display->display_options['fields']['enable_disable']['hide_alter_empty'] = 1;
  /* Field: Commerce Discount: Operations */
  $handler->display->display_options['fields']['operations_dropbutton']['id'] = 'operations_dropbutton';
  $handler->display->display_options['fields']['operations_dropbutton']['table'] = 'commerce_discount';
  $handler->display->display_options['fields']['operations_dropbutton']['field'] = 'operations_dropbutton';
  /* Filter criterion: Commerce Discount: Discount offer reference (commerce_discount_offer) */
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['id'] = 'commerce_discount_offer_target_id';
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['table'] = 'field_data_commerce_discount_offer';
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['field'] = 'commerce_discount_offer_target_id';
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['group'] = 1;
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['expose']['operator_id'] = 'commerce_discount_offer_target_id_op';
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['expose']['label'] = 'Offer';
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['expose']['operator'] = 'commerce_discount_offer_target_id_op';
  $handler->display->display_options['filters']['commerce_discount_offer_target_id']['expose']['identifier'] = 'commerce_discount_offer_target_id';
  /* Filter criterion: Commerce Discount: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_discount';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Commerce Discount: Enabled */
  $handler->display->display_options['filters']['enabled']['id'] = 'enabled';
  $handler->display->display_options['filters']['enabled']['table'] = 'commerce_discount';
  $handler->display->display_options['filters']['enabled']['field'] = 'enabled';
  $handler->display->display_options['filters']['enabled']['value'] = 'All';
  $handler->display->display_options['filters']['enabled']['group'] = 1;
  $handler->display->display_options['filters']['enabled']['exposed'] = TRUE;
  $handler->display->display_options['filters']['enabled']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['enabled']['expose']['label'] = 'Enabled';
  $handler->display->display_options['filters']['enabled']['expose']['operator'] = 'enabled_op';
  $handler->display->display_options['filters']['enabled']['expose']['identifier'] = 'enabled';

  $views['commerce_discount_overview'] = $view;

  return $views;
}
