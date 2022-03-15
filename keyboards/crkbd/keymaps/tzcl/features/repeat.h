#pragma once

#include QMK_KEYBOARD_H

// Register a keycode we should repeat with the repeat key
void register_repeat_key(uint16_t keycode);
// Last keycode
uint16_t last_key(void);
// Repeat key actions
void update_repeat_key(keyrecord_t *record);
void tap_repeat_key(void);
