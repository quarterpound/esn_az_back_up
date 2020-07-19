<?php

use ESN\Satellite\Notifications\NotificationManager;

include_once 'satellite.api.inc';

define('SATELLITE_THEME', 'esnsatellite');


function _satellite_update_usermail_templates($key, $offset = false) {
  $template = _user_mail_text($key, NULL, array(), FALSE);
  $search = "[user:name]";
  $replace = "[user:name-raw]";
  if ($offset === true) {
    $offset = strlen($search);
  } else if ($offset === false || $offset < 0) {
    $offset = 0;
  }
  if (strpos($template, $search, $offset)) {
    if ($offset > 0 && strlen($template) > $offset){
      $tmp = array(
        substr($template, 0, $offset),
        substr($template, $offset),
      );
      $tmp[1] = str_replace($search, $replace, $tmp[1]);
      $templateNew = implode('', $tmp);
    } else {
      $templateNew = str_replace($search, $replace, $template);
    }
    if ($template != $templateNew) {
      variable_set('user_mail_' . $key, $templateNew);
      watchdog('satellite', "Satellite: Email template '!template' has been updated to use !rawname", array('!template' => $key, '!rawname' => $replace), WATCHDOG_INFO);
    }
  }
}

/**
 * place blocks during installation.
 */
function satellite_install_place_blocks() {
// enable default blocks
  $blocks = array(
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'visibility' => 0,
      'pages' => '',
      'cache' => -1,
    ),

    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'visibility' => 0,
      'pages' => '',
      'cache' => -1,
    ),

    // Spotlight
    array(
      'module' => 'views',
      'delta' => 'spotlight-block',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'spotlight',
      'visibility' => 1,
      'pages' => '<front>',
      'cache' => -1,
    ),

    // News
    array(
      'module' => 'views',
      'delta' => 'news-block',
      'icon' => 'megaphone',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'middle_second',
      'visibility' => 1,
      'pages' => '<front>',
      'cache' => -1,
    ),

    // Events
    array(
      'module' => 'views',
      'delta' => 'events-next_events_block',
      'icon' => 'direction',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'middle_sidebar',
      'visibility' => 1,
      'pages' => '<front>',
      'cache' => -1,
    ),
    array(
      'module' => 'views',
      'delta' => 'events-past_events_block',
      'icon' => 'world', 
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 2,
      'region' => 'middle_second',
      'visibility' => 1,
      'pages' => '<front>',
      'cache' => -1,
    ),
    // Calendar
    array(
      'module' => 'views',
      'delta' => 'events_calendar-block',
      'icon' => 'calendar',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 2,
      'region' => 'middle_sidebar',
      'visibility' => 1,
      'pages' => '<front>',
      'cache' => -1,
    ),
    // Partners
    array(
      'module' => 'views',
      'delta' => 'partners-block',
      'icon' => 'briefcase',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'middle_first',
      'visibility' => 1,
      'pages' => '<front>',
      'cache' => -1,
    ),
    // Aggregator
    array(
      'module' => 'aggregator',
      'delta' => 'category-1',
      'icon' => 'social-rss',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'middle_first',
      'visibility' => 1,
      'pages' => '<front>',
      'cache' => 1,
    ),
    // Address
    array(
      'module' => 'satellite_settings',
      'delta' => 'address',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'footer_second',
      'visibility' => 0,
      'pages' => '',
      'cache' => 1,
    ),
    // About us
    array(
      'module' => 'satellite_base',
      'delta' => 'about_us',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'footer_first',
      'visibility' => 0,
      'pages' => '',
      'cache' => 1,
    ),
    // login button
    array(
      'module' => 'satellite_base',
      'delta' => 'login',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 0,
      'region' => 'footer_bottom',
      'visibility' => 0,
      'pages' => '',
      'cache' => 1,
    ),
    // social media buttons 
    array(
      'module' => 'satellite_socialmedia',
      'delta' => 'socialmedia',
      'theme' => SATELLITE_THEME,
      'status' => 1,
      'weight' => 5,
      'region' => 'footer_bottom',
      'visibility' => 0,
      'pages' => '',
      'cache' => 1,
    ),
  );
  satellite_insert_blocks($blocks);
}

/**
 * Install esn.org aggregation
 */
