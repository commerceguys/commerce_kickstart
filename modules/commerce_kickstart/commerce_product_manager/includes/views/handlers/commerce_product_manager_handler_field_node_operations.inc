<?php

/**
 * Displays the product operations in a ctools dropbutton.
 *
 * @ingroup views_field_handlers
 */
class commerce_product_manager_handler_field_node_operations extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['nid'] = 'nid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $nid = $this->get_value($values, 'nid');
    $links = menu_contextual_links('node', 'node', array($nid));

    $element = array(
      '#markup' => theme('links__ctools_dropbutton', array('links' => $links, 'attributes' => array('class' => array('links', 'inline')))),
    );

    return $element;
  }
}
