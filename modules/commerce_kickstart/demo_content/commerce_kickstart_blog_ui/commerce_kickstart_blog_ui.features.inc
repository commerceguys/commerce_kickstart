<?php
/**
 * @file
 * commerce_kickstart_blog_ui.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commerce_kickstart_blog_ui_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commerce_kickstart_blog_ui_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function commerce_kickstart_blog_ui_image_default_styles() {
  $styles = array();

  // Exported image style: blog_full
  $styles['blog_full'] = array(
    'name' => 'blog_full',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '940',
          'height' => '380',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: blog_medium
  $styles['blog_medium'] = array(
    'name' => 'blog_medium',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '430',
          'height' => '300',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
