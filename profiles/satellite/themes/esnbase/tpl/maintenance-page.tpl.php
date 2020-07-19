<!DOCTYPE html>
<!--[if IEMobile 7]><html class="iem7" <?php print $html_attributes; ?>><![endif]-->
<!--[if lte IE 6]><html class="lt-ie9 lt-ie8 lt-ie7" <?php print $html_attributes; ?>><![endif]-->
<!--[if (IE 7)&(!IEMobile)]><html class="lt-ie9 lt-ie8" <?php print $html_attributes; ?>><![endif]-->
<!--[if IE 8]><html class="lt-ie9" <?php print $html_attributes; ?>><![endif]-->

<html class="maintenance-page">
<head>
	<?php print $head; ?>
	<title><?php print $head_title; ?></title>
	<?php if ($default_mobile_metatags): ?>
		<meta name="MobileOptimized" content="width">
		<meta name="HandheldFriendly" content="true">
		<meta name="viewport" content="width=device-width, initial-scale=1">
  
	<?php endif; ?>
	<meta http-equiv="cleartype" content="on">
	<?php print $styles; ?>
	<?php print $scripts; ?>
	<?php if ($add_respond_js): ?>
		<!--[if lt IE 9]><script src="<?php print $base_path . $path_to_zen; ?>/js/html5-respond.js"></script><![endif]-->
	<?php elseif ($add_html5_shim): ?>
		<!--[if lt IE 9]><script src="<?php print $base_path . $path_to_zen; ?>/js/html5.js"></script><![endif]-->
	<?php endif; ?>
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>

	<div id="wrapper">

		<div id="maintenance">
			
				<div id="maintenance-icon"></div>

				<div id="maintenance-message">
					<?php print $content; ?>
				</div>
			
		</div>

		
	</div>
</body>

</html>