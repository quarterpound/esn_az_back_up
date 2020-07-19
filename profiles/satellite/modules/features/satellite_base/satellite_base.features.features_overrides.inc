<?php
/**
 * @file
 * satellite_base.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function satellite_base_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: wysiwyg
  $overrides["wysiwyg.rich_text.settings|advanced__active_tab"] = 'edit-basic';

 return $overrides;
}
