

	
	<!-- TEST -->

	<?php if (!isset($node_content) && $node_content['field_image']): ?>
		<div id="title-image">
			<?php
				if ($my_image_field):
				   print render($my_image_field);
				endif;
			?>
		</div>
	<?php endif; ?>


	

	<?php if (!isset($node_content) && ($node_content['field_date'])): ?>
		<div class="subtitle">
			<?php print render($node_content['field_date']) ?>
		</div>
	<?php endif; ?>