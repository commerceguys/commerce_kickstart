<?php

/**
 * Implements hook_rules_action_info().
 */
function commerce_kickstart_product_ui_rules_action_info() {
  return array(
    'commerce_kickstart_add_to_cart_message' => array(
      'label' => t('Kickstart Add to Cart message'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
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
function commerce_kickstart_product_ui_rules_add_to_cart_message($line_item) {
  $message = '<div class="added-product-title clearfix">' . t('Item successfully added to your cart') . '</div>';

  $message .= '<div class="button-wrapper">';
  $message .= '<div class="button checkout">' . l(t('Go to checkout'), 'cart') . '</div>';
  $message .= '<div class="button continue"><span class="commerce-kickstart-add-to-cart-close">' . t('Continue shopping') . '</span></div>';
  $message .= '</div>';
  $message .= views_embed_view('confirm_message_product_display', 'default', $line_item->line_item_id);

  $close = t('Close');

  drupal_set_message('<div class="message-inner">' . $message . '<a class="commerce-kickstart-add-to-cart-close" href="#"><span class="element-invisible">' . $close . '</span></a></div>', 'commerce-kickstart-add-to-cart');
}
