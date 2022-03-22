#pragma once

#include QMK_KEYBOARD_H

/* Custom keys */
enum custom_keycodes {
    CAPS = SAFE_RANGE,
    REP,
    SCOPE,
    LAMBDA,
};

/* Key aliases */
/* Home row mods */
#define H_A LGUI_T(KC_A)
#define H_R LALT_T(KC_R)
#define H_S LSFT_T(KC_S)
#define H_T LCTL_T(KC_T)

#define H_N LCTL_T(KC_N)
#define H_E LSFT_T(KC_E)
#define H_I LALT_T(KC_I)
#define H_O LGUI_T(KC_O)

/* Thumb key mods */
#define T_TAB LT(NAV, KC_TAB)
#define T_ESC LT(NUMS, KC_ESC)
#define T_SPC LT(SYMS, KC_SPC)
#define T_BSPC LT(SYMS, KC_BSPC)
#define REP_LAYER NUMS
#define T_ENT LT(NAV, KC_ENT)
