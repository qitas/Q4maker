/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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

#ifndef UTF_MAPPER_H
#define UTF_MAPPER_H

#include  "language.h"

#if ENABLED(DOGLCD)
  #define HARDWARE_CHAR_OUT u8g.print
#else
  #define HARDWARE_CHAR_OUT lcd.write
#endif

#if DISABLED(SIMULATE_ROMFONT) && ENABLED(DOGLCD)
  #if ENABLED(DISPLAY_CHARSET_ISO10646_1)
    #define MAPPER_ONE_TO_ONE
  #elif ENABLED(DISPLAY_CHARSET_ISO10646_5)
    #define MAPPER_ONE_TO_ONE
  #elif ENABLED(DISPLAY_CHARSET_ISO10646_KANA)
    #define MAPPER_ONE_TO_ONE
  #elif ENABLED(DISPLAY_CHARSET_ISO10646_GREEK)
    #define MAPPER_ONE_TO_ONE
  #endif
#else // SIMULATE_ROMFONT
  #if DISPLAY_CHARSET_HD44780 == JAPANESE
    #if ENABLED(MAPPER_C2C3)
      const PROGMEM uint8_t utf_recode[] =
           { // 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f          This is fair for symbols
             0x20,0x3f,0xec,0xed,0x3f,0x5c,0x7c,0x3f,0x22,0x63,0x61,0x7f,0x3f,0x3f,0x52,0xb0,  // c2a
  //          ' '       垄    拢         颅    l         "    c    a    芦              R
             0xdf,0x3f,0x32,0x33,0x27,0xe4,0xf1,0xa5,0x2c,0x31,0xdf,0x7e,0x3f,0x3f,0x3f,0x3f,  // c2b but relatively bad for letters.
  //          掳         2    3    `    N    p    .    ,    1    掳    禄
             0x3f,0x3f,0x3f,0x3f,0xe1,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,  // c38
  //                              盲
             0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0xef,0x78,0x3f,0x3f,0x3f,0x3f,0xf5,0x3f,0x3f,0xe2,  // c39 missing characters display as '?'
  //                                        枚     x                       眉              脽
             0x3f,0x3f,0x3f,0x3f,0xe1,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,  // c3a
  //                              盲
             0x3f,0xee,0x3f,0x3f,0x3f,0x3f,0xef,0xfd,0x3f,0x3f,0x3f,0x3f,0xf5,0x3f,0x3f,0x3f   // c3b
  //               n                        枚    梅                        眉
           };
    #elif ENABLED(MAPPER_E382E383)
      const PROGMEM uint8_t utf_recode[] =
           { // 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f
             0x3d,0xb1,0xb1,0xa8,0xb2,0xa9,0xb3,0xaa,0xb4,0xab,0xb5,0xb6,0xb6,0xb7,0xb7,0xb8,  // e382a Please test and correct
  //          =    銈�    銈�    銈�    銈�    銈�    銈�    銈�    銈�    銈�    銈�   銈�    銈�    銈�   銈�    銈�
             0xb8,0xb9,0xb9,0xba,0xba,0xbb,0xbb,0xbc,0xbc,0xbd,0xbd,0xbe,0xbe,0xbf,0xbf,0xc0,  // e382b
  //          銈�    銈�    銈�   銈�    銈�    銈�    銈�    銈�    銈�   銈�    銈�    銈�    銈�    銈�   銈�    銈�
             0xc0,0xc1,0xc1,0xc2,0xc2,0xc2,0xc3,0xc3,0xc4,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,  // e3838
  //          銈�    銉�    銉�    銉�    銉�    銉�    銉�   銉�    銉�    銉�    銉�    銉�    銉�    銉�   銉�    銉�
             0xca,0xca,0xcb,0xcb,0xcb,0xcc,0xcc,0xcc,0xcd,0xcd,0xcd,0xce,0xce,0xce,0xcf,0xd0,  // e3839
  //          銉�    銉�    銉�   銉�    銉�     銉�    銉�   銉�    銉�    銉�    銉�    銉�    銉�    銉�   銉�    銉�
             0xd1,0xd2,0xd3,0xd4,0xd4,0xd5,0xd5,0xae,0xd6,0xd7,0xd8,0xd9,0xda,0xdb,0xdc,0xdc,  // e383a
  //          銉�    銉�    銉�    銉�   銉�    銉�    銉�    銉�    銉�    銉�    銉�    銉�    銉�    銉�   銉�    銉�
             0xec,0xa7,0xa6,0xdd,0xcc,0x3f,0x3f,0x3f,0x3f,0x3f,0xa6,0xa5,0xb0,0xa4,0xa4,0x3f   // e383b
  //          銉�    銉�    銉�    銉�    銉�    ?    ?   ?    ?    ?    銉�    銉�    銉�    銉�    銉�   ?
           };
    #elif ENABLED(MAPPER_D0D1)
      #error "Cyrillic on a JAPANESE display makes no sense. There are no matching symbols."
    #endif

  #elif DISPLAY_CHARSET_HD44780 == WESTERN
    #if ENABLED(MAPPER_C2C3)
      const PROGMEM uint8_t utf_recode[] =
           { // 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f   This is relative complete.
             0x20,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0x22,0xa9,0xaa,0xab,0x3f,0x3f,0xae,0x3f,  // c2a聽隆垄拢陇楼娄搂篓漏陋芦卢颅庐炉
  //         ' '   隆    垄    拢    陇    楼    娄    搂    "    漏    陋    芦    ?    ?    庐    ?
             0xb0,0xb1,0xb2,0xb3,0x27,0xb5,0xb6,0xb7,0x2c,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,  // c2b 掳卤虏鲁麓碌露路赂鹿潞禄录陆戮驴
  //          掳    卤    鲁    虏    ?    碌    露    路    ,    鹿    潞    禄    录    陆    戮    驴
             0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,  // c38 脌脕脙脛脜脝脟脠脡脢脣脤脥脦脧
  //          脌    脕    脗    脙    脛    脜    脝    脟    脠    脡    脢    脣    脤    脥    脦    脧
             0xd0,0xd1,0xd2,0xd3,0xd4,0xd5,0xd6,0xd7,0xd8,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0xdf,  // c39 脨脩脫脭脮脰脳脴脵脷脹脺脻脼脽
  //          脨    脩    脪    脫    脭    脮    脰    脳    脴    脵    脷    脹    脺    脻    脼    脽
             0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,0xe8,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,  // c3a 脿谩茫盲氓忙莽猫茅锚毛矛铆卯茂
  //          脿    谩    芒    茫    盲    氓    忙    莽    猫    茅    锚    毛    矛    铆    卯    茂
             0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff   // c3b 冒帽贸么玫枚梅酶霉煤没眉媒镁每
  //          冒    帽    貌    贸    么    玫    枚    梅    酶    霉    煤    没    眉    媒    镁    每
           };
    #elif ENABLED(MAPPER_D0D1)
      #define MAPPER_D0D1_MOD
      const PROGMEM uint8_t utf_recode[] =
           {//0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f
             0x41,0x80,0x42,0x92,0x81,0x45,0x82,0x83,0x84,0x85,0x4b,0x86,0x4d,0x48,0x4f,0x87,  // d0a
  //          A    袘    B    袚    袛    E    袞    袟    袠    袡    K    袥    M    H    O    袩
             0x50,0x43,0x54,0x88,0xd8,0x58,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x62,0x8f,0xac,0xad,  // d0b
  //          P    C    T    校    肖    X    效    褔    楔    些    歇    蝎    b    协    挟    携
             0x61,0x36,0x42,0x92,0x81,0x65,0x82,0xb3,0x84,0x85,0x6b,0x86,0x4d,0x48,0x6f,0x87,  // d18
  //          a    6    B    袚    袛    e    袞    鲁    袠    袡    k    袥    M    H    o    袩
             0x70,0x63,0x54,0x79,0xd8,0x78,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x62,0x8f,0xac,0xad   // d19
  //          p    c    T    y    肖    x    效    褔    楔    些    歇    蝎    b    协    挟    携
            };
    #elif ENABLED(MAPPER_E382E383)
      #error "Katakana on a WESTERN display makes no sense. There are no matching symbols."
    #endif

  #elif DISPLAY_CHARSET_HD44780 == CYRILLIC
    #if ENABLED(MAPPER_D0D1)
      #define MAPPER_D0D1_MOD
      // it is a Russian alphabet translation
      // except 0401 --> 0xa2 = 衼, 0451 --> 0xb5 = 褢
      const PROGMEM uint8_t utf_recode[] =
             { 0x41,0xa0,0x42,0xa1,0xe0,0x45,0xa3,0xa4,   // unicode U+0400 to U+047f
             // A   袘->衼  B    袚    袛    E    袞    袟      // 0  衻 衼 袀 袃 袆 袇 袉 袊
               0xa5,0xa6,0x4b,0xa7,0x4d,0x48,0x4f,0xa8,   //    袌 袎 袏 袐 袑 袓 袔 袕
             // 袠    袡    K    袥    M    H    O    袩      // 1  袗 袘 袙 袚 袛 袝 袞 袟
               0x50,0x43,0x54,0xa9,0xaa,0x58,0xe1,0xab,   //    袠 袡 袣 袥 袦 袧 袨 袩
             // P    C    T    校    肖    X    效    褔      // 2  袪 小 孝 校 肖 啸 袚 效
               0xac,0xe2,0xad,0xae,0x62,0xaf,0xb0,0xb1,   //    楔 些 歇 蝎 鞋 协 挟 携
             // 楔    些    歇    蝎    b    协    挟    携      // 3  邪 斜 胁 谐 写 械 卸 蟹
               0x61,0xb2,0xb3,0xb4,0xe3,0x65,0xb6,0xb7,   //    懈 泄 泻 谢 屑 薪 芯 锌
             // a   斜->褢  胁    谐    写    e    卸    蟹      // 4  褉 褋 褌 褍 褎 褏 褑 褔
               0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0x6f,0xbe,   //    褕 褖 褗 褘 褜 褝 褞 褟
             // 懈    泄    泻    谢    屑    薪    o    锌      // 5  褠 褢 褣 褤 褦 褧 褨 褩
               0x70,0x63,0xbf,0x79,0xe4,0x78,0xe5,0xc0,   //    褬 褭 褮 褯 褱 褲 褳 褵
             // p    c    褌    y    褎    x    褑    褔      // 6  褷 选 癣 眩 绚 靴 薛 学
               0xc1,0xe6,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7    //    血 雪 血 勋 熏 循 旬 询
             // 褕    褖    褗    褘    褜    褝    褞    褟      // 7  寻 驯 巡 殉 汛 训 讯 逊
             };                                           //    鸦 压 押 鸦 鸭 呀 丫 芽
    #elif ENABLED(MAPPER_C2C3)
      #error "Western languages on a CYRILLIC display makes no sense. There are no matching symbols."
    #elif ENABLED(MAPPER_E382E383)
      #error "Katakana on a CYRILLIC display makes no sense. There are no matching symbols."
    #endif
  #else
    #error "Something went wrong in the setting of DISPLAY_CHARSET_HD44780"
  #endif // DISPLAY_CHARSET_HD44780
