<?php

/**
 * @file
 * Views for order management.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_backoffice_views_default_views() {

  $view = new view();
  $view->name = 'commerce_backoffice_orders';
  $view->description = '';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Commerce Backoffice: Orders';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orders';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table_megarows';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_number' => 'order_number',
    'created' => 'created',
    'name' => 'name',
    'mail' => 'name',
    'commerce_order_total' => 'commerce_order_total',
    'operations_dropbutton' => 'operations_dropbutton',
    'status' => 'status',
    'megarow_links' => 'megarow_links',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
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
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'megarow_links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Commerce Order: Empty text */
  $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_order';
  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['add_path'] = 'admin/commerce/orders/add';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '50';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete order',
    ),
    'rules_component::rules_commerce_order_status_canceled' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_cart' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_checkout' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_complete' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_payment' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_review' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_shipping' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_pending' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_processing' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order ID';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Name/Email';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'Email';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Commerce Order: Operations links (Dropbutton) */
  $handler->display->display_options['fields']['operations_dropbutton']['id'] = 'operations_dropbutton';
  $handler->display->display_options['fields']['operations_dropbutton']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['operations_dropbutton']['field'] = 'operations_dropbutton';
  $handler->display->display_options['fields']['operations_dropbutton']['label'] = 'Actions';
  $handler->display->display_options['fields']['operations_dropbutton']['add_destination'] = 1;
  /* Contextual filter: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Filter by';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  /* Filter criterion: Date: Date (commerce_order) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_order.created' => 'commerce_order.created',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'name' => 'name',
    'mail' => 'mail',
  );

  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/commerce/orders/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Orders';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Orders';
  $handler->display->display_options['tab_options']['description'] = 'Manage orders in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $views[$view->name] = $view;

  $view = new view;
  $view->name = 'commerce_backoffice_order_messages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'Commerce Backoffice: Order messages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Order History';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'message_order_display_name' => 'message_order_display_name',
    'timestamp' => 'timestamp',
    'name' => 'name',
    'message_render' => 'message_render',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_order_display_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_render' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* Footer: Message: Add new message */
  $handler->display->display_options['footer']['add']['id'] = 'add';
  $handler->display->display_options['footer']['add']['table'] = 'message';
  $handler->display->display_options['footer']['add']['field'] = 'add';
  $handler->display->display_options['footer']['add']['empty'] = TRUE;
  $handler->display->display_options['footer']['add']['valid_types'] = array(
    'commerce_order_admin_comment' => 'commerce_order_admin_comment',
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No history has been recorded for this order.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['required'] = 1;
  /* Relationship: Message: Type */
  $handler->display->display_options['relationships']['type']['id'] = 'type';
  $handler->display->display_options['relationships']['type']['table'] = 'message';
  $handler->display->display_options['relationships']['type']['field'] = 'type';
  $handler->display->display_options['relationships']['type']['required'] = 1;
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
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
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  /* Field: Message type: Display name */
  $handler->display->display_options['fields']['message_order_display_name']['id'] = 'message_order_display_name';
  $handler->display->display_options['fields']['message_order_display_name']['table'] = 'field_data_message_order_display_name';
  $handler->display->display_options['fields']['message_order_display_name']['field'] = 'message_order_display_name';
  $handler->display->display_options['fields']['message_order_display_name']['relationship'] = 'type';
  $handler->display->display_options['fields']['message_order_display_name']['label'] = 'Type';
  $handler->display->display_options['fields']['message_order_display_name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['text'] = '<span class="[type]">[message_order_display_name]</span>';
  $handler->display->display_options['fields']['message_order_display_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['message_order_display_name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['message_order_display_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['message_order_display_name']['field_api_classes'] = 0;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Date';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Message: Render message (Get text) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['label'] = 'Description';
  $handler->display->display_options['fields']['message_render']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['external'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['message_render']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['message_render']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['message_render']['alter']['html'] = 0;
  $handler->display->display_options['fields']['message_render']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['message_render']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['message_render']['hide_empty'] = 0;
  $handler->display->display_options['fields']['message_render']['empty_zero'] = 0;
  $handler->display->display_options['fields']['message_render']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['message_render']['partials'] = 0;
  $handler->display->display_options['fields']['message_render']['partials_delta'] = '0';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Sort criterion: Message: Message ID */
  $handler->display->display_options['sorts']['mid']['id'] = 'mid';
  $handler->display->display_options['sorts']['mid']['table'] = 'message';
  $handler->display->display_options['sorts']['mid']['field'] = 'mid';
  $handler->display->display_options['sorts']['mid']['order'] = 'DESC';
  /* Contextual filter: Message: Order (message_commerce_order) */
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['id'] = 'message_commerce_order_target_id';
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['table'] = 'field_data_message_commerce_order';
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['field'] = 'message_commerce_order_target_id';
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['message_commerce_order_target_id']['not'] = 0;
  /* Filter criterion: Message: Message category */
  $handler->display->display_options['filters']['type_category']['id'] = 'type_category';
  $handler->display->display_options['filters']['type_category']['table'] = 'message';
  $handler->display->display_options['filters']['type_category']['field'] = 'type_category';
  $handler->display->display_options['filters']['type_category']['value'] = array(
    'commerce_order_message' => 'commerce_order_message',
  );

  /* Display: Entity content */
  $handler = $view->new_display('entity_view', 'Entity content', 'order_view');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['entity_type'] = 'commerce_order';
  $handler->display->display_options['bundles'] = array(
    0 => 'commerce_order',
  );
  $handler->display->display_options['show_title'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $views[$view->name] = $view;

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
  $handler->display->display_options['fields']['operations_dropbutton']['table'] = 'node';
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

  $view = new view;
  $view->name = 'commerce_backoffice_user_orders';
  $view->description = 'Display a list of completed orders for a user.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Commerce Backoffice: User orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Order history';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 25;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'order_number' => 'order_number',
    'status' => 'status',
    'view_order' => 'view_order',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_order' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'You have not placed any orders with us yet.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['order_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['order_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['order_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['order_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['order_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['order_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_order_total']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['empty_zero'] = 0;
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_order_total']['field_api_classes'] = 0;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid_1']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['uid_1']['validate']['type'] = 'current_user_or_role';
  $handler->display->display_options['arguments']['uid_1']['validate_options']['restrict_roles'] = '1';
  $handler->display->display_options['arguments']['uid_1']['validate_options']['roles'] = array(
    3 => '3',
  );
  $handler->display->display_options['arguments']['uid_1']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid_1']['not'] = 0;
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
    'cart' => 'cart',
    'checkout' => 'checkout',
  );

  /* Display: User Orders */
  $handler = $view->new_display('page', 'User Orders', 'order_page');
  $handler->display->display_options['path'] = 'user/%/orders';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Order history';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Order history';
  $handler->display->display_options['tab_options']['description'] = 'User orders in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent orders';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'View complete order history';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Order date';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'F m, Y';
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['order_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['order_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['order_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['order_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['order_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['order_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['order_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'View order';
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['text'] = 'View order';
  $handler->display->display_options['fields']['order_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['order_id']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['order_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['order_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['order_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['order_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['order_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['order_id']['link_to_order'] = 'customer';
  $views[$view->name] = $view;

  return $views;
}

/**
 * Implements hook_views_default_views_alter().
 */
function commerce_backoffice_views_default_views_alter(&$views) {
  // Disable the default order and product listings.
  if (isset($views['commerce_orders'])) {
    $views['commerce_orders']->disabled = TRUE;
  }
  if (isset($views['commerce_products'])) {
    $views['commerce_products']->disabled = TRUE;
  }
  if (isset($views['commerce_user_orders'])) {
    $views['commerce_user_orders']->disabled = TRUE;
  }
}
