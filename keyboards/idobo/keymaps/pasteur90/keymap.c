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

enum custom_keycodes {
	LOWER = SAFE_RANGE,
	RAISE,
};

// qwerty
#define _QWERTY 0
// functions
#define _LOWER 1
// and some gayming
#define _RAISE 2
//
#define _ADJUST 3

#define _GM 4

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

// Home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

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

 [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,  TG(_GM), KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_LBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC, \
    MT_CTRL, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    XXXXXXX, KC_UP,   KC_PSCR, KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT, KC_DOWN, KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_SHFT, \
    TG(_GM), KC_BSLS, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, KC_DEL,  KC_ENT , _______, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT  \
 ),

 [_RAISE]= LAYOUT_ortho_5x15( /* FUNCTION */
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______, _______, _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, \
    KC_GRV ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, _______, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12, \
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______, _______, _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, KC_COMM,  KC_DOT, _______, \
    TG(_GM), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
 ),

 [_LOWER]= LAYOUT_ortho_5x15( /* MOUSE */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    S(KC_GRV),KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
    _______, _______, _______, _______, _______, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______  \
 ),

 [_ADJUST]= LAYOUT_ortho_5x15( /* MOUSE */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______, _______, \
      RESET, _______, _______, _______, _______, KC_ACL1, KC_ACL2, _______, KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______  \
 ),

 [_GM] = LAYOUT_ortho_5x15( /* GAME */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F10 , KC_F11 , KC_F12 , KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F7  , KC_F8  , KC_F9  , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD_MINS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F4  , KC_F5  , KC_F6  , KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F1  , KC_F2  , KC_F3  , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    TG(_GM), KC_BSLS, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, KC_DEL , KC_ENT , KC_GRAVE,KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT  \
 ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
	layer_on(_LOWER);
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
	layer_off(_LOWER);
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
	layer_off(_RAISE);
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
  }
  return true;
}
