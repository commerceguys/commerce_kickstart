<?php
/**
 * @file
 * commerce_kickstart_merchandising_ui.features.inc
 */

/**
 * Implements hook_views_api().
 */
function commerce_kickstart_merchandising_ui_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function commerce_kickstart_merchandising_ui_image_default_styles() {
  $styles = array();

  // Exported image style: hp_blocks
  $styles['hp_blocks'] = array(
    'name' => 'hp_blocks',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '270',
          'height' => '305',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: hp_slideshow
  $styles['hp_slideshow'] = array(
    'name' => 'hp_slideshow',
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
          'height' => '480',
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}
