<?php
/**
 * @file
 * commerce_kickstart_lite_product_ui.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_kickstart_lite_product_ui_default_rules_configuration() {
  $items = array();
  $items['commerce_kickstart_add_to_cart_message'] = entity_import('rules_config', '{ "commerce_kickstart_add_to_cart_message" : {
      "LABEL" : "Kickstart Add to Cart message",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "commerce_kickstart_lite_product_ui", "commerce_cart" ],
      "ON" : [ "commerce_cart_product_add" ],
      "DO" : [ { "commerce_kickstart_add_to_cart_message" : [] } ]
    }
  }');
  return $items;
}

/*
 * Implements hook_default_rules_configuration_alter().
 */
function commerce_kickstart_lite_product_ui_default_rules_configuration_alter(&$configs) {
  if (isset($configs['commerce_cart_add_to_cart_message'])) {
    // Disable the default add-to-cart message.
    $configs['commerce_cart_add_to_cart_message']->active = FALSE;
  }
}
