<?php
/**
 * @file
 * Load the Sections in the database.
 */

/**
 * Populate the database with ESN sections from Galaxy.
 */
function _esn_galaxy_api_save_sections($local = FALSE) {
  /** @var \ESNSection[] $sources */
  $sources = ESNGalaxyApiParser::sections($local)
    ->fetchDataSource()
    ->parse();
  $last_updated = date_now()->getTimestamp();
  $count_created = 0;
  $count_updated = 0;
  $count_deleted = 0;
  $sections = esn_section_load_multiple();
  $countries = esn_country_load_all();
  foreach ($sources as $source) {
    $code = $source->getCode();
    if (array_key_exists($code, $sections)) {
      $section = $sections[$code];
      unset($sections[$code]);
      $count_updated++;
    }
    else {
      $section = esn_section_create(array('code' => $code));
      $count_created++;
    }

    $source->update($section);
    // TODO: Add country reference.
    if (array_key_exists($source->getCountryCode(), $countries)) {
      $country = $countries[$source->getCountryCode()];
      $section->country = $country->getIdentifier();
    }

    $section->last_updated->set($last_updated);
    $section->save();
  }

  // Now the remaining countries in database are not in the update from Galaxy, so remove them.
  foreach ($sections as $section) {
    esn_section_delete($section);
    $count_deleted++;
  }
  watchdog('esn_galaxy_api', 'Updated ESN Sections: %created created, %updated updated, %deleted deleted',
    array(
      '%created' => $count_created,
      '%updated' => $count_updated,
      '%deleted' => $count_deleted
    ));
}

/**
 * Populate the database with ESN countries from Galaxy.
 */
function _esn_galaxy_api_save_countries($local = FALSE) {
  $sources = ESNGalaxyApiParser::countries($local)
    ->fetchDataSource()
    ->parse();
  $last_updated = date_now()->getTimestamp();
  $count_created = 0;
  $count_updated = 0;
  $count_deleted = 0;
  $countries = esn_country_load_multiple();
  foreach ($sources as $source) {
    $code = $source->getCode();
    if (array_key_exists($code, $countries)) {
      $country = $countries[$code];
      unset($countries[$code]);
      $count_updated++;
    }
    else {
      $country = esn_country_create(array('code' => $code));
      $count_created++;
    }
    $source->update($country);
    $country->last_updated->set($last_updated);
    $country->save();
  }

  // Now the remaining countries in database are not in the update from Galaxy, so remove them.
  foreach ($countries as $country) {
    esn_country_delete($country);
    $count_deleted++;
  }
  watchdog('esn_galaxy_api', 'Updated ESN Countries: %created created, %updated updated, %deleted deleted',
    array(
      '%created' => $count_created,
      '%updated' => $count_updated,
      '%deleted' => $count_deleted
    ));
}


class ESNGalaxyApiParser {

  private static $COUNTRY_URI = 'https://accounts.esn.org/countries/xml';

  private static $SECTION_URI = 'https://accounts.esn.org/sections/xml';

  private static $COUNTRY_OFFLINE_URI = 'countries.xml';

  private static $SECTION_OFFLINE_URI = 'sections.xml';

  /** @var bool Use local data file */
  private $local;

  /** @var string Data file uri */
  private $uri;

  /** @var string Data file uri for offline fallback */
  private $fallbackUri;

  /** @var bool|\SimpleXMLElement */
  private $xml = FALSE;

  protected function __construct($local, $uri, $fallbackUri = NULL) {
    $this->local = $local;
    $this->uri = $uri;
    $this->fallbackUri = implode('/',
      [
        DRUPAL_ROOT,
        drupal_get_path('module', 'esn_galaxy_api'),
        $fallbackUri
      ]
    );

    $this->xml = NULL;
  }

  public static function countries($local = FALSE) {
    return new ESNCountryParser($local, self::$COUNTRY_URI, self::$COUNTRY_OFFLINE_URI);
  }

  public static function sections($local = FALSE) {
    return new ESNSectionParser($local, self::$SECTION_URI, self::$SECTION_OFFLINE_URI);
  }

