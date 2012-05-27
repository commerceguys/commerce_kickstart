<?php

/**
 * @file
 * Implement a megarow using AJAX.
 */

function views_megarow_add_js() {
  // Provide a gate so we only do this once.
  static $done = FALSE;
  if ($done) {
    return;
  }

  $settings = array(
    'ViewsMegarow' => array(
      'loadingText' => t('Loading...'),
      'closeText' => 'x',
      'closeImage' => theme('image', array(
        'path' => ctools_image_path('icon-close-window.png'),
        'title' => t('Close window'),
        'alt' => t('Close window'),
      )),
      'throbber' => theme('image', array(
        //'path' => ctools_image_path('throbber.gif'),
        'path' => ctools_image_path('ajax-loader.gif', 'ctools_ajax_sample'),
        'title' => t('Loading...'),
        'alt' => t('Loading'),
      )),
    ),
  );

  drupal_add_js($settings, 'setting');
  drupal_add_js('misc/jquery.form.js');
  drupal_add_js('misc/progress.js');
  drupal_add_js('misc/ajax.js');
  drupal_add_js(drupal_get_path('module', 'views_megarow') . "/views_megarow.js");
  drupal_add_css(drupal_get_path('module', 'views_megarow') . "/views_megarow.css");

  $done = TRUE;
}

/**
 * Place HTML within the modal.
 *
 * @param $title
 *   The title of the modal.
 * @param $html
 *   The html to place within the modal.
 */
function views_megarow_command_display($title, $html, $entity_id) {
  if (is_array($html)) {
    $html = drupal_render($html);
  }

  return array(
    'command' => 'megarow_display',
    'entity_id' => $entity_id,
    'title' => $title,
    'output' => $html,
  );
}

/**
 * Dismiss the modal.
 */
function views_megarow_command_dismiss($entity_id) {
  return array(
    'command' => 'megarow_dismiss',
    'entity_id' => $entity_id,
  );
}

/**
 * Render an image as a button link. This will automatically apply an AJAX class
 * to the link and add the appropriate javascript to make this happen.
 *
 * @param $image
 *   The path to an image to use that will be sent to theme('image') for rendering.
 * @param $dest
 *   The destination of the link.
 * @param $alt
 *   The alt text of the link.
 * @param $class
 *   Any class to apply to the link. @todo this should be a options array.
 */
function views_megarow_image_button($image, $dest, $alt, $class = '') {
  return ctools_ajax_text_button(theme('image', array('path' => $image)), $dest, $alt, $class, 'views-megarow-open');
}

/**
 * Render text as a link. This will automatically apply an AJAX class
 * to the link and add the appropriate javascript to make this happen.
 *
 * Note: 'html' => true so be sure any text is vetted! Chances are these kinds of buttons will
 * not use user input so this is a very minor concern.
 *
 * @param $text
 *   The text that will be displayed as the link.
 * @param $dest
 *   The destination of the link.
 * @param $alt
 *   The alt text of the link.
 * @param $class
 *   Any class to apply to the link. @todo this should be a options array.
 */
function views_megarow_text_button($text, $dest, $alt, $class = '') {
  return ctools_ajax_text_button($text, $dest, $alt, $class, 'views-megarow-open');
}

/**
 * Wrap a form so that we can use it properly with AJAX. Essentially if the
 * form wishes to render, it automatically does that, otherwise it returns
 * so we can see submission results.
 *
 * @return
 *   The output of the form, if it was rendered. If $form_state['ajax']
 *   is set, this will use ctools_modal_form_render so it will be
 *   a $command object suitable for ajax_render already.
 *
 *   The return will be NULL if the form was successfully submitted unless
 *   you specifically set re_render = TRUE. If ajax is set the
 *   form will never be redirected.
 */
function views_megarow_form_wrapper($form_id, &$form_state) {
  // This won't override settings already in.
  $form_state += array(
    're_render' => FALSE,
    'no_redirect' => !empty($form_state['ajax']),
  );

  $output = drupal_build_form($form_id, $form_state);
  if (!empty($form_state['ajax']) && empty($form_state['executed'])) {
    $output = drupal_render($output);
    $title = empty($form_state['title']) ? drupal_get_title() : $form_state['title'];

    return views_megarow_display($title, $output, 0);
  }

  return $output;
}

/**
 * Perform a simple modal render and immediately exit.
 */
function views_megarow_display($title, $output, $entity_id) {
  // If there are messages for the form, render them.
  if ($messages = theme('status_messages')) {
    $output = '<div class="messages">' . $messages . '</div>' . $output;
  }

  $commands = array();
  $commands[] = views_megarow_command_display($title, $output, $entity_id);

  // @todo Find out why passing $commands to ajax_deliver fails, forcing us
  // to do the print / exit dance.
  print ajax_render($commands);
  exit;
}
