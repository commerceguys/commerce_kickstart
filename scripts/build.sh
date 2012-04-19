#!/bin/bash
set -e

#
# Build the distribution using the same process used on Drupal.org
#
# Usage: scripts/build.sh <destination> from the profile main directory.
#

if [ "x$1" == "x" ]; then
  echo "[error] Usage: build.sh [destination]"
  exit 1
fi
DESTINATION=$1

if [ ! -f drupal-org.make ]; then
  echo "[error] Run this script from the distribution base path."
  exit 1
fi

# Build the profile.
echo "Building the profile..."
drush make --no-core --contrib-destination drupal-org.make .

# Build a drupal-org-core.make file if it doesn't exist.
if [ ! -f drupal-org-core.make ]; then
  cat >> drupal-org-core.make <<EOF
api = 2
core = 7.x
projects[drupal] = 7
EOF
fi

# Build the distribution and copy the profile in place.
echo "Building the distribution..."
drush make drupal-org-core.make $DESTINATION
cp -r . $DESTINATION/profiles/commerce_kickstart
