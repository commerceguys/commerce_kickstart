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
})(jQuery);
