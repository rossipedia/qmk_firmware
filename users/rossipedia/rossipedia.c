#include QMK_KEYBOARD_H
#include "rossipedia.h"

#ifdef TAP_DANCE_ENABLE
// Tap Dance Array
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_OPT_SPACE] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LALT(KC_SPC))
};
#endif

