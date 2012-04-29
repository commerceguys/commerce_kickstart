; Drupal.org release file.
core = 7.12
api = 2

; Basic contributed modules.
projects[ctools] = 1.0
projects[ctools][subdir] = "contrib"
projects[entity] = 1.0-rc1
projects[entity][subdir] = "contrib"
projects[rules] = 2.1
projects[rules][subdir] = "contrib"
projects[views] = 3.3
projects[views][subdir] = "contrib"
projects[views_bulk_operations] = 3.0-rc1
projects[views_bulk_operations][subdir] = "contrib"
projects[addressfield] = 1.0-beta2
projects[addressfield][subdir] = "contrib"
projects[features] = 1.0-rc2
projects[features][patch][] = "http://drupal.org/files/1265168.23.Enabling_multiple_features_at_the_same_time_may_fail.patch"
projects[features][subdir] = "contrib"
projects[strongarm] = 2.0-rc1
projects[strongarm][subdir] = "contrib"
projects[taxonomy_menu] = 1.2
projects[taxonomy_menu][subdir] = "contrib"
projects[views_slideshow] = 3.0
projects[views_slideshow][subdir] = "contrib"
projects[libraries] = 1.0
projects[libraries][subdir] = "contrib"
projects[tipsy] = 1.0-rc1
projects[tipsy][subdir] = "contrib"
projects[advanced_help] = 1.0
projects[advanced_help][subdir] = "contrib"

; Drupal Commerce and Commerce contribs.
projects[commerce] = 1.2
projects[commerce][subdir] = "contrib"
projects[commerce][patch][] = "http://drupal.org/files/1534464-unserialize-fix.patch"
projects[commerce][patch][] = "http://drupal.org/files/1518084-commerce-expose-amount-floatted-4.patch"
projects[commerce_features] = 1.x-dev
projects[commerce_features][subdir] = "contrib"
projects[commerce_addressbook] = 2.x-dev
projects[commerce_addressbook][subdir] = "contrib"
projects[commerce_shipping] = 2.x-dev
projects[commerce_shipping][subdir] = "contrib"
projects[commerce_flat_rate] = 1.x-dev
projects[commerce_flat_rate][subdir] = "contrib"
projects[commerce_flat_rate][patch][] = "http://drupal.org/files/1402762_export_flat_rate_commerce_features-4.patch"



; Other contribs.
projects[http_client] = 2.3
projects[http_client][subdir] = "contrib"
projects[oauth] = 3.x-dev
projects[oauth][subdir] = "contrib"
projects[oauth][patch][] = "http://drupal.org/files/980340-d7.patch"
projects[oauth][patch][] = "http://drupal.org/files/1535764-fix-signatures.patch"
projects[inline_entity_form] = 1.x-dev
projects[inline_entity_form][subdir] = "contrib"
projects[field_extractor] = 1.x-dev
projects[field_extractor][subdir] = "contrib"

; Search related modules.
projects[search_api] = 1.x-dev
projects[search_api][subdir] = "contrib"
projects[search_api_db] = 1.x-dev
projects[search_api_db][subdir] = "contrib"
projects[search_api_ranges][type] = module
projects[search_api_ranges][download][type] = git
projects[search_api_ranges][download][branch] = 7.x-1.x
projects[search_api_ranges][patch][] = "patches/search_api_ranges-add-support-for-commerce-price-fields-1350528-16.patch"
projects[search_api_ranges][subdir] = "contrib"
projects[facetapi] = 1.0-rc4
projects[facetapi][subdir] = "contrib"

; UI improvement modules.
projects[module_filter] = 1.6
projects[module_filter][subdir] = "contrib"
projects[flexslider] = 1.0-rc2
projects[flexslider][subdir] = "contrib"
projects[image_delta_formatter] = 1.x-dev
projects[image_delta_formatter][subdir] = "contrib"
projects[link] = 1.0
projects[link][subdir] = "contrib"

; Base theme
projects[omega] = 3.1

; Libraries
libraries[flexslider][type] = "libraries"
libraries[flexslider][download][type] = "git"
libraries[flexslider][download][url] = "https://github.com/woothemes/FlexSlider.git"
