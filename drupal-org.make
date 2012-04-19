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
projects[features] = 1.0-rc1
projects[features][subdir] = "contrib"
projects[strongarm] = 2.0-rc1
projects[strongarm][subdir] = "contrib"
projects[taxonomy_menu] = 1.2
projects[taxonomy_menu][subdir] = "contrib"
projects[views_slideshow] = 3.0
projects[views_slideshow][subdir] = "contrib"
projects[libraries] = 1.0
projects[libraries][subdir] = "contrib"

; Drupal Commerce and Commerce contribs.
projects[commerce] = 1.2
projects[commerce][subdir] = "contrib"
projects[commerce][patch][] = "http://drupal.org/files/1534464-unserialize-fix.patch"
projects[commerce_features] = 1.x-dev
projects[commerce_features][subdir] = "contrib"
projects[commerce_addressbook] = 2.x-dev
projects[commerce_addressbook][subdir] = "contrib"
projects[commerce_shipping] = 2.0-beta1
projects[commerce_shipping][subdir] = "contrib"
projects[commerce_flat_rate] = 1.0-beta1
projects[commerce_flat_rate][subdir] = "contrib"


; Other contribs.
projects[inline_entity_form][type] = module
projects[inline_entity_form][download][type] = git
projects[inline_entity_form][download][revision] = 0b57262da6b6e0f5b3107a0f4e6a1a8c935b1449
projects[inline_entity_form][download][branch] = 7.x-1.x
projects[inline_entity_form][subdir] = "contrib"

; Search related modules.
projects[search_api] = 1.x-dev
projects[search_api][subdir] = "contrib"
projects[search_api_db] = 1.x-dev
projects[search_api_db][subdir] = "contrib"
projects[search_api_ranges] = 1.2
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

; Base theme
projects[omega] = 3.1

; Libraries
libraries[flexslider][type] = "libraries"
libraries[flexslider][download][type] = "git"
libraries[flexslider][download][url] = "https://github.com/woothemes/FlexSlider.git"
