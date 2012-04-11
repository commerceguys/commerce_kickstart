<?php
/**
 * @file
 * ft_dsc_searchapi.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ft_dsc_searchapi_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'display_all_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_search_commerce_product';
  $view->human_name = 'Display all products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Display all products';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Indexed Commerce Product: A bridge to node referenced by field_product */
  $handler->display->display_options['relationships']['field_product_node']['id'] = 'field_product_node';
  $handler->display->display_options['relationships']['field_product_node']['table'] = 'search_api_index_search_commerce_product';
  $handler->display->display_options['relationships']['field_product_node']['field'] = 'field_product_node';
  /* Field: Indexed Commerce Product: Product ID */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'search_api_index_search_commerce_product';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  /* Field: Node: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity_1']['id'] = 'rendered_entity_1';
  $handler->display->display_options['fields']['rendered_entity_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity_1']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity_1']['relationship'] = 'field_product_node';
  $handler->display->display_options['fields']['rendered_entity_1']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rendered_entity_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity_1']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity_1']['view_mode'] = 'teaser';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'display-all-products';
  $export['display_all_products'] = $view;

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
  $handler->display->display_options['title'] = 'Display Products';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'product_list';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_search_commerce_display';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'all-products';
  $export['display_products'] = $view;

  return $export;
}
