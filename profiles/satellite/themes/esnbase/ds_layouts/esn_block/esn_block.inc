<?php

/**
 * @file
 * Display Suite core_promotabs_side_3sub configuration.
 */

function ds_esn_block() {
  return array(
    'label' => t('Block'),
    'regions' => array(
      'image' => t('Image'),
      'main_content' => t('Content'),
    ),
    // Uncomment if you want to include a CSS file for this layout (core_promotabs_side_3sub.css)
    'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (core_promotabs_side_3sub.png)
    'image' => TRUE,
  );
}
