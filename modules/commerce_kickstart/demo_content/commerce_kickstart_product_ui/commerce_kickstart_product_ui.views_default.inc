<?php
/**
 * @file
 * commerce_kickstart_product_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_kickstart_product_ui_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'display_products';
  $view->description = 'Display all the products that are available, using Search API';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_search_commerce_display';
  $view->human_name = 'Display Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '24, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'all-products';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'product_list';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found for your search.
Check your spelling or try another term.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_search_commerce_display';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_search_commerce_display';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'products';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All products';
  $handler->display->display_options['menu']['weight'] = '99';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['display_products'] = $view;

  $view = new view;
  $view->name = 'shopping_cart';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'shopping cart';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'shopping cart';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Commerce Line Item: Line item summary */
  $handler->display->display_options['footer']['line_item_summary']['id'] = 'line_item_summary';
  $handler->display->display_options['footer']['line_item_summary']['table'] = 'commerce_line_item';
  $handler->display->display_options['footer']['line_item_summary']['field'] = 'line_item_summary';
  $handler->display->display_options['footer']['line_item_summary']['info'] = array(
    'quantity' => 'quantity',
    'total' => 'total',
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Your cart is empty.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* No results behavior: Commerce Line Item: Line item summary */
  $handler->display->display_options['empty']['line_item_summary']['id'] = 'line_item_summary';
  $handler->display->display_options['empty']['line_item_summary']['table'] = 'commerce_line_item';
  $handler->display->display_options['empty']['line_item_summary']['field'] = 'line_item_summary';
  $handler->display->display_options['empty']['line_item_summary']['info'] = array(
    'quantity' => 'quantity',
    'total' => 'total',
  );
  /* Relationship: Commerce Order: Referenced line item */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = 1;
  /* Field: Commerce Line Item: Line item ID */
  $handler->display->display_options['fields']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['line_item_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['line_item_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['line_item_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['line_item_id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['line_item_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['line_item_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['line_item_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['line_item_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['line_item_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['line_item_id']['hide_alter_empty'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Contextual filter: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'commerce_cart_current_cart_order_id';
  $handler->display->display_options['arguments']['order_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['order_id']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['order_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['order_id']['not'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Empty';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* No results behavior: Commerce Line Item: Line item summary */
  $handler->display->display_options['empty']['line_item_summary']['id'] = 'line_item_summary';
  $handler->display->display_options['empty']['line_item_summary']['table'] = 'commerce_line_item';
  $handler->display->display_options['empty']['line_item_summary']['field'] = 'line_item_summary';
  $handler->display->display_options['empty']['line_item_summary']['info'] = array(
    'quantity' => 'quantity',
    'total' => 'total',
  );
  $export['shopping_cart'] = $view;

  return $export;
}
