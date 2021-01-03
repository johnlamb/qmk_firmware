/* Copyright 2015-2017 Jack Humbert
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

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE
};

enum planck_keycodes {
  QWERTY = EZ_SAFE_RANGE,
  COLEMAK
};
/*
enum tap_dance {
  CT_BRC,
  CT_PAR,
  CT_SQR
};
*/

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE MO(_MOUSE)

#define KC_TLC TOGGLE_LAYER_COLOR

/*
void dance_closed_brc(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);
    register_code (KC_LBRC);
    unregister_code (KC_LBRC);
    unregister_code (KC_LSFT);
  } else {
    register_code (KC_LSFT);
    register_code (KC_LBRC);
    unregister_code (KC_LBRC);
    register_code (KC_RBRC);
    unregister_code (KC_RBRC);
    unregister_code (KC_LSFT);
    register_code (KC_LEFT);
    unregister_code (KC_LEFT);
  }
  reset_tap_dance(state);
}

void dance_closed_par(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);
    register_code (KC_9);

    unregister_code (KC_9);
    unregister_code (KC_LSFT);
  } else {
    register_code (KC_LSFT);
    register_code (KC_9);
    unregister_code (KC_9);
    register_code (KC_0);
    unregister_code (KC_0);
    unregister_code(KC_LSFT);
    register_code (KC_LEFT);
    unregister_code (KC_LEFT);
  }
  reset_tap_dance(state);
}

void dance_closed_sqr(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LBRC);
    unregister_code (KC_LBRC);
  } else {
    register_code (KC_LBRC);
    unregister_code (KC_LBRC);
    register_code (KC_RBRC);
    unregister_code (KC_RBRC);
    register_code (KC_LEFT);
    unregister_code (KC_LEFT);
  }
  reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_BRC] = ACTION_TAP_DANCE_FN(dance_closed_brc),
  [CT_PAR] = ACTION_TAP_DANCE_FN(dance_closed_par),
  [CT_SQR] = ACTION_TAP_DANCE_FN(dance_closed_sqr)
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BkSp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Ret  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  HP  |  Fn  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,                KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC), KC_A,                KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSPO,        KC_Z,                KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RCTL_T(KC_ENT),
    LCAG_T(KC_NO),  LM(LOWER, MOD_LGUI), KC_LALT, KC_LGUI, LOWER,   LT(MOUSE, KC_SPC),  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Matrix Colemak-DH
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  HP  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'

[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,               KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,               KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    LCAG_T(KC_NO),  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LT(MOUSE, KC_SPC),  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
 */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |   +  |   -  |   *  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | VolU |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | VolD |      
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      | VolM |
 * `-----------------------------------------------------------------------------------'
 */
/* Ignore Q and W to prevent accidental kills */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_NO,   KC_NO,   _______, _______, _______, _______, S(KC_EQL), KC_MINS, S(KC_8), KC_SLSH, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_VOLD,
    _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_MUTE
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |      |      |   -  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | VolU |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   [  |   (  |   )  |   ]  |      |      |      | VolD |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      | VolM |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  _______, _______, _______, _______, _______, _______,  _______, _______, KC_MINS, KC_EQL,  _______,
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6),  S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_VOLU,
    _______, _______, _______, _______, KC_LBRC, S(KC_9), S(KC_0),  KC_RBRC, _______, _______, KC_BSLS, KC_VOLD,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, KC_MUTE
),

/* Adjust (Lower + Raise)
 *                      v--------RGB CONTROL--------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD|BRGTH+|BRGTH-|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |LED_LV|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGL_LA|      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______,  RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_VAD,   RGB_VAI, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, LED_LEVEL, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    KC_TLC , _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |M_BTN1| M_UP |M_BTN2|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |M_LEFT| M_DWN|M_RGHT|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |M_WH_D|M_WH_U|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};
extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_QWERTY] = {  {0,255,255},   {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {0,255,255},
	    	   {0,255,255},   {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {0,255,255},
		   {0,255,255},   {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {172,255,255}, {0,255,255},
		   {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},                  {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255} },

    [_LOWER] = {   {212,255,255}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
	           {0,0,0},       {28,255,255},  {28,255,255},  {28,255,255},  {28,255,255},  {28,255,255},  {28,255,255},  {28,255,255},  {28,255,255},  {28,255,255},  {28,255,255},  {28,255,255},
		   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {28,255,255},
		   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {28,255,255} },

    [_RAISE] = {   {212,255,255}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {212,255,255}, {212,255,255}, {0,0,0},
	           {0,0,0},       {212,255,255}, {212,255,255}, {212,255,255}, {212,255,255}, {212,255,255}, {212,255,255}, {212,255,255}, {212,255,255}, {212,255,255}, {212,255,255}, {28,255,255},
		   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {212,255,255}, {212,255,255}, {212,255,255}, {212,255,255}, {0,0,0},       {0,0,0},       {212,255,255}, {28,255,255},
		   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {28,255,255} },

    [_ADJUST] = {  {0,0,0},       {0,255,255},   {0,255,255},   {43,255,255},  {43,255,255},  {43,255,255},  {43,255,255},  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
	           {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {43,255,255},  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
		   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
		   {43,255,255},  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0} },
    
    [_MOUSE] = {   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {85,255,255},  {85,255,255},  {85,255,255},  {0,0,0},       {0,0,0},
	           {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {85,255,255},  {85,255,255},  {85,255,255},  {0,0,0},       {0,0,0},
		   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {85,255,255},  {85,255,255},  {0,0,0},       {0,0,0},       {0,0,0},
		   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0} },

};
void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  /*
  switch (biton32(default_layer_state)) {
    case _QWERTY:
      set_layer_color(_QWERTY);
      break;
    case _COLEMAK:
      set_layer_color(_COLEMAK);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  */ 
  switch (biton32(layer_state)) {
    case _QWERTY:
      set_layer_color(_QWERTY);
      break;
  /*
    case _COLEMAK:
      set_layer_color(_COLEMAK);
      break;
   */
    case _LOWER:
      set_layer_color(_LOWER);
      break;
    case _RAISE:
      set_layer_color(_RAISE);
      break;
    case _ADJUST:
      set_layer_color(_ADJUST);
      break;
    case _MOUSE:
      set_layer_color(_MOUSE);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
}
*/
