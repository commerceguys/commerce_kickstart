<?php

/**
 * Implements hook_form_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function commerce_kickstart_form_install_configure_form_alter(&$form, $form_state) {
  // Since any module can add a drupal_set_message, this can bug the user
  // when we display this page. For a better user experience,
  // remove all the message that are only "notifications" message.
  drupal_get_messages('status', TRUE);

  // Set a default name for the dev site and change title's label.
  $form['site_information']['site_name']['#title'] = 'Store name';
  $form['site_information']['site_mail']['#title'] = 'Store email address';
  $form['site_information']['site_name']['#default_value'] = t('Commerce Kickstart');

  // Set a default country so we can benefit from it on Address Fields.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';

  // Use "admin" as the default username.
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['name']['#access'] = FALSE;
  // Set the default admin password.
  $form['admin_account']['account']['pass']['#value'] = 'admin';
  // Make the password "hidden".
  $form['admin_account']['account']['pass']['#type'] = 'hidden';
  $form['admin_account']['account']['mail']['#access'] = FALSE;

  // Hide Update Notifications.
  $form['update_notifications']['#access'] = FALSE;

  // Add informations about the default username and password.
  $form['admin_account']['account']['commerce_kickstart_name'] = array(
    '#type' => 'item', '#title' => st('Username'),
    '#markup' => 'admin'
  );
  $form['admin_account']['account']['commerce_kickstart_password'] = array(
    '#type' => 'item', '#title' => st('Password'),
    '#markup' => 'admin'
  );
  $form['admin_account']['account']['commerce_kickstart_informations'] = array(
    '#markup' => '<p>' . t('You can change the default username and password from the store administration page. This information will be emailed to the store email address.') . '</p>'
  );

  // Add a custom validation that needs to be trigger before the original one,
  // where we can copy the site's mail as the admin account's mail.
  array_unshift($form['#validate'], 'commerce_kickstart_customset_admin_mail');
}

/**
 * Validate callback; Populate the admin account mail with the site's mail.
 */
function commerce_kickstart_customset_admin_mail(&$form, &$form_state) {
  $form_state['values']['account']['mail'] = $form_state['values']['site_mail'];
}

/**
 * Implements hook_install_tasks().
 */
function commerce_kickstart_install_tasks() {
  $tasks = array();
  $commerce_kickstart_import_product = variable_get('commerce_kickstart_import_product', FALSE);
  // Add a page allowing the user to indicate they'd like to install demo
  // content.
  $tasks['commerce_kickstart_configure_store_form'] = array(
    'display_name' => st('Configure store'),
    'type' => 'form',
  );
  // And let the user choose an example tax to be set up by default.
  $tasks['commerce_kickstart_import_product'] = array(
    'display_name' => st('Import products'),
    'display' => $commerce_kickstart_import_product,
    'type' => 'batch',
    'run' => $commerce_kickstart_import_product ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
  );
  return $tasks;
}

/**
 * Implements hook_install_tasks_alter().
 */
function commerce_kickstart_install_tasks_alter(&$tasks, $install_state) {
  $tasks['install_select_profile']['display'] = FALSE;
  $tasks['install_finished']['function'] = 'commerce_kickstart_install_finished';

  _commerce_kickstart_set_theme('commerce_kickstart_admin');
}

/**
 * Force-set a theme at any point during the execution of the request.
 *
 * Drupal doesn't give us the option to set the theme during the installation
 * process and forces enable the maintenance theme too early in the request
 * for us to modify it in a clean way.
 */
function _commerce_kickstart_set_theme($target_theme) {
  if ($GLOBALS['theme'] != $target_theme) {
    unset($GLOBALS['theme']);

    drupal_static_reset();
    $GLOBALS['conf']['maintenance_theme'] = $target_theme;
    _drupal_maintenance_theme();
  }
}

/**
 * Custom installation task; perform final steps and redirect the user to the new site if there are no errors.
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
    drupal_get_messages('completed', TRUE);
    // Migrate adds its messages under the wrong type, see #1659150.
    drupal_get_messages('ok', TRUE);

    // If we don't install drupal using Drush, redirect the user to the front
    // page.
    if (!drupal_is_cli()) {
      if (module_exists('overlay')) {
        drupal_goto('', array('fragment' => 'overlay=admin/getting-started'));
      }
      else {
        drupal_goto('admin/getting-started');
      }
    }
  }
}

/**
 * Task callback: returns the form allowing the user to add example store content on install.
 */
