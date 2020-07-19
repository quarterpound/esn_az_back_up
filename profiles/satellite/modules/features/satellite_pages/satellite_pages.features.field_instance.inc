<?php
/**
 * @file
 * satellite_pages.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function satellite_pages_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-page-body'.
  $field_instances['node-page-body'] = array(
    'bundle' => 'page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'spotlight' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-page-field_file'.
  $field_instances['node-page-field_file'] = array(
    'bundle' => 'page',
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'You can attach files to the page like a printed programme. Download links to the files using the file names as link text will be added at the bottom of the page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 4,
      ),
      'spotlight' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_file',
    'label' => 'Attachment Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'pages',
      'file_extensions' => 'txt zip rar pdf doc docx ppt pptx xls xlsx',
      'max_filesize' => '1 MB',
      'resup' => 1,
      'resup_autostart' => 1,
      'resup_max_filesize' => '20 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-page-field_image'.
  $field_instances['node-page-field_image'] = array(
    'bundle' => 'page',
    'deleted' => 0,
    'description' => ' Upload an image which will be displayed for the news item. The image should have a ratio of 3 x 2 (width x height) and a width of at least 250px. It will be displayed
 <ul>
   <li><strong>block:</strong> on the <a href="/" target="_blank">start page</a> with <strong>60 x 60 px</strong></li>
   <li><strong>list:</strong> on the page list with <strong>120 x 80 px</strong></li>
   <li><strong>page:</strong> on the page itself with <strong>250 px and dynamic height</strong></li>
  </ul>
 You can modify the part of the image being displayed for all three versions by clicking on the image previews.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'none',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => 'zoom',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'page',
          'colorbox_node_style_first' => '',
        ),
        'type' => 'colorbox',
        'weight' => 0,
      ),
      'spotlight' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'pages/images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'resup' => 1,
      'resup_autostart' => 1,
      'resup_max_filesize' => '2 MB',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 1,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(
          'block' => 'block',
          'list' => 'list',
          'page' => 'page',
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-page-field_image_gallery'.
  $field_instances['node-page-field_image_gallery'] = array(
    'bundle' => 'page',
    'default_value' => array(),
    'deleted' => 0,
    'description' => 'You can upload as many images as you want. Previews will be displayed on the page with <em>100 x 100 px </em>. If the user clicks on them an image viewer opens the selected image as uploaded with navigation options.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'none',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => 'zoom',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'gallery-thumbnail',
          'colorbox_node_style_first' => '',
        ),
        'type' => 'colorbox',
        'weight' => 2,
      ),
      'spotlight' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image_gallery',
    'label' => 'Gallery',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'pages/galleries',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'resup' => 1,
      'resup_autostart' => 1,
      'resup_max_filesize' => '2 MB',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 0,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 0,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-page-field_image_spotlight'.
  $field_instances['node-page-field_image_spotlight'] = array(
    'bundle' => 'page',
    'deleted' => 0,
    'description' => 'If you want to display the page in the spotlight of the start page please upload an image. It will be displayed with <strong>621 x 311 px</strong>. Your image should have at least this size and a ratio of 2 x 1 to look nice in the spotlight.<br />
You can modify the part of the image being displayed for all three versions by clicking on the image previews.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'spotlight' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => 'spotlight',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image_spotlight',
    'label' => 'Spotlight Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'pages/spotlight',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'resup' => 1,
      'resup_autostart' => 1,
      'resup_max_filesize' => '2 MB',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 1,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(
          'spotlight' => 'spotlight',
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-page-field_link'.
  $field_instances['node-page-field_link'] = array(
    'bundle' => 'page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Links to more information, like homepages of event partners, facebook etc. <strong>The url must be valid, which includes that it starts with <code>http://</code>, <code>https://</code> or something like this.</strong>. You can provide an optional title for the link, if not the url will be used as title. Links open in a new window.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
      'spotlight' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_link',
    'label' => 'More information',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' Upload an image which will be displayed for the news item. The image should have a ratio of 3 x 2 (width x height) and a width of at least 250px. It will be displayed
 <ul>
   <li><strong>block:</strong> on the <a href="/" target="_blank">start page</a> with <strong>60 x 60 px</strong></li>
   <li><strong>list:</strong> on the page list with <strong>120 x 80 px</strong></li>
   <li><strong>page:</strong> on the page itself with <strong>250 px and dynamic height</strong></li>
  </ul>
 You can modify the part of the image being displayed for all three versions by clicking on the image previews.');
  t('Attachment Files');
  t('Body');
  t('Gallery');
  t('If you want to display the page in the spotlight of the start page please upload an image. It will be displayed with <strong>621 x 311 px</strong>. Your image should have at least this size and a ratio of 2 x 1 to look nice in the spotlight.<br />
You can modify the part of the image being displayed for all three versions by clicking on the image previews.');
  t('Image');
  t('Links to more information, like homepages of event partners, facebook etc. <strong>The url must be valid, which includes that it starts with <code>http://</code>, <code>https://</code> or something like this.</strong>. You can provide an optional title for the link, if not the url will be used as title. Links open in a new window.');
  t('More information');
  t('Spotlight Image');
  t('You can attach files to the page like a printed programme. Download links to the files using the file names as link text will be added at the bottom of the page.');
  t('You can upload as many images as you want. Previews will be displayed on the page with <em>100 x 100 px </em>. If the user clicks on them an image viewer opens the selected image as uploaded with navigation options.');

  return $field_instances;
}
