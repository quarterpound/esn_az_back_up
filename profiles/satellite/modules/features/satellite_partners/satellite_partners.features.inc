<?php
/**
 * @file
 * satellite_partners.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_partners_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function satellite_partners_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function satellite_partners_image_default_styles() {
  $styles = array();

  // Exported image style: partner.
  $styles['partner'] = array(
    'label' => 'partner',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'partner',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: partner_block.
  $styles['partner_block'] = array(
    'label' => 'partner block',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'partner',
        ),
        'weight' => 0,
      ),
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 60,
          'height' => 60,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      7 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 60,
            'height' => 60,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: partner_list.
  $styles['partner_list'] = array(
    'label' => 'partner list',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'partner',
        ),
        'weight' => 0,
      ),
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 120,
          'height' => 80,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      4 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 120,
            'height' => 80,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: partner_page.
  $styles['partner_page'] = array(
    'label' => 'partner page',
    'effects' => array(
      8 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'partner',
        ),
        'weight' => 0,
      ),
      9 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function satellite_partners_node_info() {
  $items = array(
    'partner' => array(
      'name' => t('Partner'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a cooperation partner <em>local</em> to your section, country or specific to what you create this satellite site for.<br />
You can control the sort order of partners by setting the <strong>weight</strong> property for them.
'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function satellite_partners_weight_features_default_settings() {
  $settings = array();

  $settings['partner'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
