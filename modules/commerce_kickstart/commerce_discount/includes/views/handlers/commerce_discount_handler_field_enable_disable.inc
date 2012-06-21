<?php

/**
 * Field handler to show enable / disable widget.
 */
class commerce_discount_handler_field_enable_disable extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['discount_id'] = 'discount_id';

    // Set real_field in order to make it generate a field_alias.
    $this->real_field = 'discount_id';
  }

  function render($values) {
    drupal_add_library('system', 'drupal.ajax');
    // Load the line item and return its title.
    $discount_id = $this->get_value($values, 'discount_id');
    $commerce_discount = entity_load_single('commerce_discount', $discount_id);

    $entity_info = entity_get_info('commerce_discount');
    $path = $entity_info['admin ui']['path'] . '/manage';

    $content = commerce_discount_state_switch_content($commerce_discount->enabled, $discount_id);

    return "<div class=\"discount-$discount_id\">$content</div>";
  }
}
