<?php
/**
 * @file
 * commerce_kickstart_homepage.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function commerce_kickstart_homepage_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: secondary-navigation:blog
  $menu_links['secondary-navigation:blog'] = array(
    'menu_name' => 'secondary-navigation',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: secondary-navigation:brands
  $menu_links['secondary-navigation:brands'] = array(
    'menu_name' => 'secondary-navigation',
    'link_path' => 'brands',
    'router_path' => 'brands',
    'link_title' => 'Brands',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Exported menu link: secondary-navigation:news
  $menu_links['secondary-navigation:news'] = array(
    'menu_name' => 'secondary-navigation',
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'News',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Brands');
  t('News');


  return $menu_links;
}
