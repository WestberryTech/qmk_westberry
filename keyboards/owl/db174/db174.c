/* Copyright (C) 2022 Westberry Technology (ChangZhou) Corp., Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "db174.h"
#include "rgb_driver.h"
#ifdef VIA_ENABLE
#include "custom_key.h"
#endif

#ifdef RGB_MATRIX_ENABLE

const wb003_led g_wb003_leds[RGB_MATRIX_LED_COUNT] = {
   { 4, 0 }, //  0 ESC
   { 3, 0 }, //  1 F1
   { 2, 0 }, //  2 F2
   { 1, 0 }, //  3 F3
   { 0, 0 }, //  4 F4
   {11, 0 }, //  5 F5
   {10, 0 }, //  6 F6
   { 9, 0 }, //  7 F7
   { 8, 0 }, //  8 F8
   { 7, 0 }, //  9 F9
   { 6, 0 }, // 10 F10
   {16, 0 }, // 11 F11
   {15, 0 }, // 12 F12
   {14, 0 }, // 13 DEL

   { 5, 0 }, // 14 ~
   { 4, 1 }, // 15 1
   { 3, 1 }, // 16 2
   { 2, 1 }, // 17 3
   { 1, 1 }, // 18 4
   { 0, 1 }, // 19 5
   {11, 1 }, // 20 6
   {10, 1 }, // 21 7
   { 9, 1 }, // 22 8
   { 8, 1 }, // 23 9
   { 7, 1 }, // 24 0
   { 6, 1 }, // 25 -
   {16, 1 }, // 26 =
   {13, 0 }, // 27 Backspace
   {12, 0 }, // 28 PGUP

   { 5, 1 }, // 29 tab
   { 4, 2 }, // 30 Q
   { 3, 2 }, // 31 W
   { 2, 2 }, // 32 E
   { 1, 2 }, // 33 R
   { 0, 2 }, // 34 T
   {11, 2 }, // 35 Y
   {10, 2 }, // 36 U
   { 9, 2 }, // 37 I
   { 8, 2 }, // 38 O
   { 7, 2 }, // 39 P
   { 6, 2 }, // 40 [
   {15, 1 }, // 41 ]
   {14, 1 }, // 42 KC_BSLS
   {13, 1 }, // 43 PGDN

   { 5, 2 }, // 44 Caps Lock
   { 4, 3 }, // 45 A
   { 3, 3 }, // 46 S
   { 2, 3 }, // 47 D
   { 1, 3 }, // 48 F
   { 0, 3 }, // 49 G
   {11, 3 }, // 50 H
   {10, 3 }, // 51 J
   { 9, 3 }, // 52 K
   { 8, 3 }, // 53 L
   { 7, 3 }, // 54 ;
   {16, 2 }, // 55 '
   {15, 2 }, // 56 Enter
   {12, 1 }, // 57 HOME

   { 5, 3 }, // 58 L_Shift
   { 2, 4 }, // 59 Z
   { 1, 4 }, // 60 X
   { 0, 4 }, // 61 C
   {11, 4 }, // 62 V
   {10, 4 }, // 63 B
   { 8, 4 }, // 64 N
   { 7, 4 }, // 65 M
   { 6, 4 }, // 66 ,
   {16, 4 }, // 67 .
   { 6, 3 }, // 68 /
   {14, 2 }, // 69 R_Shift
   {13, 2 }, // 70 UP

   { 5, 4 }, // 71 L_Ctrl
   { 4, 4 }, // 72 Opt
   { 3, 4 }, // 73 L_WIN
   { 9, 4 }, // 74 Space
   {15, 4 }, // 75 R_WIN
   {14, 4 }, // 76 FN
   {16, 3 }, // 77 R_Ctrl
   {15, 3 }, // 78 LEFT
   {14, 3 }, // 79 DOWN
   {12, 2 }  // 80 RIGHT
};

#define __ NO_LED

led_config_t g_led_config = {{
    {14, 29, 44, 58, 71},
    { 0, 15, 30, 45, 72},
    { 1, 16, 31, 46, 73},
    { 2, 17, 32, 47, 59},
    { 3, 18, 33, 48, 60},
    { 4, 19, 34, 49, 61},
    { 5, 20, 35, 50, 62},
    { 6, 21, 36, 51, 63},
    { 7, 22, 37, 52, 74},
    { 8, 23, 38, 53, 64},
    { 9, 24, 39, 54, 65},
    {10, 25, 40, 68, 66},
    {11, 26, 55, 77, 67},
    {12, 41, 56, 78, 75},
    {13, 42, 69, 79, 76},
    {27, 43, 70, __, __},
    {28, 57, 80, __, __}
}, {
    {  0 ,  0}, //  0
    { 17 ,  0}, //  1
    { 34 ,  0}, //  2
    { 52 ,  0}, //  3
    { 69 ,  0}, //  4
    { 86 ,  0}, //  5
    {103 ,  0}, //  6
    {121 ,  0}, //  7
    {138 ,  0}, //  8
    {155 ,  0}, //  9
    {172 ,  0}, // 10
    {190 ,  0}, // 11
    {207 ,  0}, // 12
    {224 ,  0}, // 13

    {  0 , 12}, // 14
    { 16 , 12}, // 15
    { 32 , 12}, // 16
    { 48 , 12}, // 17
    { 64 , 12}, // 18
    { 80 , 12}, // 19
    { 96 , 12}, // 20
    {112 , 12}, // 21
    {128 , 12}, // 22
    {144 , 12}, // 23
    {160 , 12}, // 24
    {176 , 12}, // 25
    {192 , 12}, // 26
    {208 , 12}, // 27
    {224 , 12}, // 28

    {  0 , 25}, // 29
    { 16 , 25}, // 30
    { 32 , 25}, // 31
    { 48 , 25}, // 32
    { 64 , 25}, // 33
    { 80 , 25}, // 34
    { 96 , 25}, // 35
    {112 , 25}, // 36
    {128 , 25}, // 37
    {144 , 25}, // 38
    {160 , 25}, // 39
    {176 , 25}, // 40
    {192 , 25}, // 41
    {208 , 25}, // 42
    {224 , 25}, // 43

    {  0 , 38}, // 44
    { 17 , 38}, // 45
    { 34 , 38}, // 46
    { 52 , 38}, // 47
    { 69 , 38}, // 48
    { 86 , 38}, // 49
    {103 , 38}, // 50
    {121 , 38}, // 51
    {138 , 38}, // 52
    {155 , 38}, // 53
    {172 , 38}, // 54
    {190 , 38}, // 55
    {207 , 38}, // 56
    {224 , 38}, // 57

    {  0 , 51}, // 58
    { 18 , 51}, // 59
    { 37 , 51}, // 60
    { 56 , 51}, // 61
    { 74 , 51}, // 62
    { 93 , 51}, // 63
    {112 , 51}, // 64
    {130 , 51}, // 65
    {149 , 51}, // 66
    {168 , 51}, // 67
    {186 , 51}, // 68
    {205 , 51}, // 69
    {224 , 51}, // 70

    {  0 , 64}, // 71
    { 25 , 64}, // 72
    { 50 , 64}, // 73
    { 75 , 64}, // 74
    {100 , 64}, // 75
    {124 , 64}, // 76
    {149 , 64}, // 77
    {174 , 64}, // 78
    {199 , 64}, // 79
    {224 , 64}, // 80
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 4, 4, 4, 4, 1, 1, 1
}};

// clang-format on
#endif

#ifdef ENABLE_CUSTOM_KEY

typedef union {
  uint32_t raw;
  struct {
    uint8_t dkey_states : 1;
  };
} confinfo_t;

confinfo_t confinfo;
uint32_t peek_close_rgb = 0;

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (peek_close_rgb & 0x10000) {
        if (timer_elapsed(peek_close_rgb) <= 200) {
            for (uint8_t idx = led_min; idx < led_max; idx++) {
                rgb_matrix_set_color(idx, RGB_OFF);
            }
            return false;
        } else {
            peek_close_rgb = 0;
        }
    }

    if (confinfo.dkey_states == true) {
        rgb_matrix_set_color(31, 0x57, 0x77, 0x77); // KC_W
    }

    return true;
}
#endif

void matrix_init_user(void) {
    rgb_driver_init();
    confinfo.raw = eeconfig_read_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
#    ifdef VIA_ENABLE
        case VIA_RST: {
            if (record->event.pressed) {
                #include "via.h"
                via_eeprom_set_valid(false);
                eeconfig_init_via();
            }
        } break;
        case EE_RST: {
            eeconfig_disable();
        } break;
        case KC_RPDIR: {
            if (record->event.pressed) {
                confinfo.dkey_states = !confinfo.dkey_states;
                peek_close_rgb = timer_read() | 0x10000;
                eeconfig_update_user(confinfo.raw);
            }
        } break;
#    endif
        case KC_W: {
            if (confinfo.dkey_states) {
                if (record->event.pressed)
                    register_code(KC_UP);
                else
                    unregister_code(KC_UP);
                return false;
            }
            return true;
        } break;
        case KC_A: {
            if (confinfo.dkey_states) {
                if (record->event.pressed)
                    register_code(KC_LEFT);
                else
                    unregister_code(KC_LEFT);
                return false;
            }
            return true;
        } break;
        case KC_S: {
            if (confinfo.dkey_states) {
                if (record->event.pressed)
                    register_code(KC_DOWN);
                else
                    unregister_code(KC_DOWN);
                return false;
            }
            return true;
        } break;
        case KC_D: {
            if (confinfo.dkey_states) {
                if (record->event.pressed)
                    register_code(KC_RIGHT);
                else
                    unregister_code(KC_RIGHT);
                return false;
            }
            return true;
        } break;
        default: {
            return true;
        }
    }

  return false;
}

#endif /* ENABLE_CUSTOM_KEY */
