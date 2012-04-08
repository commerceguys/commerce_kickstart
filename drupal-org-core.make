api = 2
core = 7.x
projects[drupal][version] = 7.12

; Patches for Core
projects[drupal][patch][] = "patches/1074108-skip-profile-11.patch"
projects[drupal][patch][] = "patches/kickstart-hide-other-profiles.patch"
projects[drupal][patch][] = "patches/728702-install-redirect-on-empty-database-36.patch"
