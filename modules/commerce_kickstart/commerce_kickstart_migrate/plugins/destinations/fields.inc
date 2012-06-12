<?php


class KickstartMigrateTaxonomyTermReferenceFieldHandler extends MigrateTaxonomyTermReferenceFieldHandler {
  public function __construct() {
    $this->registerTypes(array('taxonomy_term_reference'));
  }

  public function fields($type) {
    return array(
      'source_type' => t('Option: Set to \'tid\' when the value is a source ID'),
      'create_term' => t('Option: Set to TRUE to create referenced terms when necessary'),
      'additional_field' => t('Option: Pass any additional field that should be added in the term. Array should be "field_name|value".')
    );
  }

  public function prepare($entity, array $field_info, array $instance, array $values) {
    if (isset($values['arguments'])) {
      $arguments = $values['arguments'];
      unset($values['arguments']);
    }
    else {
      $arguments = array();
    }
    if (empty($values[0])) {
      $values = array();
    }

    $tids = array();
    if (isset($arguments['source_type']) && $arguments['source_type'] == 'tid') {
      // Nothing to do. We have tids already.
      $tids = $values;
    }
    elseif ($values) {
      // Get the vocabulary for this term
      if (isset($field_info['settings']['allowed_values'][0]['vid'])) {
        $vid = $field_info['settings']['allowed_values'][0]['vid'];
      }
      else {
        $vocab_name = $field_info['settings']['allowed_values'][0]['vocabulary'];
        $names = taxonomy_vocabulary_get_names();
        $vid = $names[$vocab_name]->vid;
      }

      // Cannot use taxonomy_term_load_multiple() since we have an array of names.
      // It wants a singular value. This query may return case-insensitive
      // matches.
      $existing_terms = db_select('taxonomy_term_data', 'td')
        ->fields('td', array('tid', 'name'))
        ->condition('td.name', $values, 'IN')
        ->condition('td.vid', $vid)
        ->execute()
        ->fetchAllKeyed(1, 0);
      foreach ($values as $value) {
        if (isset($existing_terms[$value])) {
          $tids[] = $existing_terms[$value];
        }
        elseif (!empty($arguments['create_term'])) {
          $new_term = new stdClass();
          $new_term->vid = $vid;
          $new_term->name = $value;
          if (!empty($arguments['additional_field'])) {
            $additional_field = explode('|', $arguments['additional_field']);
            $additional_field_machine_name = $additional_field[0];
            $additional_field_value = $additional_field[1];
            $new_term->{$additional_field_machine_name}[LANGUAGE_NONE][]['value'] = $additional_field_value;
          }
          taxonomy_term_save($new_term);
          $tids[] = $new_term->tid;
        }
      }
    }

    $language = $this->getFieldLanguage($entity, $field_info, $arguments);
    $result = array();
    $delta = 0;
    foreach ($tids as $tid) {
      if (is_array($language)) {
        $current_language = $language[$delta];
      }
      else {
        $current_language = $language;
      }
      $result[$current_language][] = array('tid' => $tid);
      $delta++;
    }
    return $result;
  }
}
