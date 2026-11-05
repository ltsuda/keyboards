// Iris CE Rev.1 - 7-layer macOS/Windows keymap
// Copyright: MIT
//
// L0 _MAC_BASE   macOS base (pinky=Cmd, thumb=Ctrl, 2nd Cmd/Ctrl on right outer keys)
// L1 _MAC_SYM    macOS symbols
// L2 _MAC_NAV    macOS nav/Apple row (macOS "Use F-keys as standard function keys" = OFF)
// L3 _WIN_BASE   Windows base (pinky=Ctrl, thumb=Win/GUI, 2nd Win/GUI + Ctrl on right outer keys)
// L4 _WIN_SYM    Windows symbols
// L5 _WIN_NAV    Windows nav/F-row (Win/Ctrl order, 2nd Win/GUI + Ctrl on right outer keys,
//                  PrintScreen in the spare slot)
// L6 _SETTINGS   Settings (QK_BOOT/DB_TOGG/EEPROM-clear/RGB), entered by holding MO13+MO23
//                  (tri-layer), from either OS side.
//
// FN keys: _MAC_* -> MO(L1)/MO(L2), _WIN_* -> MO(L4)/MO(L5). Settings layer keeps KC_TRNS.
// OS toggle: OS_TOG (QK_KB_0) = top-right key on the TWO BASE LAYERS ONLY. Press flips the
//   DEFAULT layer between _MAC_BASE and _WIN_BASE (via default_layer_set in process_record_user).
//   Symbols/Nav/Settings are per-OS and entered from their base layer; toggling OS underneath
//   a held sublayer would produce a broken mixed macOS/Windows state.
//   Press once = flip OS; Esc on L0/L3 is a plain KC_ESC; Backspace exists ONLY above Space.
//   Top-right on L1/L4/L6 = KC_NO. _MAC_NAV top-right = Cmd+Shift+4 (screenshot), _WIN_NAV
//   top-right = PrintScreen. Mission Control (KC_MCTL) stays on _MAC_NAV's spare slot.
// RGB indicator: red = macOS side, blue = Windows side, magenta = Settings.
//   NOTE: this board has RGB MATRIX (no rgblight). Hues are applied as the *base* hue,
//   so for a clearly visible indicator pick a hue-respecting effect such as
//   "Gradient Left/Right", "Gradient Up/Down" or "Reactive Simple" in the Settings layer.
//   Hue-cycling effects (Cycle All, Rainbow Pinwheels...) will override it.
//
// BUILD: keyboards/keebio/iris_ce/rev1/keymaps/ltsuda/
//   rules.mk must contain: TRI_LAYER_ENABLE = yes (tri-layer does nothing without it). DEFAULTS TO WINDOWS on boot; the OS toggle is
//   session-only (default_layer_set, NOT EEPROM). Compile with:
//   qmk compile -kb keebio/iris_ce/rev1 -km ltsuda

#include QMK_KEYBOARD_H

