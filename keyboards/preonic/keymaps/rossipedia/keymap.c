/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

#define CTL_ESC CTL_T(KC_ESC)
#define RS_ENTR RSFT_T(KC_ENT)
#define OSM_GA OSM(MOD_LGUI | MOD_LALT)

enum {
    TD_OPT_SPACE = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_OPT_SPACE] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LALT(KC_SPC))
};

#define TD_OSPC TD(TD_OPT_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_preonic_2x2u( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS_ENTR, \
  //├────────┼────────┼────────┼────────┼─────────────────┼─────────────────┼────────┼────────┼────────┼────────┤
     OSM_GA,  KC_LCTL, KC_LALT, TD_OSPC,       LOWER,            KC_SPC,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  //└────────┴────────┴────────┴────────┴─────────────────┴─────────────────┴────────┴────────┴────────┴────────┘
),

[_LOWER] = LAYOUT_preonic_2x2u( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_VOLU, _______, _______, _______, _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_BRIU, KC_VOLD, _______, _______, KC_MINS, KC_EQL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_BRID, KC_MUTE, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______,     _______,           _______,     _______, _______, _______, _______  \
  //└────────┴────────┴────────┴────────┴─────────────────┴─────────────────┴────────┴────────┴────────┴────────┘
),

[_RAISE] = LAYOUT_preonic_2x2u( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______,     _______,           _______,     _______, _______, _______, _______  \
  //└────────┴────────┴────────┴────────┴─────────────────┴─────────────────┴────────┴────────┴────────┴────────┘
),

[_ADJUST] = LAYOUT_preonic_2x2u( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______,     _______,           _______,     _______, _______, _______, _______  \
  //└────────┴────────┴────────┴────────┴─────────────────┴─────────────────┴────────┴────────┴────────┴────────┘
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BASE:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_BASE);
        }
        return false;
        break;
    case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
