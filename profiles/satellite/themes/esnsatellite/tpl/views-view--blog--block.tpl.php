<?php
/**
 * Created by PhpStorm.
 * User: Marco
 * Date: 08.12.2014
 * Time: 22:55
 */

?>
<div class="<?php print $classes; ?>">
<?php if ($view->total_rows): ?>
  <ul>
    <?php foreach ($view->result as $index => $item):
      $first = $index == 0;
      $last = $index == ($view->total_rows - 1);
      $item_classes = array("item-$index", 'item-' . ($index % 2 == 0 ? 'even' : 'odd'));
      if ($first) {
        $item_classes[] = 'item-first';
      }
      if ($last) {
        $item_classes[] = 'item-last';
      }
      $item_classes = implode(' ', $item_classes);
      $link = l($item->node_title, "node/{$item->nid}");
      $created = format_date($item->node_created, 'short');
      ?>
      <li class="<?php print $item_classes; ?>">
        <?php print $link; ?><span class="node-created"><?php print $created; ?></span>
      </li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
  <?php print $more; ?>
</div>