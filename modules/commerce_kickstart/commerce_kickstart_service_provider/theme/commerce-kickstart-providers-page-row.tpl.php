<div class="provider-row-wrappepr <?php print $name; ?> <?php print $zebra; ?> clearfix">
  <a class="anchor" name="<?php print $name; ?>"></a>
  <div class="row-wrapper">
    <div class="first">
      <div class="service-logo"><?php print $logo; ?></div>
      <div class="status"><span class="<?php print $status_class; ?>"><?php print $status_text; ?></span></div>
      <div class="requirements"><?php print $requirements; ?></div>
    </div>

    <div class="second">
      <div class="top-wrapper clearfix">
        <div class="service-title"><?php print $title; ?></div>
        <div class="service-type"><?php print $type; ?></div>
      </div>

      <div class="body-wrapper">
        <p class="body"><?php print $description; ?></p>

        <h4 class="installation-title"><?php print t('Installation'); ?></h4>
        <p  class="installation-body">
          <?php print $installation; ?>
        </p>
      </div>
    </div>
  </div>
</div>
