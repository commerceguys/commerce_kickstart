<?php

/**
 * @file
 * Views for order management.
 */

/**
 * Implements hook_views_default_views().
 */
function kickstart_order_manager_views_default_views() {
  $state_weight = 0;
  foreach (commerce_order_states() as $state_name => $state_info) {
    $status_weight = 0;
    $first_status = TRUE;
    foreach (commerce_order_statuses(array('state' => $state_name)) as $status_name => $status_info) {
      $view = new view;
      $view->name = 'kom_' . $status_name;
      $view->description = '';
      $view->tag = 'default';
      $view->base_table = 'commerce_order';
      $view->human_name = t('Kickstart: order management (status: @status)', array('@status' => $status_info['title']));
      $view->core = 7;
      $view->api_version = '3.0';
      $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

      /* Display: Master */
      $handler = $view->new_display('default', 'Master', 'default');
      $handler->display->display_options['title'] = 'Orders';
      $handler->display->display_options['access']['type'] = 'perm';
      $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
      $handler->display->display_options['cache']['type'] = 'none';
      $handler->display->display_options['query']['type'] = 'views_query';
      $handler->display->display_options['query']['options']['query_comment'] = FALSE;
      $handler->display->display_options['exposed_form']['type'] = 'basic';
      $handler->display->display_options['pager']['type'] = 'full';
      $handler->display->display_options['pager']['options']['items_per_page'] = '50';
      $handler->display->display_options['style_plugin'] = 'table';
      $handler->display->display_options['style_options']['group_rendered'] = 1;
      $handler->display->display_options['style_options']['columns'] = array(
        'order_number' => 'order_number',
        'mail' => 'mail',
        'commerce_order_total' => 'commerce_order_total',
        'created' => 'created',
        'changed' => 'changed',
        'operations' => 'operations',
      );
      $handler->display->display_options['style_options']['default'] = 'changed';
      $handler->display->display_options['style_options']['info'] = array(
        'order_number' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
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
          'sortable' => 1,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
        ),
        'created' => array(
          'sortable' => 1,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
        ),
        'changed' => array(
          'sortable' => 1,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
        ),
        'operations' => array(
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
        ),
      );
      /* No results behavior: Commerce Order: Empty text */
      $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
      $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_order';
      $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
      $handler->display->display_options['empty']['empty_text']['add_path'] = 'test';
      $handler->display->display_options['style_options']['empty_table'] = 1;
      /* Relationship: Commerce Order: Referenced customer profile */
      $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
      $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
      $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
      $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['required'] = 0;
      /* Relationship: Commerce Order: Owner */
      $handler->display->display_options['relationships']['uid']['id'] = 'uid';
      $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
      $handler->display->display_options['relationships']['uid']['field'] = 'uid';
      $handler->display->display_options['relationships']['uid']['required'] = 0;
      /* Field: Bulk operations: Commerce Order */
      $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
      $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
      $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
      $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
      $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '50';
      $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
        'action::system_message_action' => array(
          'selected' => 1,
          'use_queue' => 0,
          'skip_confirmation' => 1,
          'override_label' => 0,
          'label' => '',
        ),
      );
      $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
      $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
      $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
      $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
      $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
      /* Field: Commerce Order: Order number */
      $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
      $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
      $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
      $handler->display->display_options['fields']['order_number']['label'] = '#';
      $handler->display->display_options['fields']['order_number']['alter']['alter_text'] = 0;
      $handler->display->display_options['fields']['order_number']['alter']['make_link'] = 0;
      $handler->display->display_options['fields']['order_number']['alter']['absolute'] = 0;
      $handler->display->display_options['fields']['order_number']['alter']['external'] = 0;
      $handler->display->display_options['fields']['order_number']['alter']['replace_spaces'] = 0;
      $handler->display->display_options['fields']['order_number']['alter']['trim_whitespace'] = 0;
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
      $handler->display->display_options['fields']['order_number']['hide_alter_empty'] = 1;
      /* Field: User: E-mail */
      $handler->display->display_options['fields']['mail']['id'] = 'mail';
      $handler->display->display_options['fields']['mail']['table'] = 'users';
      $handler->display->display_options['fields']['mail']['field'] = 'mail';
      $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
      $handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['external'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
      $handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
      $handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
      $handler->display->display_options['fields']['mail']['alter']['html'] = 0;
      $handler->display->display_options['fields']['mail']['element_label_colon'] = 1;
      $handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
      $handler->display->display_options['fields']['mail']['hide_empty'] = 0;
      $handler->display->display_options['fields']['mail']['empty_zero'] = 0;
      $handler->display->display_options['fields']['mail']['hide_alter_empty'] = 1;
      $handler->display->display_options['fields']['mail']['link_to_user'] = 'user';
      /* Field: Commerce Order: Order total */
      $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
      $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
      $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
      $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
      $handler->display->display_options['fields']['commerce_order_total']['alter']['alter_text'] = 0;
      $handler->display->display_options['fields']['commerce_order_total']['alter']['make_link'] = 0;
      $handler->display->display_options['fields']['commerce_order_total']['alter']['absolute'] = 0;
      $handler->display->display_options['fields']['commerce_order_total']['alter']['external'] = 0;
      $handler->display->display_options['fields']['commerce_order_total']['alter']['replace_spaces'] = 0;
      $handler->display->display_options['fields']['commerce_order_total']['alter']['trim_whitespace'] = 0;
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
      $handler->display->display_options['fields']['commerce_order_total']['hide_alter_empty'] = 1;
      $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
      $handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_price_formatted_amount';
      $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
        'calculation' => FALSE,
      );
      $handler->display->display_options['fields']['commerce_order_total']['field_api_classes'] = 0;
      /* Field: Commerce Order: Created date */
      $handler->display->display_options['fields']['created']['id'] = 'created';
      $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
      $handler->display->display_options['fields']['created']['field'] = 'created';
      $handler->display->display_options['fields']['created']['label'] = 'Created';
      $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
      $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
      $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
      $handler->display->display_options['fields']['created']['alter']['external'] = 0;
      $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
      $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
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
      $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
      $handler->display->display_options['fields']['created']['date_format'] = 'short';
      /* Field: Commerce Order: Updated date */
      $handler->display->display_options['fields']['changed']['id'] = 'changed';
      $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
      $handler->display->display_options['fields']['changed']['field'] = 'changed';
      $handler->display->display_options['fields']['changed']['label'] = 'Updated';
      $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
      $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
      $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
      $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
      $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
      $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
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
      $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 1;
      $handler->display->display_options['fields']['changed']['date_format'] = 'short';
      /* Field: Commerce Order: Operations links */
      $handler->display->display_options['fields']['operations']['id'] = 'operations';
      $handler->display->display_options['fields']['operations']['table'] = 'commerce_order';
      $handler->display->display_options['fields']['operations']['field'] = 'operations';
      $handler->display->display_options['fields']['operations']['label'] = 'Operations';
      $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['trim_whitespace'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
      $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
      $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
      $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
      $handler->display->display_options['fields']['operations']['element_label_colon'] = FALSE;
      $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
      $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
      $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
      $handler->display->display_options['fields']['operations']['hide_alter_empty'] = 1;
      /* Filter criterion: Commerce Order: Order status */
      $handler->display->display_options['filters']['status']['id'] = 'status';
      $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
      $handler->display->display_options['filters']['status']['field'] = 'status';
      $handler->display->display_options['filters']['status']['value'] = array(
        $status_name => $status_name,
      );

      /* Display: Page */
      $handler = $view->new_display('page', 'Page', 'page');
      $handler->display->display_options['path'] = 'admin/commerce/orders/' . $state_name . '/' . $status_name;
      $handler->display->display_options['menu']['type'] = 'tab';
      $handler->display->display_options['menu']['title'] = $status_info['title'];
      $handler->display->display_options['menu']['weight'] = $status_weight++;
      $handler->display->display_options['menu']['name'] = 'management';
      if ($first_status) {
        // Define the first status as a default tab.
        $handler->display->display_options['menu']['type'] = 'default tab';
        $handler->display->display_options['tab_options']['type'] = 'tab';
        $handler->display->display_options['tab_options']['title'] = $state_info['title'];
        $handler->display->display_options['tab_options']['weight'] = $state_weight++;
        $handler->display->display_options['tab_options']['name'] = 'management';
        $first_status = FALSE;
      }
      $views[$view->name] = $view;
    }
  }

  // For translation support.
  $translatables = array(
    t('Master'),
    t('Orders'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Customer profile'),
    t('Order owner'),
    t('#'),
    t('E-mail'),
    t('Total'),
    t('Created'),
    t('Updated'),
    t('Operations'),
    t('Page'),
  );

  return $views;
}

/**
 * Implements hook_views_default_views_alter().
 */
function kickstart_order_manager_views_default_views_alter(&$views) {
  // Disable the default order administration view.
  unset($views['commerce_orders']);
}
