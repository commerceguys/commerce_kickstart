
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <div class="content-left">
      <?php
        print render($content_left);
      ?>
    </div>

    <div class="content-right">
      <?php
        print render($content_right);
      ?>
    </div>
  </div>
</div>
