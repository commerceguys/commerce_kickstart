; Use this file to build a full distribution including Drupal core and the
; Commerce Kickstart install profile using the following command:
;
; drush make distro.make <target directory>

api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = "7"

; Add Commerce Kickstart to the full distribution build.
projects[commerce_kickstart][type] = profile
projects[commerce_kickstart][version] = 1.x-dev
projects[commerce_kickstart][download][type] = git
projects[commerce_kickstart][download][url] = http://git.drupal.org/project/commerce_kickstart.git
projects[commerce_kickstart][download][branch] = 7.x-1.x
