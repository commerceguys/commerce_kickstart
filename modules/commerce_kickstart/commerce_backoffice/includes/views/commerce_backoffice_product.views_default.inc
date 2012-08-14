<?php

/**
 * @file
 * Views for order management.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_backoffice_product_views_default_views() {

  $view = new view();
  $view->name = 'commerce_backoffice_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Commerce Backoffice: Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Products';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_product entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table_megarows';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'term_node_tid' => 'term_node_tid',
    'title' => 'title',
    'operations_dropbutton' => 'operations_dropbutton',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'term_node_tid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations_dropbutton' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Referenced product */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['required'] = TRUE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete product',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: COUNT(Commerce Product: SKU) */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['sku']['group_type'] = 'count';
  $handler->display->display_options['fields']['sku']['label'] = '';
  $handler->display->display_options['fields']['sku']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'bag_size' => 0,
    'brand' => 0,
    'category' => 0,
    'collection' => 0,
    'color' => 0,
    'gender' => 0,
    'hat_size' => 0,
    'shoe_size' => 0,
    'storage_capacity' => 0,
    'tags' => 0,
    'top_size' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Title';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]<br />[term_node_tid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Operations links (Dropbutton) */
  $handler->display->display_options['fields']['operations_dropbutton']['id'] = 'operations_dropbutton';
  $handler->display->display_options['fields']['operations_dropbutton']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['operations_dropbutton']['field'] = 'operations_dropbutton';
  $handler->display->display_options['fields']['operations_dropbutton']['label'] = 'Operations';
  $handler->display->display_options['fields']['operations_dropbutton']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Product Display Content Type */
  $handler->display->display_options['filters']['product_display_node_type']['id'] = 'product_display_node_type';
  $handler->display->display_options['filters']['product_display_node_type']['table'] = 'node';
  $handler->display->display_options['filters']['product_display_node_type']['field'] = 'product_display_node_type';
  $handler->display->display_options['filters']['product_display_node_type']['group'] = 1;
  $handler->display->display_options['filters']['product_display_node_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['product_display_node_type']['expose']['operator_id'] = 'product_display_node_type_op';
  $handler->display->display_options['filters']['product_display_node_type']['expose']['label'] = 'Filter by';
  $handler->display->display_options['filters']['product_display_node_type']['expose']['operator'] = 'product_display_node_type_op';
  $handler->display->display_options['filters']['product_display_node_type']['expose']['identifier'] = 'product_display_node_type';
  $handler->display->display_options['filters']['product_display_node_type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['product_display_node_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Commerce Product: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Has taxonomy terms (from Multiple Vocabularies) */
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['id'] = 'term_node_tid_multiple_vocabularies';
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['field'] = 'term_node_tid_multiple_vocabularies';
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['expose']['operator_id'] = 'term_node_tid_multiple_vocabularies_op';
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['expose']['operator'] = 'term_node_tid_multiple_vocabularies_op';
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['expose']['identifier'] = 'term_node_tid_multiple_vocabularies';
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['vocabulary'] = array(
    4 => '4',
    5 => '5',
    6 => '6',
    8 => '8',
    3 => 0,
    1 => 0,
    7 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    2 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_multiple_vocabularies']['per_vocabulary'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'sku' => 'sku',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/commerce/products/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Products';
  $handler->display->display_options['tab_options']['description'] = 'Manage products in the store.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $views[$view->name] = $view;

  $view = new view;
  $view->name = 'commerce_backoffice_product_variations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'Commerce Backoffice: Product variations';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'product_id' => 'product_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'product_id' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No variations have been created for this product.';
  $handler->display->display_options['empty']['area']['format'] = 'commerce_order_message';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Commerce Product: Node referencing products from field_product */
  $handler->display->display_options['relationships']['field_product']['id'] = 'field_product';
  $handler->display->display_options['relationships']['field_product']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['field_product']['field'] = 'field_product';
  $handler->display->display_options['relationships']['field_product']['required'] = 1;
  /* Field: Commerce Product: Capacity */
  $handler->display->display_options['fields']['field_storage_capacity']['id'] = 'field_storage_capacity';
  $handler->display->display_options['fields']['field_storage_capacity']['table'] = 'field_data_field_storage_capacity';
  $handler->display->display_options['fields']['field_storage_capacity']['field'] = 'field_storage_capacity';
  $handler->display->display_options['fields']['field_storage_capacity']['label'] = '';
  $handler->display->display_options['fields']['field_storage_capacity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_storage_capacity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_storage_capacity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_storage_capacity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_storage_capacity']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_storage_capacity']['field_api_classes'] = 0;
  /* Field: Commerce Product: Color */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['label'] = '';
  $handler->display->display_options['fields']['field_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_color']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_color']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_color']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_color']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_color']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_color']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_color']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_color']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_color']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_color']['field_api_classes'] = 0;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_images']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_images']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_images']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_images']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_images']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_images']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['type'] = 'image_delta';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'deltas' => '0',
    'deltas_reversed' => 0,
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_images']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_images']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_images']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_images']['field_api_classes'] = 0;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] <br />
    [field_storage_capacity] [field_color]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['label'] = '';
  $handler->display->display_options['fields']['sku']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sku']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sku']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sku']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sku']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sku']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sku']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Commerce Product: Quick Edit Form */
  $handler->display->display_options['fields']['quick_edit_form']['id'] = 'quick_edit_form';
  $handler->display->display_options['fields']['quick_edit_form']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['quick_edit_form']['field'] = 'quick_edit_form';
  $handler->display->display_options['fields']['quick_edit_form']['label'] = '';
  $handler->display->display_options['fields']['quick_edit_form']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['external'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['alter']['html'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['quick_edit_form']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['quick_edit_form']['hide_empty'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['empty_zero'] = 0;
  $handler->display->display_options['fields']['quick_edit_form']['hide_alter_empty'] = 1;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_product';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $views[$view->name] = $view;

  return $views;
}

/**
 * Implements hook_views_default_views_alter().
 */
function commerce_backoffice_product_views_default_views_alter(&$views) {
  // Disable the default product listing.
  if (isset($views['commerce_products'])) {
    $views['commerce_products']->disabled = TRUE;
  }
}
