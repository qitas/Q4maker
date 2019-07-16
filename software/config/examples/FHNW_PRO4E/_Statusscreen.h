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
 * Custom Status Screen bitmap
 *
 * Place this file in the root with your configuration files
 * and enable CUSTOM_STATUS_SCREEN_IMAGE in Configuration.h.
 *
 * Use the Marlin Bitmap Converter to make your own:
 * http://marlinfw.org/tools/u8glib/converter.html
 */

//
// Status Screen Logo bitmap
//
#define STATUS_LOGO_Y            7
#define STATUS_LOGO_WIDTH       41

const unsigned char bitmap_lpc0sj[] PROGMEM = {
  
};

const unsigned char status_logo_bmp[] PROGMEM = {
  B11111010,B00101000,B10100010,B00000011,B11100111,B00000000, // #####.#...#.#...#.#...#.......#####..###........
  B10000010,B00101000,B10100010,B00000000,B10001000,B10000000, // #.....#...#.#...#.#...#.........#...#...#.......
  B10000010,B00101100,B10100010,B00000000,B10001000,B10000000, // #.....#...#.##..#.#...#.........#...#...#.......
  B11110011,B11101010,B10100010,B11111000,B10000111,B00000000, // ####..#####.#.#.#.#...#.#####...#....###........
  B10000010,B00101001,B10101010,B00000000,B10001000,B10000000, // #.....#...#.#..##.#.#.#.........#...#...#.......
  B10000010,B00101000,B10101010,B00000000,B10001000,B10000000, // #.....#...#.#...#.#.#.#.........#...#...#.......
  B10000010,B00101000,B10010100,B00000000,B10000111,B00000000  // #.....#...#.#...#..#.#..........#....###........
};

//
// Use default bitmaps
//
#define STATUS_HOTEND_ANIM
#define STATUS_BED_ANIM
#define STATUS_HEATERS_XSPACE   20
#if HOTENDS < 2
  #define STATUS_HEATERS_X      48
  #define STATUS_BED_X          72
#else
  #define STATUS_HEATERS_X      40
  #define STATUS_BED_X          80
#endif
