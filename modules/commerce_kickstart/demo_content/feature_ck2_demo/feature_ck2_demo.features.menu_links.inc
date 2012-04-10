<?php
/**
 * @file
 * feature_ck2_demo.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_ck2_demo_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:blog
  $menu_links['main-menu:blog'] = array(
    'menu_name' => 'main-menu',
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
  // Exported menu link: main-menu:brands
  $menu_links['main-menu:brands'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'brands',
    'router_path' => 'brands',
    'link_title' => 'Brands',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:news
  $menu_links['main-menu:news'] = array(
    'menu_name' => 'main-menu',
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
  // Exported menu link: menu-footer-navigation:node/1
  $menu_links['menu-footer-navigation:node/1'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Contact us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => 'node/2',
  );
  // Exported menu link: menu-footer-navigation:node/2
  $menu_links['menu-footer-navigation:node/2'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Company info',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-50',
  );
  // Exported menu link: menu-footer-navigation:node/3
  $menu_links['menu-footer-navigation:node/3'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Terms of use',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'node/8',
  );
  // Exported menu link: menu-footer-navigation:node/5
  $menu_links['menu-footer-navigation:node/5'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Shipping & returns',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-footer-navigation:node/6
  $menu_links['menu-footer-navigation:node/6'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Press links',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'parent_path' => 'node/2',
  );
  // Exported menu link: menu-footer-navigation:node/7
  $menu_links['menu-footer-navigation:node/7'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Service & support',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-footer-navigation:node/8
  $menu_links['menu-footer-navigation:node/8'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'Security & privacy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Brands');
  t('Company info');
  t('Contact us');
  t('News');
  t('Press links');
  t('Security & privacy');
  t('Service & support');
  t('Shipping & returns');
  t('Terms of use');


  return $menu_links;
}
