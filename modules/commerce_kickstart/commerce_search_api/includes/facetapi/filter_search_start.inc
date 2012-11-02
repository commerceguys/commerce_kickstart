<?php

/**
 * Filter out items should not appear on empty search.
 */
class CommerceSearchApiSearchStart extends FacetapiFilter {

  public function execute(array $build) {
    if (!count($this->adapter->getAllActiveItems())) {
      return array();
    }
    return $build;
  }
}
