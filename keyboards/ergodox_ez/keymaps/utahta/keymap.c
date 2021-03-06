#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define FNCK 1 // function keys
#define WINS 2 // windows
#define FF14 3 // ff14 for mac

//enum custom_keycodes {
//  PLACEHOLDER = SAFE_RANGE, // can always be here
//  EPRM,
//  VRSN,
//  RGB_SLD
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  BS    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  `   |           |  [   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------|  '   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl| LAlt |      | LCmd | RCmd |                                       | Left | Down |  Up  | Right|   L1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LAlt | L3   |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | UP   |        |      |
 *                                 | Space|LShift|------|       |------| Space  | Enter|
 *                                 |      |      | End  |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_NO,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_GRV,
        KC_LCTRL,       KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_QUOT,
        KC_LCTRL, KC_LALT, KC_NO, KC_LGUI, KC_RGUI,
                                                             KC_LALT, TG(WINS),
                                                                      KC_HOME,
                                                     KC_SPC, KC_LSFT, KC_END,
        // right hand
        KC_NO,       KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
        KC_LBRC,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_MINS,
        KC_RBRC,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_EQL,
                                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TG(FNCK),
        TG(FF14), KC_RGHT,
        KC_UP,
        KC_DOWN, KC_SPC, KC_ENT
    ),
/* Keymap 1: Function key Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   F1 |   F2 |   F3 |   F4 |   F5 |      |           |      |   F6 |   F7 |   F8 |   F9 |  F10 |  BS    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  `   |           |  [   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------|  '   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl| LAlt |      | LCmd | RCmd |                                       | Left | Down |  Up  | Right|   L1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LAlt | L3   |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | UP   |        |      |
 *                                 | Space|LShift|------|       |------| Space  | Enter|
 *                                 |      |      | Reset|       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[FNCK] = LAYOUT_ergodox(  // layer 1 : function key
        // left hand
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, RESET,
        // right hand
        KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Windows layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  ;   |           | PSCR |   6  |   7  |   8  |   9  |   0  | BS/DEL |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ^   |           |  [   |   Y  |   U  |   I  |   O  |   P  |   ¥    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------|  *   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl|  Win |      | ZKHK | LAlt |                                       | Left | Down |  Up  | Right|   L1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LAlt | TGL  |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | UP   |        |      |
 *                                 | Space|LShift|------|       |------| Space  | Enter|
 *                                 |      |      | End  |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[WINS] = LAYOUT_ergodox(  // layer 2 : windows
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_SCLN,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_EQL,
        KC_LCTRL,       KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_QUOT,
        KC_LCTRL, KC_LGUI, KC_NO, KC_ZKHK, KC_LALT,
                                                             KC_LALT, KC_TRNS,
                                                                      KC_HOME,
                                                     KC_SPC, KC_LSFT, KC_END,
        // right hand
        KC_PSCR,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             MT(KC_DEL, KC_BSPC),
        KC_RBRC,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_JYEN,
                     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_MINS,
        KC_BSLS,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_RO,
                                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TG(FNCK),
        KC_LEFT, KC_RGHT,
        KC_UP,
        KC_DOWN, KC_SPC, KC_ENT
    ),
/* Keymap 3: FF14 for mac layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  6   |           |      |   6  |   7  |   8  |   9  |   0  |  BS    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  7   |           |  [   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------|  8   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl|   9  |   0  | LCmd | RCmd |                                       | Left | Down |  Up  | Right|  TGL |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LAlt | TGL  |       | TGL  | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | UP   |        |      |
 *                                 | Space|LShift|------|       |------| Space  | Enter|
 *                                 |      |      | End  |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[FF14] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_7,
        KC_LCTRL,       KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_8,
        KC_LCTRL, KC_9, KC_0, KC_LGUI, KC_RGUI,
                                                             KC_LALT, KC_TRNS,
                                                                      KC_HOME,
                                                     KC_SPC, KC_LSFT, KC_END,
        // right hand
        KC_NO,       KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
        KC_LBRC,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_MINS,
        KC_RBRC,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_EQL,
                                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS,
        KC_TRNS, KC_RGHT,
        KC_UP,
        KC_DOWN, KC_SPC, KC_ENT
    ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(FNCK)                // FN1 - Momentary Layer 1 (Function keys)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
    case 1:
    if (record->event.pressed) { // For resetting EEPROM
      eeconfig_init();
    }
    break;
  }
  return MACRO_NONE;
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    // dynamically generate these.
//    case EPRM:
//      if (record->event.pressed) {
//        eeconfig_init();
//      }
//      return false;
//      break;
//    case VRSN:
//      if (record->event.pressed) {
//        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//      }
//      return false;
//      break;
//    case RGB_SLD:
//      if (record->event.pressed) {
//        #ifdef RGBLIGHT_ENABLE
//          rgblight_mode(1);
//        #endif
//      }
//      return false;
//      break;
//  }
//  return true;
//}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};

