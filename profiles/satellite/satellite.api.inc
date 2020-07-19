<?php
/**
 * Created by PhpStorm.
 * User: Marco
 * Date: 08.12.2014
 * Time: 03:05
 */


function satellite_file_get_contents($filename) {
  $path = DRUPAL_ROOT . '/profiles/satellite/' . $filename;
  if (file_exists($path)) {
    $content = file_get_contents($path);
    return $content;
  }
  return NULL;
}

function satellite_insert_blocks($blocks) {
// execute the database query
$query = db_insert('block')->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'visibility', 'pages', 'cache'));
foreach ($blocks as $block) {
  if (isset($block['icon'])) {
    // set the default icon
    esn_blocktheme_set_icon($block['module'], $block['delta'], $block['icon']);
    unset($block['icon']);
  }
  $query->values($block);
}
$query->execute();
}