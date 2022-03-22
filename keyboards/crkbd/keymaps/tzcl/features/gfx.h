#pragma once

#include QMK_KEYBOARD_H

void render_luna(int x, int y);

/* Set Luna states */
void luna_bark(bool);
void luna_sneak(bool);
void luna_jump(void);

void render_windows_logo(int x, int y);
void render_mac_logo(int x, int y);

void render_layers(int x, int y);

void render_wpm(int x, int y);
