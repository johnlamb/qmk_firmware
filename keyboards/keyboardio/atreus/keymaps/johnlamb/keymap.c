// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _RS,
    _LW,
    _MO,
};

char *swedish_codes[][2] = {
  {
    SS_RALT("a"), // Option+a -> å
    SS_RALT("A"), // Option+A -> Å
  },
  {
    SS_RALT("u")"a", // Option+u -> ä
    SS_RALT("u")"A", // Option+U -> Ä
  },
  {
    SS_RALT("u")"o", // Option+o -> ö
    SS_RALT("u")"O", // Option+O -> Ö
  }
};
enum custom_keycodes {
  SE_AA,
  SE_AE,
  SE_OE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,             KC_U,    KC_I,          KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,             KC_J,    KC_K,          KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  KC_BSPC, KC_N,             KC_M,    KC_COMM,       KC_DOT,  KC_SLSH,
    KC_LALT, KC_TAB,  KC_LGUI, MO(_LW), KC_SPC,  KC_LCTL, KC_LSFT, LT(_MO, KC_ENT),  MO(_RS), LCAG_T(KC_NO), KC_BSLS, KC_TILD
  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC,         KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    _______, _______, _______, _______, _______,                   KC_MINS,         KC_EQL,  KC_LCBR, KC_RCBR, KC_QUOT,
    _______, _______, _______, _______, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC,         _______, KC_LBRC, KC_RBRC, _______,
    KC_LALT, KC_TAB,  _______, _______, _______, KC_LCTL, KC_LSFT, LT(_MO, KC_ENT), _______, _______, _______, _______
    ),
  /*[_RS] = LAYOUT(  [> RAISE <] 
    KC_EXLM, KC_AT,   KC_UP,   KC_DLR,  KC_PERC,                  KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC,
    KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                  KC_PGDN, KC_4,    KC_5,   KC_6, KC_BSLS,
    KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR,KC_ASTR, KC_1,    KC_2,   KC_3, KC_PLUS,
    TG(_LW), RESET,   KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL),*/
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */ 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,            KC_7,    KC_8,    KC_9,     KC_0,
    _______, _______, _______, _______, KC_VOLU,                   KC_LEFT,         KC_DOWN, KC_UP,   KC_RIGHT, SE_AE,
    _______, _______, _______, _______, KC_VOLD, _______, _______, _______,         _______, _______, SE_OE,    SE_AA,
    KC_LALT, KC_TAB,  _______, _______, _______, KC_LCTL, KC_LSFT, LT(_MO, KC_ENT), _______, _______, _______,  _______
    ),
  /* [_LW] = LAYOUT(  [> LOWER <] 
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,   _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )*/
  [_MO] = LAYOUT( /* [> LOWER <] */
    _______, _______, _______, _______, _______,                   _______,         KC_BTN1, KC_BTN2, _______, KC_WH_U,
    _______, _______, _______, _______, _______,                   KC_MS_L,         KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______,
    KC_LALT, KC_TAB,  _______, _______, _______, KC_LCTL, KC_LSFT, LT(_MO, KC_ENT), _______, _______, _______, _______
    )
  /* [_LW] = LAYOUT(  [> LOWER <] 
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,   _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )*/
};
