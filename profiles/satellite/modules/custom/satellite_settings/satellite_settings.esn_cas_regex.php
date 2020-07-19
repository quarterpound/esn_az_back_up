<?php

define('ESN_LEVEL_LOCAL', 'Local');
define('ESN_LEVEL_NATIONAL', 'National');
define('ESN_LEVEL_INTERNATIONAL', 'International');

define('ESN_ROLE_PRESIDENT', 'president');
define('ESN_ROLE_SECRETARY', 'secretary');
define('ESN_ROLE_TREASURER', 'treasurer');
define('ESN_ROLE_PR', 'pr');
define('ESN_ROLE_WEBMASTER', 'webmaster');
define('ESN_ROLE_VICEPRESIDENT', 'vicePresident');
define('ESN_ROLE_REGULARBOARDMEMBER', 'regularBoardMember');
define('ESN_ROLE_NR', 'nationalRepresentative');
define('ESN_ROLE_VICENR', 'nationalViceRepresentative');
define('ESN_ROLE_WPA', 'webProjectAdministrator');
define('ESN_ROLE_ITCHAIR', 'ITChair');
define('ESN_ROLE_ITViceCHAIR', 'ITVChair');
define('ESN_ROLE_ITSUPPORT', 'ITSupport');
define('ESN_ROLE_ACTIVEMEMBER', 'activeMember');


final class ESN_CAS_Regex {
  private function implodeWrapParens(array &$alts) {
    $implAlts = implode('|', $alts);

    if (count($alts) > 1) {
      return '(' . $implAlts . ')';
    } else {
      return $implAlts;
    }
  }

  private function mkRegex(array $alts) {
    if (count($alts) > 0) {
      return '/^' . $this->implodeWrapParens($alts) . '$/';
    } else {
      return '';
    }
  }

  private function trimSectionCode($sectionCode) {
    $explSectionCode = explode('-', $sectionCode, 2);
    return $explSectionCode[1];
  }

  public function mkAdministratorRegex($satellite_settings) {
    $lnWebmasterAlts = array();

    if ($satellite_settings['permissions']['localWebmasterAdmin'] && !empty($satellite_settings['sectionCode'])) {
      $lnWebmasterAlts[] = $this->mkSectionLevel(ESN_LEVEL_LOCAL,
        $this->trimSectionCode($satellite_settings['sectionCode']));
    }

    if ($satellite_settings['permissions']['nationalWebmasterAdmin']) {
      $lnWebmasterAlts[] = $this->mkSectionLevel(ESN_LEVEL_NATIONAL);
    }

    $webmasterAlts = array();

    if (!empty($lnWebmasterAlts)) {
      $webmasterAlts[] = $this->mkFullPatt($satellite_settings['countryCode'],
        array($this->mkClause($lnWebmasterAlts, array(ESN_ROLE_WEBMASTER))));
    }

    if ($satellite_settings['permissions']['internationalAdmin']) {
      $webmasterAlts[] = $this->mkFullPatt('[A-Z]{2}',
        array($this->mkClause(array($this->mkSectionLevel(ESN_LEVEL_INTERNATIONAL)),
         array(ESN_ROLE_WPA, ESN_ROLE_ITCHAIR, ESN_ROLE_ITViceCHAIR, ESN_ROLE_ITSUPPORT))));
    }

    return $this->mkRegex($webmasterAlts);
  }

  public function mkEditorRegex($satellite_settings) {
    $lnBoardMemberAlts = array();

    if ($satellite_settings['permissions']['localBoardEditor'] && !empty($satellite_settings['sectionCode'])) {
      $lnBoardMemberAlts[] = $this->mkClause(array($this->mkSectionLevel(
        ESN_LEVEL_LOCAL, $this->trimSectionCode($satellite_settings['sectionCode']))),
        array(ESN_ROLE_WEBMASTER, ESN_ROLE_PRESIDENT, ESN_ROLE_PR,
        ESN_ROLE_REGULARBOARDMEMBER, ESN_ROLE_SECRETARY,
        ESN_ROLE_VICEPRESIDENT));
    }

    if ($satellite_settings['permissions']['nationalBoardEditor']) {
      $lnBoardMemberAlts[] = $this->mkClause(array($this->mkSectionLevel(
        ESN_LEVEL_NATIONAL)), array(ESN_ROLE_NR, ESN_ROLE_VICENR,
        ESN_ROLE_PRESIDENT, ESN_ROLE_PR, ESN_ROLE_REGULARBOARDMEMBER,
        ESN_ROLE_SECRETARY, ESN_ROLE_TREASURER, ESN_ROLE_VICEPRESIDENT,
        ESN_ROLE_WEBMASTER));
    }

    $boardMemberAlts = array();

    if (!empty($lnBoardMemberAlts)) {
      $boardMemberAlts[] = $this->mkFullPatt($satellite_settings['countryCode'],
        $lnBoardMemberAlts);
    }

    return $this->mkRegex($boardMemberAlts);
  }

  public function mkMemberRegex($satellite_settings) {
    $alts = array();

    if (!empty($satellite_settings['sectionCode'])) {
      $alts[] = $this->mkFullPatt($satellite_settings['countryCode'], array(
        $clause = $this->mkClause(array($this->mkSectionLevel(ESN_LEVEL_LOCAL,
        $this->trimSectionCode($satellite_settings['sectionCode']))),
        array(ESN_ROLE_ACTIVEMEMBER))
      ));
    }

    return $this->mkRegex($alts);
  }

  public function mkFullPatt($country, $alts) {
    return $country . '-' . $this->implodeWrapParens($alts);
  }

  private function mkSectionLevel($level, $section = null) {
    if (empty($section)) {
      $section = '[A-Z]{4}-[A-Z]{3}';
    }

    return $section . '_' . $level;
  }

  //public function mkClause($level, array $roles, $section = null) {
  public function mkClause(array $sectionLevels, array $roles) {
    return $this->implodeWrapParens($sectionLevels) . '\.' . $this->implodeWrapParens($roles);
  }
}




