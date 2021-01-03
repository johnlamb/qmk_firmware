#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
              LCAG(KC_M),
              LCAG(KC_P)
          )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LCAG(KC_M):
      if (record->event.pressed) {
          rgblight_setrgb(RGB_ORANGE);
      } else {
          rgblight_setrgb(RGB_YELLOW);
      }
      return true; // Let QMK send the enter press/release events
    case LCAG(KC_P):
      if (record->event.pressed) {
          rgblight_setrgb(RGB_BLUE);
      } else {
          rgblight_setrgb(RGB_YELLOW);
      }
      return true; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }
}

