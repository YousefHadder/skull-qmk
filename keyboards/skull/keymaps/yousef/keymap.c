// Copyright 2024 Yousef Hadder
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Skull keyboard keymap - ported from Ferris Sweep ZMK configuration
// Features:
// - Home row mods on top row (QWERTY positions)
// - 5 layers: Base, Media/Nav, Numbers, Symbols, Right-hand mods
// - Combos for brackets/braces/parens

#include QMK_KEYBOARD_H
#include "transactions.h"
#include "color.h"

// Layer definitions
enum layers {
    _BASE = 0,
    _MEDIA_NAV,
    _NUMBERS,
    _SYMBOLS,
    _RMOD
};

// Hyper key (Ctrl+Shift+Alt+Cmd)
#define HYPER LCTL(LSFT(LALT(LGUI(KC_NO))))
#define MT_HYPR_ESC MT(MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI, KC_ESC)

// Home row mods - top row (matching ZMK mt_repeat behavior)
// Left hand
#define HM_Q LALT_T(KC_Q)
#define HM_W LSFT_T(KC_W)
#define HM_E LCTL_T(KC_E)
#define HM_R LGUI_T(KC_R)

// Right hand
#define HM_U RGUI_T(KC_U)
#define HM_I RCTL_T(KC_I)
#define HM_O RSFT_T(KC_O)
#define HM_P RALT_T(KC_P)

// Layer-tap keys
#define LT_Z LT(_MEDIA_NAV, KC_Z)
#define LT_SCLN LT(_RMOD, KC_SCLN)
#define LT_BSPC LT(_NUMBERS, KC_BSPC)
#define LT_SPC LT(_SYMBOLS, KC_SPC)

// Rectangle window management shortcuts (macOS)
#define RECT_FL LALT(LCTL(KC_F))      // Fullscreen
#define RECT_LH LALT(LCTL(KC_LEFT))   // Left half
#define RECT_RH LALT(LCTL(KC_RIGHT))  // Right half
#define RECT_TH LALT(LCTL(KC_UP))     // Top half
#define RECT_BH LALT(LCTL(KC_DOWN))   // Bottom half
#define RECT_EN LALT(LCTL(KC_ENT))    // Enter (maximize)
#define RECT_MV LALT(LCTL(LGUI(KC_LEFT))) // Move to display
#define RECT_CE LALT(LCTL(KC_C))      // Center

