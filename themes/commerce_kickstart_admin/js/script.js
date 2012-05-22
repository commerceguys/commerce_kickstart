(function ($) {
  Drupal.behaviors.customSelect = {
    attach: function(context) {
      $("select.form-select").not(".draggable select.form-select, #views-ajax-popup select.form-select").customSelect();
    }
  }
})(jQuery);
