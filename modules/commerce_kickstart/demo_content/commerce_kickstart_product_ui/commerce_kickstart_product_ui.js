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
      $('.field-name-body .field-item p').expander({
        slicePoint: 200,
        expandPrefix: '...<br />',
        expandText: 'read more',
        userCollapseText: 'read less',
        expandEffect: 'fadeIn',
        expandSpeed: 250,
        collapseEffect: 'fadeOut',
        collapseSpeed: 200
      });
    }
  }

})(jQuery);
