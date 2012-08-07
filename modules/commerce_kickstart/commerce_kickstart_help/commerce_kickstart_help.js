(function ($) {
  Drupal.behaviors.kickstarthelp = {
    attach:function () {
      // Disable search if we are not online.
      if (!navigator.onLine) {
        $('#edit-submit, #edit-text').attr('disabled', true);
        $('#edit-text').attr('placeholder', "You are not able to search DrupalCommerce.org while offline.");
      }
      $('#edit-submit').bind('click', function (event) {
        var dc_search_url = 'http://www.drupalcommerce.org/search/node/';
        var search = $('#edit-text').val().trim();
        if (!search.length || !navigator.onLine) {
          event.preventDefault();
          return false;
        }
        search = encodeURI(search).replace('%2f', '/');
        var url = dc_search_url + search;
        $(this).attr('href', url);
      })
    }
  }
})(jQuery);
