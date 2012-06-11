<?php

/**
 * Implements hook_rules_action_info().
 */
function commerce_kickstart_product_ui_rules_action_info() {
  return array(
    'commerce_kickstart_add_to_cart_message' => array(
      'label' => t('Kickstart Add to Cart message'),
      'parameter' => array(
        'commerce_product' => array(
          'type' => 'commerce_product',
          'label' => t('Product added to the cart'),
        ),
      ),
      'group' => t('Commerce Kickstart'),
      'callbacks' => array(
        'execute' => 'commerce_kickstart_product_ui_rules_add_to_cart_message',
      ),
    )
  );
}

/**
 * Rules action: displays a custom Add to Cart message.
 */
function commerce_kickstart_product_ui_rules_add_to_cart_message($product) {
  drupal_set_message(t('%title successfully added to your cart', array('%title' => $product->title)), 'commerce-kickstart-add-to-cart');
}
