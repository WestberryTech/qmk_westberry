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

#include "owlt87.h"

#ifdef RGB_MATRIX_ENABLE

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
 /* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
   {0, A_1,    B_1,    C_1}, //  0
   {0, A_2,    B_2,    C_2}, //  1
   {0, A_3,    B_3,    C_3}, //  2
   {0, A_4,    B_4,    C_4}, //  3
   {0, A_5,    B_5,    C_5}, //  4
   {0, A_6,    B_6,    C_6}, //  5
   {0, A_7,    B_7,    C_7}, //  6
   {0, A_8,    B_8,    C_8}, //  7
   {0, A_9,    B_9,    C_9}, //  8
   {0, A_10,   B_10,  C_10}, //  9
   {0, A_11,   B_11,  C_11}, // 10
   {0, A_12,   B_12,  C_12}, // 11
   {1, G_1,    H_1,    I_1}, // 12
   {1, G_2,    H_2,    I_2}, // 13
   {1, G_3,    H_3,    I_3}, // 14
   {1, G_4,    H_4,    I_4}, // 15

   {0, D_1,    E_1,    F_1}, // 16
   {0, D_2,    E_2,    F_2}, // 17
   {0, D_3,    E_3,    F_3}, // 18
   {0, D_4,    E_4,    F_4}, // 19
   {0, D_5,    E_5,    F_5}, // 20
   {0, D_6,    E_6,    F_6}, // 21
   {0, D_7,    E_7,    F_7}, // 22
   {0, D_8,    E_8,    F_8}, // 23
   {0, D_9,    E_9,    F_9}, // 24
   {0, D_10,  E_10,   F_10}, // 25
   {0, D_11,  E_11,   F_11}, // 26
   {0, D_12,  E_12,   F_12}, // 27
   {1, G_5,    H_5,    I_5}, // 28
   {1, G_6,    H_6,    I_6}, // 29
   {1, G_7,    H_7,    I_7}, // 30
   {1, G_8,    H_8,    I_8}, // 31
   {1, G_9,    H_9,    I_9}, // 32

   {0, G_1,    H_1,    I_1}, // 33
   {0, G_2,    H_2,    I_2}, // 34
   {0, G_3,    H_3,    I_3}, // 35
   {0, G_4,    H_4,    I_4}, // 36
   {0, G_5,    H_5,    I_5}, // 37
   {0, G_6,    H_6,    I_6}, // 38
   {0, G_7,    H_7,    I_7}, // 39
   {0, G_8,    H_8,    I_8}, // 40
   {0, G_9,    H_9,    I_9}, // 41
   {0, G_10,  H_10,   I_10}, // 42
   {0, G_11,  H_11,   I_11}, // 43
   {0, G_12,  H_12,   I_12}, // 44
   {1, J_1,    K_1,    L_1}, // 45
   {1, J_2,    K_2,    L_2}, // 46
   {1, J_3,    K_3,    L_3}, // 47
   {1, J_4,    K_4,    L_4}, // 48
   {1, J_5,    K_5,    L_5}, // 49

   {0, J_1,    K_1,    L_1}, // 50
   {0, J_2,    K_2,    L_2}, // 51
   {0, J_3,    K_3,    L_3}, // 52
   {0, J_4,    K_4,    L_4}, // 53
   {0, J_5,    K_5,    L_5}, // 54
   {0, J_6,    K_6,    L_6}, // 55
   {0, J_7,    K_7,    L_7}, // 56
   {0, J_8,    K_8,    L_8}, // 57
   {0, J_9,    K_9,    L_9}, // 58
   {0, J_10,  K_10,   L_10}, // 59
   {0, J_11,  K_11,   L_11}, // 60
   {0, J_12,  K_12,   L_12}, // 61
   {1, J_6,    K_6,    L_6}, // 62

   {1, D_1,    E_1,    F_1}, // 63
   {1, D_2,    E_2,    F_2}, // 64
   {1, D_3,    E_3,    F_3}, // 65
   {1, D_4,    E_4,    F_4}, // 66
   {1, D_5,    E_5,    F_5}, // 67
   {1, D_6,    E_6,    F_6}, // 68
   {1, D_7,    E_7,    F_7}, // 69
   {1, D_8,    E_8,    F_8}, // 70
   {1, D_9,    E_9,    F_9}, // 71
   {1, D_10,  E_10,   F_10}, // 72
   {1, J_7,    K_7,    L_7}, // 73
   {1, J_8,    K_8,    L_8}, // 74
   {1, J_9,    K_9,    L_9}, // 75

   {1, A_1,    B_1,    C_1}, // 76
   {1, A_2,    B_2,    C_2}, // 77
   {1, A_3,    B_3,    C_3}, // 78
   {1, A_4,    B_4,    C_4}, // 79
   {1, A_5,    B_5,    C_5}, // 80
   {1, A_6,    B_6,    C_6}, // 81
   {1, A_7,    B_7,    C_7}, // 82
   {1, A_8,    B_8,    C_8}, // 83
   {1, A_9,    B_9,    C_9}, // 84
   {1, A_10,  B_10,   C_10}, // 85
   {1, A_11,  B_11,   C_11}  // 86
};

#define __ NO_LED

led_config_t g_led_config = {{
    { 0,  1,  2,  3,  4,  5,  6,  7,  8},
    {16, 17, 18, 19, 20, 21, 22, 23, 24},
    {33, 34, 35, 36, 37, 38, 39, 40, 41},
    {50, 51, 52, 53, 54, 55, 56, 57, 58},
    {63, 64, 65, 66, 72, __, 68, 69, 71},
    {76, 77, 78, 67, 80, __, 79, 70, __},
    { 9, 10, 11, 12, 13, 14, 15, 73, 74},
    {25, 26, 27, 28, 29, 30, 31, 32, 82},
    {42, 43, 44, 45, 46, 75, 48, 49, 83},
    {59, 60, 61, 62, 47, 85, 86, 81, 84}
}, {
    {  0,  0}, //  0
    { 14,  0}, //  1
    { 29,  0}, //  2
    { 44,  0}, //  3
    { 59,  0}, //  4
    { 74,  0}, //  5
    { 89,  0}, //  6
    {104,  0}, //  7
    {119,  0}, //  8
    {134,  0}, //  9
    {149,  0}, // 10
    {164,  0}, // 11
    {179,  0}, // 12
    {194,  0}, // 13
    {209,  0}, // 14
    {224,  0}, // 15

    {  0, 12}, // 16
    { 14, 12}, // 17
    { 28, 12}, // 18
    { 42, 12}, // 19
    { 56, 12}, // 20
    { 70, 12}, // 21
    { 84, 12}, // 22
    { 98, 12}, // 23
    {112, 12}, // 24
    {126, 12}, // 25
    {140, 12}, // 26
    {154, 12}, // 27
    {168, 12}, // 28
    {182, 12}, // 29
    {196, 12}, // 30
    {210, 12}, // 31
    {224, 12}, // 32

    {  0, 25}, // 33
    { 14, 25}, // 34
    { 28, 25}, // 35
    { 42, 25}, // 36
    { 56, 25}, // 37
    { 70, 25}, // 38
    { 84, 25}, // 39
    { 98, 25}, // 40
    {112, 25}, // 41
    {126, 25}, // 42
    {140, 25}, // 43
    {154, 25}, // 44
    {168, 25}, // 45
    {182, 25}, // 46
    {196, 25}, // 47
    {210, 25}, // 48
    {224, 25}, // 49

    {  0, 38}, // 50
    { 18, 38}, // 51
    { 37, 38}, // 52
    { 56, 38}, // 53
    { 74, 38}, // 54
    { 93, 38}, // 55
    {112, 38}, // 56
    {130, 38}, // 57
    {149, 38}, // 58
    {168, 38}, // 59
    {186, 38}, // 60
    {205, 38}, // 61
    {224, 38}, // 62

    {  0, 51}, // 63
    { 18, 51}, // 64
    { 37, 51}, // 65
    { 56, 51}, // 66
    { 74, 51}, // 67
    { 93, 51}, // 68
    {112, 51}, // 69
    {130, 51}, // 70
    {149, 51}, // 71
    {168, 51}, // 72
    {186, 51}, // 73
    {205, 51}, // 74
    {224, 51}, // 75

    {  0, 64}, // 76
    { 22, 64}, // 77
    { 44, 64}, // 78
    { 67, 64}, // 79
    { 89, 64}, // 80
    {112, 64}, // 81
    {134, 64}, // 82
    {156, 64}, // 83
    {179, 64}, // 84
    {201, 64}, // 85
    {224, 64}  // 86
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
}};

// clang-format on
#endif

void led_init_ports(void) {
    // Set our LED pins as output
    setPinOutput(A15); // LED1 Num Lock
    writePinHigh(A15);
    setPinOutput(C10); // LED2 Scroll Lock
    writePinHigh(C10);
    setPinOutput(C11); // LED3 Caps Lock
    writePinHigh(C11);
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        writePin(A15, !led_state.num_lock);
        writePin(C10, !led_state.scroll_lock);
        writePin(C11, !led_state.caps_lock);
    }
    return res;
}

void restart_usb_driver(USBDriver *usbp) {
    // Do nothing. Restarting the USB driver on these boards breaks it.
}

#ifdef ENABLE_CUSTOM_KEY

enum custom_keycodes {
  BT_DEV1 = USER00,
  BT_DEV2,
  BT_DEV3,
  BT_2_4G,
  VIA_RST,
  EE_RST,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VIA_RST: {
      if (record->event.pressed) {
#ifdef VIA_ENABLE
        #include "via.h"
        via_eeprom_set_valid(false);
        eeconfig_init_via();
#endif
      }
      break;
    }
    case EE_RST: {
      eeconfig_disable();
      break;
    }
    default: {
      return true;
    }
  }

  return false;
}

#endif /* ENABLE_CUSTOM_KEY */
