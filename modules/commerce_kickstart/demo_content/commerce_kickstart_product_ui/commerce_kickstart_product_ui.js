(function ($) {

  // Add a spinner on quantity widget.
  Drupal.behaviors.quantityWidgetSpinner = {
    attach: function ( context, settings ) {
      $('.form-item-quantity input').spinner({
        min: 1,
        max: 20,
        increment: 'fast'
      });
    }
  }

  // Add 'read more' link on description.
  Drupal.behaviors.bodyReadMore = {
    attach: function ( context, settings ) {
      $('.field-name-body .field-item.even').expander({
        slicePoint:       200,
        expandPrefix:     ' ... ',
        expandText:       'read more',
        userCollapseText: 'Close'
      });
    }
  }

})(jQuery);
