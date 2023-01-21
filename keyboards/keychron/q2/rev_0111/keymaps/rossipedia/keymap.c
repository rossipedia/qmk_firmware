/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "print.h"

enum layers{
    LAYER_BASE = 0,
    LAYER_WINDOWS = 1,
    LAYER_FN = 2,
};

enum custom_keycodes {
    MD_BOOT = SAFE_RANGE,
    MD_DBG,
};

#define KC_FN MO(LAYER_FN)

/*#define KC_WAVE S(KC_GRV)*/
/*#define KC_TASK LGUI(KC_TAB)*/
/*#define KC_FLXP LGUI(KC_E)*/
/*#define KC_MCTL KC_MISSION_CONTROL*/
/*#define KC_LPAD KC_LAUNCHPAD*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,           KC_UP,
        KC_FN,   KC_LOPT, KC_LCMD,                            KC_SPC,                             KC_RCMD, KC_FN,    KC_FN,    KC_LEFT, KC_DOWN, KC_RGHT),

    [LAYER_WINDOWS] = LAYOUT_ansi_67(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,           _______,
        _______, KC_LGUI, KC_LALT,                            _______,                            KC_RALT, _______,  _______,  _______, _______, _______),

    [LAYER_FN] = LAYOUT_ansi_67(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    _______,          _______,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR,  KC_SLCK,   KC_PAUS,          KC_INS,
        _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,             _______,          MD_DBG,
        _______, _______, _______, _______, _______, MD_BOOT, _______, _______, _______, _______, _______,           _______,            KC_PGUP,
        _______, _______, _______,                            RGB_TOG,                            _______, _______,  _______,   KC_HOME, KC_PGDN, KC_END )

    /*[LAYER_FN3] = LAYOUT_ansi_67(*/
        /*KC_WAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    _______,          _______,*/
        /*RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,   _______,          _______,*/
        /*_______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,             _______,          _______,*/
        /*_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,*/
        /*_______, _______, _______,                            _______,                            _______, _______,  _______,   _______, _______, _______)*/
};


const uint8_t LAYER_HUE_SATS[][2] = {
    [LAYER_BASE] = {16,207},
    [LAYER_WINDOWS] = {8, 255}, // Orange
    /*[LAYER_GAMING] = {0, 255}, // Red*/
};

 layer_state_t default_layer_state_set_user(layer_state_t state) {
     uint32_t active_layer = biton32(state);
     dprintf("Default layer: %d\n", active_layer);

     if (active_layer < LAYER_FN) {
         rgb_matrix_sethsv(
             LAYER_HUE_SATS[active_layer][0],
             LAYER_HUE_SATS[active_layer][1],
             rgb_matrix_get_val()
         );
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
        case MD_DBG:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    debug_enable=!debug_enable;
                    dprintf("Debug enabled: %u\n", debug_enable);
                }
            }
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}