// Note: Combos are configured via Vial GUI
// Suggested combos to configure in Vial:
// - Caps Lock: Both thumb keys (positions 30+33)
// - Left Paren: R+T (positions 3+4)
// - Right Paren: Y+U (positions 5+6)
// - Left Bracket: F+G (positions 13+14)
// - Right Bracket: H+J (positions 15+16)
// - Left Brace: V+B (positions 23+24)
// - Right Brace: N+M (positions 25+26)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layer 0: Base (QWERTY with home row mods on top row)
     *
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │Q/Alt│W/Sft│E/Ctl│R/Gui│  T  │       │  Y  │U/Gui│I/Ctl│O/Sft│P/Alt│
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │;/L4 │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │Z/L1 │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │  /  │
     * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
     *                   ┌─────┐                   ┌─────┐
     *                   │Bs/L2├─────┐       ┌─────┤Sp/L3│
     *                   └─────┤Esc/H│       │ Ent ├─────┘
     *                         └─────┘       └─────┘
     */
    [_BASE] = LAYOUT_split_3x5_2(
        HM_Q,    HM_W,    HM_E,    HM_R,    KC_T,                               KC_Y,    HM_U,    HM_I,    HM_O,    HM_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    LT_SCLN,
        LT_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                            LT_BSPC, MT_HYPR_ESC,     KC_ENT,   LT_SPC
    ),

    /*
     * Layer 1: Media/Navigation (accessed via Z hold)
     *
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │Bri- │Bri+ │Prev │Play │Next │       │Vol- │Mute │Vol+ │     │  \  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │RectF│     │       │ ←   │  ↓  │  ↑  │  →  │  '  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │█████│Shift│RectC│     │     │       │RctLH│RctBH│RctTH│RctRH│  `  │
     * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
     *                   ┌─────┐                   ┌─────┐
     *                   │     ├─────┐       ┌─────┤RctMV│
     *                   └─────┤Space│       │RctEN├─────┘
     *                         └─────┘       └─────┘
     */
    [_MEDIA_NAV] = LAYOUT_split_3x5_2(
        KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT,                            KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, RECT_FL, XXXXXXX,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
        _______, KC_LSFT, RECT_CE, _______, _______,                            RECT_LH, RECT_BH, RECT_TH, RECT_RH, KC_GRV,
                                            _______, KC_SPC,          RECT_EN,  RECT_MV
    ),

    /*
     * Layer 2: Numbers (accessed via Backspace hold)
     *
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  1  │2/Sft│3/Ctl│4/Gui│  5  │       │  6  │7/Gui│8/Ctl│9/Sft│  0  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │  =  │  -  │  '  │Ctl+B│     │       │     │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │ MO1 │     │     │     │     │       │     │     │  ,  │  .  │     │
     * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
     *                   ┌─────┐                   ┌─────┐
     *                   │█████├─────┐       ┌─────┤RAlt │
     *                   └─────┤Space│       │ Ent ├─────┘
     *                         └─────┘       └─────┘
     */
    [_NUMBERS] = LAYOUT_split_3x5_2(
        KC_1,    LSFT_T(KC_2), LCTL_T(KC_3), LGUI_T(KC_4), KC_5,                KC_6,    RGUI_T(KC_7), RCTL_T(KC_8), RSFT_T(KC_9), KC_0,
        KC_EQL,  KC_MINS,      KC_QUOT,      LGUI(KC_B),   _______,             XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        MO(_MEDIA_NAV), _______, _______,    _______,      _______,             XXXXXXX, XXXXXXX,      KC_COMM,      KC_DOT,       XXXXXXX,
                                             _______,      KC_SPC,     KC_ENT,  KC_RALT
    ),

    /*
     * Layer 3: Symbols (accessed via Space hold)
     *
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │  !  │  @  │  #  │  $  │  %  │       │  ^  │  &  │  *  │  (  │  -  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │     │     │  {  │  [  │  (  │       │  )  │  ]  │  }  │     │  =  │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │BT 0 │BT 1 │BT 2 │BT 3 │BT 4 │       │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
     *                   ┌─────┐                   ┌─────┐
     *                   │     ├─────┐       ┌─────┤█████│
     *                   └─────┤     │       │     ├─────┘
     *                         └─────┘       └─────┘
     *
     * Note: BT keys are placeholders - Skull is wired, not wireless
     */
    [_SYMBOLS] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_MINS,
        XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN,                            KC_RPRN, KC_RBRC, KC_RCBR, XXXXXXX, KC_EQL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, _______, _______, _______, XXXXXXX,
                                            XXXXXXX, _______,         _______,  _______
    ),

    /*
     * Layer 4: Right-hand mods (accessed via ; hold)
     *
     * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
     * │ Tab │     │     │     │     │       │     │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │       │     │ Cmd │ Ctl │Shift│█████│
     * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │       │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
     *                   ┌─────┐                   ┌─────┐
     *                   │     ├─────┐       ┌─────┤     │
     *                   └─────┤     │       │     ├─────┘
     *                         └─────┘       └─────┘
     */
    [_RMOD] = LAYOUT_split_3x5_2(
        KC_TAB,  _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, KC_RGUI, KC_RCTL, KC_RSFT, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
                                            _______, _______,         _______,  _______
    )
};
// clang-format on

// Eye RGB configuration (from original Skull firmware)
typedef union eyergb_config_t {
    uint32_t raw;
    struct {
        bool    enable : 1;
        uint8_t hue : 8;
        uint8_t sat : 8;
        uint8_t val : 8;
    };
} eyergb_config_t;

