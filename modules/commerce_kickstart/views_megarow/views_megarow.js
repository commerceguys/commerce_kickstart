/**
 * @file
 *
 * Alternative implementation of the CTools modal form.
 * Opens a "megarow" in the table instead of a dialog.
 *
 * Unlike with CTools modals, multiple megarows can be open at the same time,
 * which is why each command accepts an id used to match the correct megarow.
 *
 * This javascript relies on the CTools ajax responder.
 */

(function ($) {
  Drupal.ViewsMegarow = Drupal.ViewsMegarow || {};

  /**
   * Display the modal
   */
  Drupal.ViewsMegarow.show = function(entity_id) {
    // There's already a megarow open for this entity, abort.
    if ($(Drupal.ViewsMegarow.getRow(entity_id)).length > 0) {
      return;
    }

    var defaults = {
      modalTheme: 'ViewsMegarowDialog',
      throbberTheme: 'ViewsMegarowThrobber',
      animation: 'show',
      animationSpeed: 'fast',
      modalOptions: {
        opacity: .55,
        background: '#fff'
      }
    };
    var settings = {};
    $.extend(true, settings, defaults, Drupal.settings.ViewsMegarow);
    Drupal.ViewsMegarow.currentSettings = settings;

    var megarowContent = $(Drupal.theme(settings.modalTheme, entity_id));

    $('.megarow-title', megarowContent).html(Drupal.ViewsMegarow.currentSettings.loadingText);
    $('.megarow-content', megarowContent).html(Drupal.theme(settings.throbberTheme));
    megarowContent.hide();

    // Create our megarow.
    var tableclass = $(".views-table").attr('class');
    var nbcols = tableclass.replace('views-table cols-','');
    $('tr.item-' + entity_id).after('<tr class="megarow-content"><td class="megarow-cell" colspan="' + nbcols + '"><div class="modalContent">' + $(megarowContent).html() + '</div></td></tr>');

    // Bind a click for closing the modalContent
    modalContentClose = function(event){
      close(event);
      return false;
    };
    $(Drupal.ViewsMegarow.getRow(entity_id)).find('.close').bind('click', modalContentClose);

    // Close the open modal content and backdrop
    function close(event) {
      var megarow = $(event.target).parents('tr.megarow-content');

      // Unbind the events
      $(event.target).unbind('click', modalContentClose);
      $(document).trigger('CToolsDetachBehaviors', megarow);

      // Set our animation parameters and use them
      if (settings.animation == 'fadeIn') animation = 'fadeOut';
      if (settings.animation == 'slideDown') animation = 'slideUp';
      if (settings.animation == 'show') animation = 'hide';

      // Close and remove the megarw
      $('.modalContent', megarow).hide()[animation](settings.speed);
      $(megarow).remove();
    };
  };

  /**
   * Helper to get the megarow matching the passed entity id.
   */
  Drupal.ViewsMegarow.getRow = function (entity_id) {
    return $('.views-megarow-content-' + entity_id).parents('tr').eq(0);
  }

  /**
   * Provide the HTML to create the megarow.
   */
  Drupal.theme.prototype.ViewsMegarowDialog = function (entity_id) {
    var html = '';
    html += '<div class="views-megarow" class="popups-box">';
    html += '  <div class="views-megarow-content views-megarow-content-' + entity_id + '">';
    html += '    <div class="popups-container">';
    html += '      <div class="megarow-header clearfix">';
    html += '        <span class="megarow-title" class="megarow-title"></span>';
    html += '        <span class="popups-close"><a class="close" href="#">' + Drupal.ViewsMegarow.currentSettings.closeText + '</a></span>';
    html += '        <div class="clear-block"></div>';
    html += '      </div>';
    html += '      <div class="megarow-scroll"><div class="megarow-content" class="megarow-content popups-body"></div></div>';
    html += '    </div>';
    html += '  </div>';
    html += '</div>';
    return html;
  }

  /**
   * Provide the HTML to create the throbber.
   */
  Drupal.theme.prototype.ViewsMegarowThrobber = function () {
    var html = '';
    html += '  <div class="megarow-throbber">';
    html += '    <div class="megarow-throbber-wrapper">';
    html +=        Drupal.ViewsMegarow.currentSettings.throbber;
    html += '    </div>';
    html += '  </div>';

    return html;
  };

  /**
   * Handler to prepare the megarow for the response
   */
  Drupal.ViewsMegarow.clickAjaxLink = function () {
    var entity_id = $(this).parents('tr').attr('data-entity-id');
    Drupal.ViewsMegarow.show(entity_id);

    return false;
  };

  /**
   * Submit responder to do an AJAX submit on all megarow forms.
   */
  Drupal.ViewsMegarow.submitAjaxForm = function(e) {
    var url = $(this).attr('action');
    var form = $(this);

    setTimeout(function() { Drupal.CTools.AJAX.ajaxSubmit(form, url); }, 1);
    return false;
  }

  /**
   * Bind links that will open megarows to the appropriate function.
   */
  Drupal.behaviors.ViewsMegarow = {
    attach: function(context) {
      // Bind links
      // Note that doing so in this order means that the two classes can be
      // used together safely.
      $('a.views-megarow-open:not(.views-megarow-open-processed)', context)
        .addClass('views-megarow-open-processed')
        .click(Drupal.ViewsMegarow.clickAjaxLink)
        .each(function () {
          // Create a drupal ajax object
          var element_settings = {};
          if ($(this).attr('href')) {
            element_settings.url = $(this).attr('href');
            element_settings.event = 'click';
            element_settings.progress = { type: 'throbber' };
          }
          var base = $(this).attr('href');
          Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
        }
      );

      // Bind our custom event to the form submit
      $('.megarow-content form:not(.views-megarow-open-processed)')
        .addClass('views-megarow-open-processed')
        .each(function() {
          var element_settings = {};
          element_settings.url = $(this).attr('action');
          element_settings.event = 'submit';
          element_settings.progress = { 'type': 'throbber' }
          var base = $(this).attr('id');

          Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
          Drupal.ajax[base].form = $(this);

          $('input[type=submit], button', this).click(function() {
            Drupal.ajax[base].element = this;
            this.form.clk = this;
          });
        });
    }
  };

  // The following are implementations of AJAX responder commands.

  /**
   * AJAX responder command to place HTML within the modal.
   */
  Drupal.ViewsMegarow.megarow_display = function(ajax, response, status) {
    if ($(Drupal.ViewsMegarow.getRow(response.entity_id)).find('.modalContent').length == 0) {
      Drupal.ViewsMegarow.show(response.entity_id);
    };
    Drupal.ViewsMegarow.getRow(response.entity_id).find('.megarow-title').html(response.title);
    Drupal.ViewsMegarow.getRow(response.entity_id).find('.megarow-content').html(response.output);
    Drupal.attachBehaviors();
  }

  /**
   * AJAX responder command to dismiss the modal.
   * @TODO: Find an example to use the dismiss part and test it.
   */
  Drupal.ViewsMegarow.megarow_dismiss = function(ajax, response, status) {
    var content = Drupal.ViewsMegarow.getRow(response.entity_id).find('.modalContent');

    // If our animation isn't "fadeIn" or "slideDown" then it always is show
    if (animation != 'fadeOut' && animation != 'slideUp') {
      animation = 'show';
    }

    // Unbind the events we bound
   // $('.close').unbind('click', modalContentClose);
    $(document).trigger('CToolsDetachBehaviors', content);

    // jQuery magic loop through the instances and run the animations or removal.
    content.each(function(){
      if (animation == 'fade') {
        Drupal.ViewsMegarow.getRow().find('.modalContent').fadeOut(speed,function(){$(this).remove();});
      }
      else {
        if (animation == 'slide') {
          Drupal.ViewsMegarow.getRow().find('.modalContent').slideUp(speed,function(){$(this).remove();});
        }
        else {
          Drupal.ViewsMegarow.getRow().find('.modalContent').remove();
        }
      }
    });
  }

  /**
   * Find a URL for an AJAX button.
   *
   * The URL for this gadget will be composed of the values of items by
   * taking the ID of this item and adding -url and looking for that
   * class. They need to be in the form in order since we will
   * concat them all together using '/'.
   */
  Drupal.ViewsMegarow.findURL = function(item) {
    var url = '';
    var url_class = '.' + $(item).attr('id') + '-url';
    $(url_class).each(
      function() {
        if (url && $(this).val()) {
          url += '/';
        }
        url += $(this).val();
      });
    return url;
  };

  /**
   * Add an extra function to the Drupal ajax object
   * which allows us to trigger an ajax response without
   * an element that triggers it.
   */
  Drupal.ajax.prototype.updateRow = function(url) {
    var ajax = this;

    ajax.url = url;
    ajax.options.url = url;

    // Do not perform another ajax command if one is already in progress.
    if (ajax.ajaxing) {
      return false;
    }

    try {
      $.ajax(ajax.options);
    }
    catch (err) {
      alert('An error occurred while attempting to process ' + ajax.options.url);
      return false;
    }

    return false;
  };

  /**
   * Define a custom ajax action not associated with an element.
   */
  var custom_settings = {};
  // fake url
  custom_settings.url = '/views_megarow_update/';
  custom_settings.keypress = false;
  custom_settings.prevent = false;
  Drupal.ajax['custom_ajax_action'] = new Drupal.ajax(null, $(document.body), custom_settings);

  /**
   * Define a point to trigger our custom actions. e.g. on page load.
   */
  Drupal.behaviors.viewsMegarowRefresh = {
    attach: function (context) {
      // bind custom event on a row that will refresh it when form is submit with success
      $('table.views-table tr').bind('refreshRow', function() {
        var viewName = $(this).parents('table.views-table').attr('data-viewname');
        var viewDisplay = $(this).parents('table.views-table').attr('data-viewdisplay');
        var entityId = $(this).attr('data-entity-id');
        var url = '/views_megarow_update/' + entityId + '/ajax/' + viewName + '/' + viewDisplay;
        Drupal.ajax['custom_ajax_action'].updateRow(url);
      });
    }
  };

  $(function() {
    Drupal.ajax.prototype.commands.megarow_display = Drupal.ViewsMegarow.megarow_display;
    Drupal.ajax.prototype.commands.megarow_dismiss = Drupal.ViewsMegarow.megarow_dismiss;
  });
})(jQuery);
