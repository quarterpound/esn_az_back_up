Satellite 4.x

## Requirements

* PHP
 * Minimum: 5.3.2
 * **Recommended: 5.5.x**
 * [-Unsupported: 5.7.x-]
 *(see https://www.drupal.org/docs/7/system-requirements/php)
* Database server
 * MySQL
  * Minimum: 5.1.30
  * **Recommended: 5.5.x**
 * PostgreSQL
  * Minimum: 8.3
  * **Recommended: latest**
 * SQLite
  * Minimum: 3.3.7
  * **Recommended: latest**
 * see https://www.drupal.org/docs/7/system-requirements/database-server
* Web server
 * Apache 2.x
 * Nginx *(see Drupal documentation for further information!)*
 * see https://www.drupal.org/docs/7/system-requirements/web-server

## Installation

Unpack the Satellite download and copy all files to the web root folder on your webserver or webhosting via FTP or SSH (depends on what your hosting provider offers you). Go into the `sites/default/ ` folder, create a folder named `files`  and copy the `default.settings.php`  to `settings.php`. Then assign the *files* folder and *settings.php* file write permission to the webserver group.

```
cd sites/default
cp default.settings.php settings.php
mkdir files
# Maybe you have to execute the next command with sudo, depending on your hosting setup.
chmod -R g+w files/ settings.php
```

In your browser open `http://[your-domain]/install.php` and follow the instructions in the Drupal setup wizard.

# Update an existing installation

To update an existing installation first create a backup of your database and all code files!

* Enable the Read-only mode to prevent people from changing contents during update.
(In a multi-site installation do this for all sites.)
* Create a database backup
* Create a code and files backup
* Delete all files from your Drupal root **except the `sites/` folder (or `sites/[site-name]` folders if you have a multisite).**
* Unpack all files from the Satellite download and move them into your Drupal root.
** If you have custom modifications of files located in the Drupal root (`.htaccess`, `robots.txt`, `web.config`), re-apply them to the new files. *Do not keep your files because the files from the Satellite download might contain important changes or bugfixes!*
* Run the database updates.
(In a multi-site installation do this for all sites.)

```
# Single site:
drush updb

# Multisite:
cd sites/default
drush updb
cd ../[site-name]
drush updb
# Repeat the last two steps for every site
```

* Disable the Read-only mode.
(In a multi-site installation do this for all sites.)

## You need help?

If you have problems with installing, updating or maintaining Satellite? Don't hesite and contact us via email at it-support@esn.org or in Slack at `#it-support`.

If you found an issue or a bug in Satellite you can report it via the same channels or directly create an issue in GitLab at https://git.esn.org/satellite/satellite_profile/issues/new.
**Of course you're welcome to fix it on your on (after creating the issue) and send us a merge request.**
*Please ask the IT chairs at it-chair@esn.org for guidelines how to contribute to our projects and using Git in ESN.*