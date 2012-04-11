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
  $commerce_kickstart_import_product = variable_get('commerce_kickstart_import_product', FALSE);
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
    'display' => $commerce_kickstart_import_product,
    'type' => 'batch',
    'run' => $commerce_kickstart_import_product ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
  );
  $tasks['commerce_kickstart_configure_searchapi'] = array(
    'display_name' => st('Configure Search API'),
    'display' => $commerce_kickstart_import_product,
    'type' => 'normal',
    'run' => $install_configure_seachapi ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
  );
  return $tasks;
}

/**
 * Implements hook_install_tasks_alter().
 */
function commerce_kickstart_install_tasks_alter(&$tasks, $install_state) {
  $tasks['install_finished']['function'] = 'commerce_kickstart_install_finished';
}

/**
 * Custom Installation task; perform final steps and redirect the user to the
 * new site if there are no errors.
 *
 * @param $install_state
 *   An array of information about the current installation state.
 *
 * @return
 *   A message informing the user about errors if there was some.
 */
function commerce_kickstart_install_finished(&$install_state) {
  drupal_set_title(st('@drupal installation complete', array('@drupal' => drupal_install_profile_distribution_name())), PASS_THROUGH);
  $messages = drupal_set_message();

  // Flush all caches to ensure that any full bootstraps during the installer
  // do not leave stale cached data, and that any content types or other items
  // registered by the install profile are registered correctly.
  drupal_flush_all_caches();

  // Remember the profile which was used.
  variable_set('install_profile', drupal_get_profile());

  // Install profiles are always loaded last
  db_update('system')
    ->fields(array('weight' => 1000))
    ->condition('type', 'module')
    ->condition('name', drupal_get_profile())
    ->execute();

  // Cache a fully-built schema.
  drupal_get_schema(NULL, TRUE);

  // Run cron to populate update status tables (if available) so that users
  // will be warned if they've installed an out of date Drupal version.
  // Will also trigger indexing of profile-supplied content or feeds.
  drupal_cron_run();

  if (isset($messages['error'])) {
    $output = '<p>' . (isset($messages['error']) ? st('Review the messages above before visiting <a href="@url">your new site</a>.', array('@url' => url(''))) : st('<a href="@url">Visit your new site</a>.', array('@url' => url('')))) . '</p>';
    return $output;
  }
  else {
    // Since any module can add a drupal_set_message, this can bug the user
    // when we redirect him to the front page. For a better user experience,
    // remove all the message that are only "notifications" message.
    drupal_get_messages('status', TRUE);
    // Redirect the user to the front page.
    drupal_goto('');
  }
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
  $form['commerce_kickstart_example_content'] = array(
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
  $form['commerce_kickstart_choose_tax_country'] = array(
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
  variable_set('commerce_kickstart_example_content', $form_state['values']['commerce_kickstart_example_content']);
  variable_set('commerce_kickstart_choose_tax_country', $form_state['values']['commerce_kickstart_choose_tax_country']);
  if (!empty($form_state['values']['commerce_kickstart_example_content']['products'])) {
    variable_set('commerce_kickstart_import_product', TRUE);
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
      array('_commerce_kickstart_example_taxes', array()),
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
