/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * FHNW pro4E Team8 (STM32F130ZET6, TMC2660 drivers) board pin assignments
 * loosely based on the MKS Robin, changes made by Dominik Mueller
 * 
 * Note: SPI2 interface is used. Maple core has to be configured accordingly:
 *       Change `SPIClass SPI(1);` to `SPIClass SPI(2);` in `SPI.cpp` file
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif

/**
 * Expansion board
 */
// #define EXPANSION_BOARD

#if defined(EXPANSION_BOARD)
  #define MAX_HOTENDS 3
#else
  #define MAX_HOTENDS 1
#endif

#if HOTENDS > MAX_HOTENDS || E_STEPPERS > MAX_HOTENDS
  #error "More extruders configured than supported by this board."
#endif

/**
 * Board name
 */
#define BOARD_NAME "FHNW pro4E Team8"

/**
 * Disable JTAG and SWD
 * 
 * to get more GPIO pins
 */
// #define DISABLE_DEBUG

/**
 * Creality LCD (128 x 64 dot matrix)
 * 
 * EXP3, wrongly labeled as EXT3 on the board
 */
#define BEEPER_PIN          PE1     // EXP3-1 (J202-1) [LCD_Beeper]

#define BTN_EN1             PB8     // EXP3-5 (J202-5) [LCD_Encoder_A] [EXTI8]
#define BTN_EN2             PB9     // EXP3-3 (J202-3) [LCD_Encoder_B] [EXTI9]
#define BTN_ENC             PE3     // EXP3-2 (J202-2) [LCD_Encoder_BTN] [EXTI3]

#define LCD_PINS_RS         PE0     // EXP3-7 (J202-7) [LCD_CS]
#define LCD_PINS_ENABLE     PB15    // EXP3-8 (J202-8) [LCD_MOSI] / Fallback SW-SPI: PE2
#define LCD_PINS_D4         PB13    // EXP3-6 (J202-6) [LCD_SCK] / Fallback SW-SPI: PE6

// Draw alternative Bootscreen (Bat)
// #define DRAW_ALT_BOOTSCREEN

/**
 * Developer Interface
 */
#define LED_PIN             PA12    // `LED MARLIN`
#define LED_USER1           PC5     // not used by Marlin
#define LED_USER2           PB0     // not used by Marlin

#define BTN_USER1           PD10    // [EXTI10] not used by Marlin
#define BTN_USER2           PC7     // not used by Marlin

/**
 * SD card (uSD)
 */
#define SD_DETECT_PIN       PA11
#define SDSS                -1      // not required, SDIO interface is used
// #define LCD_SDSS            -1      // not present

/**
 * Servos (enables e.g. BLTouch support)
 * 
 * only two servo headers are present on the board, both wrongly labeled `Servo 1`
 * (two more can be configured through the expansion board)
 * 
 * Note: There is an error in the include guard of the `servo.cpp` file.
 *       It wrongly checks, if the macro `STM32F1` instead of `__STM32F1__` is defined.
 * 
 * Note 2: At the moment it is not possible to enable the servo pins due to the lack of software PWM support.
 */
#define SERVO0_PIN          PD6     // J605 (BOTTOM)
#define SERVO1_PIN          PD7     // J606 (TOP)
#if defined(EXPANSION_BOARD)
  // #define SERVO2_PIN          -1      // any GPIO pin from expansion header
  // #define SERVO3_PIN          -1      // any GPIO pin from expansion header
#endif

/**
 * Steppers
 */
#define X_ENABLE_PIN        PF11
#define X_STEP_PIN          PA5
#define X_DIR_PIN           PA6
#define X_CS_PIN            PF12
#define X_SG_PIN            PA7     // [EXTI7]

#define Y_ENABLE_PIN        PG0
#define Y_STEP_PIN          PF13
#define Y_DIR_PIN           PF14
#define Y_CS_PIN            PG1
#define Y_SG_PIN            PF15    // [EXTI15]

#define Z_ENABLE_PIN        PG2
#define Z_STEP_PIN          PD11
#define Z_DIR_PIN           PD12
#define Z_CS_PIN            PG3
#define Z_SG_PIN            PD13    // [EXTI13]

// Second z-axis
#if defined(EXPANSION_BOARD)
  // #define Z3_ENABLE_PIN       PG10    // or PG13
  // #define Z3_STEP_PIN         PD14    // or PD0
  // #define Z3_DIR_PIN          PD1     // or PG9
  // #define Z3_CS_PIN           PD9     // or PD15
  // #define Z3_SG_PIN           PG11    // [EXTI11] or PG12 [EXTI12]
#endif

#define E0_ENABLE_PIN       PG7
#define E0_STEP_PIN         PG4
#define E0_DIR_PIN          PG5
#define E0_CS_PIN           PG8
#define E0_SG_PIN           PG6     // [EXTI6]

// Second and third extruder
#if defined(EXPANSION_BOARD)
  // #define E1_ENABLE_PIN       PG10
  // #define E1_STEP_PIN         PD14
  // #define E1_DIR_PIN          PD1
  // #define E1_CS_PIN           PD9
  // #define E1_SG_PIN           PG11    // [EXTI11]

  // #define E2_ENABLE_PIN       PG13
  // #define E2_STEP_PIN         PD0
  // #define E2_DIR_PIN          PG9
  // #define E2_CS_PIN           PD15
  // #define E2_SG_PIN           PG12    // [EXTI12]
#endif

