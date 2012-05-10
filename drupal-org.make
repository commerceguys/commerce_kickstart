; Drupal.org release file.
core = 7.12
api = 2

; Basic contributed modules.
projects[ctools][version] = 1.0
projects[ctools][subdir] = "contrib"
projects[entity][version] = 1.0-rc1
projects[entity][subdir] = "contrib"
projects[entity][patch][] = "http://drupal.org/files/1556192-hook_options_list-invocation-1.patch"
projects[rules][version] = 2.1
projects[rules][subdir] = "contrib"
projects[views][version] = 3.3
projects[views][subdir] = "contrib"
projects[views_bulk_operations][version] = 3.0-rc1
projects[views_bulk_operations][subdir] = "contrib"
projects[addressfield][version] = 1.0-beta2
projects[addressfield][subdir] = "contrib"
projects[features][version] = 1.0-rc2
projects[features][patch][] = "http://drupal.org/files/1265168.23.Enabling_multiple_features_at_the_same_time_may_fail.patch"
projects[features][subdir] = "contrib"
projects[strongarm][version] = 2.0-rc1
projects[strongarm][subdir] = "contrib"
projects[taxonomy_menu][version] = 1.2
projects[taxonomy_menu][subdir] = "contrib"
projects[views_slideshow][version] = 3.0
projects[views_slideshow][subdir] = "contrib"
projects[libraries][version] = 1.0
projects[libraries][subdir] = "contrib"
projects[tipsy][version] = 1.0-rc1
projects[tipsy][subdir] = "contrib"
projects[advanced_help][version] = 1.0
projects[advanced_help][subdir] = "contrib"

; Drupal Commerce and Commerce contribs.
projects[commerce][version] = 1.x-dev
projects[commerce][subdir] = "contrib"
projects[commerce][patch][] = "http://drupal.org/files/1518084-commerce-expose-amount-floatted-4.patch"
projects[commerce_features][version] = 1.x-dev
projects[commerce_features][subdir] = "contrib"
projects[commerce_features][patch][] = "http://drupal.org/files/1402762_export_flat_rate_commerce_features-4.patch"
projects[commerce_addressbook][version] = 2.x-dev
projects[commerce_addressbook][subdir] = "contrib"
projects[commerce_shipping][version] = 2.x-dev
projects[commerce_shipping][subdir] = "contrib"
projects[commerce_flat_rate][version] = 1.x-dev
projects[commerce_flat_rate][subdir] = "contrib"

; Other contribs.
projects[http_client][version] = 2.3
projects[http_client][subdir] = "contrib"
projects[oauth][version] = 3.x-dev
projects[oauth][subdir] = "contrib"
projects[oauth][patch][] = "http://drupal.org/files/980340-d7.patch"
projects[inline_entity_form][version] = 1.x-dev
projects[inline_entity_form][subdir] = "contrib"
projects[field_extractor][version] = 1.x-dev
projects[field_extractor][subdir] = "contrib"

; Search related modules.
projects[search_api][version] = 1.x-dev
projects[search_api][subdir] = "contrib"
projects[search_api_db][version] = 1.x-dev
projects[search_api_db][subdir] = "contrib"
projects[search_api_ranges][type] = module
projects[search_api_ranges][download][type] = git
projects[search_api_ranges][download][branch] = 7.x-1.x
projects[search_api_ranges][patch][] = "patches/search_api_ranges-add-support-for-commerce-price-fields-1350528-16.patch"
projects[search_api_ranges][subdir] = "contrib"
projects[facetapi][version] = 1.0-rc4
projects[facetapi][subdir] = "contrib"

; UI improvement modules.
projects[module_filter][version] = 1.6
projects[module_filter][subdir] = "contrib"
projects[flexslider][version] = 1.0-rc2
projects[flexslider][subdir] = "contrib"
projects[image_delta_formatter][version] = 1.x-dev
projects[image_delta_formatter][subdir] = "contrib"
projects[link][version] = 1.0
projects[link][subdir] = "contrib"

; Base theme
projects[omega][version] = 3.1

; Libraries
libraries[flexslider][type] = "libraries"
libraries[flexslider][download][type] = "git"
libraries[flexslider][download][url] = "https://github.com/woothemes/FlexSlider.git"
libraries[jquery.bxSlider][type] = "libraries"
libraries[jquery.bxSlider][download][type] = "git"
libraries[jquery.bxSlider][download][url] = "https://github.com/wandoledzep/bxslider.git"
