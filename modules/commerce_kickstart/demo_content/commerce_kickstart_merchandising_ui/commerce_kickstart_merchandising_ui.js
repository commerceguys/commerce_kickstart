(function ($) {
  Drupal.behaviors.commerce_kickstart_merchandising_ui_custom = {
    attach: function(context, settings) {

      // Conflict betwwen this script bxslider and ctools for display the modal.
      // Hack: add a class on slider when the pager is displayed and test after if the class exist.
      var processed = $('.event-slider', context).hasClass('pager-processed');
      if (typeof $.fn.bxSlider != 'undefined' && processed == false) {
        // bx Slider.
        var slider = $('.event-slider', context).bxSlider({
          auto: true,
          autoHover: true,
          controls: true,
          pause: 2000,
          hideControlOnEnd: false,
          mode: 'fade',
          prevText: '<span>' + $('.event-slider .views-row:last .views-field-field-headline').text() + '</span>',
          nextText: '<span>' + $('.event-slider .views-row-2 .views-field-field-headline').text() + '</span>',
          onBeforeSlide: function(currentSlideNumber, totalSlideQty, currentSlideHtmlObject){
            var leftSlideNumber = currentSlideNumber == 0 ? (totalSlideQty - 1) : (currentSlideNumber - 1);
            var rightSlideNumber = currentSlideNumber == (totalSlideQty - 1) ? 0 : (currentSlideNumber + 1);
            var leftSlideText = $(currentSlideHtmlObject).parents('.event-slider').find('.views-row-' + (leftSlideNumber + 1) + ':first .views-field-field-headline').text();
            var rightSlideText = $(currentSlideHtmlObject).parents('.event-slider').find('.views-row-' + (rightSlideNumber + 1) + ':first .views-field-field-headline').text();
            $(currentSlideHtmlObject).parents('.bx-wrapper').find('a.bx-prev span').text(leftSlideText);
            $(currentSlideHtmlObject).parents('.bx-wrapper').find('a.bx-next span').text(rightSlideText);
          },
          speed: 0
        });
        $('.event-slider', context).addClass('pager-processed')
      };
    }
  };
})(jQuery);
