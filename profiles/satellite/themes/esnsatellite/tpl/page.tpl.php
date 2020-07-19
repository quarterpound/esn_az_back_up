<?php
/**
* @file
* Zen theme's implementation to display a single Drupal page.
*
* Available variables:
*
* General utility variables:
* - $base_path: The base URL path of the Drupal installation. At the very
*   least, this will always default to /.
* - $directory: The directory the template is located in, e.g. modules/system
*   or themes/bartik.
* - $is_front: TRUE if the current page is the front page.
* - $logged_in: TRUE if the user is registered and signed in.
* - $is_admin: TRUE if the user has permission to access administration pages.
*
* Site identity:
* - $front_page: The URL of the front page. Use this instead of $base_path,
*   when linking to the front page. This includes the language domain or
*   prefix.
* - $logo: The path to the logo image, as defined in theme configuration.
* - $site_name: The name of the site, empty when display has been disabled
*   in theme settings.
* - $site_slogan: The slogan of the site, empty when display has been disabled
*   in theme settings.
*
* Navigation:
* - $main_menu (array): An array containing the Main menu links for the
*   site, if they have been configured.
* - $secondary_menu (array): An array containing the Secondary menu links for
*   the site, if they have been configured.
* - $secondary_menu_heading: The title of the menu used by the secondary links.
* - $breadcrumb: The breadcrumb trail for the current page.
*
* Page content (in order of occurrence in the default page.tpl.php):
* - $title_prefix (array): An array containing additional output populated by
*   modules, intended to be displayed in front of the main title tag that
*   appears in the template.
* - $title: The page title, for use in the actual HTML content.
* - $title_suffix (array): An array containing additional output populated by
*   modules, intended to be displayed after the main title tag that appears in
*   the template.
* - $messages: HTML for status and error messages. Should be displayed
*   prominently.
* - $tabs (array): Tabs linking to any sub-pages beneath the current page
*   (e.g., the view and edit tabs when displaying a node).
* - $action_links (array): Actions local to the page, such as 'Add menu' on the
*   menu administration interface.
* - $feed_icons: A string of all feed icons for the current page.
* - $node: The node object, if there is an automatically-loaded node
*   associated with the page, and the node ID is the second argument
*   in the page's path (e.g. node/12345 and node/12345/revisions, but not
*   comment/reply/12345).
*
* Regions:
* - $page['header']: Items for the header region.
* - $page['navigation']: Items for the navigation region, below the main menu (if any).
* - $page['help']: Dynamic help text, mostly for admin pages.
* - $page['highlighted']: Items for the highlighted content region.
* - $page['content']: The main content of the current page.
* - $page['sidebar_first']: Items for the first sidebar.
* - $page['sidebar_second']: Items for the second sidebar.
* - $page['footer']: Items for the footer region.
* - $page['bottom']: Items to appear at the bottom of the page below the footer.
*
* @see template_preprocess()
* @see template_preprocess_page()
* @see zen_preprocess_page()
* @see template_process()
*/
?>

<?php
	$nav_primary      = render($page['nav_primary']);
	$nav_secondary    = render($page['nav_secondary']);

	$spotlight        = render($page['spotlight']);

	$content_main     = render($page['content']);
	$content_sidebar  = render($page['content_sidebar']);

	$middle_top       = render($page['middle_top']);
	$middle_first     = render($page['middle_first']);
	$middle_second    = render($page['middle_second']);
	$middle_bottom    = render($page['middle_bottom']);
	$middle_sidebar   = render($page['middle_sidebar']);

	$bottom           = render($page['bottom']);

	$footer_first     = render($page['footer_first']);
	$footer_second    = render($page['footer_second']);
	$footer_third     = render($page['footer_third']);
	$footer_bottom    = render($page['footer_bottom']);
?>

