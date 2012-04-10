<?php

/**
 * Implements hook_form_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function commerce_kickstart_form_install_configure_form_alter(&$form, $form_state) {
  // Set a default name for the dev site and change title's label.
  $form['site_information']['site_name']['#title'] = 'Store name';
  $form['site_information']['site_name']['#default_value'] = t('Commerce Kickstart');

  // Set a default country so we can benefit from it on Address Fields.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
}

/**
 * Implements hook_install_tasks().
 */
function commerce_kickstart_install_tasks() {
  $tasks = array();
  $import_product = variable_get('import_product', FALSE);
  // Add a page allowing the user to indicate they'd like to install demo content.
  $install_configure_seachapi = variable_get('install_configure_seachapi', FALSE);
  // Add a page allowing the user to indicate they'd like to install demo
  // content.
  $tasks['commerce_kickstart_example_store_form'] = array(
    'display_name' => st('Example store'),
    'type' => 'form',
  );
  // And let the user choose an example tax to be set up by default.
  $tasks['commerce_kickstart_import_product'] = array(
    'display_name' => st('Import example products'),
    'display' => $import_product,
    'type' => 'batch',
    'run' => $import_product ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
  );
  $tasks['commerce_kickstart_configure_searchapi'] = array(
    'display_name' => st('Configure Search API'),
    'display' => $import_product,
    'type' => 'normal',
    'run' => $install_configure_seachapi ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
  );
  return $tasks;
}

/**
 * Task callback: returns the form allowing the user to add example store
 * content on install.
 */
function commerce_kickstart_example_store_form() {
  drupal_set_title(st('Example store content'));

  // Prepare all the options for example content.
  $options = array(
    'products' => st('Products'),
  );
  $form['example_content'] = array(
    '#type' => 'checkboxes',
    '#title' => st('Create example content for the following store components:'),
    '#description' => st('The example content is not comprehensive but illustrates how the basic components work.'),
    '#options' => $options,
    '#default_value' => drupal_map_assoc(array_keys($options)),
  );
  // Prepare all the options for example content.
  $options = array(
    'us' => st('US'),
    'europe' => st('Europe'),
  );
  $form['example_choose_country'] = array(
    '#type' => 'radios',
    '#title' => st('Setup default currency and taxes:'),
    '#description' => st('The example content is not comprehensive but illustrates how the basic components work.'),
    '#options' => $options,
    '#default_value' => key($options),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Create and continue'),
    '#weight' => 15,
  );

  return $form;
}

/**
 * Submit callback: creates the requested example content.
 */
function commerce_kickstart_example_store_form_submit(&$form, &$form_state) {
  $example_content = $form_state['values']['example_content'];
  $choose_country = $form_state['values']['example_choose_country'];

  // Create products if specified.
  if (!empty($example_content['products'])) {
    variable_set('import_product', TRUE);
    module_enable(array(
      'features',
      'commerce_features',
      'ft_dsc_architecture',
      'kickstart_view_modes',
      'feature_ck2_demo',
      'demo_features',
    ));
    features_rebuild();
    drupal_static_reset();
    node_types_rebuild();
    module_enable(array('demo'));
  }

  // Create the choosen tax.
  if (!empty($choose_country)) {
    if ($choose_country == 'us') {
      $tax = array(
        'name' => 'sample_californian_sales_tax',
        'title' => 'Sample Californian Sales Tax 7,25%',
        'display_title' => 'Sample Californian Sales Tax 7,25%',
        'description' => '',
        'rate' => 0.0725,
        'type' => 'sales_tax', // vat
        'default_rules_component' => TRUE,
        'tax_component' => '',
        'admin_list' => TRUE,
        'calculation_callback' => 'commerce_tax_rate_calculate',
        'module' => 'commerce_tax_ui',
        'is_new' => TRUE,
      );
      commerce_tax_ui_tax_rate_save($tax);
    }

    if ($choose_country == 'europe') {
      variable_set('import_choosen_tax', 'europe');
      $tax = array(
        'name' => 'sample_french_vat_tax',
        'title' => 'Sample French VAT 19,6%',
        'display_title' => 'Sample French VAT 19,6%',
        'description' => '',
        'rate' => 0.196,
        'type' => 'vat', // vat
        'default_rules_component' => TRUE,
        'tax_component' => '',
        'admin_list' => TRUE,
        'calculation_callback' => 'commerce_tax_rate_calculate',
        'module' => 'commerce_tax_ui',
        'is_new' => TRUE,
      );
      commerce_tax_ui_tax_rate_save($tax);
    }
  }
}

/**
 * Task callback: return a batch API array with the products to be imported.
 */
function commerce_kickstart_import_product() {
  // Batch api
  $batch = array(
    'title' => t('Importing'),
    'operations' => array(
      array('_commerce_kickstart_example_storage_device', array()),
      array('_commerce_kickstart_example_bags', array()),
      array('_commerce_kickstart_example_drinks', array()),
      array('_commerce_kickstart_example_hats', array()),
      array('_commerce_kickstart_example_shoes', array()),
      array('_commerce_kickstart_example_tops', array()),
      array('_commerce_kickstart_example_display', array()),
    ),
    'file' => drupal_get_path('profile', 'commerce_kickstart') . '/import/kickstart.import.inc',
  );
  variable_set('install_configure_seachapi', TRUE);
  return $batch;
}

/**
 * Task callback: Configure Search API and facets for the imported products.
 */
function commerce_kickstart_configure_searchapi() {
  // Enable the search API modules.
  module_enable(array('search_api_db', 'search_api_views', 'facetapi'));
  // Enable the feature.
  module_enable(array('ft_dsc_searchapi'));

  // Load the search api index.
  $index = search_api_index_load('1');
  // Index it.
  search_api_index_items($index);

  // Put the facets blocks in the right place.
  _block_rehash('ck2');
  try {
    db_update('block')
      ->fields(array(
      'region' => 'sidebar_first',
      'status' => (int) '1',
    ))
      ->condition('module', 'facetapi')
      ->condition('delta', '0', '<>')
      ->condition('theme', 'ck2')
      ->execute();
  }
  catch (Exception $e) {
    watchdog_exception('block', $e);
    throw $e;
  }
}

function _commerce_kickstart_parse_csv($file) {
  $csv = array();
  $path = drupal_get_path('profile', 'commerce_kickstart') . '/import/csv/';
  $row = 1;
  $file = fopen(DRUPAL_ROOT . '/' . $path . $file, 'r');
  while (($result = fgetcsv($file, NULL, ',')) !== FALSE) {
    if ($row == 1) {
      $row++;
      continue;
    }
    $row++;
    $csv[] = $result;
  }
  fclose($file);
  return $csv;
}

function _commerce_kickstart_custom_createContent($title, $body_text, $path, $content_type, $field_type, $image_file) {
  $node = new stdClass();
  $node->type = $content_type;
  $node->title    = $title;
  $node->language = LANGUAGE_NONE;
  $node->comment = '0';
  $node->field_type[$node->language][0]['value'] = $field_type;
  $node->body[$node->language][0]['value']   = $body_text;
  $node->body[$node->language][0]['format']  = 'filtered_html';
  $file_temp = file_get_contents(drupal_get_path('profile', 'commerce_kickstart') . '/import/images/' . $image_file);
  $file_temp = file_save_data($file_temp, 'public://' . $image_file, FILE_EXISTS_REPLACE);
  $node->field_image[$node->language][]['fid'] = $file_temp->fid;
  $node->path = array('alias' => $path);
  node_object_prepare($node);
  node_save($node);
}
