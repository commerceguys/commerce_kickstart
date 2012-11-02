<?php

/**
 * Data alteration callback that filters out nodes that aren't
 * product displays.
 */
class CommerceSearchApiProductDisplayFilter extends SearchApiAbstractAlterCallback {

  /**
   * @param SearchApiIndex $index
   * @return bool
   */
  public function supportsIndex(SearchApiIndex $index) {
    $bundles = commerce_product_reference_node_types();
    return ($index->item_type == 'node' && !empty($bundles));
  }

  /**
   * Exclude items that doesn't have a product reference field attached to
   * the bundle.
   */
  public function alterItems(array &$items) {
    if ($bundles = commerce_product_reference_node_types()) {
      foreach ($items as $id => $item) {
        if (!isset($bundles[$item->type])) {
          unset($items[$id]);
        }
      }
    }
  }

}
