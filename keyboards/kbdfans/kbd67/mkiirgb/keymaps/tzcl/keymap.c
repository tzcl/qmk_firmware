#include QMK_KEYBOARD_H
#include "features/caps_word.h"
#include "features/custom_shift_keys.h"

/* Key aliases */
#define CTL_ESC CTL_T(KC_ESC)

/* Custom shift keys */
const custom_shift_key_t custom_shift_keys[] = {
    {KC_BSPC, KC_DEL}, /* shift + bspc is del */
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

enum layer_names { BASE, EXTEND };

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base layer
   * ,--------------------------------------------------------------------------------------------------.
   * | ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |       \       | Home |
   * |-------------------------------------------------------------------------------------------+------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   BSPC   | End  |
   * |-------------------------------------------------------------------------------------------+------+
   * | Ctrl/Esc |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgUp |
   * |-------------------------------------------------------------------------------------------+------+
   * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | PgDn |
   * +-------------------------------------------------------------------------┬---┬-------------+------+
   * | MO(1) | LGUI | LAlt |               Space                 | Btn2 | MO(1)|   | Left  |Down | Right|
   * `-------------------------------------------------------------------------┘   └-------------+------´
   */
    [BASE] = LAYOUT_65_ansi_blocker( /* Base */
        KC_GRV,  KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,   KC_EQL, KC_BSLS,  KC_HOME,
        KC_TAB,  KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,  KC_RBRC, KC_BSPC,   KC_END,
        CTL_ESC, KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,             KC_UP,  KC_PGDN,
          MO(1), KC_LGUI, KC_LALT,                KC_SPC,                KC_LALT,          MO(1),                     KC_LEFT, KC_DOWN,  KC_RGHT
    ),

    [EXTEND] = LAYOUT_65_ansi_blocker( /* Extend */
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,   RESET,  KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,  KC_SLCK, KC_PAUS,  KC_DEL,  KC_PGUP,
        CTL_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          EEP_RST,  KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          KC_VOLU,  KC_MUTE,
        _______, _______, _______,                  _______,             _______,        _______,                    KC_MPRV, KC_VOLD,  KC_MNXT
    )
};
/* clang-format on */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) {
        return false;
    }
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    return true;
}
