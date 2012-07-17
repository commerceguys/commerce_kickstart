<?php

/**
 * Implements hook_form_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function commerce_kickstart_form_install_configure_form_alter(&$form, $form_state) {
  // Since any module can add a drupal_set_message, this can bug the user
  // when we display this page. For a better user experience,
  // remove all the messages.
  drupal_get_messages(NULL, TRUE);

  // Set a default name for the dev site and change title's label.
  $form['site_information']['site_name']['#title'] = 'Store name';
  $form['site_information']['site_mail']['#title'] = 'Store email address';
  $form['site_information']['site_name']['#default_value'] = t('Commerce Kickstart');

  // Set a default country so we can benefit from it on Address Fields.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';

  // Use "admin" as the default username.
  $form['admin_account']['account']['name']['#default_value'] = 'admin';

  // Set the default admin password.
  $form['admin_account']['account']['pass']['#value'] = 'admin';

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
    '#markup' => '<p>' . t('This information will be emailed to the store email address.') . '</p>'
  );
  $form['admin_account']['override_account_informations'] = array(
    '#type' => 'checkbox',
    '#title' => t('Change my username and password.'),
  );
  $form['admin_account']['setup_account'] = array(
    '#type' => 'container',
    '#parents' => array('admin_account'),
    '#states' => array(
      'invisible' => array(
        'input[name="override_account_informations"]' => array('checked' => FALSE),
      ),
    ),
  );

  // Make a "copy" of the original name and pass form fields.
  $form['admin_account']['setup_account']['account']['name'] = $form['admin_account']['account']['name'];
  $form['admin_account']['setup_account']['account']['pass'] = $form['admin_account']['account']['pass'];

  // Use "admin" as the default username.
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['name']['#access'] = FALSE;

  // Set the default admin password.
  $form['admin_account']['account']['pass']['#value'] = 'admin';

  // Make the password "hidden".
  $form['admin_account']['account']['pass']['#type'] = 'hidden';
  $form['admin_account']['account']['mail']['#access'] = FALSE;

  // Add a custom validation that needs to be trigger before the original one,
  // where we can copy the site's mail as the admin account's mail.
  array_unshift($form['#validate'], 'commerce_kickstart_custom_setting');
}

/**
 * Validate callback; Populate the admin account mail, user and password with
 * custom values.
 */
function commerce_kickstart_custom_setting(&$form, &$form_state) {
  $form_state['values']['account']['mail'] = $form_state['values']['site_mail'];
  // Use our custom values only the corresponding checkbox is checked.
  if ($form_state['values']['override_account_informations'] == TRUE) {
    if ($form_state['input']['pass']['pass1'] == $form_state['input']['pass']['pass2']) {
      $form_state['values']['account']['name'] = $form_state['values']['name'];
      $form_state['values']['account']['pass'] = $form_state['input']['pass']['pass1'];
    }
  else {
      form_set_error('pass', t('The specified passwords do not match.'));
    }
  }
}

/**
 * Implements hook_install_tasks().
 */
