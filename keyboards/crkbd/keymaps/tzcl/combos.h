#pragma once

#include "keycodes.h"

/* Combos */
enum combos_events {
    CAPS_COMBO,
    NUM_COMBOS,
};
uint16_t COMBO_LEN = NUM_COMBOS;

const uint16_t PROGMEM caps_combo[] = {H_T, KC_G, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO(caps_combo, CAPS),
};
