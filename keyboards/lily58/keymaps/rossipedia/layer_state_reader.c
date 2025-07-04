#include QMK_KEYBOARD_H
#include <stdio.h>
// #include "lily58.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_GAMING (1 << 1)
#define L_LOWER (1 << 2)
#define L_RAISE (1 << 3)
#define L_ADJUST (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  // Base layers
  switch (layer_state) {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    return layer_state_str;
  case L_GAMING:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Gaming");
    return layer_state_str;
  }

  // layer mods, check against shifted layers only
  switch (layer_state & ~(L_BASE | L_GAMING))
  {
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
  }

  return layer_state_str;
}