#endif // SIMULATE_ROMFONT

#if ENABLED(MAPPER_C2C3)

  char charset_mapper(char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_c2 = false;
    uint8_t d = c;
    if ( d >= 0x80u ) { // UTF-8 handling
      if ( (d >= 0xc0u) && (!seen_c2) ) {
        utf_hi_char = d - 0xc2u;
        seen_c2 = true;
        return 0;
      }
      else if (seen_c2) {
        d &= 0x3fu;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80u + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_c2 = false;
    return 1;
  }

#elif ENABLED(MAPPER_CECF)

  char charset_mapper(char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_ce = false;
    uint8_t d = c;
    if ( d >= 0x80 ) { // UTF-8 handling
      if ( (d >= 0xc0) && (!seen_ce) ) {
        utf_hi_char = d - 0xce;
        seen_ce = true;
        return 0;
      }
      else if (seen_ce) {
        d &= 0x3f;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80 + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_ce = false;
    return 1;
  }

#elif ENABLED(MAPPER_CECF)

  char charset_mapper(char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_ce = false;
    uint8_t d = c;
    if ( d >= 0x80 ) { // UTF-8 handling
      if ( (d >= 0xc0) && (!seen_ce) ) {
        utf_hi_char = d - 0xce;
        seen_ce = true;
        return 0;
      }
      else if (seen_ce) {
        d &= 0x3f;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80 + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_ce = false;
    return 1;
  }

#elif ENABLED(MAPPER_D0D1_MOD)

  char charset_mapper(char c) {
    // it is a Russian alphabet translation
    // except 0401 --> 0xa2 = 衼, 0451 --> 0xb5 = 褢
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_d5 = false;
    uint8_t d = c;
    if (d >= 0x80) { // UTF-8 handling
      if (d >= 0xd0 && !seen_d5) {
        utf_hi_char = d - 0xd0;
        seen_d5 = true;
        return 0;
      }
      else if (seen_d5) {
        d &= 0x3f;
        if (!utf_hi_char && d == 1) {
          HARDWARE_CHAR_OUT((char) 0xa2); // 衼
        }
        else if (utf_hi_char == 1 && d == 0x11) {
          HARDWARE_CHAR_OUT((char)0xb5); // 褢
        }
        else {
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x10));
        }
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_d5 = false;
    return 1;
  }

#elif ENABLED(MAPPER_D0D1)

  char charset_mapper(char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_d5 = false;
    uint8_t d = c;
    if (d >= 0x80u) { // UTF-8 handling
      if (d >= 0xd0u && !seen_d5) {
        utf_hi_char = d - 0xd0u;
        seen_d5 = true;
        return 0;
      }
      else if (seen_d5) {
        d &= 0x3fu;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0xa0u + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_d5 = false;
    return 1;
  }

#elif ENABLED(MAPPER_E382E383)

  char charset_mapper(char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_e3 = false;
    static bool seen_82_83 = false;
    uint8_t d = c;
    if (d >= 0x80) { // UTF-8 handling
      if (d == 0xe3 && !seen_e3) {
        seen_e3 = true;
        return 0;      // eat 0xe3
      }
      else if (d >= 0x82 && seen_e3 && !seen_82_83) {
        utf_hi_char = d - 0x82;
        seen_82_83 = true;
        return 0;
      }
      else if (seen_e3 && seen_82_83) {
        d &= 0x3f;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80 + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT((char) '?' );
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_e3 = false;
    seen_82_83 = false;
    return 1;
  }

#else

  #define MAPPER_NON

  char charset_mapper(char c) {
    HARDWARE_CHAR_OUT( c );
    return 1;
  }

  #endif // code mappers

#endif // UTF_MAPPER_H

