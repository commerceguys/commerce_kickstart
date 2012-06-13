<?php

function commerce_kickstart_theme_preprocess_html(&$vars) {
  // Ad respond.js to the footer to avoid crashes in IE8
  drupal_add_js(drupal_get_path('theme', 'commerce_kickstart_theme') . '/js/respond.js',
  array(
    'type' => 'file',
    'scope' => 'footer',
    'group' => JS_THEME,
    'preprocess' => TRUE,
    'cache' => TRUE,
  )
  );
}
