
// Common defines
#define CTL_ESC CTL_T(KC_ESC)
#define RS_ENTR RSFT_T(KC_ENT)
#define OSM_GA OSM(MOD_LGUI | MOD_LALT)
#define LWR_SFT LM(_LOWER, MOD_LSFT)


#ifdef TAP_DANCE_ENABLE

// Opt Space when double tapping LGUI
#define TD_OSPC TD(TD_OPT_SPACE)
enum {
    TD_OPT_SPACE = 0
};

tap_dance_action_t tap_dance_actions[1];

#endif
