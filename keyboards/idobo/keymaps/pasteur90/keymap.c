/* Copyright 2020 Jordan Egstad
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// qwerty
#define _QW 0
// functions
#define _FN 1
// and some gayming
#define _GM 2
//
#define _MS 3

// Tap dances
#define TD_ESCP TD(TD_GV_ESC)           // Tap for grave, twice for escape
#define TD_MINS TD(TD_MIN)              // Tap for minus, twice for equal
#define TD_BRAC TD(TD_BRC)              // Tap for open brace, twice for close
#define TD_LBLC TD(TD_LBC)
#define TD_RBRC TD(TD_RBC)

// Layers
#define FN_SPC LT(_FN, KC_SPC)          // Tap for space, hold for _FN

// Modifiers
#define LG_ZMIN LGUI(KC_EQUAL)          // Command + plus (zoom in)
#define LG_ZMOT LGUI(KC_MINUS)          // Command + minus (zoom out)
#define MT_SHFT MT(MOD_RSFT, KC_ENT)    // Tap for enter, hold for shift
#define MT_CTRL MT(MOD_LCTL, KC_ESC)

// Tap Dances
enum {
  TD_BRC = 0,
  TD_MIN,
  TD_GV_ESC,
  TD_BS,
  TD_LBC,
  TD_RBC,
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Left Brace, twice for Right Brace
  [TD_BRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  //Tap once for Minus, twice for Equal
  [TD_MIN]  = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
  // Tap once for Grave, tap twice for Escape
  [TD_GV_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESCAPE),
  [TD_LBC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY (_QW)
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      |   \|   | 6      | 7      | 8      | 9      | 0      |  -  +  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      |  [  ]  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      |        |        |        | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      |        |        |        | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | ZOOM-  | ZOOM+  | LALT   | FN     | CMD    | BSPC   |        |        | FN     | SPACE  | ENTER  | LEFT   | UP     | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGUP, TG(_GM), KC_HOME, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGDN, KC_BSLS, KC_END , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    MT_CTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    TD_LBLC, _______, TD_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCTL, KC_LALT, KC_LCTL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
    TT(_MS), LG_ZMIN, KC_LCTL, KC_LGUI, KC_LALT, FN_SPC , KC_BSPC, KC_DEL , KC_ENT , FN_SPC,  KC_RALT, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT  \
 ),


/* FUNCTION (_FN)
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     |        | P      |        | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | RGB HD | RGB HI |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | A-SFT  |        |        |        |        |        | RGB SD | RGB SI |        |        | LEFT   | UP     | DOWN   | RIGHT  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RGB    |        |        |        |        |        | RGB VD | RGB VI |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  |        |        |        |        |        | RGB RMD| RGB MD |        |        | PLAY   | PREV   | VOL UP | VOL DN | NEXT   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, KC_F12,  \
    KC_ASTG, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______, \
    RGB_TOG, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, \
    RESET,   _______, _______, _______, _______, _______, RGB_RMOD,RGB_MOD, _______, _______, KC_MPLY, KC_MRWD, KC_VOLU, KC_VOLD, KC_MFFD  \
 ),

 [_GM] = LAYOUT_ortho_5x15( /* GAME */
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGUP, TG(_GM), KC_HOME, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGDN, KC_BSLS, KC_END , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC, _______, KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, MO(_FN), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC , KC_BSPC, KC_DEL , KC_ENT , KC_SPC,  KC_EQUAL,KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT  \
 ),

 [_MS] = LAYOUT_ortho_5x15( /* MOUSE */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______, _______, \
    TT(_MS), _______, _______, _______, _______, KC_ACL1, KC_ACL2, _______, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______  \
 ),

};