eyergb_config_t user_eyeconfig = {
    .enable = true,
    .hue = 8,
    .sat = 255,
    .val = 255
};

void set_eyehsv(bool enable, uint8_t hue, uint8_t sat, uint8_t val) {
    if (user_eyeconfig.enable) {
        hsv_t hsv = {hue, sat, val};
        rgb_t colour = hsv_to_rgb(hsv);
        for (uint8_t i = 10; i < 13; i++) {
            rgblight_driver.set_color(i, colour.r, colour.g, colour.b);
        }
    } else {
        for (uint8_t i = 10; i < 13; i++) {
            rgblight_driver.set_color(i, 0, 0, 0);
        }
    }
    rgblight_driver.flush();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EY_TOGG:
        if (record->event.pressed) {
            user_eyeconfig.enable = !user_eyeconfig.enable;
            set_eyehsv(user_eyeconfig.enable, user_eyeconfig.hue, user_eyeconfig.sat, user_eyeconfig.val);
        }
        break;
    case EY_HUE:
        if (record->event.pressed) {
            user_eyeconfig.hue = user_eyeconfig.hue + RGBLIGHT_HUE_STEP;
            set_eyehsv(user_eyeconfig.enable, user_eyeconfig.hue, user_eyeconfig.sat, user_eyeconfig.val);
        }
        break;
    case EY_SAT:
        if (record->event.pressed) {
            user_eyeconfig.sat = user_eyeconfig.sat + RGBLIGHT_SAT_STEP;
            set_eyehsv(user_eyeconfig.enable, user_eyeconfig.hue, user_eyeconfig.sat, user_eyeconfig.val);
        }
        break;
    case EY_VAL:
        if (record->event.pressed) {
            user_eyeconfig.val = user_eyeconfig.val + RGBLIGHT_VAL_STEP;
            set_eyehsv(user_eyeconfig.enable, user_eyeconfig.hue, user_eyeconfig.sat, user_eyeconfig.val);
        }
        break;
    }
    return true;
}

void user_sync_eyehsv_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const eyergb_config_t *m2s = (const eyergb_config_t*)in_data;

    if (user_eyeconfig.raw != m2s->raw) {
        user_eyeconfig.raw = m2s->raw;
        set_eyehsv(user_eyeconfig.enable, user_eyeconfig.hue, user_eyeconfig.sat, user_eyeconfig.val);
    }
}

void eeconfig_init_user(void) {
    user_eyeconfig.raw = 0;
    user_eyeconfig.enable = 1;
    user_eyeconfig.hue = 0;
    user_eyeconfig.sat = 255;
    user_eyeconfig.val = 255;

    eeconfig_update_user(user_eyeconfig.raw);
    set_eyehsv(user_eyeconfig.enable, user_eyeconfig.hue, user_eyeconfig.sat, user_eyeconfig.val);
}

void keyboard_post_init_user(void) {
    user_eyeconfig.raw = eeconfig_read_user();
    if (is_keyboard_left()) {
        rgblight_set_effect_range(0, 10);
    } else {
        rgblight_set_effect_range(13, 10);
    }
    transaction_register_rpc(USER_SYNC_A, user_sync_eyehsv_handler);
    set_eyehsv(user_eyeconfig.enable, user_eyeconfig.hue, user_eyeconfig.sat, user_eyeconfig.val);
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 100) {
            if (transaction_rpc_send(USER_SYNC_A, sizeof(user_eyeconfig), &user_eyeconfig)) {
                last_sync = timer_read32();
            }
        }
    }

    static uint32_t eeprom_sync = 0;
    if (timer_elapsed32(eeprom_sync) > 10000) {
        uint32_t raw = eeconfig_read_user();
        if (raw != user_eyeconfig.raw) {
            raw = user_eyeconfig.raw;
            eeconfig_update_user(raw);
        }
    }
}
