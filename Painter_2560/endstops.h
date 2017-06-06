
#ifndef ENDSTOPS_H
#define ENDSTOPS_H

#include "enum.h"

class Endstops {

  public:

    static bool enabled, enabled_globally;
    static volatile char endstop_hit_bits;     // use X_MIN, Y_MIN, Z_MIN and Z_MIN_PROBE as BIT value

    #if ENABLED(Z_DUAL_ENDSTOPS)
      static uint16_t
    #else
      static byte
    #endif
        current_endstop_bits, old_endstop_bits;

    Endstops() {};

    /**
     * Initialize the endstop pins
     */
    void init();

    /**
     * Update the endstops bits from the pins
     */
    static void update();

    /**
     * Print an error message reporting the position when the endstops were last hit.
     */
    static void report_state(); //call from somewhere to create an serial error message with the locations the endstops where hit, in case they were triggered

    /**
     * Report endstop positions in response to M119
     */
    static void M119();

    // Enable / disable endstop checking globally
    static void enable_globally(bool onoff=true) { enabled_globally = enabled = onoff; }

    // Enable / disable endstop checking
    static void enable(bool onoff=true) { enabled = onoff; }

    // Disable / Enable endstops based on ENSTOPS_ONLY_FOR_HOMING and global enable
    static void not_homing() { enabled = enabled_globally; }

    // Clear endstops (i.e., they were hit intentionally) to suppress the report
    static void hit_on_purpose() { endstop_hit_bits = 0; }

    // Enable / disable endstop z-probe checking
    #if HAS_BED_PROBE
      static volatile bool z_probe_enabled;
      static void enable_z_probe(bool onoff=true) { z_probe_enabled = onoff; }
    #endif

  private:

    #if ENABLED(Z_DUAL_ENDSTOPS)
      static void test_dual_z_endstops(EndstopEnum es1, EndstopEnum es2);
    #endif
};

extern Endstops endstops;

#endif // ENDSTOPS_H

