<?php
/**
 * @file
 * commerce_kickstart_blog_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function commerce_kickstart_blog_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-navigation_about-us:node/2
  $menu_links['menu-footer-navigation_about-us:node/2'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'About us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_about-us:node/2',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
    'parent_identifier' => 'menu-footer-navigation_company-info:<nolink>',
  );
  // Exported menu link: menu-footer-navigation_blog:blog
  $menu_links['menu-footer-navigation_blog:blog'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'parent_identifier' => 'menu-footer-navigation_company-info:<nolink>',
  );
  // Exported menu link: menu-footer-navigation_company-info:<nolink>
  $menu_links['menu-footer-navigation_company-info:<nolink>'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Company info',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_company-info:<nolink>',
      'toolbar_expanded' => 0,
      'toolbar_break' => 0,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-50',
  );
  // Exported menu link: menu-footer-navigation_our-security-policy:node/8
  $menu_links['menu-footer-navigation_our-security-policy:node/8'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'Our security policy',
    'options' => array(
      'toolbar_expanded' => 0,
      'toolbar_break' => 0,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_our-security-policy:node/8',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_identifier' => 'menu-footer-navigation_security--privacy:<nolink>',
  );
  // Exported menu link: menu-footer-navigation_press-links:node/6
  $menu_links['menu-footer-navigation_press-links:node/6'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Press links',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_press-links:node/6',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
    'parent_identifier' => 'menu-footer-navigation_company-info:<nolink>',
  );
  // Exported menu link: menu-footer-navigation_security--privacy:<nolink>
  $menu_links['menu-footer-navigation_security--privacy:<nolink>'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Security & privacy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_security--privacy:<nolink>',
      'toolbar_expanded' => 0,
      'toolbar_break' => 0,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-48',
  );
  // Exported menu link: menu-footer-navigation_service--support:<nolink>
  $menu_links['menu-footer-navigation_service--support:<nolink>'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Service & support',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_service--support:<nolink>',
      'toolbar_expanded' => 0,
      'toolbar_break' => 0,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-49',
  );
  // Exported menu link: menu-footer-navigation_service-agreements:node/7
  $menu_links['menu-footer-navigation_service-agreements:node/7'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Service agreements',
    'options' => array(
      'toolbar_expanded' => 0,
      'toolbar_break' => 0,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_service-agreements:node/7',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_identifier' => 'menu-footer-navigation_service--support:<nolink>',
  );
  // Exported menu link: menu-footer-navigation_shipping--returns:<nolink>
  $menu_links['menu-footer-navigation_shipping--returns:<nolink>'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Shipping & returns',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_shipping--returns:<nolink>',
      'toolbar_expanded' => 0,
      'toolbar_break' => 0,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-47',
  );
  // Exported menu link: menu-footer-navigation_shipping-fees:node/5
  $menu_links['menu-footer-navigation_shipping-fees:node/5'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Shipping fees',
    'options' => array(
      'toolbar_expanded' => 0,
      'toolbar_break' => 0,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_shipping-fees:node/5',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_identifier' => 'menu-footer-navigation_shipping--returns:<nolink>',
  );
  // Exported menu link: menu-footer-navigation_terms-of-use:node/3
  $menu_links['menu-footer-navigation_terms-of-use:node/3'] = array(
    'menu_name' => 'menu-footer-navigation',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Terms of use',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-navigation_terms-of-use:node/3',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-42',
    'parent_identifier' => 'menu-footer-navigation_security--privacy:<nolink>',
  );
  // Exported menu link: menu-kickstart-user-menu_create-account:user/register
  $menu_links['menu-kickstart-user-menu_create-account:user/register'] = array(
    'menu_name' => 'menu-kickstart-user-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Create account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-kickstart-user-menu_create-account:user/register',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-kickstart-user-menu_log-in:user/login
  $menu_links['menu-kickstart-user-menu_log-in:user/login'] = array(
    'menu_name' => 'menu-kickstart-user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-kickstart-user-menu_log-in:user/login',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-kickstart-user-menu_log-out:user/logout
  $menu_links['menu-kickstart-user-menu_log-out:user/logout'] = array(
    'menu_name' => 'menu-kickstart-user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-kickstart-user-menu_log-out:user/logout',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-kickstart-user-menu_my-account:user
  $menu_links['menu-kickstart-user-menu_my-account:user'] = array(
    'menu_name' => 'menu-kickstart-user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-kickstart-user-menu_my-account:user',
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: secondary-navigation_about:node/2
  $menu_links['secondary-navigation_about:node/2'] = array(
    'menu_name' => 'secondary-navigation',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'secondary-navigation_about:node/2',
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Exported menu link: secondary-navigation_blog:blog
  $menu_links['secondary-navigation_blog:blog'] = array(
    'menu_name' => 'secondary-navigation',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'identifier' => 'secondary-navigation_blog:blog',
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: secondary-navigation_contact:node/1
  $menu_links['secondary-navigation_contact:node/2'] = array(
    'menu_name' => 'secondary-navigation',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'identifier' => 'secondary-navigation_contact:node/1',
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('About us');
  t('Blog');
  t('Company info');
  t('Contact');
  t('Create account');
  t('Log in');
  t('Log out');
  t('My account');
  t('Our security policy');
  t('Press links');
  t('Security & privacy');
  t('Service & support');
  t('Service agreements');
  t('Shipping & returns');
  t('Shipping fees');
  t('Terms of use');


  return $menu_links;
}
