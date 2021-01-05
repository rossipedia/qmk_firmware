#include QMK_KEYBOARD_H
#include "rossipedia.h"

enum alt_keycodes {
    MD_BOOT = SAFE_RANGE,               //Restart into bootloader after hold timeout
    KC_WIN,
    KC_GAM
};

enum alt_layers {
    LAYER_BASE = 0,
    LAYER_WINDOWS = 1,
    LAYER_GAMING = 2,
    LAYER_FN = 3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_ESC,  KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(LAYER_FN),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [LAYER_WINDOWS] = LAYOUT_65_ansi_blocker(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, KC_LGUI, KC_LALT,                            _______,                            KC_LALT, _______, _______, _______, _______  \
    ),
    [LAYER_GAMING] = LAYOUT_65_ansi_blocker(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [LAYER_FN] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_INS,  \
        _______, _______, KC_WIN,  _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_MUTE,\
        _______, _______, _______, _______, _______, KC_GAM,  _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, _______, _______, _______, _______, MD_BOOT, _______, _______, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    )
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

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
        default:
            return true; //Process all other keycodes normally
    }
}
