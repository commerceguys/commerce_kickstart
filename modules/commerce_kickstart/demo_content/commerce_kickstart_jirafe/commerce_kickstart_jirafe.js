(function ($) {

/**
 * Summary for the module Commerce Kickstart Jirafe.
 */
Drupal.behaviors.commerce_kickstart_jirafe_summaries = {
  attach: function (context) {
    $('fieldset.jirafe-vocab', context).drupalSetSummary(function (context) {
      var fieldset_id = $(context).attr('id');
      var checked = new Array();
      $(':checkbox', context).each(function (index, el) {
        if ($(el).attr('checked')) {
          var element_id =$(el).attr('id');
          checked.push($("label[for='" + element_id + "']").text().trim());
        }
      });

      if (checked.length > 0) {
        return Drupal.t('Using: ') + Drupal.checkPlain(checked.join(', ')) + '.';
      }
      else {
        return Drupal.t('None selected.');
      }
    });
  }
};

})(jQuery);
