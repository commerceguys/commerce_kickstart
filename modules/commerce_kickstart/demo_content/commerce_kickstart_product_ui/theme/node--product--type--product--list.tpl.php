<article<?php print $attributes; ?>>
  <figure>
    <?php print render($content['product:field_images']); ?>
  </figure>
  <header>
    <div class="product-title"><h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2></div>
  </header>
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
</article>
