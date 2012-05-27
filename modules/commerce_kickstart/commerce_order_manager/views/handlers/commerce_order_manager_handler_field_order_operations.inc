<?php

/**
 * Displays the order operations in a ctools dropbutton.
 *
 * @ingroup views_field_handlers
 */
class commerce_order_manager_handler_field_order_operations extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['order_id'] = 'order_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $order_id = $this->get_value($values, 'order_id');
    $links = menu_contextual_links('commerce-order', 'admin/commerce/orders', array($order_id));
    // Remove the View link, that functionality opens in a megarow.
    array_shift($links);

    $element = array(
      '#markup' => theme('links__ctools_dropbutton', array('links' => $links, 'attributes' => array('class' => array('links', 'inline')))),
    );

    return $element;
  }
}
