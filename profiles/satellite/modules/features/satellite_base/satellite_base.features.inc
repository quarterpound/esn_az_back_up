<?php
/**
 * @file
 * satellite_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function satellite_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function satellite_base_image_default_styles() {
  $styles = array();

  // Exported image style: block.
  $styles['block'] = array(
    'label' => 'block',
    'effects' => array(
      8 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 60,
          'height' => 60,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'block',
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: gallery-thumbnail.
  $styles['gallery-thumbnail'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'gallery-thumbnail',
  );

  // Exported image style: list.
  $styles['list'] = array(
    'label' => 'list',
    'effects' => array(
      9 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 120,
          'height' => 80,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'list',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: mobile_large__1280x640_.
  $styles['mobile_large__1280x640_'] = array(
    'label' => 'Mobile Large (1280x640)',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1280,
          'height' => 640,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'mobile_large__1280x640_',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: mobile_small__640x320_.
  $styles['mobile_small__640x320_'] = array(
    'label' => 'Mobile Small (640x320)',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 640,
          'height' => 320,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'mobile_small__640x320_',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: mobile_thumb__160x160_.
  $styles['mobile_thumb__160x160_'] = array(
    'label' => 'Mobile Thumb (160x160)',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 160,
          'height' => 160,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'mobile_thumb__160x160_',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: page.
  $styles['page'] = array(
    'label' => 'page',
    'effects' => array(
      11 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 250,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'page',
        ),
        'weight' => 0,
      ),
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: spotlight.
  $styles['spotlight'] = array(
    'label' => 'spotlight',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 621,
          'height' => 311,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'spotlight',
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: zoom.
  $styles['zoom'] = array(
    'effects' => array(
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 900,
          'height' => 600,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'zoom',
  );

  return $styles;
}