function satellite_install_aggregator() {
  // Adding the ESN international category
  $cid = db_insert('aggregator_category')
    ->fields(array(
      'title' => "ESN International",
      'description' => "ESN International news feed",
      'block' => 5,
    ))
    ->execute();
  // Adding the ESN international feed
  $fid = db_insert('aggregator_feed')
    ->fields(array(
      'title' => "ESN International news",
      'url' => "http://esn.org/news/feed",
      'refresh' => 3600,
      'block' => 5,
      'link' => '',
      'description' => '',
      'image' => '',
    ))
    ->execute();
  // Adding the feed to the category.
  $query = db_insert('aggregator_category_feed')->fields(array( 'fid' => $fid, 'cid' => $cid))->execute();
}

/**
 * set satellite theme
 */
function satellite_install_set_theme() {
  $admin_theme = 'adminimal';
  theme_enable(array(SATELLITE_THEME));
  theme_disable(array('bartik'));
  
  // Enable the default theme.
  db_update('system')
    ->fields(array('status' => 1))
    ->condition('type', 'theme')
    ->condition('name', SATELLITE_THEME)
    ->execute();
  variable_set('theme_default', SATELLITE_THEME);
  
  // Enable the admin theme.
  db_update('system')
    ->fields(array('status' => 1))
    ->condition('type', 'theme')
    ->condition('name', $admin_theme)
    ->execute();
  variable_set('admin_theme', $admin_theme);
  variable_set('node_admin_theme', '1');
}

/**
 * create menu link
 */
function satellite_install_set_menu() {
  // Create a Home link in the main menu.
  $item = array(
    'link_title' => st('Home'),
    'link_path' => '<front>',
    'menu_name' => 'main-menu',
    'weight' => -20,
  );
  menu_link_save($item);

  // Create a Calendar link in the main menu.
  $item = array(
    'link_title' => 'Calendar',
    'link_path' => 'calendar',
    'menu_name' => 'main-menu',
    'weight' => 0,
  );
  menu_link_save($item);
  
  // Create the contact menu item.
  $item = array(
    'link_title' => 'Contact',
    'link_path' => 'contact',
    'menu_name' => 'main-menu',
    'weight' => 10,
  );
  menu_link_save($item);

  // Update the menu router information.
  menu_rebuild();
}

/**
 * set cache settings to cache and aggregate css and js by default, except when site is installed
 * in development mode.
 *
 * @see esn_base_is_development_install()
 */
function satellite_install_set_cache_settings() {
  if (esn_base_is_development_install()){
    return;
  }
  variable_set('cache', TRUE);
  variable_set('cache_lifetime', '3600');
  variable_set('page_cache_maximum_age', '86400');
  variable_set('page_compression', TRUE);
  variable_set('preprocess_css', TRUE);
  variable_set('preprocess_js', TRUE);
}


/**
 * The Satellite configuration form, see: satellite_install_tasks().
 */