function commerce_kickstart_configure_store_form() {
  drupal_set_title(st('Configure store content'));

  // Prepare all the options for example content.
  $options = array(
    '1' => st('Yes'),
    '0' => st('No'),
  );
  $form['commerce_kickstart_example_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => st('Example Content'),
  );
  $form['commerce_kickstart_example_wrapper']['commerce_kickstart_example_content'] = array(
    '#type' => 'radios',
    '#title' => st('Do you want to install example store content?'),
    '#description' => st('Recommended for new users. Demonstrates how you can set-up your Drupal Commerce site.'),
    '#options' => $options,
    '#default_value' => '1',
     // This still needs some love
    '#disabled' => TRUE,
  );

  // Build a currency options list from all defined currencies.
  $options = array();

  foreach (commerce_currencies(FALSE, TRUE) as $currency_code => $currency) {
    $options[$currency_code] = t('@code - !name', array(
      '@code' => $currency['code'],
      '@symbol' => $currency['symbol'],
      '!name' => $currency['name']
    ));

    if (!empty($currency['symbol'])) {
      $options[$currency_code] .= ' - ' . check_plain($currency['symbol']);
    }
  }

  $form['commerce_default_currency_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => st('Currency'),
  );
  $form['commerce_default_currency_wrapper']['commerce_default_currency'] = array(
    '#type' => 'select',
    '#title' => t('Default store currency'),
    '#description' => t('The default store currency will be used as the default for all price fields.'),
    '#options' => $options,
    '#default_value' => commerce_default_currency(),
  );

  // Prepare all the options for example content.
  $options = array(
    'none' => st("No sample tax rate."),
    'us' => st('US - Sales taxes displayed in checkout'),
    'europe' => st('European - Inclusive tax rates (VAT)'),
  );
  $form['commerce_kickstart_tax_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => st('Tax Rate'),
  );
  $form['commerce_kickstart_tax_wrapper']['commerce_kickstart_choose_tax_country'] = array(
    '#type' => 'radios',
    '#title' => st('Tax rate examples'),
    '#description' => st('Example tax rates will be created in this style.'),
    '#options' => $options,
    '#default_value' => key($options),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Create and Finish'),
    '#weight' => 15,
  );
  return $form;
}

/**
 * Submit callback: creates the requested example content.
 */
function commerce_kickstart_configure_store_form_submit(&$form, &$form_state) {
  variable_set('commerce_kickstart_example_content', $form_state['values']['commerce_kickstart_example_content']);
  variable_set('commerce_kickstart_choose_tax_country', $form_state['values']['commerce_kickstart_choose_tax_country']);
  variable_set('commerce_default_currency', $form_state['values']['commerce_default_currency']);
  if ($form_state['values']['commerce_kickstart_example_content'] == 1) {
    variable_set('commerce_kickstart_import_product', TRUE);
  }
}

/**
 * Task callback: return a batch API array with the products to be imported.
 */
function commerce_kickstart_import_product() {
  drupal_set_title(st('Import products'));

  // Fixes problems when the CSV files used for importing have been created
  // on a Mac, by forcing PHP to detect the appropriate line endings.
  ini_set("auto_detect_line_endings", TRUE);

  $migrations = migrate_migrations();

  $operations[] = array('_commerce_kickstart_example_nodes', array(t('Setting up example nodes.')));
  $operations[] = array('_commerce_kickstart_example_taxes', array(t('Setting up example taxes.')));
  $operations[] = array('_commerce_kickstart_taxonomy_menu', array(t('Setting up menu.')));

  foreach ($migrations as $machine_name => $migration) {
    $operations[] =  array('_commerce_kickstart_import_example_products', array($machine_name, t('Setting up example display.')));
  }

  $operations[] = array('_commerce_kickstart_example_user', array(t('Setting up example user.')));
  $operations[] = array('_commerce_kickstart_post_enable_modules', array(t('Setting up example modules.')));

  // Batch api import products
  $batch = array(
    'title' => t('Importing Products'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'commerce_kickstart') . '/import/kickstart.import.inc',
  );
  variable_set('install_configure_seachapi', TRUE);

  return $batch;
}

/**
 * Helper function to create node.
 *
 * @param $content
 */
