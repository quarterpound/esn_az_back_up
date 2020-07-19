<?php
/**
 * @file
 * Display Suite core_promotabs_side_3sub template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 * - $layout_wrapper: wrapper surrounding the layout.
 *
 * Regions:
 *
 * - $promo: Rendered content for the "Promo" region.
 * - $promo_classes: String of classes that can be used to style the "Promo" region.
 *
 * - $sidebar_1: Rendered content for the "Sidebar 1" region.
 * - $sidebar_1_classes: String of classes that can be used to style the "Sidebar 1" region.
 *
 * - $subpod_1: Rendered content for the "Subpod 1" region.
 * - $subpod_1_classes: String of classes that can be used to style the "Subpod 1" region.
 *
 * - $subpod_2: Rendered content for the "Subpod 2" region.
 * - $subpod_2_classes: String of classes that can be used to style the "Subpod 2" region.
 *
 * - $subpod_3: Rendered content for the "Subpod 3" region.
 * - $subpod_3_classes: String of classes that can be used to style the "Subpod 3" region.
 */
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes;?> clearfix">

	<!-- Needed to activate contextual links -->
	<?php if (isset($title_suffix['contextual_links'])): ?>
		<?php print render($title_suffix['contextual_links']); ?>
	<?php endif; ?>

	<<?php print $image_wrapper; ?> class="group-image<?php print $image_classes; ?>">
		<?php print $image; ?>
	</<?php print $image_wrapper; ?>>

	<<?php print $main_content_wrapper; ?> class="group-content<?php print $main_content_classes; ?>">
		<?php print $main_content; ?>
	</<?php print $main_content_wrapper; ?>>

</<?php print $layout_wrapper ?>>

<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
	<?php print $drupal_render_children ?>
<?php endif; ?>