function satellite_configuration($form, &$form_state) {
  drupal_set_title(st('Satellite Configuration'));
  
  $form = satellite_settings_configuration_form();

  $form['optional_features'] = array(
    '#type' => 'fieldset',
    '#title' => st('Optional Satellite features'),
    '#collapsible' => false,
    '#collapsed' => false,
    '#class' => array('form-wrapper', 'form-optional-features'),
  );

  $form['optional_features']['explanation'] = array(
    '#markup' => st('Optional features of Satellite which can be enabled during install. You can enable and disable them as well as admin under <a href="/admin/structure/features" target="_blank">admin/structure/features</a>'),
  );

  $form['optional_features']['of_events_registration'] = array(
    '#type' => 'checkbox',
    '#title' => st('Satellite Events registration<br /><small>Add webforms to the Event so that events can be used for registrations</small>'),
    '#default_value' => false,
  );

  $form['optional_features']['of_faq'] = array(
    '#type' => 'checkbox',
    '#title' => st('Satellite FAQ<br /><small>Adds a Frequently asked questions field to events</small>'),
    '#default_value' => false,
  );

  $form['optional_features']['of_blog'] = array(
    '#type' => 'checkbox',
    '#title' => st('Satellite Blog<br /><small>A blog for your section.</small>'),
    '#default_value' => false,
  );


  // Default content
  
  $form['default_content'] = array(
    '#type' => 'fieldset',
    '#title' => st('Default Content'),
    '#collapsible' => false,
    '#collapsed' => false,
    '#class' => array('form-wrapper'),
  );
  $form['default_content']['explanation'] = array(
    '#markup' => st('Dummy content provides you with some content to allow you to see a non empty site. <strong>It will be deleted after one week.</strong>'),
  );
  
  $form['default_content']['enable_content'] = array(
    '#type' => 'checkbox',
    '#title' => st('Add dummy content.'),
    '#default_value' => FALSE,
    '#disabled' => TRUE,
    '#description' => st('Default contents are not available in this version.'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    '#class' => array('form-submit'),
  );

  return $form;
}

/**
 * The Satellite configuration form validation.
 */
function satellite_configuration_validate($form, &$form_state) {
  return satellite_settings_configuration_form_validate($form_state);
}

/**
 * The Satellite configuration form submission.
 */
function satellite_configuration_submit($form, &$form_state) {
  $satellite_settings = satellite_settings_parse_admin_form($form_state);
  satellite_settings_configure_cas($satellite_settings);
  satellite_settings_save_settings($satellite_settings,TRUE);
  
  if (satellite_settings_get_name()) {
    variable_set('site_name', satellite_settings_get_name());
  }
  
  if ($form_state['values']['enable_content']) {
    variable_set('satellite_install_default_content', TRUE);
  }
  if ($form_state['values']['of_events_registration']){
    variable_set('satellite_optional_feature_events_registration', true);
  }
  if ($form_state['values']['of_faq']){
    variable_set('satellite_optional_feature_faq', true);
  }
  if ($form_state['values']['of_blog']){
    variable_set('satellite_optional_feature_blog', true);
  }

}

/**
 * The Satellite configuration, see: satellite_install_tasks().
 *
 * Here we run the second batch of installation tasks.
 */
function satellite_final_install() {
  
  $operations = array();
  $operations[] = array('satellite_disable_cas_if_no_curl', array());
  $operations[] = array('satellite_add_event_audience', array());
  $operations[] = array('satellite_add_event_types', array());

  // We need to revert the field instance of the features with field collections
  $operations[] = array('esn_base_features_revert', array(array('satellite_base')));
  $operations[] = array('esn_base_features_revert', array(array('satellite_news')));
  $operations[] = array('esn_base_features_revert', array(array('satellite_events')));
  $operations[] = array('esn_base_features_revert', array(array('satellite_pages')));
      
  $operations[] = array('satellite_assign_default_roles', array());
  $operations[] = array('satellite_add_contact_form', array());

  $optional_features = array();
  if ('DEV' === ($satellite_mode = getenv('SATELLITE_MODE'))) {
    $optional_features[] = 'satellite_dev_settings';
  }
  if (variable_get('satellite_optional_feature_events_registration', false)) {
    $optional_features[] = 'satellite_events_registration';
  }
  if (variable_get('satellite_optional_feature_faq', false)) {
    $optional_features[] = 'satellite_faq';
  }
  if (variable_get('satellite_optional_feature_blog', false)) {
    $optional_features[] = 'satellite_blog';
  }
  if (count($optional_features)) {
    $operations[] = array('module_enable', array($optional_features, true));
  }
  if (in_array('satellite_blog', $optional_features)) {
    $operations[] = array('satellite_blog_add_categories', array());
  }

  if (variable_get('satellite_install_default_content', FALSE)) {
    $operations[] = array('module_enable', array(array('satellite_dummy_content')));

    $default_feeds = array(
      'default_events'   => 'events.xml',
      'default_news'     => 'news.xml',
      'default_pages'    => 'pages.xml',
      'default_partners' => 'partners.xml',
    );
    
    foreach ($default_feeds as $importer_id => $source_file) {
      $operations[] = array('satellite_enable_default_content', array($importer_id, $source_file));
    }
  }

  $operations[] = array('satellite_preconfigure_eu_cookie_compliance', array(FALSE));
  $operations[] = array('satellite_update_notifications', array());
  $operations[] = array('satellite_cleanup_after_install', array());

  $batch = array(
    'title' => st('Satellite Installation'),
    'init_message' => st('Starting setup'),
    'progress_message' => st('Please wait, completed @current of @total tasks'),
    'error_message' => st('Your satellite needs a specialist! Ask the IT committee!'),
    'operations' => $operations,
  );
  return $batch;

}

function satellite_assign_default_roles(&$context) {
  $editor_permissions = array( 
    'create event content',
    'edit own event content',
    'edit any event content',
    'delete own event content',
    'delete any event content',
    'create news content',
    'edit own news content',
    'edit any news content',
    'delete own news content',
    'delete any news content',
    'create partner content',
    'edit own partner content',
    'edit any partner content',
    'delete own partner content',
    'delete any partner content',
    'create page content',
    'edit own page content',
    'edit any page content',
    'delete own page content',
    'delete any page content',
    'override event promote to front page option',
    'override event published option',
    'override news promote to front page option',
    'override news published option',
    'override page promote to front page option',
    'override page published option',
    'override partner promote to front page option',
    'override partner published option',
    'access administration menu',
    'access content overview',
    'access user profiles',
    'administer menu',
    'use text format rich_text',
    'view own unpublished content',
    'view revisions',
    'view the administration theme',
  );

  $editor_role = user_role_load_by_name('editor');
  user_role_grant_permissions($editor_role->rid, $editor_permissions);
  
  $admin_role = user_role_load_by_name('administrator');
  user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
  variable_set('user_admin_role', $admin_role->rid);

  drupal_set_message(st('Configured default roles "Editor" and "Administrator".'));
}

function satellite_disable_cas_if_no_curl(&$context) {
  $pass = FALSE;
  if (function_exists('curl_version')) {
    $curl_version = curl_version();
    if ((version_compare($curl_version['version'], '7.5.0') >= 0) && ($curl_version['features'] & CURL_VERSION_SSL)) {
      $pass = TRUE;
    }
  }
  if (!$pass) {
    module_disable(array('esn_cas', 'cas', 'cas_attributes', 'cas_roles'));
    drupal_set_message(st('CAS disabled. curl is not available or curl version not supported.'), 'warning');
  }
  else {
    variable_set('cas_roles_roles', '[cas:attribute:sc]_[cas:attribute:roles]');
    drupal_set_message(st('CAS has been configured.'));
  }
}

function satellite_add_event_audience(&$context) {
  $vocabulary = taxonomy_vocabulary_machine_name_load('event_audience');
  
  $terms = array(
    'An ESNcard of this section required.' => 'An ESNcard of this section required.',
    'Everyone is invited.' => 'Everyone is invited.',
  );
  
  foreach ($terms as $name => $description) {
    $values = array();
    $values['vocabulary_machine_name'] = $vocabulary->machine_name;
    $values['vid'] = $vocabulary->vid;
    $values['name'] = $name;
    $values['description'] = $description;

    $entity = entity_create('taxonomy_term', $values);
    entity_save('taxonomy_term', $entity);
  }
  drupal_set_message(st('Added event audiences.'));
}

function satellite_add_event_types(&$context) {
  $vocabulary = taxonomy_vocabulary_machine_name_load('event_type');
  
  $terms = array(
    'Trip' => '#7AC143',
    'Party' => '#EC00BF',
    'Social' => '#F47A20',
    'Cultural' => '#2E3192',
    'Informational' => '#00ADEF',
  );
  
  foreach ($terms as $name => $color) {
    $values = array();
    $values['vocabulary_machine_name'] = $vocabulary->machine_name;
    $values['vid'] = $vocabulary->vid;
    $values['name'] = $name;

    $entity = entity_create('taxonomy_term', $values);
    $wrapper = entity_metadata_wrapper('taxonomy_term', $entity);
    $wrapper->field_calendar_color->set($color);
    $wrapper->save(true);
    entity_save('taxonomy_term', $entity);
  }
  drupal_set_message(st('Added event types.'));
}

function satellite_add_contact_form(&$context) {
  db_update('contact')
    ->fields(array(
      'category' => 'General contact',
      'recipients' => variable_get('site_mail', ini_get('sendmail_from')),
      'selected' => 1,
      'reply' => '',
    ))
    ->condition('cid', 1)
    ->execute();
  drupal_set_message(st('Configured contact form.'));
}

function satellite_enable_default_content($importer_id, $source_file, &$context) {
  if (empty($context['sandbox'])) {
    $source = feeds_source($importer_id);
    $fetcher_config = $source->getConfigFor($source->importer->fetcher);
    $fetcher_config['source'] = 'profiles/satellite/modules/content/' . $source_file;
    $source->setConfigFor($source->importer->fetcher, $fetcher_config);
    $source->save();
    $context['sandbox']['source'] = $source;
  }
  else {
    $source = $context['sandbox']['source'];
  }
  // process the import
  if (FEEDS_BATCH_COMPLETE != $source->import()) {
    $context['finished'] = 0;
  }
}

function satellite_preconfigure_eu_cookie_compliance($is_update = FALSE) {
  $t = get_t();
  $privacy_page = FALSE;
  $link_attributes = array('attributes' => array('target' => '_blank'));
  if ($is_update) {
    $query = (new EntityFieldQuery())
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'page')
      ->propertyCondition('title', 'privacy policy', 'CONTAINS')
      ->execute();
    if (!empty($query['node'])) {
      $query = $query['node'];
      $privacy_page = array_pop($query);
      $privacy_page = 'node/' . $privacy_page->nid;
    }
  }
  // Create the privacy policy page because we couldn't find it...
  if (!$privacy_page) {
    $node = array(
      'type' => 'page',
      'uid' => 1,
      'status' => 1,
      'comment' => 0,
      'promote' => 0
    );
    $node = entity_metadata_wrapper('node', entity_create('node', $node));
    $node->title->set('Privacy Policy');
    $body = '<p><strong>Please fill in your <em style="color: red;">Privacy Policy</em> information here!!!</strong></p>';
    $lipsum = satellite_file_get_contents('modules/content/lorem-ipsum.en.htt');
    $node->body->set(array('value' => $body . $lipsum, 'format' => 'rich_text'));
    $node->body->summary->set($body);
    $node->save();
    $privacy_page = 'node/' . $node->getIdentifier();
    drupal_set_message($t("A <em>Privacy Policy</em> page has been created for you. Please !privacy_link it to your needs.",
      array('!privacy_link' => l($t('edit and customize'), $privacy_page, $link_attributes))
    ));
  }
  module_enable(array('eu_cookie_compliance'), TRUE);
  $eucookie_defaults = array(
    'popup_enabled' => TRUE,
    'popup_clicking_confirmation' => TRUE,
    'popup_position' => 0,
    'popup_agree_button_message' => 'OK, I agree',
    'popup_disagree_button_message' => 'No, give me more info',
    'popup_info'=> array(
      'value' => '<h3>We use cookies on this site to enhance your user experience</h3><p>By clicking any link on this page you are giving your consent for us to set cookies.</p>',
      'format' => 'rich_text',
    ),
    'popup_agreed_enabled' => FALSE,
    'popup_hide_agreed' => FALSE,
    'popup_find_more_button_message' => 'More info',
    'popup_hide_button_message' => 'Hide',
    'popup_agreed' => array(
      'value' => '<h3>Thank you for accepting cookies</h3><p>You can now hide this message or find out more about cookies.</p>',
      'format' => 'rich_text',
    ),
    'popup_link' => $privacy_page,
    'popup_link_new_window' => TRUE,
    'popup_height' => '',
    'popup_width' => '100%',
    'popup_delay' => 1,
    'popup_bg_hex' => '2e3192', // ESN Dark Blue
    'popup_text_hex' => 'ffffff',
    'domains_option' => TRUE,
    'domains_list' => '',
    'exclude_paths' => 'admin/*',
  );
  $eucookies = variable_get('eu_cookie_compliance_en', array());
  if ($is_update) {
    // preserve existing settings made by any site builder, but in text messages
    // change H2s to H3s...
    if (isset($eucookies['popup_info']['value'])) {
      $eucookies['popup_info']['value'] = str_replace(array('<h2','</h2'), array('<h3', '</h3'), $eucookies['popup_info']['value']);
    }
    if (isset($eucookies['popup_agreed']['value'])) {
      $eucookies['popup_agreed']['value'] = str_replace(array('<h2','</h2'), array('<h3', '</h3'), $eucookies['popup_agreed']['value']);
    }
    $eucookies = array_merge($eucookie_defaults, $eucookies);
  } else {
    $eucookies = $eucookie_defaults;
  }
  variable_set('eu_cookie_compliance_en', $eucookies);
  drupal_set_message($t("EU Cookie Compliance has been pre-configured. You can !customization to your country's needs.",
    array('!customization' => l('modify the configuration', 'admin/config/system/eu-cookie-compliance', $link_attributes))
  ));
}

function satellite_update_notifications() {
  if (($satellite_messages = getenv('SATELLITE_MESSAGES'))) {
    $satellite_messages = url($satellite_messages, ['absolute' => TRUE]);
    variable_set('satellite_notification_messages_url', $satellite_messages);
    NotificationManager::update();
  }
}

function satellite_cleanup_after_install(&$context) {
  _satellite_update_usermail_templates('register_no_approval_required_body', true);
  _satellite_update_usermail_templates('register_admin_created_body', true);
  _satellite_update_usermail_templates('status_activated_body', true);
  variable_del('satellite_optional_feature_blog');
  variable_del('satellite_install_default_content');
  variable_del('satellite_notification_initializing');
  drupal_set_message(st('Cleaned up installation information.'));
}