function _commerce_kickstart_custom_create_content($content) {
  $node = new stdClass();
  $node->is_new = TRUE;
  $node->language = LANGUAGE_NONE;
  $node->comment = '0';
  $node->title = $content['title'];
  $node->type = $content['type'];

  $instance = field_info_instance('node', 'body', $content['type']);
  if (!empty($instance) && isset($content['body'])) {
    $node->body[$node->language][0]['value']   = $content['body'];
    $node->body[$node->language][0]['format']  = 'filtered_html';
  }
  if (isset($content['path'])) {
    $node->path = array('alias' => $content['path']);
  }
  $instance = field_info_instance('node', 'field_image', $content['type']);
  if (!empty($instance) && isset($content['image'])) {
    $file_temp = file_get_contents(drupal_get_path('profile', 'commerce_kickstart') . '/import/images/' . $content['image']);
    $file_temp = file_save_data($file_temp, 'public://' . $content['image'], FILE_EXISTS_REPLACE);
    $node->field_image[$node->language][]['fid'] = $file_temp->fid;
  }
  $instance = field_info_instance('node', 'field_tags', $content['type']);
  if (!empty($instance) && isset($content['terms'])) {
    foreach($content['terms'] as $tid) {
      $node->field_tags[$node->language][] = array('tid' => $tid);
    }
  }
  $instance = field_info_instance('node', 'field_headline', $content['type']);
  if (!empty($instance) && isset($content['headline'])) {
    $node->field_headline[$node->language][0] = array('value' => $content['headline']);
  }
  $instance = field_info_instance('node', 'field_tagline', $content['type']);
  if (!empty($instance) && isset($content['tagline'])) {
    $node->field_tagline[$node->language][0] = array('value' => $content['tagline']);
  }
  $instance = field_info_instance('node', 'field_link', $content['type']);
  if (!empty($instance) && isset($content['link'])) {
    $node->field_link[$node->language][0] = array('url' => $content['link']);
  }
  node_object_prepare($node);
  node_save($node);
}

/**
 * Implements hook_update_projects_alter().
 */
function commerce_kickstart_update_projects_alter(&$projects) {
  // Enable update status for the Commerce Kickstart profile.
  $modules = system_rebuild_module_data();
  // The module object is shared in the request, so we need to clone it here.
  $kickstart = clone $modules['commerce_kickstart'];
  $kickstart->info['hidden'] = FALSE;
  _update_process_info_list($projects, array('commerce_kickstart' => $kickstart), 'module', TRUE);
}

/**
 * Implements hook_update_status_alter().
 *
 * Disable reporting of modules that are in the distribution, but only
 * if they have not been updated manually. In addition, we only hide security
 * issues if the distribution itself has not been updated.
 */
function commerce_kickstart_update_status_alter(&$projects) {
  if (!isset($projects['commerce_kickstart']['status'])) {
    // We cannot proceed if we don't know the update status of the distribution.
    return;
  }
  $distribution_secure = !in_array($projects['commerce_kickstart']['status'], array(UPDATE_NOT_SECURE, UPDATE_REVOKED, UPDATE_NOT_SUPPORTED));

  $make_filepath = drupal_get_path('module', 'commerce_kickstart') . '/drupal-org.make';
  if (!file_exists($make_filepath)) {
    // We cannot proceed if we cannot find a proper makefile for the distribution.
    return;
  }

  $make_info = drupal_parse_info_file($make_filepath);
  foreach ($projects as $project_name => $project_info) {
    if (!isset($project_info['info']['version']) || !isset($make_info['projects'][$project_name])) {
      // Don't hide a project that is not shipped with the distribution.
      continue;
    }
    if ($distribution_secure && in_array($project_info['status'], array(UPDATE_NOT_SECURE, UPDATE_REVOKED, UPDATE_NOT_SUPPORTED))) {
      // Don't hide a project that is in a security state if the distribution
      // is not in a security state.
      continue;
    }
    if (is_string($make_info['projects'][$project_name])) {
      $make_project_version = $make_info['projects'][$project_name];
    }
    elseif (is_array($make_info['projects'][$project_name]) && isset($make_info['projects'][$project_name]['version'])) {
      $make_project_version = $make_info['projects'][$project_name]['version'];
    }
    else {
      break;
    }

    // Current version matches the version we shipped, remove it from the list.
    if (DRUPAL_CORE_COMPATIBILITY . '-' . $make_project_version == $project_info['info']['version']) {
      $projects['commerce_kickstart']['includes'][$project_info['name']] = $project_info['info']['name'];
      unset($projects[$project_name]);
    }
  }
}
