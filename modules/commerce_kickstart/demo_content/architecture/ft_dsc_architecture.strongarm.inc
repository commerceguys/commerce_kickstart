<?php
/**
 * @file
 * ft_dsc_architecture.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ft_dsc_architecture_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_bags_cases';
  $strongarm->value = 0;
  $export['comment_anonymous_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_blog_post';
  $strongarm->value = 0;
  $export['comment_anonymous_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_brand';
  $strongarm->value = 0;
  $export['comment_anonymous_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_drinks';
  $strongarm->value = 0;
  $export['comment_anonymous_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_hats';
  $strongarm->value = 0;
  $export['comment_anonymous_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_shoes';
  $strongarm->value = 0;
  $export['comment_anonymous_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_slideshow';
  $strongarm->value = 0;
  $export['comment_anonymous_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_storage_devices';
  $strongarm->value = 0;
  $export['comment_anonymous_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_tops';
  $strongarm->value = 0;
  $export['comment_anonymous_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_bags_cases';
  $strongarm->value = '0';
  $export['comment_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_blog_post';
  $strongarm->value = '0';
  $export['comment_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_brand';
  $strongarm->value = '0';
  $export['comment_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_bags_cases';
  $strongarm->value = 1;
  $export['comment_default_mode_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_blog_post';
  $strongarm->value = 1;
  $export['comment_default_mode_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_brand';
  $strongarm->value = 1;
  $export['comment_default_mode_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_drinks';
  $strongarm->value = 1;
  $export['comment_default_mode_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_hats';
  $strongarm->value = 1;
  $export['comment_default_mode_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_shoes';
  $strongarm->value = 1;
  $export['comment_default_mode_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_slideshow';
  $strongarm->value = 1;
  $export['comment_default_mode_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_storage_devices';
  $strongarm->value = 1;
  $export['comment_default_mode_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_tops';
  $strongarm->value = 1;
  $export['comment_default_mode_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_bags_cases';
  $strongarm->value = '50';
  $export['comment_default_per_page_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_blog_post';
  $strongarm->value = '50';
  $export['comment_default_per_page_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_brand';
  $strongarm->value = '50';
  $export['comment_default_per_page_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_drinks';
  $strongarm->value = '50';
  $export['comment_default_per_page_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_hats';
  $strongarm->value = '50';
  $export['comment_default_per_page_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_shoes';
  $strongarm->value = '50';
  $export['comment_default_per_page_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_slideshow';
  $strongarm->value = '50';
  $export['comment_default_per_page_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_storage_devices';
  $strongarm->value = '50';
  $export['comment_default_per_page_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_tops';
  $strongarm->value = '50';
  $export['comment_default_per_page_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_drinks';
  $strongarm->value = '0';
  $export['comment_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_bags_cases';
  $strongarm->value = 1;
  $export['comment_form_location_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_blog_post';
  $strongarm->value = 1;
  $export['comment_form_location_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_brand';
  $strongarm->value = 1;
  $export['comment_form_location_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_drinks';
  $strongarm->value = 1;
  $export['comment_form_location_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_hats';
  $strongarm->value = 1;
  $export['comment_form_location_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_shoes';
  $strongarm->value = 1;
  $export['comment_form_location_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_slideshow';
  $strongarm->value = 1;
  $export['comment_form_location_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_storage_devices';
  $strongarm->value = 1;
  $export['comment_form_location_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_tops';
  $strongarm->value = 1;
  $export['comment_form_location_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_hats';
  $strongarm->value = '0';
  $export['comment_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_bags_cases';
  $strongarm->value = '1';
  $export['comment_preview_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_blog_post';
  $strongarm->value = '1';
  $export['comment_preview_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_brand';
  $strongarm->value = '1';
  $export['comment_preview_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_drinks';
  $strongarm->value = '1';
  $export['comment_preview_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_hats';
  $strongarm->value = '1';
  $export['comment_preview_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_shoes';
  $strongarm->value = '1';
  $export['comment_preview_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_slideshow';
  $strongarm->value = '1';
  $export['comment_preview_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_storage_devices';
  $strongarm->value = '1';
  $export['comment_preview_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_tops';
  $strongarm->value = '1';
  $export['comment_preview_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_product_display';
  $strongarm->value = 0;
  $export['comment_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_shoes';
  $strongarm->value = '0';
  $export['comment_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_slideshow';
  $strongarm->value = '0';
  $export['comment_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_storage_devices';
  $strongarm->value = '0';
  $export['comment_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_bags_cases';
  $strongarm->value = 1;
  $export['comment_subject_field_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_blog_post';
  $strongarm->value = 1;
  $export['comment_subject_field_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_brand';
  $strongarm->value = 1;
  $export['comment_subject_field_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_drinks';
  $strongarm->value = 1;
  $export['comment_subject_field_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_hats';
  $strongarm->value = 1;
  $export['comment_subject_field_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_shoes';
  $strongarm->value = 1;
  $export['comment_subject_field_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_slideshow';
  $strongarm->value = 1;
  $export['comment_subject_field_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_storage_devices';
  $strongarm->value = 1;
  $export['comment_subject_field_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_tops';
  $strongarm->value = 1;
  $export['comment_subject_field_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_tops';
  $strongarm->value = '2';
  $export['comment_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings';
  $strongarm->value = array(
    'commerce_product' => array(
      'bags_cases' => array(
        'view_modes' => array(
          'line_item' => array(
            'custom_settings' => TRUE,
          ),
          'node_teaser' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => FALSE,
          ),
          'node_product_list' => array(
            'custom_settings' => TRUE,
          ),
          'commerce_line_item_display' => array(
            'custom_settings' => FALSE,
          ),
          'node_full' => array(
            'custom_settings' => TRUE,
          ),
          'node_rss' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_index' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'node_product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '3',
                'visible' => FALSE,
              ),
              'node_product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'drinks' => array(
        'view_modes' => array(
          'line_item' => array(
            'custom_settings' => TRUE,
          ),
          'node_teaser' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => FALSE,
          ),
          'node_product_list' => array(
            'custom_settings' => TRUE,
          ),
          'commerce_line_item_display' => array(
            'custom_settings' => FALSE,
          ),
          'node_full' => array(
            'custom_settings' => TRUE,
          ),
          'node_rss' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_index' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'node_product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'hats' => array(
        'view_modes' => array(
          'line_item' => array(
            'custom_settings' => TRUE,
          ),
          'node_teaser' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => FALSE,
          ),
          'node_product_list' => array(
            'custom_settings' => TRUE,
          ),
          'commerce_line_item_display' => array(
            'custom_settings' => FALSE,
          ),
          'node_full' => array(
            'custom_settings' => TRUE,
          ),
          'node_rss' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_index' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'sku' => array(
              'default' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'title' => array(
              'default' => array(
                'weight' => '1',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'node_product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'shoes' => array(
        'view_modes' => array(
          'line_item' => array(
            'custom_settings' => TRUE,
          ),
          'node_teaser' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => FALSE,
          ),
          'node_product_list' => array(
            'custom_settings' => TRUE,
          ),
          'commerce_line_item_display' => array(
            'custom_settings' => FALSE,
          ),
          'node_full' => array(
            'custom_settings' => TRUE,
          ),
          'node_rss' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_index' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'node_product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'storage_devices' => array(
        'view_modes' => array(
          'line_item' => array(
            'custom_settings' => TRUE,
          ),
          'node_teaser' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => FALSE,
          ),
          'node_product_list' => array(
            'custom_settings' => TRUE,
          ),
          'commerce_line_item_display' => array(
            'custom_settings' => FALSE,
          ),
          'node_full' => array(
            'custom_settings' => TRUE,
          ),
          'node_rss' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_index' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'node_product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'tops' => array(
        'view_modes' => array(
          'line_item' => array(
            'custom_settings' => TRUE,
          ),
          'node_teaser' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => FALSE,
          ),
          'node_product_list' => array(
            'custom_settings' => TRUE,
          ),
          'commerce_line_item_display' => array(
            'custom_settings' => FALSE,
          ),
          'node_full' => array(
            'custom_settings' => TRUE,
          ),
          'node_rss' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_index' => array(
            'custom_settings' => FALSE,
          ),
          'node_search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'node_product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => TRUE,
              ),
              'node_full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'node_product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
    ),
    'node' => array(
      'bags_cases' => array(
        'view_modes' => array(
          'teaser' => array(
            'custom_settings' => TRUE,
          ),
          'product_list' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => TRUE,
          ),
          'rss' => array(
            'custom_settings' => FALSE,
          ),
          'search_index' => array(
            'custom_settings' => FALSE,
          ),
          'search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'product:sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '9',
                'visible' => FALSE,
              ),
            ),
            'product:title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '1',
                'visible' => TRUE,
              ),
            ),
            'product:commerce_price' => array(
              'default' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '8',
                'visible' => TRUE,
              ),
            ),
            'product:field_bag_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '6',
                'visible' => TRUE,
              ),
            ),
            'product:field_color' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '3',
                'visible' => TRUE,
              ),
            ),
            'product:field_images' => array(
              'default' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'product:field_hat_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '5',
                'visible' => TRUE,
              ),
            ),
            'product:field_shoe_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '7',
                'visible' => TRUE,
              ),
            ),
            'product:field_storage_capacity' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
            'product:field_top_size' => array(
              'default' => array(
                'weight' => '39',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '39',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '4',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'drinks' => array(
        'view_modes' => array(
          'teaser' => array(
            'custom_settings' => TRUE,
          ),
          'product_list' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => TRUE,
          ),
          'rss' => array(
            'custom_settings' => FALSE,
          ),
          'search_index' => array(
            'custom_settings' => FALSE,
          ),
          'search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'product:sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '9',
                'visible' => FALSE,
              ),
            ),
            'product:title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '1',
                'visible' => TRUE,
              ),
            ),
            'product:commerce_price' => array(
              'default' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '8',
                'visible' => TRUE,
              ),
            ),
            'product:field_bag_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '6',
                'visible' => TRUE,
              ),
            ),
            'product:field_color' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '3',
                'visible' => TRUE,
              ),
            ),
            'product:field_images' => array(
              'default' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'product:field_hat_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '5',
                'visible' => TRUE,
              ),
            ),
            'product:field_shoe_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '7',
                'visible' => TRUE,
              ),
            ),
            'product:field_storage_capacity' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
            'product:field_top_size' => array(
              'default' => array(
                'weight' => '39',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '39',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '4',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'hats' => array(
        'view_modes' => array(
          'teaser' => array(
            'custom_settings' => TRUE,
          ),
          'product_list' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => TRUE,
          ),
          'rss' => array(
            'custom_settings' => FALSE,
          ),
          'search_index' => array(
            'custom_settings' => FALSE,
          ),
          'search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'product:sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '9',
                'visible' => FALSE,
              ),
            ),
            'product:title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '1',
                'visible' => TRUE,
              ),
            ),
            'product:commerce_price' => array(
              'default' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '8',
                'visible' => TRUE,
              ),
            ),
            'product:field_bag_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '6',
                'visible' => TRUE,
              ),
            ),
            'product:field_color' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '3',
                'visible' => TRUE,
              ),
            ),
            'product:field_images' => array(
              'default' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'product:field_hat_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '5',
                'visible' => TRUE,
              ),
            ),
            'product:field_shoe_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '7',
                'visible' => TRUE,
              ),
            ),
            'product:field_storage_capacity' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
            'product:field_top_size' => array(
              'default' => array(
                'weight' => '39',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '39',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '4',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'shoes' => array(
        'view_modes' => array(
          'teaser' => array(
            'custom_settings' => TRUE,
          ),
          'product_list' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => TRUE,
          ),
          'rss' => array(
            'custom_settings' => FALSE,
          ),
          'search_index' => array(
            'custom_settings' => FALSE,
          ),
          'search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'product:sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '9',
                'visible' => FALSE,
              ),
            ),
            'product:title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '1',
                'visible' => TRUE,
              ),
            ),
            'product:commerce_price' => array(
              'default' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '8',
                'visible' => TRUE,
              ),
            ),
            'product:field_bag_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '6',
                'visible' => TRUE,
              ),
            ),
            'product:field_color' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '3',
                'visible' => TRUE,
              ),
            ),
            'product:field_images' => array(
              'default' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'product:field_hat_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '5',
                'visible' => TRUE,
              ),
            ),
            'product:field_shoe_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '7',
                'visible' => TRUE,
              ),
            ),
            'product:field_storage_capacity' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
            'product:field_top_size' => array(
              'default' => array(
                'weight' => '39',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '39',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '4',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'storage_devices' => array(
        'view_modes' => array(
          'teaser' => array(
            'custom_settings' => TRUE,
          ),
          'product_list' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => TRUE,
          ),
          'rss' => array(
            'custom_settings' => FALSE,
          ),
          'search_index' => array(
            'custom_settings' => FALSE,
          ),
          'search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'product:sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '9',
                'visible' => FALSE,
              ),
            ),
            'product:title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '1',
                'visible' => TRUE,
              ),
            ),
            'product:commerce_price' => array(
              'default' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '8',
                'visible' => TRUE,
              ),
            ),
            'product:field_bag_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '6',
                'visible' => TRUE,
              ),
            ),
            'product:field_color' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '3',
                'visible' => TRUE,
              ),
            ),
            'product:field_images' => array(
              'default' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'product:field_hat_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '5',
                'visible' => TRUE,
              ),
            ),
            'product:field_shoe_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '7',
                'visible' => TRUE,
              ),
            ),
            'product:field_storage_capacity' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
            'product:field_top_size' => array(
              'default' => array(
                'weight' => '39',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '39',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '4',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
      'tops' => array(
        'view_modes' => array(
          'teaser' => array(
            'custom_settings' => TRUE,
          ),
          'product_list' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => TRUE,
          ),
          'rss' => array(
            'custom_settings' => FALSE,
          ),
          'search_index' => array(
            'custom_settings' => FALSE,
          ),
          'search_result' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'product:sku' => array(
              'default' => array(
                'weight' => '-10',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-10',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '9',
                'visible' => FALSE,
              ),
            ),
            'product:title' => array(
              'default' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'full' => array(
                'weight' => '-5',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '1',
                'visible' => TRUE,
              ),
            ),
            'product:commerce_price' => array(
              'default' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '8',
                'visible' => TRUE,
              ),
            ),
            'product:field_bag_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '6',
                'visible' => TRUE,
              ),
            ),
            'product:field_color' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '3',
                'visible' => TRUE,
              ),
            ),
            'product:field_images' => array(
              'default' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '37',
                'visible' => TRUE,
              ),
              'product_list' => array(
                'weight' => '0',
                'visible' => TRUE,
              ),
            ),
            'product:field_hat_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '5',
                'visible' => TRUE,
              ),
            ),
            'product:field_shoe_size' => array(
              'default' => array(
                'weight' => '40',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '40',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '7',
                'visible' => TRUE,
              ),
            ),
            'product:field_storage_capacity' => array(
              'default' => array(
                'weight' => '38',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '38',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '2',
                'visible' => TRUE,
              ),
            ),
            'product:field_top_size' => array(
              'default' => array(
                'weight' => '39',
                'visible' => TRUE,
              ),
              'full' => array(
                'weight' => '39',
                'visible' => FALSE,
              ),
              'product_list' => array(
                'weight' => '4',
                'visible' => TRUE,
              ),
            ),
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_bags_cases';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_blog_post';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_brand';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_drinks';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hats';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_shoes';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_slideshow';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_storage_devices';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_tops';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_bags_cases';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_blog_post';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_brand';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_drinks';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hats';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_shoes';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_slideshow';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_storage_devices';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_tops';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_bags_cases';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_blog_post';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_brand';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_drinks';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hats';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_product_display';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_shoes';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_slideshow';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_storage_devices';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_tops';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_bags_cases';
  $strongarm->value = '1';
  $export['node_preview_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_blog_post';
  $strongarm->value = '1';
  $export['node_preview_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_brand';
  $strongarm->value = '1';
  $export['node_preview_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_drinks';
  $strongarm->value = '1';
  $export['node_preview_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hats';
  $strongarm->value = '1';
  $export['node_preview_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_shoes';
  $strongarm->value = '1';
  $export['node_preview_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_slideshow';
  $strongarm->value = '1';
  $export['node_preview_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_storage_devices';
  $strongarm->value = '1';
  $export['node_preview_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_tops';
  $strongarm->value = '1';
  $export['node_preview_tops'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_bags_cases';
  $strongarm->value = 0;
  $export['node_submitted_bags_cases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_blog_post';
  $strongarm->value = 1;
  $export['node_submitted_blog_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_brand';
  $strongarm->value = 1;
  $export['node_submitted_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_drinks';
  $strongarm->value = 0;
  $export['node_submitted_drinks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hats';
  $strongarm->value = 0;
  $export['node_submitted_hats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_product_display';
  $strongarm->value = FALSE;
  $export['node_submitted_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_shoes';
  $strongarm->value = 0;
  $export['node_submitted_shoes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_slideshow';
  $strongarm->value = 1;
  $export['node_submitted_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_storage_devices';
  $strongarm->value = 0;
  $export['node_submitted_storage_devices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_tops';
  $strongarm->value = 0;
  $export['node_submitted_tops'] = $strongarm;

  return $export;
}
