<?php
/**
 * @file
 * satellite_partners_external.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function satellite_partners_external_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-partner_external-body'.
  $field_instances['node-partner_external-body'] = array(
    'bundle' => 'partner_external',
    'default_value' => array(
      0 => array(
        'summary' => '',
        'value' => '',
        'format' => 'filtered_html',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'block' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'list' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
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
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
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

  // Exported field_instance: 'node-partner_external-field_file'.
  $field_instances['node-partner_external-field_file'] = array(
    'bundle' => 'partner_external',
    'deleted' => 0,
    'description' => 'You can attach files like a printed programme. Download links to the files using the file names as link text will be added at the bottom of the partner page.',
    'display' => array(
      'block' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 3,
      ),
      'list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_file',
    'label' => 'Attachment Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'partners',
      'file_extensions' => 'txt',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-partner_external-field_image'.
  $field_instances['node-partner_external-field_image'] = array(
    'bundle' => 'partner_external',
    'deleted' => 0,
    'description' => 'Upload the logo of your partner. The image should have a ratio of 3 x 2 (width x height) and a width of at least 250px. It will be displayed
 <ul>
   <li><strong>block:</strong> on the <a href="/" target="_blank">start page</a> with <strong>60 x 60 px</strong></li>
   <li><strong>list:</strong> on the <a href="news" target="_blank">news page</a> with <strong>120 x 80 px</strong></li>
   <li><strong>page:</strong> on the news item full view with <strong>250 px and dynamic height</strong></li>
  </ul>
  You can modify the part of the image being displayed for all three versions by clicking on the image previews.',
    'display' => array(
      'block' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => 'thumbnail',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'none',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => 'large',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'medium',
          'colorbox_node_style_first' => '',
        ),
        'type' => 'colorbox',
        'weight' => 0,
      ),
      'list' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Logo',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'partners/images',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-partner_external-field_link'.
  $field_instances['node-partner_external-field_link'] = array(
    'bundle' => 'partner_external',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Links to website, facebook page etc. of the partner. <strong>The url must be valid, which includes that it starts with <code>http://</code>, <code>https://</code> or something like this.</strong>. You can provide an optional title for the link, if not the url will be used as title. Links open in a new window.',
    'display' => array(
      'block' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
      'list' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_link',
    'label' => 'Website',
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
      'enable_tokens' => 1,
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
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Attachment Files');
  t('Description');
  t('Links to website, facebook page etc. of the partner. <strong>The url must be valid, which includes that it starts with <code>http://</code>, <code>https://</code> or something like this.</strong>. You can provide an optional title for the link, if not the url will be used as title. Links open in a new window.');
  t('Logo');
  t('Upload the logo of your partner. The image should have a ratio of 3 x 2 (width x height) and a width of at least 250px. It will be displayed
 <ul>
   <li><strong>block:</strong> on the <a href="/" target="_blank">start page</a> with <strong>60 x 60 px</strong></li>
   <li><strong>list:</strong> on the <a href="news" target="_blank">news page</a> with <strong>120 x 80 px</strong></li>
   <li><strong>page:</strong> on the news item full view with <strong>250 px and dynamic height</strong></li>
  </ul>
  You can modify the part of the image being displayed for all three versions by clicking on the image previews.');
  t('Website');
  t('You can attach files like a printed programme. Download links to the files using the file names as link text will be added at the bottom of the partner page.');

  return $field_instances;
}
