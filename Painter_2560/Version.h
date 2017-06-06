
/**
 * This file is the standard Marlin version identifier file, all fields can be
 * overriden by the ones defined on _Version.h by using the Configuration.h
 * directive USE_AUTOMATIC_VERSIONING.
 */

#if ENABLED(USE_AUTOMATIC_VERSIONING)

  #include "_Version.h"

#else

  /**
   * Marlin release version identifier
   */
  #define SHORT_BUILD_VERSION " Based Marlin -RC7"

  /**
   * Verbose version identifier which should contain a reference to the location
   * from where the binary was downloaded or the source code was compiled.
   */
  #define DETAILED_BUILD_VERSION SHORT_BUILD_VERSION " (Github)"

  /**
   * The STRING_DISTRIBUTION_DATE represents when the binary file was built,
   * here we define this default string as the date where the latest release
   * version was tagged.
   */
  #define STRING_DISTRIBUTION_DATE "2016-10-12 12:00"

  /**
   * Required minimum Configuration.h and Configuration_adv.h file versions.
   *
   * You must increment this version number for every significant change such as,
   * but not limited to: ADD, DELETE RENAME OR REPURPOSE any directive/option on
   * the configuration files.
   */
  #define REQUIRED_CONFIGURATION_H_VERSION 010100
  #define REQUIRED_CONFIGURATION_ADV_H_VERSION 010100

  /**
   * @todo: Missing documentation block
   */
  #define PROTOCOL_VERSION "1.0"

  /**
   * Defines a generic printer name to be output to the LCD after booting Marlin.
   */
  #define MACHINE_NAME "3D Printer"

  /**
   * The SOURCE_CODE_URL is the location where users will find the Marlin Source
   * Code which is installed on the device. In most cases 鈥攗nless the manufacturer
   * has a distinct Github fork鈥� the Source Code URL should just be the main
   * Marlin repository.
   */
  #define SOURCE_CODE_URL "https://github.com/MarlinFirmware/Marlin"

  /**
   * Default generic printer UUID.
   */
  #define DEFAULT_MACHINE_UUID "cede2a2f-41a2-4748-9b12-c55c62f367ff"

  /**
   * The WEBSITE_URL is the location where users can get more information such as
   * documentation about a specific Marlin release.
   */
  #define WEBSITE_URL "http://marlinfw.org"

#endif // USE_AUTOMATIC_VERSIONING

