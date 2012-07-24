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
    }
  }
})(jQuery);
