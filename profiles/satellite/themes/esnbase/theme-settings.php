<?php
/**
 * Implements hook_form_system_theme_settings_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function esnbase_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL)  {
	

	$form['esnbase_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('ESN Base settings')
	);

	$form['esnbase_settings']['nav-size'] = array(
		'#type'          => 'select',
		'#title'         => t('Navigation Size'),
		'#default_value' => theme_get_setting('nav-size'),
		'#description'   => t("Lorem ipsum dolor init"),
		'#options' => array(
			's' => t('Small'),
			'm' => t('Medium'),
			'l' => t('Large'),
		),
	);

	$form['esnbase_settings']['fade-effect'] = array(
		'#type' => 'checkbox',
		'#title' => t('Fade-in effect'),
		'#default_value' => theme_get_setting('fade-effect'),
		'#description' => t('Check here if you want the theme to fade in pages when they load.'),
	);

	

	// Work-around for a core bug affecting admin themes. See issue #943212.

	if (isset($form_id)) {
		return;
	}

	// Create the form using Forms API: http://api.drupal.org/api/7

	/* -- Delete this line if you want to use this setting
	$form['pulsar_example'] = array(
	'#type'          => 'checkbox',
	'#title'         => t('pulsar sample setting'),
	'#default_value' => theme_get_setting('pulsar_example'),
	'#description'   => t("This option doesn't do anything; it's just an example."),
	);
	// */

	// Remove some of the base theme's settings.
	/* -- Delete this line if you want to turn off this setting.
	unset($form['themedev']['zen_wireframes']); // We don't need to toggle wireframes on this site.
	// */

	// We are editing the $form in place, so we don't need to return anything.
}
