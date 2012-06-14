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
  $message = t('%title successfully added to <a href="!cart-url">your cart</a>.', array('%title' => $product->title, '!cart-url' => url('cart')));
  $close = t('Close');
  drupal_set_message('<div class="message-inner">' . $message . '<a class="commerce-kickstart-add-to-cart-close" href="#"><span class="element-invisible">' . $close . '</span></a></div>', 'commerce-kickstart-add-to-cart');
}
