<div id="wrapper">

<div id="page">

	<div id="header">
		<?php if ($logo): ?>
			<img id="logo" src="<?php print $logo ?>" alt="<?php print $site_name ?>" />
		<?php endif; ?>
	</div>

	<div id="main">

		<?php if ($sidebar_first): ?>
			<div id="sidebar" class="sidebar">
				<?php print $sidebar_first ?>
			</div>
		<?php endif; ?>

		<div id="content">
			
			<!-- TITLE -->

			<?php if ($title): ?>
				<h1 class="page-title"><?php print $title; ?></h1>
			<?php endif; ?>

			<!-- CONSOLE -->

			<?php if ($messages): ?>
				<div id="console"><?php print $messages; ?></div>
			<?php endif; ?>

			<!-- HELP -->

			<?php if ($help): ?>
				<div id="help"><?php print $help; ?></div>
			<?php endif; ?>

			<!-- BODY -->

			<div id="body">
				<?php print $content; ?>
			</div>

		</div>

	</div>

</div>

<div id="footer">
	The ESN Satellite is made by the IT committee of ESN International
</div>

</div>