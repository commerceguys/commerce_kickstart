<?php

/**
 * Implements hook_form_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function commerce_kickstart_form_install_configure_form_alter(&$form, $form_state) {
  // Set a default name for the dev site.
  $form['site_information']['site_name']['#default_value'] = t('Commerce Kickstart');

  // Set a default country so we can benefit from it on Address Fields.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
}

/**
 * Implements hook_install_tasks().
 */
function commerce_kickstart_install_tasks() {
  $tasks = array();

  // Add a page allowing the user to indicate they'd like to install demo content.
  $tasks['commerce_kickstart_example_store_form'] = array(
    'display_name' => st('Example store'),
    'type' => 'form',
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
    'product_displays' => st('Product display nodes (if <em>Products</em> is selected)'),
  );

  $form['example_content'] = array(
    '#type' => 'checkboxes',
    '#title' => st('Create example content for the following store components:'),
    '#description' => st('The example content is not comprehensive but illustrates how the basic components work.'),
    '#options' => $options,
    '#default_value' => drupal_map_assoc(array_keys($options)),
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
  $created_products = array();
  $created_nodes = array();

  // First create products if specified.
  if (!empty($example_content['products'])) {
    $product_names = array(
      '01' => st('Product One'),
      '02' => st('Product Two'),
      '03' => st('Product Three')
    );

    foreach ($product_names as $sku => $title) {
      // Create the new product.
      $product = commerce_product_new('product');
      $product->sku = 'PROD-' . $sku;
      $product->title = $title;
      $product->language = LANGUAGE_NONE;
      $product->uid = 1;

      // Set a default price.
      $product->commerce_price[LANGUAGE_NONE][0]['amount'] = $sku * 1000;
      $product->commerce_price[LANGUAGE_NONE][0]['currency_code'] = 'USD';

      // Save it and retain a copy.
      commerce_product_save($product);
      $created_products[] = $product;

      // Create a node display for the product if specified.
      if (!empty($example_content['product_displays'])) {
        // Create the new node.
        $node = (object) array('type' => 'product_display');
        node_object_prepare($node);
        $node->title = $product->title;
        $node->uid = 1;

        // Reference the product we just made.
        $node->field_product[LANGUAGE_NONE][]['product_id'] = $product->product_id;

        // Make sure we set the default language
        $node->language = LANGUAGE_NONE;

        // Save it and retain a copy.
        node_save($node);
        $created_nodes[] = $node;
      }
    }
  }
}

/**
 * Creates a Catalog taxonomy vocabulary and adds a term reference field for it
 * to the default product display node type.
 *
 * @todo This function is currently unused but should be added in as an option
 * for example content creation.
 */
function _commerce_kickstart_create_example_catalog() {
  // Create a default Catalog vocabulary for the Product display node type.
  $description = st('Describes a hierarchy for the product catalog.');
  $vocabulary = (object) array(
    'name' => st('Catalog'),
    'description' => $description,
    'machine_name' => 'catalog',
    'help' => '',
  );
  taxonomy_vocabulary_save($vocabulary);

  $field = array(
    'field_name' => 'taxonomy_' . $vocabulary->machine_name,
    'type' => 'taxonomy_term_reference',
    'cardinality' => 1,
    'settings' => array(
      'allowed_values' => array(
        array(
          'vocabulary' => $vocabulary->machine_name,
          'parent' => 0,
        ),
      ),
    ),
  );
  field_create_field($field);

  $instance = array(
    'field_name' => 'taxonomy_' . $vocabulary->machine_name,
    'entity_type' => 'node',
    'label' => st('Catalog category'),
    'bundle' => 'product_display',
    'description' => '',
    'widget' => array(
      'type' => 'options_select',
    ),
  );
  field_create_instance($instance);
}

/**
 * Creates an image field on the specified entity bundle.
 */
function _commerce_kickstart_create_product_image_field($entity_type, $bundle) {
  // Add a default image field to the specified product type.
  $instance = array(
    'field_name' => 'field_image',
    'entity_type' => $entity_type,
    'label' => st('Image'),
    'bundle' => $bundle,
    'description' => st('Upload an image for this product.'),
    'required' => FALSE,

    'settings' => array(
      'file_directory' => 'field/image',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => TRUE,
      'title_field' => '',
    ),

    'widget' => array(
      'type' => 'image_image',
      'settings' => array(
        'progress_indicator' => 'throbber',
        'preview_image_style' => 'thumbnail',
      ),
      'weight' => -1,
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'medium', 'image_link' => 'file'),
        'weight' => -1,
      ),
      'full' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'medium', 'image_link' => 'file'),
        'weight' => -1,
      ),
      'line_item' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'thumbnail', 'image_link' => ''),
        'weight' => -1,
      ),
      'node_full' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'medium', 'image_link' => 'file'),
        'weight' => -1,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'thumbnail', 'image_link' => 'content'),
        'weight' => -1,
      ),
      'node_rss' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'medium', 'image_link' => ''),
        'weight' => -1,
      ),
    ),
  );
  field_create_instance($instance);
}

/**
 * Creates a product reference field on the specified entity bundle.
 */
function _commerce_kickstart_create_product_reference($entity_type, $bundle, $field_name = 'field_product') {
  // Add a product reference field to the Product display node type.
  $field = array(
    'field_name' => $field_name,
    'type' => 'commerce_product_reference',
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'translatable' => FALSE,
  );
  field_create_field($field);

  $instance = array(
    'field_name' => $field_name,
    'entity_type' => $entity_type,
    'label' => st('Product'),
    'bundle' => $bundle,
    'description' => st('Choose the product(s) to display for sale on this node by SKU. Enter multiple SKUs using a comma separated list.'),
    'required' => TRUE,

    'widget' => array(
      'type' => 'commerce_product_reference_autocomplete',
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'commerce_cart_add_to_cart_form',
      ),
      'full' => array(
        'label' => 'hidden',
        'type' => 'commerce_cart_add_to_cart_form',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'commerce_cart_add_to_cart_form',
      ),
    ),
  );
  field_create_instance($instance);
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
  $distribution_secure = !in_array($projects['commerce_kickstart']['status'], array(UPDATE_NOT_SECURE, UPDATE_REVOKED, UPDATE_NOT_SUPPORTED));
  $make_filepath = drupal_get_path('module', 'commerce_kickstart') . '/drupal-org.make';
  if (!file_exists($make_filepath)) {
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
    $make_project_version = is_array($make_info['projects'][$project_name]) ? $make_info['projects'][$project_name]['version'] : $make_info['projects'][$project_name];

    // Current version matches the version we shipped, remove it from the list.
    if (DRUPAL_CORE_COMPATIBILITY . '-' . $make_project_version == $project_info['info']['version']) {
      $projects['commerce_kickstart']['includes'][$project_info['name']] = $project_info['info']['name'];
      unset($projects[$project_name]);
    }
  }
}
