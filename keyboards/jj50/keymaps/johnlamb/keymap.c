/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define ______ KC_TRNS
#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3
#define _MOUSE 4

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE MO(_MOUSE)

enum custom_keycodes {
    P_MACRO = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
        KC_GRV,         KC_1,                KC_2,    KC_3,    KC_4,    KC_5,               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,         KC_Q,                KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LCTL_T(KC_ESC), KC_A,                KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSPO,        KC_Z,                KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RCTL_T(KC_ENT),
        LCAG_T(KC_NO),  LM(LOWER, MOD_LGUI), KC_LALT, KC_LGUI, LOWER,   LT(MOUSE, KC_SPC),  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_RAISE] = LAYOUT( \
       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_GRV,  _______, _______, _______, _______, _______, _______,  _______, _______, KC_MINS, KC_EQL,  _______,
       _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6),  S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_VOLU,
       _______, _______, _______, _______, KC_LBRC, S(KC_9), S(KC_0),  KC_RBRC, _______, _______, KC_BSLS, KC_VOLD,
       _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, KC_MUTE
    ),

    [_LOWER] = LAYOUT( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_NO,   KC_NO,   _______, _______, _______, _______, S(KC_EQL), KC_MINS, S(KC_8), KC_SLSH, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_VOLD,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_MUTE
    ),

    [_ADJUST] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RESET,   _______, RGB_TOG, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT( \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
