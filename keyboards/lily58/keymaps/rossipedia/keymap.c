#include QMK_KEYBOARD_H
#include "rossipedia.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _BASE 0
#define _GAMING 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  LOWER,
  RAISE,
  ADJUST
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_BASE] = LAYOUT(
    // +--------+--------+--------+--------+--------+--------+                      +--------+--------+--------+--------+--------+--------+
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    // |--------+--------+--------+--------+--------+--------+--------+    +--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     XXXXXXX,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS_ENTR,
    // +--------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+--------+
                                   KC_LCTL, KC_LALT, TD_OSPC, LOWER,        RAISE,   KC_SPC,  OSM_GA,  XXXXXXX
                               // +--------+--------+--------+--------+    +--------+--------+--------+--------+
 ),
 [_GAMING] = LAYOUT(
    // +--------+--------+--------+--------+--------+--------+                      +--------+--------+--------+--------+--------+--------+
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        KC_LCTL, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    // |--------+--------+--------+--------+--------+--------+--------+    +--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    // +--------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+--------+
                                   KC_ESC,  KC_LALT, KC_SPC,  _______,      _______, _______, KC_RGUI, KC_APP
                               // +--------+--------+--------+--------+    +--------+--------+--------+--------+
 ),
 [_LOWER] = LAYOUT(
    // +--------+--------+--------+--------+--------+--------+                      +--------+--------+--------+--------+--------+--------+
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        RGB_TOG, _______, KC_VOLU, _______, KC_PLUS, KC_INS,                         KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        _______, KC_BRIU, KC_VOLD, _______, KC_UNDS, KC_MINS,                        KC_EQL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
    // |--------+--------+--------+--------+--------+--------+--------+    +--------+--------+--------+--------+--------+--------+--------|
        _______, KC_BRID, KC_MUTE, _______, KC_LCBR, KC_LBRC, _______,      _______, KC_RBRC, KC_RCBR, KC_DEL,  KC_BSPC, _______, _______,
    // +--------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+--------+
                                   _______, _______, _______, _______,      _______, _______, _______, _______
                               // +--------+--------+--------+--------+    +--------+--------+--------+--------+
 ),
 [_RAISE] = LAYOUT(
    // +--------+--------+--------+--------+--------+--------+                      +--------+--------+--------+--------+--------+--------+
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        RGB_TOG, _______, KC_VOLU, _______, KC_PLUS, KC_INS,                         KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        _______, KC_BRIU, KC_VOLD, _______, KC_UNDS, KC_MINS,                        KC_EQL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
    // |--------+--------+--------+--------+--------+--------+--------+    +--------+--------+--------+--------+--------+--------+--------|
        _______, KC_BRID, KC_MUTE, _______, KC_LCBR, KC_LBRC, _______,      _______, KC_RBRC, KC_RCBR, KC_DEL,  KC_BSPC, _______, _______,
    // +--------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+--------+
                                   _______, _______, _______, _______,      _______, _______, _______, _______
                               // +--------+--------+--------+--------+    +--------+--------+--------+--------+
 ),
 [_ADJUST] = LAYOUT(
    // +--------+--------+--------+--------+--------+--------+                      +--------+--------+--------+--------+--------+--------+
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, GAMING,                         _______, _______, _______, _______, _______, _______,
    // |--------+--------+--------+--------+--------+--------+--------+    +--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    // +--------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+--------+
                                   EE_CLR,  _______, _______, _______,      _______, DB_TOGG, _______, QK_RBT
                               // +--------+--------+--------+--------+    +--------+--------+--------+--------+
 )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void set_timelog(void);
const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
  return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
    set_timelog();
  }
#endif

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case GAMING:
        if (record->event.pressed) {
            layer_invert(_GAMING);
        }
        return false;
        break;
  }
  return true;
}
