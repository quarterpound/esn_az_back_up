<?php
/**
 * @file
 * satellite_team.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_team_ctools_plugin_api($module = NULL, $api = NULL) {
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
function satellite_team_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function satellite_team_image_default_styles() {
  $styles = array();

  // Exported image style: profile.
  $styles['profile'] = array(
    'label' => 'profile',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 132,
          'height' => 136,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'profile',
        ),
        'weight' => 0,
      ),
      2 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 132,
            'height' => 136,
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
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_profile2_type().
 */
function satellite_team_default_profile2_type() {
  $items = array();
  $items['team_member'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "team_member",
    "label" : "Team Member",
    "weight" : "0",
    "data" : { "registration" : 1 }
  }');
  return $items;
}
