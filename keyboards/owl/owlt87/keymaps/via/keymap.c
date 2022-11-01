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

#include QMK_KEYBOARD_H
#include "custom_key.h"

enum layers{
    WIN_BASE,
    WIN_FN,
    MAC_BASE,
    MAC_FN
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_BASE] = LAYOUT( /* Base */
        KC_ESC,   KC_F1,        KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,    KC_F12,               KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,   KC_1,         KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,   KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,         KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_LBRC,   KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,         KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN, KC_QUOT,   KC_ENT,
        KC_LSFT,  KC_Z,         KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,                                   KC_UP,
        KC_LCTL,  KC_LGUI,      KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_APP,     KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [WIN_FN] = LAYOUT( /* FN */
        QK_BOOT,  KC_BRID,      KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,              _______,  _______,  _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_VAD,  RGB_VAI,    _______,  _______,  _______,  _______,
        _______,  _______,      KC_RPDIR, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                                  RGB_TOG,
        _______,  TO(MAC_BASE), _______,                                _______,                                _______,  _______,  _______,    _______, RGB_RMOD,  RGB_TOG,  RGB_MOD),

    [MAC_BASE] = LAYOUT( /* Base */
        KC_ESC,   KC_BRID,      KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,              KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,         KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,         KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,         KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
        KC_LSFT,  KC_Z,         KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                                  KC_UP,
        KC_LCTL,  KC_LOPTN,     KC_LCMMD,                               KC_SPC,                                 KC_ROPTN, MO(MAC_FN), KC_RCMMD, KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT( /* FN */
        QK_BOOT,  KC_F1,        KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,               _______,  _______,  RGB_TOG,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_VAI,      KC_RPDIR, RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  RGB_VAD,      RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,  _______,      _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,                                  RGB_TOG,
        _______,  TO(WIN_BASE), _______,                               _______,                                _______,  _______,  _______,    _______,  RGB_RMOD, RGB_TOG,  RGB_MOD)
};
// clang-format on

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {

    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }

    if (layer_state_is(WIN_BASE) | layer_state_is(WIN_FN)) {
        rgb_matrix_set_color(77, RGB_WHITE);
    } else if (layer_state_is(MAC_BASE) | layer_state_is(MAC_FN)) {
        rgb_matrix_set_color(78, RGB_WHITE);
    }

    return true;
}

void housekeeping_task_user(void) {
    housekeeping_task_custom();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {

    if (!process_record_custom(keycode, record)) {
        return false;
    }
    if (!process_record_user(keycode, record)) {
        return false;
    }

    return true;
}