/**
 * Endstops
 * 
 * NO:     Endstop inverting must be set to true in Configuration.h
 * NC:     Endstop inverting must be set to false in Configuration.h
 * SG_TST: Endstop inverting must be set to false in Configuration.h
 * 
 * Software pull-up / pull-down resistors should be turned off (`ENDSTOPPULLUPS` and `ENDSTOPPULLDOWNS`).
 * Pull-up resistors (10 kOhm) are already present on the board itself.
 * 
 * Note: There is a problem in the `SanityCheck.h` file when using the TMC2660 stallGuard2 (`SG_TST` pin) as an endstop.
 *       This is due to the fact that the TMC2660 `SG_TST` pin is always push-pull and the default setup of the TMC2130 `DIAG1` pin is open-drain.
 *       Thus, to use the TMC2660 `SG_TST` pin as an endstop neither a software pull-up nor an inverted signal interpretation is necessary.
 */
#define X_MIN_PIN           X_SG_PIN // PF1      // [EXTI1]
#define X_MAX_PIN           -1
#define Y_MIN_PIN           Y_SG_PIN // PF2      // [EXTI2]
#define Y_MAX_PIN           -1
#define Z_MIN_PIN           PE5 // Z_SG_PIN      // [EXTI5]
#define Z_MAX_PIN           -1
#define FIL_RUNOUT_PIN      PE4 // E0_SG_PIN     // [EXTI4]
#if defined(EXPANSION_BOARD)
  // #define FIL_RUNOUT2_PIN     PG14      // [EXTI14]
  // #define FIL_RUNOUT3_PIN     PF0       // [EXTI0]
#endif

/**
 * Temperature sensors
 * 
 * Note: At the moment there is no possibility to use a temperature sensor located on the printer board.
 *       This implies that the following pins can't be used as intended: [ADC_TEMP_PCB, PA1] and [EXT_TEMP, PF9].
 */
#define TEMP_0_PIN          PC2     // [ADC]
#if defined(EXPANSION_BOARD)
  // #define TEMP_1_PIN          PF10    // [ADC]
  // #define TEMP_2_PIN          PF8     // [ADC]
#endif
#define TEMP_BED_PIN        PC3     // [ADC]

/**
 * Heaters / Fans
 * 
 * Bed and extruders are set to PID control mode.
 * PID frequency of the bed heater is the same as the PWM frequency of the heaters.
 * 
 * Note: `FAN_SOFT_PWM` has to be enabled due to the fact that the pins used for the fans
 *       are not mapped to a timer channel. This causes the extruders and the fans to use software PWM.
 * 
 * Note 2: `EXTRUDER_AUTO_FAN_TEMPERATURE` has to be set to an appropriate value.
 *         Furthermore, `CONTROLLERFAN_SECS` has to be set to an appropriate value.
 * 
 * Note 3: At the moment there is no possibility to use a second fan to cool the/another controller board.
 *         This implies that the intended pin on the expansion header can't be used in this way [EXT_FAN, PE15].
 * 
 * Note 4: There is a bug in the `SanityCheck.h` file with comparing pins in the `P<bank><pin>` notation.
 */
#define HEATER_0_PIN        PB10
#if defined(EXPANSION_BOARD)
  // #define HEATER_1_PIN        PE10    // [EXT1_HE]
  // #define HEATER_2_PIN        PE9     // [EXT2_HE]
#endif
#define HEATER_BED_PIN      PB11

#define FAN_PIN             PF3     // [FAN1] used to cool the filament
#define E0_AUTO_FAN_PIN     PF4     // [FAN2] used to cool the hot end

#if defined(EXPANSION_BOARD)
  // #define FAN1_PIN            PE14    // [EXT1_FAN1] used to cool the filament
  // #define E1_AUTO_FAN_PIN     PE12    // [EXT1_FAN2] used to cool the hot end

  // #define FAN2_PIN            PE13    // [EXT2_FAN1] used to cool the filament
  // #define E2_AUTO_FAN_PIN     PE11    // [EXT2_FAN2] used to cool the hot end
#endif

// `USE_CONTROLLER_FAN` feature must be configured to use software PWM in `controllerfan.cpp`.
// To achieve this, the following line has to be removed: `analogWrite(CONTROLLER_FAN_PIN, speed);`.
#define CONTROLLER_FAN_PIN  PF5     // [FAN3] used to cool the FETs and the stepper drivers on the PCB

/**
 * Not implemented
 */
// #define POWER_LOSS_PIN      -1
// #define PS_ON_PIN           -1

/**
 * MKS Robin TFT
 * (FHNW pro4E Team8 board doesn't support this at the moment!)
 * 
 * Note: MKS Robin TFT screens may have different TFT controllers
 * If the screen stays white, disable 'LCD_RESET_PIN' to rely on the bootloader to do screen initialization.
 * 
 * Enabling 'LCD_RESET_PIN' causes flickering when entering the LCD menu due to LCD controller reset.
 * Reset feature was designed to "revive the LCD if static electricity killed it."
 */
#if defined(MKS_ROBIN_TFT)
  // Pin usage (32 pin connector, including supply and NC pins):
  // Data D0-D15 (PD14, PD15, PD0, PD1, PE7-PE15, PD8-PD10)
  // NOE: Read operation (PD4) / NWE: Write operation (PD5)
  // SPI2 (PB13, PB14, PB15) / Unknown (PB1, PC13)
  #define LCD_RESET_PIN       PF6     // Reset
  #define LCD_BACKLIGHT_PIN   PG11    // Backlight
  #define FSMC_CS_PIN         PG12    // NE4 (Chip Select)
  #define FSMC_RS_PIN         PF0     // A0 (LCD Register Select)
#endif
