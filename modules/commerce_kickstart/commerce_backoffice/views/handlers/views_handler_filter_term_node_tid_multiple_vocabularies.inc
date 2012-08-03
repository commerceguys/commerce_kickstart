<?php

/**
 * @file
 * Definition of views_handler_filter_term_node_tid_multiple_vocabularies.
 */

/**
 * Filter by term id.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_term_node_tid_multiple_vocabularies extends views_handler_filter_term_node_tid {
  // Stores the exposed input for this filter.
  var $validated_exposed_input = NULL;

  function init(&$view, &$options) {
    parent::init($view, $options);
    if (!empty($this->definition['vocabulary'])) {
      $this->options['vocabulary'] = $this->definition['vocabulary'];
    }

    // Convert legacy vid option to machine name vocabulary.
    if (isset($this->options['vid']) && !empty($this->options['vid']) & empty($this->options['vocabulary'])) {
      $vocabularies = taxonomy_get_vocabularies();
      $vid = $this->options['vid'];
      if (isset($vocabularies[$vid], $vocabularies[$vid]->machine_name)) {
        $this->options['vocabulary'] = $vocabularies[$vid]->machine_name;
      }
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['per_vocabulary'] = array('default' => 0);

    return $options;
  }

  function extra_options_form(&$form, &$form_state) {
    $vocabularies = taxonomy_get_vocabularies();
    $options = array();
    foreach ($vocabularies as $voc) {
      $options[$voc->vid] = check_plain($voc->name);
    }

    if ($this->options['limit']) {
      // We only do this when the form is displayed.
      if (empty($this->options['vocabulary'])) {
        $first_vocabulary = reset($vocabularies);
        $this->options['vocabulary'] = $first_vocabulary->machine_name;
      }

      if (empty($this->definition['vocabulary'])) {
        $form['vocabulary'] = array(
          '#type' => 'checkboxes',
          '#title' => t('Vocabulary'),
          '#options' => $options,
          '#description' => t('Select which vocabulary to show terms for in the regular options.'),
          '#default_value' => $this->options['vocabulary'],
        );
      }
    }

    $form['per_vocabulary'] = array(
      '#type' => 'checkbox',
      '#title' => t('Each vocabulary separately'),
      '#description' => t('Like independent filter per vocabulary.'),
      '#default_value' => !empty($this->options['per_vocabulary']),
    );

    $form['hierarchy'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show hierarchy in dropdown'),
      '#default_value' => !empty($this->options['hierarchy']),
    );

  }

  function value_form(&$form, &$form_state) {
    $vocabularies = taxonomy_vocabulary_load_multiple($this->options['vocabulary']);
    if (empty($vocabularies) && $this->options['limit']) {
      $form['markup'] = array(
        '#markup' => '<div class="form-item">' . t('An invalid vocabulary is selected. Please change it in the options.') . '</div>',
      );
      return;
    }

    if ($this->options['type'] == 'textfield') {
      $default = '';
      if ($this->value) {
        $result = db_select('taxonomy_term_data', 'td')
          ->fields('td')
          ->condition('td.tid', $this->value)
          ->execute();
        foreach ($result as $term) {
          if ($default) {
            $default .= ', ';
          }
          $default .= $term->name;
        }
      }

      $form['value'] = array(
        '#title' => $this->options['limit'] ? t('Select terms from vocabulary @voc', array('@voc' => $vocabulary->name)) : t('Select terms'),
        '#type' => 'textfield',
        '#default_value' => $default,
      );

      if ($this->options['limit']) {
        $form['value']['#autocomplete_path'] = 'admin/views/ajax/autocomplete/taxonomy/' . $vocabulary->vid;
      }
    }
    else {
      $options = array();
      $vocabularies_names = array();
      foreach ($vocabularies as $vocabulary) {
        $options[$vocabulary->name] = array();
        $vocabularies_names[] = $vocabulary->name;
        if (!empty($this->options['hierarchy']) && $this->options['limit']) {
          $tree = taxonomy_get_tree($vocabulary->vid);
          if ($tree) {
            foreach ($tree as $term) {
              $choice = new stdClass();
              if (!empty($this->options['per_vocabulary'])) {
                $choice->option = array($term->vid . '-' . $term->tid => str_repeat('-', $term->depth) . $term->name);
              }
              else {
                $choice->option = array($term->tid => str_repeat('-', $term->depth) . $term->name);
              }
              $options[$vocabulary->name][] = $choice;
            }
          }
        }
        else {
          $query = db_select('taxonomy_term_data', 'td');
          $query->innerJoin('taxonomy_vocabulary', 'tv', 'td.vid = tv.vid');
          $query->fields('td');
          $query->orderby('tv.weight');
          $query->orderby('tv.name');
          $query->orderby('td.weight');
          $query->orderby('td.name');
          $query->addTag('term_access');
          if ($this->options['limit']) {
            $query->condition('tv.machine_name', $vocabulary->machine_name);
          }
          $result = $query->execute();
          foreach ($result as $term) {
            if (!empty($this->options['per_vocabulary'])) {
              $options[$vocabulary->name][$term->vid . '-' . $term->tid] = $term->name;
            }
            else {
              $options[$vocabulary->name][$term->tid] = $term->name;
            }
          }
        }
      }

      $default_value = (array) $this->value;

      if (!empty($form_state['exposed'])) {
        $identifier = $this->options['expose']['identifier'];

        if (!empty($this->options['expose']['reduce'])) {
          $options = $this->reduce_value_options($options);

          if (!empty($this->options['expose']['multiple']) && empty($this->options['expose']['required'])) {
            $default_value = array();
          }
        }

        if (empty($this->options['expose']['multiple'])) {
          if (empty($this->options['expose']['required']) && (empty($default_value) || !empty($this->options['expose']['reduce']))) {
            $default_value = 'All';
          }
          elseif (empty($default_value)) {
            $keys = array_keys($options);
            $default_value = array_shift($keys);
          }
          // Due to #1464174 there is a chance that array('') was saved in the admin ui.
          // Let's choose a safe default value.
          elseif ($default_value == array('')) {
            $default_value = 'All';
          }
          else {
            $copy = $default_value;
            $default_value = array_shift($copy);
          }
        }
      }
      $form['value'] = array(
        '#type' => 'select',
        '#title' => $this->options['limit'] ? t('Select terms from vocabularies @voc', array('@voc' => implode(', ', $vocabularies_names))) : t('Select terms'),
        '#multiple' => TRUE,
        '#options' => $options,
        '#size' => min(9, count($options, COUNT_RECURSIVE)),
        '#default_value' => $default_value,
      );

      if (!empty($form_state['exposed']) && isset($identifier) && !isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $default_value;
      }
    }


    if (empty($form_state['exposed'])) {
      // Retain the helper option
      $this->helper->options_form($form, $form_state);
    }
  }

  /**
   * Validate the user string. Since this can come from either the form
   * or the exposed filter, this is abstracted out a bit so it can
   * handle the multiple input sources.
   *
   * @param $form
   *   The form which is used, either the views ui or the exposed filters.
   * @param $values
   *   The taxonomy names which will be converted to tids.
   *
   * @return array
   *   The taxonomy ids fo all validated terms.
   */
  function validate_term_strings(&$form, $values) {
    if (empty($values)) {
      return array();
    }

    $tids = array();
    $names = array();
    $missing = array();
    foreach ($values as $value) {
      $missing[strtolower($value)] = TRUE;
      $names[] = $value;
    }

    if (!$names) {
      return FALSE;
    }

    $query = db_select('taxonomy_term_data', 'td');
    $query->innerJoin('taxonomy_vocabulary', 'tv', 'td.vid = tv.vid');
    $query->fields('td');
    $query->condition('td.name', $names);
    $query->condition('tv.vid', $this->options['vocabulary'], 'IN');
    $query->addTag('term_access');
    $result = $query->execute();
    foreach ($result as $term) {
      unset($missing[strtolower($term->name)]);
      $tids[] = $term->tid;
    }

    if ($missing && !empty($this->options['error_message'])) {
      form_error($form, format_plural(count($missing), 'Unable to find term: @terms', 'Unable to find terms: @terms', array('@terms' => implode(', ', array_keys($missing)))));
    }
    elseif ($missing && empty($this->options['error_message'])) {
      $tids = array(0);
    }

    return $tids;
  }
  function query() {
    // If no filter values are present, then do nothing.
    if (count($this->value) == 0) {
      return;
    }
    elseif (count($this->value) == 1) {
      // Somethis $this->value is an array with a single element so convert it.
      if (is_array($this->value)) {
        $this->value = current($this->value);
      }
      $operator = '=';
    }
    else {
      $operator = 'IN';# " IN (" . implode(', ', array_fill(0, sizeof($this->value), '%d')) . ")";
    }

    // The normal use of ensure_my_table() here breaks Views.
    // So instead we trick the filter into using the alias of the base table.
    // See http://drupal.org/node/271833
    // If a relationship is set, we must use the alias it provides.
    if (!empty($this->relationship)) {
      $this->table_alias = $this->relationship;
    }
    // If no relationship, then use the alias of the base table.
    elseif (isset($this->query->table_queue[$this->query->base_table]['alias'])) {
      $this->table_alias = $this->query->table_queue[$this->query->base_table]['alias'];
    }
    // This should never happen, but if it does, we fail quietly.
    else {
      return;
    }
    if (empty($this->options['per_vocabulary']) || $operator == '=') {
      if ($value_parts = explode('-', $this->value)) {
        $tid = $value_parts[1];
      }
      else {
        $tid = $this->value;
      }
      $subquery = db_select('taxonomy_index', 'tn');
      $subquery->addField('tn', 'nid');
      $last = "tn";
      $subquery->condition('tn.tid', $tid, $operator);
      $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", $subquery, 'IN');
    }
    else {
      $values = array();
      foreach ($this->value as $value) {
        $value_parts = explode('-', $value);
        $values[$value_parts[0]][] = $value_parts[1];
      }
      foreach ($values as $vid => $tids) {
        // Now build the subqueries.
        $subquery = db_select('taxonomy_index', 'tn');
        $subquery->addField('tn', 'nid');
        $last = "tn";
        $subquery->innerJoin('taxonomy_term_data', 'td', "td.tid = tn.tid");
        $last = "td";
        $subquery->condition('tn.tid', array_values($tids), $operator);
        $subquery->condition('td.vid', $vid);
        //$this->query->innerJoin('taxonomy_index', 'tn', 'node.nid = tn.nid');
        $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", $subquery, 'IN');
      }
     }
  }
}
