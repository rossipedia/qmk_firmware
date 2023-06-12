// Copyright 2022 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "rossipedia.h"
#include "print.h"

enum s75_keycodes {
    MD_BOOT = SAFE_RANGE,               //Restart into bootloader after hold timeout
    KC_WIN,
    KC_GAM,
    KC_DBG,
};

enum s75_layers {
    LAYER_BASE = 0,
    LAYER_WINDOWS = 1,
    LAYER_GAMING = 2,
    LAYER_FN = 3
};

#define KC_FN MO(LAYER_FN)

#define TOGGLE_FLAG_AND_PRINT(var, name) { \
        if (var) { \
            dprintf(name " disabled\r\n"); \
            var = !var; \
        } else { \
            var = !var; \
            dprintf(name " enabled\r\n"); \
        } \
    }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐┌───┐
     * │Esc││F1 │F2 │F3 │F4 ││F5 │F6 │F7 │F8 ││F9 │F10│F11│F12││PSc││   │
     * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┴└───┴───┴───┴───┘└───┘└───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐┌───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp││Del│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤├───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  ││PgU│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤├───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter ││PgD│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┘└───┘
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│┌───┐
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┘│ ↑ │
     * │Ctrl│GUI │Alt │                        │Alt│GUI│Ctl│┌───┼───┼───┐
     * └────┴────┴────┴────────────────────────┴───┴───┴───┘│ ← │ ↓ │ → │
     *                                                      └───┴───┴───┘
     */
    [LAYER_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_FN,   KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_FN,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [LAYER_WINDOWS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, KC_LGUI, KC_LALT,                            _______,                            KC_RALT, _______, _______, _______, _______, _______
    ),
    [LAYER_GAMING] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [LAYER_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPLY,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          EE_CLR,
        _______, _______, KC_WIN,  _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR, KC_SCRL, KC_PAUS,          KC_HOME,
        _______, _______, _______, KC_DBG,  _______, KC_GAM,  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,          _______,          KC_END,
        _______,          RGB_VAI, RGB_SAI, RGB_HUI, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______,          _______, KC_PGUP,
        _______, _______, _______,                            RGB_TOG,                            _______, _______, _______, KC_HOME, KC_PGDN, KC_END
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_WINDOWS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_GAMING] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_FN] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif

const uint8_t LAYER_HUE_SATS[][2] = {
    [LAYER_BASE] = {32,207},
    [LAYER_WINDOWS] = {16, 255}, // Orange
    [LAYER_GAMING] = {0, 255}, // Red
};

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t active_layer = biton32(state);
    dprintf("Current layer: %u\n", active_layer);

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
        case KC_WIN:
            if (record->event.pressed) {
              layer_invert(LAYER_WINDOWS);
              layer_off(LAYER_GAMING);
            }
            return false;
        case KC_GAM:
            if (record->event.pressed) {
              layer_on(LAYER_WINDOWS);
              layer_invert(LAYER_GAMING);
            }
            return false;
        case KC_DBG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }

    if (debug_enable) {
        if (debug_matrix) {
            matrix_print();
        }
    }
}
