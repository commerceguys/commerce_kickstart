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
      $.expander.defaults.slicePoint = 120;

      $(document).ready(function() {
        $('.field-name-body p').expander({
          slicePoint:       200,
          expandPrefix:     ' ...<br />',
          expandText:       'Read more',
          userCollapseText: 'Close'
        });
      });
    }
  }

})(jQuery);