<div id="st-container" class="st-container">

	<div id="page" class="st-pusher">

		<nav id="st-menu" class="st-menu st-effect-3">
			<?php print render($main_menu_expanded); ?>
		</nav>

		<div id="page-inner" class="st-content">

			<!-- HEADER -->

			<header id="header" role="banner" class="clearfix">
				<div class="inner"><div class="inner">

					<div id="mobile-menu">
						<a href="#">Menu</a>
					</div>

					<!-- LOGO -->


					<div id="branding">
						<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
							<?php if ($logo): ?>
								<div id="logo"><img src="<?php print $logo; ?>"></div>
								<div id="site-name" class="site-name-logo"><?php print $site_name; ?></div>
							<?php else: ?>
								<div id="site-name" class="site-name-nologo"><?php print $site_name; ?></div>
							<?php endif;?>
						</a>
					</div>

					<!-- NAV (PRIMARY) -->

					<?php if ($nav_primary): ?>
						<div id="nav-primary">
							<?php print $nav_primary ?>
						</div>
					<?php endif;?>

					<!-- NAV (SECONDARY) -->

					<?php if ($nav_secondary): ?>
						<div id="nav-secondary">
							<?php print $nav_secondary ?>
						</div>
					<?php endif;?>

				</div></div>
			</header>

			<!-- SPOTLIGHT -->

			<?php if ($spotlight): ?>
				<div id="spotlight" class="clearfix">
					<div class="inner">
						<?php print $spotlight ?>
					</div>
				</div>
			<?php endif; ?>

			<!-- MAIN -->

			<div id="main">
				<div class="inner">

					<!-- TITLE -->

					<?php if ($title): ?>
						<div id="title">
							<div class="inner">
								<?php if ($breadcrumb): ?>
									<div id="breadcrumb"><?php print $breadcrumb; ?></div>
								<?php endif; ?>
								<div class="title-container">
									<h1 class="title" id="page-title">
										<?php print $title; ?>
									</h1>
								</div>
								<?php if ($tabs): ?>
									<div id="tabs"><?php print render($tabs); ?></div>
								<?php endif; ?>
							</div>
						</div>
					<?php endif; ?>

					<!-- MESSAGES -->

					<?php if ($messages): ?>
						<div id="console" class="clearfix">
							<div class="inner">
								<?php print $messages; ?>
							</div>
						</div>
					<?php endif; ?>

					<!-- CONTENT -->
					
					<?php if (trim($content_main) || trim($content_sidebar)): ?>
						<div id="content" class="clearfix">
							<div class="inner">

								<!-- CONTENT (MAIN) -->

								<?php if (trim($content_main)): ?>
									<div id="content-main" role="main" class="esn-blocks" <?php ($content_sidebar ? print '' : print 'style="width:100%;"' ) ?>>
										<?php print $content_main; ?>
									</div>
								<?php endif; ?>

								<!-- CONTENT (SIDEBAR) -->

								<?php if ($content_sidebar): ?>
									<div id="content-sidebar" class="esn-blocks">
										<?php print $content_sidebar; ?>
									</div>
								<?php endif; ?>

							</div>
						</div>
					<?php endif; ?>

					<!-- MIDDLE -->

					<div id="middle" class="esn-blocks">
						<div class="inner">

							<div id="middle-main">

								<?php if ($middle_top): ?>
									<div id="middle_top" class="clearfix">
										<?php print $middle_top; ?>
									</div>
								<?php endif; ?>

								<div id="middle-middle" class="clearfix">
									<?php if ($middle_first): ?>
										<div id="middle-first" class="clearfix">
											<?php print $middle_first; ?>
										</div>
									<?php endif; ?>
									<?php if ($middle_second): ?>
										<div id="middle-second" class="clearfix">
											<?php print $middle_second; ?>
										</div>
									<?php endif; ?>
								</div>

								<?php if ($middle_bottom): ?>
									<div id="middle-bottom" class="clearfix">
										<?php print $middle_bottom; ?>
									</div>
								<?php endif; ?>

							</div>

							<div id="middle-aside">

								<?php if ($middle_sidebar): ?>
									<div id="middle-sidebar">
										<?php print $middle_sidebar; ?>
									</div>
								<?php endif; ?>

							</div>

						</div>
					</div>

					<!-- BOTTOM -->

					<?php if ($bottom): ?>
						<div id="bottom" class="esn-blocks clearfix">
							<div class="inner">
								<?php print $bottom; ?>
							</div>
						</div>
					<?php endif; ?>

					<!-- Back to top link -->

					<div id="back-top">
						<a href="#top">Back to top</a>
					</div>
					
				</div>
			</div>

			<!-- FOOTER -->

			<footer id="footer">
				<div class="inner">

					<?php if ($footer_first|$footer_second|$footer_third): ?>

						<div id="footer-middle" class="esn-blocks">
							<div class="inner">
								<?php if ($footer_first): ?>
									<div id="footer-first">
										<?php print $footer_first; ?>
									</div>
								<?php endif; ?>
								<?php if ($footer_second): ?>
									<div id="footer-second">
										<?php print $footer_second; ?>
									</div>
								<?php endif; ?>
								<?php if ($footer_third): ?>
									<div id="footer-third">
										<?php print $footer_third; ?>
									</div>
								<?php endif; ?>
							</div>
						</div>

					<?php endif; ?>
					
					<div id="footer-bottom">
						<div class="inner">
							<?php print $footer_bottom; ?>
							<div class="copyright">
								The ESN Satellite is made by the IT committee of ESN International
							</div>
						</div>
					</div>
					
				</div>
			</footer>

		</div>

	</div>
</div>