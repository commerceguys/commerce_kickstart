<?php
/**
 * @file
 * commerce_kickstart_products.features.inc
 */

/**
 * Implements hook_commerce_flat_rate_default_services().
 */
function commerce_kickstart_products_commerce_flat_rate_default_services() {
  $items = array(
    'express_shipping' => array(
      'name' => 'express_shipping',
      'base' => 'express_shipping',
      'display_title' => 'Express Shipping',
      'description' => 'An express shipping service for a 2 days shipping.',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_express_shipping',
      'weight' => 0,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'express_shipping_details_form',
        'details_form_validate' => 'express_shipping_details_form_validate',
        'details_form_submit' => 'express_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Express Shipping',
      'base_rate' => array(
        'amount' => '1500',
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'free_shipping' => array(
      'name' => 'free_shipping',
      'base' => 'free_shipping',
      'display_title' => 'Free Shipping',
      'description' => 'A free shipping service for order over a certain amount.',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_free_shipping',
      'weight' => 1,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'free_shipping_details_form',
        'details_form_validate' => 'free_shipping_details_form_validate',
        'details_form_submit' => 'free_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Free Shipping',
      'base_rate' => array(
        'amount' => '0',
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'standard_shipping' => array(
      'name' => 'standard_shipping',
      'base' => 'standard_shipping',
      'display_title' => 'Standard Shipping',
      'description' => 'A standard shipping service for order under a certain amount.',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_standard_shipping',
      'weight' => 2,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'standard_shipping_details_form',
        'details_form_validate' => 'standard_shipping_details_form_validate',
        'details_form_submit' => 'standard_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Standard Shipping',
      'base_rate' => array(
        'amount' => '800',
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_views_api().
 */
function commerce_kickstart_products_views_api() {
  return array("version" => "3.0");
}
