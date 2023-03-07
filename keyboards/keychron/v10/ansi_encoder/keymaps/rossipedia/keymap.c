/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "rossipedia.h"

// clang-format off


enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_GAME,
    WIN_FN
};

enum v10_keycodes {
    MD_BOOT = SAFE_RANGE,               //Restart into bootloader after hold timeout
    KC_GAM,
    KC_DBG,
};


#define KC_FN_M MO(MAC_FN)
#define KC_FN_W MO(WIN_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     _______,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_FN_M,  KC_LOPT,            KC_LCMD,  KC_SPC,   _______,                       KC_SPC,             KC_RCMD,                      KC_LEFT,  KC_DOWN,  KC_RGHT),


    [MAC_FN] = LAYOUT_ansi_89(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  KC_PSCR,  KC_SCRL,  KC_PAUS,            _______,
        _______,  _______,  _______,  _______,  KC_DBG,   _______,  _______,   _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   MD_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,
        _______,  _______,  _______,            _______,  RGB_TOG,  _______,                       _______,            _______,                      KC_HOME,  KC_PGDN,  KC_END ),


    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     _______,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_FN_W,  KC_LWIN,            KC_LALT,  KC_SPC,   _______,                       KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_GAME] = LAYOUT_ansi_89(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  KC_LCTL,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  _______,  _______),


    [WIN_FN] = LAYOUT_ansi_89(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  KC_PSCR,  KC_SCRL,  KC_PAUS,            _______,
        _______,  _______,  _______,  _______,  KC_DBG,   _______,  _______,   _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   MD_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,
        _______,  _______,  _______,            _______,  RGB_TOG,  _______,                       _______,            _______,                      KC_HOME,  KC_PGDN,  KC_END )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_GAME] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif  //ENCODER_MAP_ENABLE


const uint8_t LAYER_HUE_SATS[][2] = {
    [MAC_BASE] = {32,207},
    [MAC_FN]   = {0,0},
    [WIN_BASE] = {16, 255},
    [WIN_GAME] = {0, 255},
    [WIN_FN]   = {0,0}
};

layer_state_t layer_state_set_user(layer_state_t state) {
    uint32_t layer = get_highest_layer(state);


    switch (layer) {
        case MAC_BASE:
        case WIN_BASE:
        case WIN_GAME:
            rgb_matrix_sethsv(
                LAYER_HUE_SATS[layer][0],
                LAYER_HUE_SATS[layer][1],
                rgb_matrix_get_val()
            );
            break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }

    if (debug_enable) {
        if (debug_matrix) {
            matrix_print();
        }
    }
}
