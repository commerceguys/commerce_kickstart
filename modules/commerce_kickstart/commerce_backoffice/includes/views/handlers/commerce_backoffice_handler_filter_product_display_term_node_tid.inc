<?php

/**
 * @file
 * Definition of ommerce_backoffice_handler_filter_product_display_term_node_tid.
 */

/**
 * Filter by term id.
 *
 * @ingroup views_filter_handlers
 */
class commerce_backoffice_handler_filter_product_display_term_node_tid extends views_handler_filter_term_node_tid {

  function init(&$view, &$options) {
    parent::init($view, $options);
    // change the vocbaularies options, limit to product displays
    $this->options['all_vocabularies'] = _commerce_backoffice_product_display_vocabularies();
  }
}