  public function fetchDataSource() {
    try {
      $tmpFile = 'temporary://esn-data.xml';
      $xml = FALSE;
      if (!$this->local) {
        if (system_retrieve_file($this->uri, $tmpFile, FALSE, FILE_EXISTS_REPLACE)) {
          $xml = @simplexml_load_file($tmpFile);
        }
      }
      if (!$xml) {
        $xml = @simplexml_load_file($this->fallbackUri);
      }

      if (!$xml) {
        throw new \http\Exception\InvalidArgumentException('XML data could not be loaded: '
          . (($this instanceof ESNCountryParser)
            ? self::COUNTRY_OFFLINE_URI
            : self::SECTION_OFFLINE_URI)
        );
      }

      $this->xml = $xml;

    } catch (Exception $ex) {
      watchdog('esn_galaxy_api',
        "The list of !data could not be fetched from Galaxy! Something went wrong.\n\\n@message",
        [
          '!data' => ($this instanceof ESNCountryParser) ? 'ESN countries' : 'ESN sections',
          '@message' => $ex,
        ],
        WATCHDOG_ERROR);

    }

    return $this;
  }

  /**
   * @return \ESNEntity[]
   */
  public function parse() {
    $result = [];
    if ($this->xml instanceof SimpleXMLElement) {
      foreach ($this->xml->children() as $node) {
        $item = $this->parseItem($node);
        if ($item instanceof ESNEntity) {
          $result[$item->getCode()] = $item;
        }
      }
    }

    return $result;
  }

  protected function parseItem(SimpleXMLElement $element) {
    return NULL;
  }

  protected function sanitizeUrl($url) {
    if (!empty($url)) {
      // Sanitize urls  without protocol.
      if (strpos($url, 'http://') === FALSE && strpos($url, 'https://') === FALSE) {
        $url = 'http://' . $url;
      }
      if (valid_url($url, TRUE)) {
        return $url;
      }
    }
    return '';
  }

  protected function processWebSiteLogo(ESNEntity $entity) {
    $enabled = &drupal_static(__FUNCTION__ . '::site-logo', FALSE);
    if ($enabled === NULL) {
      $enabled = variable_get('esn_galaxy_api_check_site_logo', FALSE);
    }
    if (!$enabled || !$entity || empty($entity->getWebsite())) {
      return NULL;
    }
    return function ($website) {
      if (!Strings::endsWith($website, '/')) {
        $website .= '/';
      }
      if (!Strings::startsWith($website, ['http://', 'https://'])) {
        $website = 'http://' . $website;
      }
      $website .= 'site-logo';

      return HttpUtility::getUrlStatus($website) ? $website : '';
    };
  }
}

class ESNCountryParser extends ESNGalaxyApiParser {
  protected function parseItem(SimpleXMLElement $element) {
    $code = (string)$element->c;
    if (preg_match('/^[A-Z]{2}$/', $code)) {
      $country = new ESNCountry($code);
      $country->country_name =  (string)$element->cn;
      $country->name = 'ESN ' . (string)$element->cn;
      $country->setWebsite($this->sanitizeUrl((string)$element->website));
      $country->setWebsiteLogo($this->processWebSiteLogo($country));
      return $country;
    } else {
      watchdog('esn_galaxy_api',
        "The country code '@code' is invalid. Skipping country. ",
        ['@code' => $code],
        WATCHDOG_WARNING);

      return NULL;
    }
  }
}

class ESNSectionParser extends ESNGalaxyApiParser {
  protected function parseItem(SimpleXMLElement $element) {
    $code = (string)$element->sc;
    if (preg_match('/^[A-Z]{2}-[A-Z]{4}-[A-Z]{2}[A-Z0-9]{1}$/', $code)) {
      $section = new ESNSection($code);
      $section->name = (string)$element->sectionname;
      $section->country_code = (string)$element->c;
      $section->city = (string)$element->l;
      $section->street = (string)$element->street;
      $section->postaladdress = (string)$element->postaladdress;
      $lon = (string)$element->longitude;
      $lat = (string)$element->latitude;
      if (strlen($lon) > 0 && $lon != 0.0 && strlen($lat) > 0 && $lat != 0.0) {
        $section->longitude = floatval($lon);
        $section->latitude = floatval($lat);
      }
      $section->setWebsite($this->sanitizeUrl((string)$element->website));
      $section->setWebsiteLogo($this->processWebSiteLogo($section));

      return $section;
    } else {
      watchdog('esn_galaxy_api',
        "The section code '@code' is invalid. Skipping section. ",
        ['@code' => $code],
        WATCHDOG_WARNING);

      return NULL;
    }
  }
}
