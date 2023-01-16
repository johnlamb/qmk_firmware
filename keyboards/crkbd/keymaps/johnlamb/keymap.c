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


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

typedef union {
  uint32_t raw;
  struct {
    bool on_win :1;
  };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
}
char *swedish_codes[][4] = {
  {
    SS_RALT("a"), // Option+a -> å Mac
    SS_RALT("A"), // Option+A -> Å Mac
    SS_RALT("w"), // RAlt+w -> å Win
    SS_RALT("W"), // RAlt+w -> Å Win
    // SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_9)), // å Win
    // SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_7)), // Å Win
  },
  {
    SS_RALT("u")"a", // Option+u+a -> ä Mac
    SS_RALT("u")"A", // Option+U+A -> Ä Mac
    SS_RALT("q"), // RAlt+q -> ä Win
    SS_RALT("Q"), // RAlt+Q -> Ä Win
    // SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_8)), // ä Win
    // SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6)), // Ä Win
  },
  {
    SS_RALT("u")"o", // Option+u+o -> ö Mac
    SS_RALT("u")"O", // Option+U+O -> Ö Mac
    SS_RALT("p"), // RAlt+p -> ö Win
    SS_RALT("P"), // RAlt+P -> Ö Win
    // SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6)), // ö Win
    // SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4)), // Ö Win
  }
};
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _MOUSE 5

// Left
#define HOME_A LALT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)
// Right
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RCTL_T(KC_L)
#define HOME_SCLN LALT_T(KC_SCLN)
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST, 
  SE_AA,
  SE_AE,
  SE_OE,
  ON_WIN
};

#define MOUSE MO(_MOUSE)
enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,     LT(MOUSE, KC_ENT),  RAISE,  KC_LALT \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_TAB, _______, _______, KC_MUTE, KC_VOLU,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   SE_OE,   SE_AE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, KC_LALT, KC_VOLD,                      _______, _______, _______, _______, _______,   SE_AA,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,     LT(MOUSE, KC_ENT),   RAISE, KC_LALT \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, _______, _______, _______, _______,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, KC_LALT, _______,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,     LT(MOUSE, KC_ENT),   RAISE, KC_LALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, _______, ON_WIN, _______,    KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,                        KC_F1,   KC_F2,   KC_F3,  KC_F11,  KC_F12, _______,\
  //|--------+-------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,     LT(MOUSE, KC_ENT),   RAISE, KC_LALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, KC_BTN1, KC_BTN2, _______, KC_WH_U, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

// void matrix_init_user(void) {
//     #ifdef RGBLIGHT_ENABLE
//       RGB_current_mode = rgblight_config.mode;
//     #endif
//     //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
//     #ifdef SSD1306OLED
//         iota_gfx_init(!has_usb());   // turns on the display
//     #endif
// }

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
//#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
// const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// void matrix_scan_user(void) {
//    iota_gfx_task();
// }

// void matrix_render_user(struct CharacterMatrix *matrix) {
//   if (is_master) {
//     // If you want to change the display of OLED, you need to change here
//     matrix_write_ln(matrix, read_layer_state());
//     matrix_write_ln(matrix, read_keylog());
//     //matrix_write_ln(matrix, read_keylogs());
//     //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
//     //matrix_write_ln(matrix, read_host_led_state());
//     //matrix_write_ln(matrix, read_timelog());
//   } else {
//     matrix_write(matrix, read_logo());
//   }
// }
// 
// void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
//   if (memcmp(dest->display, source->display, sizeof(dest->display))) {
//     memcpy(dest->display, source->display, sizeof(dest->display));
//     dest->dirty = true;
//   }
// }
// 
// void iota_gfx_task_user(void) {
//   struct CharacterMatrix matrix;
//   matrix_clear(&matrix);
//   matrix_render_user(&matrix);
//   matrix_update(&display, &matrix);
// }
// #endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
// #ifdef SSD1306OLED
//     set_keylog(keycode, record);
// #endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  if (!record->event.pressed) return true;
 switch(keycode){
  case SE_AA: case SE_AE: case SE_OE: {
           uint8_t mods = get_mods();
           clear_mods();
           // Send code based on which key was pressed and whether Shift was held
           uint16_t index = keycode - SE_AA;
           uint8_t shift = mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
           send_string(swedish_codes[index][(bool)shift+2*user_config.on_win]);
           set_mods(mods);
           return false;}
  case ON_WIN:{
                user_config.on_win ^= 1; // Toggle on_win
                eeconfig_update_user(user_config.raw);
                return false;
              }
  //  case SE_TA:{
  //           uint8_t mods = get_mods();
  //           clear_mods();

  //           // Send code based on which key was pressed and whether Shift was held
  //           // uint16_t index = keycode - SE_AA;
  //           // uint8_t shift = mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
  //           // send_string(SS_LALT("134"));
  //           SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_9)));
  //           set_mods(mods);
  //           return false;}
    default:
    return true;
 }
  return true;
}
