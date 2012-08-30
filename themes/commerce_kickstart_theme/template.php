<?php

/**
 * Preprocess variables for html.tpl.php
 *
 * @see system_elements()
 * @see html.tpl.php
 */
function commerce_kickstart_theme_preprocess_html(&$variables) {
  // Add conditional stylesheets for IE
  drupal_add_css(path_to_theme() . '/css/commerce-kickstart-theme-ie-lte-8.css', array('group' => CSS_THEME, 'weight' => 23, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(path_to_theme() . '/css/commerce-kickstart-theme-ie-lte-7.css', array('group' => CSS_THEME, 'weight' => 24, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));

  // Add external libraries.
  drupal_add_library('commerce_kickstart_theme', 'selectnav');
}

/**
 * Implements hook_library().
 */
function commerce_kickstart_theme_library() {
  $libraries['selectnav'] = array(
    'title' => 'Selectnav',
    'version' => '',
    'js' => array(
      libraries_get_path('selectnav.js') . '/selectnav.min.js' => array(),
    ),
  );
  return $libraries;
}

/**
 * Preprocess field.
 */
function commerce_kickstart_theme_preprocess_field(&$variables) {
  $element = $variables['element'];
  if ($element['#entity_type'] != 'node' || $element['#field_name'] != 'title_field') {
    return;
  }

  $variables['theme_hook_suggestions'][] = 'field__fences_h2__node';
}
