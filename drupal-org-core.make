api = 2
core = 7.x
projects[drupal][version] = 7.72

; Patches for Core
; This patch will not apply, and there shouldn't be any new installs happening, so skip this patch.
; projects[drupal][patch][3077423] = "https://www.drupal.org/files/issues/2019-12-19/3077423-11.patch"
projects[drupal][patch][865536] = "https://www.drupal.org/files/issues/2019-12-18/Drupal-core--865536-263--brower-key-for-js-do-not-test.patch"
projects[drupal][patch][1772316] = "http://drupal.org/files/issues/drupal-7.x-allow_profile_change_sys_req-1772316-28.patch"
projects[drupal][patch][1275902] = "https://www.drupal.org/files/issues/1275902-33-entity_uri_callback-D7_0.patch"
