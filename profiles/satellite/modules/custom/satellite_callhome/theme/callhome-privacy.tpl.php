<?php
/**
 * Created by PhpStorm.
 * User: Marco
 * Date: 04.08.2015
 * Time: 01:10
 */
$galaxy_url = url('admin/settings/satellite/galaxy');
$cas_roles_url = url('admin/config/people/cas/roles');
$clean_urls_url = url('admin/config/search/clean-urls');
?>
<article class="description callhome-info" style="font-size: 0.85em; line-height: 1.2em; color: #666;text-align: justify;">
  <h2>Satellite callhome privacy information</h2>
  <p>
    Since <em>Satellite 4.5</em> and the introduction of the <em>ESN Mobile API</em> it is required that every Satellite which supports the <em>Mobile API</em> and the <em>ESNapp</em>
    reports some technical information about itself back to the ESN IT Committee in order to provide the <em>ESNapp</em> with information which countries/sections have app support, which
    version and features of the <em>Mobile API</em> they support and where to find the API (url). As this is mostly what the <em>Satellite Callhome</em> already has sent in earlier versions
    on an opt-in basis, the <em>Mobile API</em> information has been integrated into <em>Satellite Callhome</em> and all required information made obligatory. To give the satellite administrator
    some control about what is sent back to the <em>ESN Callhome server</em> we decided to not make all information obligatory but only the required one and give you an opt-in for more
    detailed and extended information. Below we will give you a detailed overview what information is always send and what only if you opted in.
  </p>
  <p>
    <strong>Note:</strong> All information is send to the <em>ESN Callhome server</em> encrypted using public/private keys with RSA encryption. This way no sensitive information is made public.
    Only the ESN callhome server is able to decrypt the data.
  </p>
  <h4>Information always send</h4>
  <ul>
    <li>Scope and country or section of your satellite. See <a href='<?php print $galaxy_url; ?>'>Galaxy Integration</a> for details</li>
    <li>The url, hostname, server IP address, unique installation ID, administrator email address and version of your satellite (<?php print satellite_callhome_version(); ?>)</li>
    <li>If default content has been installed</li>
    <li>If <a href='<?php print $clean_urls_url; ?>'>Clean urls</a> are enabled</li>
    <li>Whether this satellite is configured as <a href='<?php print $galaxy_url; ?>'><em>Mobile API</em> data source</a> for the selected country or section (<?php print satellite_settings_get_code(); ?>) and if so, which version of teh API is installed</li>
  </ul>
  <p>&nbsp;</p>
  <h4>Information send on opt-in only</h4>
  <ul>
    <li>Operating System name, distribution and version (the same information as the Linux command <code>uname -a</code>)</li>
    <li>The PHP version of the webserver (<?php print phpversion(); ?>)</li>
    <li>All loaded PHP extensions including their version (if available)</li>
    <li>All enabled Drupal modules (Core, contributed modules, ESN modules) and their versions</li>
    <li>The CAS roles configuration for mapping ESN Galaxy roles to local roles (See <a href='<?php print $cas_roles_url; ?>'>CAS roles mappings</a> for details</li>
  </ul>
</article>