(function ($) {

  // Fadeout add to cart message.
  Drupal.behaviors.addtocartMessage = {
    attach: function ( context, settings ) {
      $('.commerce-kickstart-add-to-cart-close').live('click', function() {
        $('div.commerce-kickstart-add-to-cart').remove();
      });
    }
  }

})(jQuery);
