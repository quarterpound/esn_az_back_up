api = 2
core = 7.x

;Modules
projects[cas][subdir] = contrib
projects[cas][version] = 1.7
;projects[cas][download][type] = git
;projects[cas][download][url] = "http://git.drupal.org/project/cas.git"
;projects[cas][download][branch] = 7.x-1.x
;projects[cas][download][full_version] = 7.x-1.x-dev
projects[cas][patch][] = "http://satellite.esn.org/sites/default/files/patches/cas-esn-satellite-crawlers.patch"


projects[cas_attributes][subdir] = contrib
projects[cas_attributes][version] = 1.0-rc3

projects[cas_roles][subdir] = contrib
projects[cas_roles][version] = 1.2

; Libraries
libraries[phpcas][download][type] = "get"
libraries[phpcas][download][url] = "https://github.com/Jasig/phpCAS/archive/master.zip"
libraries[phpcas][destination] = "libraries"
libraries[phpcas][directory_name] = "CAS"
