/*
Copyright 2019 @foostan
Copyright2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "features/caps_word.h"
#include "features/repeat.h"
#include "keycodes.h"
#include "combos.h"

#ifdef OLED_ENABLE
#    include "features/gfx.h"
#endif // OLED_ENABLE

// Layers
enum layers { BASE, SYMS, NUMS, NAV };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LPRN,     H_A,     H_R,     H_S,     H_T,    KC_G,                         KC_M,     H_N,     H_E,     H_I,     H_O, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LBRC,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            T_TAB,   T_ESC,   T_SPC,     T_BSPC,     REP,   T_ENT
                                      //`--------------------------'  `--------------------------'

  ),

  [SYMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_QUOT,   KC_LT,   KC_GT, KC_DQUO, KC_AMPR,                        SCOPE,  KC_DOT, KC_LCBR, KC_RCBR, KC_PERC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_PIPE,                      KC_COLN, KC_HASH, KC_LPRN, KC_RPRN,   KC_AT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_TILD,                       LAMBDA,  KC_DLR, KC_LBRC, KC_RBRC, KC_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_DEL, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,    KC_6,    KC_5,    KC_4, KC_ASTR,                      KC_MINS,   KC_F4,   KC_F5,   KC_F6,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_DOT,    KC_3,    KC_2,    KC_1, KC_UNDS,                      KC_PLUS,   KC_F1,   KC_F2,   KC_F3,  KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_COMM,    KC_9,    KC_8,    KC_7, KC_SLSH,                       KC_EQL,   KC_F7,   KC_F8,   KC_F9,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,    KC_0, _______,    _______,    KC_0, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_H,    KC_J,    KC_K,    KC_L, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      AG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WBAK, KC_HOME,  KC_END, KC_WFWD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void oled_render_master(void) {
    if (keymap_config.swap_lalt_lgui) {
        render_mac_logo(0, 0);
    } else {
        render_windows_logo(0, 0);
    }

    render_luna(0, 13);
}

static void oled_render_slave(void) {
    render_layers(0, 3);
    render_wpm(0, 14);
}

bool oled_task_user(void) {
    luna_bark(caps_word_get());

    if (is_keyboard_master()) {
        oled_render_master();
    } else {
        oled_render_slave();
    }

    return false;
}
#endif // OLED_ENABLE

static void catch_mods(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            keycode = keycode & 0xFF;
            if (keycode == KC_SPC) return; /* don't want to jump and sneak */
            luna_sneak(record->event.pressed);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t layer_timer = 0;

    if (!process_caps_word(keycode, record)) {
        return false;
    }

    catch_mods(keycode, record);

    // Get the base keycode of a mod or layer tap key
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            keycode = keycode & 0xFF;
    }

    switch (keycode) {
        case KC_SPC:
            if (record->event.pressed) {
                luna_jump();
            }
            break;
        case CAPS:
            if (record->event.pressed) {
                caps_word_set(true);
            }
            return false;
        case REP:
            if (record->event.pressed) {
                layer_timer = timer_read32();
                layer_on(REP_LAYER);
            } else {
                if (timer_elapsed32(layer_timer) < TAPPING_TERM) {
                    tap_repeat_key();
                }
                layer_off(REP_LAYER);
            }
            return false;
        case SCOPE:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
        case LAMBDA:
            if (record->event.pressed) {
                SEND_STRING("lambda ");
            }
            return false;
    }

    if (record->event.pressed) {
        register_repeat_key(keycode);
    }

    return true;
}
