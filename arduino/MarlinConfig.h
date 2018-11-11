
#ifndef MARLIN_CONFIG_H
  #define MARLIN_CONFIG_H

  #include "fastio.h"
  #include "macros.h"
  #include "boards.h"
  #include "Version.h"
  #include "Configuration.h"
  #include "EXTRUDERS.h"
  #include "Configuration_adv.h"
  #include "pins.h"
  #ifndef USBCON
    #define HardwareSerial_h           // trick to disable the standard HWserial
  #endif
  #include "Arduino.h"                   
  #include "Conditionals_post.h"
  #include "SanityCheck.h"
  //#include "Conditionals_LCD.h"
#endif // MARLIN_CONFIG_H

