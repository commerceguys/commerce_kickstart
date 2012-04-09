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
  $tasks['commerce_kickstart_example_store_form'] = array(
    'display_name' => st('Example store'),
    'type' => 'form',
  );
  $tasks['commerce_kickstart_import_product'] = array(
    'display_name' => st('Example store'),
    'display' => $import_product,
    'type' => 'normal',
    'run' => $import_product ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
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

  $form['choose_country'] = array(
    '#type' => 'checkboxes',
    '#title' => st('Setup default currency and taxes:'),
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
  $country = $form_state['values']['choose_country'];

  // Create products if specified.
  if (!empty($example_content['products'])) {
    variable_set('import_product', TRUE);

    // Enable an other theme.
    theme_enable(array('garland'));
    variable_set('theme_default', 'garland');
  }
}

function commerce_kickstart_import_product()  {
  module_enable(array(
    'features',
    'commerce_features',
    'ft_dsc_architecture'
  ));
  features_rebuild();
  module_enable(array('demo', 'demo_content'));
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
    'label' => st('Product variations'),
    'bundle' => $bundle,
    'required' => TRUE,

    'widget' => array(
      'type' => 'inline_entity_form',
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

