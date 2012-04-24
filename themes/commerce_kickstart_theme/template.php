<?php
/*
function commerce_kickstart_theme_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  if ($form['#id'] == 'views-exposed-form-display-products-page') {
    dsm($form);
    //$form['#info']['search_api_views_fulltext']['#title'] = t('Search'); // Change the text on the label element
    $form['#info']['filter-search_api_views_fulltext']['label']['#label_display'] = 'hidden';
    $form['search_block_form']['#size'] = 40;  // define size of the textfield
    $form['search_api_views_fulltext']['#default_value'] = t('Search'); // Set a default value for the textfield
    $form['submit']['#value'] = t('Ok'); // Change the text on the submit button
    $form['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/search-button.png');

    // Add extra attributes to the text box
    $form['search_api_views_fulltext']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
    $form['search_api_views_fulltext']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
  }
}*/