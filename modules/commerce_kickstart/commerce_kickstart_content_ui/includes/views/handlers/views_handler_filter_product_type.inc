<?php

/**
 * Simple filter for Product Displays.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_product_type extends views_handler_filter_in_operator
{
  function can_expose() {
    return FALSE;
  }

  function admin_summary() {
    return $this->operator == 'in' ? t('Yes') : t('No');
  }

  function operators() {
    $operators = array(
      'in' => array(
        'title' => t('Is Product Display'),
        'short' => t('in'),
        'short_single' => t('='),
        'method' => 'op_simple',
        'values' => 1,
      ),
      'not in' => array(
        'title' => t('Is not Product Display'),
        'short' => t('not in'),
        'short_single' => t('<>'),
        'method' => 'op_simple',
        'values' => 1,
      ),
    );

    return $operators;
  }

  function op_simple() {
    if (empty($this->value)) {
      $this->value = array_keys(commerce_product_reference_node_types());
    }
    $this->ensure_my_table();

    $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", array_values($this->value), $this->operator);
  }

  function ensure_table($table, $relashionship) {
    return 'node';
  }

  function value_form(&$form, &$form_state) {
    $form['value'] = array();
  }
}
