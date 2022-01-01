// Copyright 2021 In-hwan Ryu (@pasteur90)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_LCTL,    KC_C,    KC_V
    ),
    [_FN] = LAYOUT(
        _______, _______,  _______
    )
};