// macOS/Windows chords and OS toggle (kept short to preserve the 8-char cell grid)
#define UNDO   LGUI(KC_Z)        // macOS Cmd+Z
#define CUT    LGUI(KC_X)        // macOS Cmd+X
#define COPY   LGUI(KC_C)        // macOS Cmd+C
#define PASTE  LGUI(KC_V)        // macOS Cmd+V
#define WUNDO  LCTL(KC_Z)        // Windows Ctrl+Z
#define WCUT   LCTL(KC_X)        // Windows Ctrl+X
#define WCOPY  LCTL(KC_C)        // Windows Ctrl+C
#define WPASTE LCTL(KC_V)        // Windows Ctrl+V
#define SHOT   LGUI(LSFT(KC_4))  // macOS Cmd+Shift+4 (screenshot)
#define OS_TOG QK_KB_0          // toggle macOS/Windows base (default layer)
// Layer enums
enum layer_names {
    _MAC_BASE,
    _MAC_SYM,
    _MAC_NAV,
    _WIN_BASE,
    _WIN_SYM,
    _WIN_NAV,
    _SETTINGS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC_BASE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    OS_TOG,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RGUI,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCTL,          KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LALT, MO(1),   KC_ENT,                    KC_SPC,  MO(2),   KC_RALT
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
    [_MAC_SYM] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, KC_GRV,                            KC_PIPE, KC_LT,   KC_GT,   KC_PPLS, KC_EQL,  KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LGUI, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RGUI,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_COLN, KC_SCLN, KC_LBRC, KC_RBRC, KC_SLSH, KC_LCTL,          KC_BSPC, KC_BSLS, KC_DQUO, KC_COMM, KC_DOT,  KC_QUOT, KC_RCTL,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LALT, MO(1),   KC_ENT,                    KC_SPC,  MO(2),   KC_RALT
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
    [_MAC_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  SHOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_F11,  KC_UP,   KC_F12,  KC_NO,   KC_MCTL,                           KC_NO,   UNDO,    CUT,     COPY,    PASTE,   KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LGUI, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_CAPS,                           KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RGUI,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LCTL,          KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RCTL,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LALT, MO(1),   KC_ENT,                    KC_SPC,  MO(2),   KC_RALT
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
    [_WIN_BASE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    OS_TOG,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RGUI,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,          KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LALT, MO(4),   KC_ENT,                    KC_SPC,  MO(5),   KC_RALT
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
    [_WIN_SYM] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, KC_GRV,                            KC_PIPE, KC_LT,   KC_GT,   KC_PPLS, KC_EQL,  KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RGUI,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_COLN, KC_SCLN, KC_LBRC, KC_RBRC, KC_SLSH, KC_LGUI,          KC_BSPC, KC_BSLS, KC_DQUO, KC_COMM, KC_DOT,  KC_QUOT, KC_RCTL,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LALT, MO(4),   KC_ENT,                    KC_SPC,  MO(5),   KC_RALT
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
    [_WIN_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_F11,  KC_UP,   KC_F12,  KC_NO,   KC_MYCM,                           KC_NO,   WUNDO,   WCUT,    WCOPY,   WPASTE,  KC_DEL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_CAPS,                           KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RGUI,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LGUI,          KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RCTL,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LALT, MO(4),   KC_ENT,                    KC_SPC,  MO(5),   KC_RALT
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
    [_SETTINGS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       EE_CLR,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDD,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       DB_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,   RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDU,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_NO,   KC_TRNS, KC_NO,                     KC_NO,   KC_TRNS, KC_NO
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};

// RGB OS indicator (red = macOS side, blue = Windows side, magenta = Settings).
// NOTE: this board has RGB MATRIX (no rgblight). Hues are applied as the *base* hue,
// so for a clearly visible indicator pick a hue-respecting effect such as
// "Gradient Left/Right", "Gradient Up/Down" or "Reactive Simple" in the Settings layer.
// Hue-cycling effects (Cycle All, Rainbow Pinwheels...) will override it.
static void set_os_indicator(layer_state_t state) {
#if defined(RGBLIGHT_ENABLE)
    switch (get_highest_layer(state)) {
        case _MAC_BASE:
        case _MAC_SYM:
        case _MAC_NAV:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _WIN_BASE:
        case _WIN_SYM:
        case _WIN_NAV:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _SETTINGS:
        default:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
    }
#elif defined(RGB_MATRIX_ENABLE)
    switch (get_highest_layer(state)) {
        case _MAC_BASE:
        case _MAC_SYM:
        case _MAC_NAV:
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            break;
        case _WIN_BASE:
        case _WIN_SYM:
        case _WIN_NAV:
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
        case _SETTINGS:
        default:
            rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
            break;
    }
#endif
}

// Tri-layer (hand-rolled): L1+L2 (macOS FNs) OR L4+L5 (Windows FNs) -> L6 (Settings).
// NOTE: update_tri_layer_state() CLEARS the adjust layer when its pair is not fully held,
// so two independent pairs cannot share one adjust layer — it must be computed once.
static const layer_state_t mac_pair = ((1UL << _MAC_SYM) | (1UL << _MAC_NAV));
static const layer_state_t win_pair = ((1UL << _WIN_SYM) | (1UL << _WIN_NAV));

layer_state_t layer_state_set_user(layer_state_t state) {
    if ((state & mac_pair) == mac_pair || (state & win_pair) == win_pair)
        state |=  (1UL << _SETTINGS);
    else
        state &= ~(1UL << _SETTINGS);
    // NOTE: `layer_state` excludes the DEFAULT layer; the indicator needs both,
    // otherwise an idle keyboard resolves to bit0 == _MAC_BASE (red).
    set_os_indicator(state | default_layer_state);
    return state;
}

// Called on EVERY default-layer change (boot, and our OS_TOG flip in process_record_user).
layer_state_t default_layer_state_set_user(layer_state_t state) {
    set_os_indicator(state | layer_state);
    return state;
}

// OS toggle: flip the default layer between macOS and Windows base.
// QK_KB_0 = keyboard-specific user keycode (top-right key on L0/L3).
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == OS_TOG && record->event.pressed) {
        default_layer_set(default_layer_state ^ ((1UL << _MAC_BASE) | (1UL << _WIN_BASE)));
        return false;
    }
    return true;
}

// Boot into Windows (most common host); toggle is session-only.
// RGB effect is FORCED to ALPHAS_MODS on every boot (ignores EEPROM-stored mode).
// Change freely in Settings; it reverts to ALPHAS_MODS at the next boot.
void keyboard_post_init_user(void) {
    default_layer_set(1UL << _WIN_BASE);  // triggers default_layer_state_set_user() (RGB)
    rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
}
