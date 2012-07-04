<?php

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_kickstart_lite_product_ui_default_rules_configuration() {
  // Add a reaction rule to display a custom Add to Cart message.
  $rule = rules_reaction_rule();
  $rule->label = t('Kickstart Add to Cart message');
  $rule->active = TRUE;
  $rule->event('commerce_cart_product_add')
    ->action('commerce_kickstart_add_to_cart_message', array(
    'commerce_product:select' => 'commerce-product',
  ));

  $configs['commerce_kickstart_add_to_cart_message'] = $rule;
  return $configs;
}

/*
 * Implements hook_default_rules_configuration_alter().
 */
function commerce_kickstart_lite_product_ui_default_rules_configuration_alter(&$configs) {
  // Disable the default add-to-cart message.
  $configs['commerce_cart_add_to_cart_message']->active = FALSE;
}
