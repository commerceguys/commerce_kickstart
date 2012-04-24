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

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:all-products
  $menu_links['main-menu:all-products'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'all-products',
    'router_path' => 'all-products',
    'link_title' => 'All products',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '99',
  );
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
  // Exported menu link: secondary-navigation:node/2
  $menu_links['secondary-navigation:node/2'] = array(
    'menu_name' => 'secondary-navigation',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Exported menu link: secondary-navigation:node/3
  $menu_links['secondary-navigation:node/3'] = array(
    'menu_name' => 'secondary-navigation',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  //@TODO Set it back to about-us (node/3) when issue "Menu links do not support 2+ links with same menu_name/link_path":http://drupal.org/node/927566 is resolved.
  // Exported menu link: menu-footer-navigation:node/1
  $menu_links['menu-footer-navigation:node/1'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/1',
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
  // Exported menu link: menu-footer-navigation:blog
  $menu_links['menu-footer-navigation:blog'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
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
    'parent_path' => 'node/1',
  );
  // Exported menu link: menu-footer-navigation:node/2
  $menu_links['menu-footer-navigation:node/2'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/2',
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
    'weight' => '-45',
    'parent_path' => 'node/1',
  );
  // Exported menu link: menu-footer-navigation:node/3
  $menu_links['menu-footer-navigation:node/3'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'About us',
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
    'weight' => '-44',
    'parent_path' => 'node/1',
  );
  // Exported menu link: menu-footer-navigation:node/7
  $menu_links['menu-footer-navigation:node/7'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/7',
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
    'weight' => '-43',
    'parent_path' => 'node/1',
  );
  // Exported menu link: menu-footer-navigation:node/8
  $menu_links['menu-footer-navigation:node/8'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/8',
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
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-49',
  );
  // Exported menu link: menu-footer-navigation:node/9
  $menu_links['menu-footer-navigation:node/9'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/9',
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
  // Exported menu link: menu-footer-navigation:node/4
  $menu_links['menu-footer-navigation:node/4'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/4',
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
    'weight' => '-42',
    'parent_path' => 'node/9',
  );
  // Exported menu link: menu-footer-navigation:node/6
  $menu_links['menu-footer-navigation:node/6'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/6',
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
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('About us');
  t('All products');
  t('Blog');
  t('Company info');
  t('Contact');
  t('Contact us');
  t('Home');
  t('Press links');
  t('Security & privacy');
  t('Service & support');
  t('Shipping & returns');
  t('Terms of use');


  return $menu_links;
}
