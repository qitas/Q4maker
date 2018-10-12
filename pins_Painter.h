
#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
  #error "Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu."
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME "RAMPS For Painter"
  #define DEFAULT_MACHINE_NAME    "Painter"
  #define DEFAULT_SOURCE_CODE_URL "https://Qita.ltd/Painter"  
#endif

//A10-A15   D4/5/6/8/9/10
//16,17,23,25,27,29,31,33,35,37,38,41,43,45,47,32,42,44,4,5,6,11

#define HEATER_BED_PIN	    8
#define TEMP_BED_PIN       13            // ANALOG NUMBERING  

#define HEATER_0_PIN        9
#define TEMP_0_PIN         14            // ANALOG NUMBERING  

#define HEATER_1_PIN       10
#define TEMP_1_PIN         15            // ANALOG NUMBERING  

#define HEATER_2_PIN        4            // 4 5 6 IS ANOTHER 8 9 10
#define TEMP_2_PIN         11            // ANALOG NUMBERING  A15

#define HEATER_3_PIN        5 
#define TEMP_3_PIN         12            // ANALOG NUMBERING  A11

#define FAN_PIN             6            // PWM OUTPUT AROUND FANS 6
#define FAN1_PIN           32            // OUTPUT SWITCH FOR WATER FAN & WATER PUMP

#define SERVO0_PIN         11
#define PS_ON_PIN          12
#define LED_PIN            13 

#define FIL_RUNOUT_PIN     23         
#define FIL_1_RUNOUT_PIN   25
#define FIL_2_RUNOUT_PIN   27
#define FIL_3_RUNOUT_PIN   29

#define X_MIN_PIN           3
#define X_MAX_PIN           2
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62     

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

#define E2_STEP_PIN        33
#define E2_DIR_PIN         35
#define E2_ENABLE_PIN      31

#define E3_STEP_PIN        43     
#define E3_DIR_PIN         41     
#define E3_ENABLE_PIN      37     

#define JoyStick_X          5      // ANALOG NUMBERING   A5
#define JoyStick_Y          9      // ANALOG NUMBERING   A9
#define JoyStick_Z         42      // DIGIT IO

#define HOME_PIN           44 
#define AIR_PIN            45
#define VACUUM_PIN         47

#define SD_DETECT_PIN      49
#define SDSS               53     

//#define CONTROLLERFAN_PIN  48


//#define WS8212A_PIN       4     // INNER
//#define WS8212B_PIN      45     // OUTER
//#define TOUCH_PIN        47     // TOUCH BTN
//#define KILL_PIN         41
//#define FILWIDTH_PIN      5              // ANALOG NUMBERING
//#define BEEPER_PIN                       // PWM OUTPUT  铚傞福鍣�
//#define MAIN_VOLTAGE_MEASURE_PIN    62   //Analogue PIN to measure the main voltage, with a 100k - 4k7 resitor divider.
//#define MAIN_WEIGHT_MEASURE_PIN     63   //Analogue PIN to measure the Weight

//#define SAFETY_TRIGGERED_PIN        28    //PIN to detect the safety circuit has triggered 鐢垫祦娴嬭瘯锛岄槻杩囨祦

//#define MOTOR_CURRENT_PWM_XY_PIN    46
//#define MOTOR_CURRENT_PWM_Z_PIN     47
//#define MOTOR_CURRENT_PWM_E_PIN     48

//Motor current PWM conversion, PWM value = MotorCurrentSetting * 255 / range
//#define MOTOR_CURRENT_PWM_RANGE   2000
//#define DEFAULT_PWM_MOTOR_CURRENT  {1300, 1300, 1250}

//#define BTN_EN1   40
//#define BTN_EN2   41
//#define BTN_ENC   19

//#if ENABLED(Z_PROBE_SLED)
   //  #define SLED_PIN         -1
//#endif



