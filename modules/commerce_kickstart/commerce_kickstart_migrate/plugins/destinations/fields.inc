<?php


class KickstartMigrateTaxonomyTermReferenceFieldHandler extends MigrateTaxonomyTermReferenceFieldHandler {
  public function __construct() {
    $this->registerTypes(array('taxonomy_term_reference'));
    $this->dependencies = array('MigrateTaxonomyTermReferenceFieldHandler');
  }

  public function fields($type) {
    return array(
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

    // Ensure we have tids.
    if (isset($arguments['source_type']) && $arguments['source_type'] == 'tid') {
      $tids = $values;

      // Add {additional_field} to existing terms.
      $existing_terms = taxonomy_term_load_multiple($tids);
      foreach ($tids as $tid) {
        if (!empty($arguments['additional_field'])) {
          $additional_field = explode('|', $arguments['additional_field']);
          $additional_field_machine_name = $additional_field[0];
          $additional_field_value = $additional_field[1];
          $existing_terms[$tid]->{$additional_field_machine_name}[LANGUAGE_NONE][]['value'] = $additional_field_value;
        }
        taxonomy_term_save($existing_terms[$tid]);
      }
    }

    $result = array();
    return $result;
  }
}
