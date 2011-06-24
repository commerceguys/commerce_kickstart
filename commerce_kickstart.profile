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

function commerce_kickstart_install_tasks() {
  $tasks['commerce_kickstart_demo_form'] = array(
    'display_name' => st('Demo content'),
    'type' => 'form',
  );

  return $tasks;
}

function commerce_kickstart_demo_form() {
  drupal_set_title(st('Demo content'));

  $form['demo_content'] = array(
    '#type' => 'radios',
    '#title' => st('Create some demo content?'),
    '#options' => array(
      1 => st('Yes please'),
      0 => st("No thanks, I'm a rockstar already"),
    ),
    '#default_value' => 1,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    '#weight' => 15,
  );

  return $form;
}

function commerce_kickstart_demo_form_submit(&$form, &$form_state) {
  if ($form_state['values']['demo_content']) {
    $product = commerce_product_new('product');
    $product->sku = 'TESTPRODUCT';
    $product->title = st('Test product');
    $product->title = st('Test product');
    $product->commerce_price[LANGUAGE_NONE][0]['amount'] = rand(2, 500);
    $product->commerce_price[LANGUAGE_NONE][0]['currency_code'] = 'USD';
    commerce_product_save($product);
  }
}
