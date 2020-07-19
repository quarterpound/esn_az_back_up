<?php


/**
 * return the scope of the Satellite (local, national, international)
 */
satellite_settings_get_scope();

/**
 * return the section code or country code (for example: CH-LAUS-XEP or CH)
 */
satellite_settings_get_code();

/**
 * return the section name or country mane (country names include ESN prefix)
 */
satellite_settings_get_name();

/**
 * return the section address (country address is not implemented yet)
 */
satellite_settings_get_address();

/**
 * return the country name even if its a section
 */
satellite_settings_get_countryname();