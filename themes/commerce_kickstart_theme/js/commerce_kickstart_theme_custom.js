(function ($) {
  Drupal.behaviors.commerce_kickstart_theme_custom = {
    attach: function(context, settings) {
      if ($('body').hasClass('toolbar')) {
        $(window).resize(function() {
          var toolbarHeight = $('div#toolbar').height();
          $('.zone-user-wrapper').css('top', toolbarHeight + 'px');
        });
      }
    }
  }
  // Add background overlay to add to cart popin.
  Drupal.behaviors.commerce_kickstart_add_to_cart_overlay = {
    attach:function (context, settings) {
      if ($('.commerce-kickstart-add-to-cart').length > 0 ) {
        $('body').append("<div class=\"commerce_kickstart_add_to_cart_overlay\"></div>");
        $('.commerce-kickstart-add-to-cart-close').live('click', function() {
          $('.commerce_kickstart_add_to_cart_overlay').remove();
        });
      }
  // Disable input fields on price range when viewing the site
  // on normal devices.
  Drupal.behaviors.commerce_kickstart_theme_custom_search_api_ranges = {
    attach:function (context, settings) {
      $('body').bind('responsivelayout', function(e, d) {
        if($(this).hasClass("responsive-layout-normal")) {
          $('#edit-range-from').attr({
            "disabled" : true,
            "readonly" : true
          });
          $('#edit-range-to').attr({
            "disabled" : true,
            "readonly" : true
          });
        }
        else {
          $('body').unbind('responsivelayout');
        }
      });
    }
  }
})(jQuery);
