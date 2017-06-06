
 /**
   * Extruders have some combination of stepper motors and hotends
   * so we separate these concepts into the defines:
   *  EXTRUDERS    - Number of Selectable Tools
   *  HOTENDS      - Number of hotends, whether connected or separate
   *  E_STEPPERS   - Number of actual E stepper motors
   *  TOOL_E_INDEX - Index to use when getting/setting the tool state
   */
  #if ENABLED(SINGLENOZZLE)             // One hotend, multi-extruder
    #define HOTENDS      1
    #define E_STEPPERS   EXTRUDERS
    #define E_MANUAL     EXTRUDERS
    #define TOOL_E_INDEX current_block->active_extruder
    #undef TEMP_SENSOR_1_AS_REDUNDANT
    #undef HOTEND_OFFSET_X
    #undef HOTEND_OFFSET_Y
  #elif ENABLED(SWITCHING_EXTRUDER)     // One E stepper, unified E axis, two hotends
    #define HOTENDS      EXTRUDERS
    #define E_STEPPERS   1
    #define E_MANUAL     1
    #define TOOL_E_INDEX 0
    #ifndef HOTEND_OFFSET_Z
      #define HOTEND_OFFSET_Z { 0 }
    #endif
  #elif ENABLED(MIXING_EXTRUDER)        // Multi-stepper,unified E axis, one hotend
    #define HOTENDS      1
    #define E_STEPPERS   MIXING_STEPPERS
    #define E_MANUAL     1
    #define TOOL_E_INDEX 0
  #else                                 // One stepper, E axis, and hotend per tool
    #define HOTENDS      EXTRUDERS
    #define E_STEPPERS   EXTRUDERS
    #define E_MANUAL     EXTRUDERS
    #define TOOL_E_INDEX current_block->active_extruder
  #endif


