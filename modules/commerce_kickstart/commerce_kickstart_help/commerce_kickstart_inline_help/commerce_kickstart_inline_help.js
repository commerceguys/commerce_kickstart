(function ($) {

  $(document).ready(function () {

    $('.kickstart-help-full-content').before($('<p><a href="#" class="help-show-more">Show more</a></p>'));
    $('.kickstart-help-full-content').hide();
    $('.help-show-more').click(function() {
      $('.kickstart-help-full-content').toggle('slow');
      if ($('.help-show-more').html() == 'Show more') {
        $('.help-show-more').html('Show less');
      }
      else {
        $('.help-show-more').html('Show more');
      }
    });
    // Check if the help section is hidden. If so, hide the open button.
    if ($('#commerce-kickstart-inline-help').is(":visible")) {
      $('#commerce-kickstart-inline-help-button').hide();
    }
  });

  Drupal.behaviors.KickstartInlineHelp = {
    attach:function () {

      var textArea;
      var openButton;
      var openButtonContainer;
      var closeButton;

      textArea = $('#commerce-kickstart-inline-help');
      openButton = $('#commerce-kickstart-inline-help-button #edit-commerce-kickstart-inline-help-button');
      openButtonContainer = $('#commerce-kickstart-inline-help-button');
      closeButton = $('#edit-commerce-kickstart-inline-help-close-button');

      closeButton.click(function () {
        textArea.hide('slow');
        openButtonContainer.show();
        closeButton.hide();
      });

      openButton.click(function() {
        textArea.show('slow');
        openButtonContainer.hide();
        closeButton.show();
      });
    }
  }
})(jQuery);