function commerce_kickstart_install_tasks() {
  // Since any module can add a drupal_set_message, this can bug the user
  // when we display this page. For a better user experience,
  // remove all the messages.
  drupal_get_messages(NULL, TRUE);
  $tasks = array();
  $current_task = variable_get('install_task', 'done');
  $install_demo_store = variable_get('commerce_kickstart_demo_store', FALSE);

  $tasks['commerce_kickstart_configure_store_form'] = array(
    'display_name' => st('Configure store'),
    'type' => 'form',
  );
  $tasks['commerce_kickstart_install_additional_modules'] = array(
    'display_name' => $install_demo_store ? st('Install demo store') : st('Install additional functionality'),
    'type' => 'batch',
    // Show this task only after the Kickstart steps have bene reached.
    'display' => strpos($current_task, 'commerce_kickstart_') !== FALSE,
  );
  $tasks['commerce_kickstart_import_content'] = array(
    'display_name' => st('Import content'),
    'type' => 'batch',
    // Show this task only after the Kickstart steps have bene reached.
    'display' => strpos($current_task, 'commerce_kickstart_') !== FALSE,
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
  drupal_set_title(st('Configure store'));

  // Prepare all the options for sample content.
  $options = array(
    '1' => st('Yes'),
    '0' => st('No'),
  );
  $form['functionality'] = array(
    '#type' => 'fieldset',
    '#title' => st('Functionality'),
  );
  $form['functionality']['install_demo_store'] = array(
    '#type' => 'radios',
    '#title' => st('Do you want to install the demo store?'),
    '#description' => st('Shows you everything Commerce Kickstart can do. Includes a custom theme, sample content and products.'),
    '#options' => $options,
    '#default_value' => '1',
  );

  $options_selection = array(
    'merchandising' => 'Frontpage <strong>slideshow</strong> and additional <strong>blocks</strong> for featuring specific content.',
    'menus' => 'Custom <strong>admin menu</strong> designed for store owners.',
    'blog' => '<strong>Blog</strong> functionality.',
    'social' => '<strong>Social</strong> logins and links for sharing products via social networks.',
    'zoom_cloud' => '<strong>Zoom & Gallery</strong> mode for products.',
  );
  $form['functionality']['extras'] = array(
    '#type' => 'checkboxes',
    '#options' => $options_selection,
    '#title' => t("Install additional functionality"),
    '#states' => array(
      'visible' => array(
        ':input[name="install_demo_store"]' => array('value' => '0'),
      ),
    ),
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
    '#options' => $options,
    '#default_value' => commerce_default_currency(),
  );

  // Prepare all the options for sample content.
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
 * Submit callback: creates the requested sample content.
 */
function commerce_kickstart_configure_store_form_submit(&$form, &$form_state) {
  variable_set('commerce_kickstart_demo_store', $form_state['values']['install_demo_store']);
  variable_set('commerce_kickstart_selected_extras', $form_state['values']['extras']);
  variable_set('commerce_kickstart_choose_tax_country', $form_state['values']['commerce_kickstart_choose_tax_country']);
  variable_set('commerce_default_currency', $form_state['values']['commerce_default_currency']);
}

/**
 * Task callback: uses Batch API to import modules based on user selection.
 * Installs all demo store modules if requested, or any modules providing
 * additional functionality to the base install.
 */
function commerce_kickstart_install_additional_modules() {
  $install_demo_store = variable_get('commerce_kickstart_demo_store', FALSE);
  if ($install_demo_store) {
    $modules = array(
      'commerce_kickstart_social',
      'commerce_kickstart_content',
      'commerce_kickstart_search',
      'commerce_kickstart_product',
      'commerce_kickstart_product_ui',
      'commerce_kickstart_blog',
      'commerce_kickstart_blog_ui',
      'commerce_kickstart_merchandising',
      'commerce_kickstart_merchandising_ui',
      'commerce_kickstart_menus',
      'commerce_kickstart_user',
      'commerce_kickstart_migrate',
    );
  }
  else {
    $modules = array(
      'commerce_kickstart_content',
      'commerce_kickstart_lite_search',
      'commerce_kickstart_lite_product',
      'commerce_kickstart_lite_product_ui',
      'commerce_kickstart_migrate',
    );
    $selected_extras = variable_get('commerce_kickstart_selected_extras', array());
    if (!empty($selected_extras['merchandising'])) {
      $modules[] = 'commerce_kickstart_merchandising';
      $modules[] = 'commerce_kickstart_merchandising_ui';
    }
    if (!empty($selected_extras['menus'])) {
      $modules[] = 'commerce_kickstart_menus';
    }
    if (!empty($selected_extras['blog'])) {
      $modules[] = 'commerce_kickstart_blog';
      $modules[] = 'commerce_kickstart_blog_ui';
    }
    if (!empty($selected_extras['social'])) {
      $modules[] = 'commerce_kickstart_social';
    }
    if (!empty($selected_extras['zoom_cloud'])) {
      $modules[] = 'commerce_kickstart_lite_product_zoom';
    }
  }

  // Resolve the dependencies now, so that module_enable() doesn't need
  // to do it later for each individual module (which kills performance).
  $files = system_rebuild_module_data();
  $modules_sorted = array();
  foreach ($modules as $module) {
    if ($files[$module]->requires) {
      // Create a list of dependencies that haven't been installed yet.
      $dependencies = array_keys($files[$module]->requires);
      $dependencies = array_filter($dependencies, '_commerce_kickstart_filter_dependencies');
      // Add them to the module list.
      $modules = array_merge($modules, $dependencies);
    }
  }
  $modules = array_unique($modules);
  foreach ($modules as $module) {
    $modules_sorted[$module] = $files[$module]->sort;
  }
  arsort($modules_sorted);

  $operations = array();
  foreach ($modules_sorted as $module => $weight) {
    $operations[] = array('_commerce_kickstart_enable_module', array($module, $files[$module]->info['name']));
  }
  $operations[] = array('_commerce_kickstart_flush_caches', array(t('Flushed caches.')));

  $batch = array(
    'title' => $install_demo_store ? t('Installing demo store') : t('Installing additional functionality'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'commerce_kickstart') . '/import/kickstart.import.inc',
  );

  return $batch;
}

/**
 * array_filter() callback used to filter out already installed dependencies.
 */
function _commerce_kickstart_filter_dependencies($dependency) {
  return !module_exists($dependency);
}

/**
 * Task callback: return a batch API array with the products to be imported.
 */
function commerce_kickstart_import_content() {
  // Fixes problems when the CSV files used for importing have been created
  // on a Mac, by forcing PHP to detect the appropriate line endings.
  ini_set("auto_detect_line_endings", TRUE);

  $operations = array();
  $operations[] = array('_commerce_kickstart_example_taxes', array(t('Setting up taxes.')));

  $install_demo_store = variable_get('commerce_kickstart_demo_store', FALSE);
  if ($install_demo_store) {
    $operations[] = array('_commerce_kickstart_taxonomy_menu', array(t('Setting up menus.')));
    $operations[] = array('_commerce_kickstart_example_user', array(t('Setting up users.')));
  }

  // Run all available migrations.
  $migrations = migrate_migrations();
  foreach ($migrations as $machine_name => $migration) {
    $operations[] = array('_commerce_kickstart_import', array($machine_name, t('Importing content.')));
  }

  // Perform post-import tasks.
  $operations[] = array('_commerce_kickstart_post_import', array(t('Completing setup.')));

  $batch = array(
    'title' => t('Importing content'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'commerce_kickstart') . '/import/kickstart.import.inc',
  );

  return $batch;
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
  $distribution_secure = !in_array($projects['commerce_kickstart']['status'], array(
    UPDATE_NOT_SECURE,
    UPDATE_REVOKED,
    UPDATE_NOT_SUPPORTED
  ));

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
    if ($distribution_secure && in_array($project_info['status'], array(
      UPDATE_NOT_SECURE,
      UPDATE_REVOKED,
      UPDATE_NOT_SUPPORTED
    ))
    ) {
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
