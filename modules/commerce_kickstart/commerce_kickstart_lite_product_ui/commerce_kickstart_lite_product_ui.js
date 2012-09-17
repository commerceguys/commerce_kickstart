(function ($) {

  // Add a spinner on quantity widget.
  Drupal.behaviors.quantityWidgetSpinner = {
    attach: function ( context, settings ) {
      $('.form-item-quantity input').spinner({
        min: 1,
        max: 9999,
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

  // Handle cloud zoom on small devices.
  Drupal.behaviors.cloud_zoom = {
    attach: function(context, settings) {
      $('body').bind('responsivelayout', function(e, d) {
        if($(this).hasClass("responsive-layout-mobile")) {
          $('.cloud-zoom-big, .cloud-zoom-lens').hide();
          $('.cloud-zoom-big, .mousetrap, .cloud-zoom-lens').css('display','none');
        }
        else {
          $('.cloud-zoom, .cloud-zoom-gallery').CloudZoom();
          $('body').unbind('responsivelayout');
        }
      });
    }
  }
})(jQuery);
