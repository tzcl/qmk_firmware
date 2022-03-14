/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// Custom keys
enum custom_keycodes {
    BSP_DEL = SAFE_RANGE,
    CAPS,
    REP,
};

// Key aliases
#define MOD_A LGUI_T(KC_A)
#define MOD_R LALT_T(KC_R)
#define MOD_S LCTL_T(KC_S)
#define MOD_T LSFT_T(KC_T)
#define MOD_N LSFT_T(KC_N)
#define MOD_E LCTL_T(KC_E)
#define MOD_I LALT_T(KC_I)
#define MOD_O LGUI_T(KC_O)

#define O_LGUI OSM(MOD_LGUI)
#define O_LALT OSM(MOD_LALT)
#define O_LCTL OSM(MOD_LCTL)
#define O_LSFT OSM(MOD_LSFT)

// Combos
enum combos_events {
    CAPS_COMBO,
    NUM_COMBOS,
};
uint16_t COMBO_LEN = NUM_COMBOS;

const uint16_t PROGMEM caps_combo[] = {KC_G, KC_M, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO(caps_combo, CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   MOD_A,   MOD_R,   MOD_S,   MOD_T,    KC_G,                         KC_M,   MOD_N,   MOD_E,   MOD_I,   MOD_O,   TO(1),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TAB,  KC_ESC,  KC_SPC,    BSP_DEL,     REP,  KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_LT,  KC_EQL,   KC_GT, XXXXXXX,                      KC_MINS, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE,   TO(3),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(0), XXXXXXX, KC_LCBR, KC_LPRN, KC_LBRC, KC_UNDS,                      KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, XXXXXXX,   TO(2),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_RCBR, KC_RPRN, KC_RBRC,  KC_EQL,                      KC_SLSH, KC_EXLM,   KC_AT, KC_HASH, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   TO(0), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, KC_ASTR,                      KC_MINS,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(1), XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_UNDS,                      KC_PLUS,    KC_4,    KC_5,    KC_6,    KC_0,   TO(3),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_BRID, XXXXXXX, KC_BRIU,  KC_DOT,                       KC_EQL,    KC_1,    KC_2,    KC_3, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   TO(0), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_WBAK, KC_HOME,  KC_END, KC_WFWD, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TO(2),  O_LGUI,  O_LALT,  O_LCTL,  O_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,   TO(1),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   TO(0), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case L_ADJUST:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to the next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case BSP_DEL:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

// We don't return anything because we always want to keep processing
uint16_t process_repeat_key(uint16_t keycode, keyrecord_t* record) {
    static uint16_t last_keycode = KC_NO;

    if (keycode == REP) {
        if (record->event.pressed) {
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
        }
        return last_keycode;
    }

    // Get the base keycode in case MT or LT
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            keycode = keycode & 0xFF;
            break;
    }

    uint8_t mods = get_mods() | get_oneshot_mods();
    if (mods & MOD_MASK_CTRL) keycode |= QK_LCTL;
    if (mods & MOD_MASK_SHIFT) keycode |= QK_LSFT;
    if (mods & MOD_MASK_GUI) keycode |= QK_LGUI;
    if (mods & MOD_BIT(KC_LALT)) keycode |= QK_LALT;
    if (mods & MOD_BIT(KC_RALT)) keycode |= QK_RALT;

    if (record->event.pressed) {
      last_keycode = keycode;
    }

    return keycode;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) {
        return false;
    }

    keycode = process_repeat_key(keycode, record);

    static uint8_t saved_mods   = 0;

    switch (keycode) {
        case BSP_DEL:
            if (record->event.pressed) {
                saved_mods = get_mods() & MOD_MASK_SHIFT;

                if (saved_mods == MOD_MASK_SHIFT) { /* both shifts pressed */
                    register_code(KC_DEL);
                } else if (saved_mods) {  /* one shift pressed */
                    del_mods(saved_mods); /* remove shift */
                    register_code(KC_DEL);
                    add_mods(saved_mods); /* add back shift */
                } else {
                    register_code(KC_BSPC);
                }
            } else { /* key released */
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
            }
            return false;
        case CAPS:
            if (record->event.pressed) {
                caps_word_set(true);
            }
            return false;
    }

    return true;
}
