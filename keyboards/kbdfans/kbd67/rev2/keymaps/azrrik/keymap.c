/* Copyright 2018 'mechmerlin'
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

#define _______ KC_TRNS

#define L1 MO(1)
#define L2 MO(2)
#define L3 MO(3)
#define BS_L1 LT(1, KC_BSPC)
#define SP_L2 LT(2, KC_SPACE)
#define TG_L0 TO(0)
#define TG_L3 TO(3)
#define TG_L5 TO(5)

#define CUT   LCTL(KC_X)
#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO  LCTL(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* base
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ins│del│hom|
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │ tab │ q │ w │ e │ r │ t │ y │ u │ i │ o │ p │ [ │ ] │ \ | end │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┴─┬───┤
    * │ caps │ a │ s │ d │ f │ g │ h │ j | k │ l │ ; │ ' │ enter  │pUp|
    * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * │shif│F12│ z │ x │ c │ v │ b │ n │ m │ , │ . │ / │ shift│ ^ │pDn|
    * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
    * │esc │gui │alt │bksp/L1 │ctrl│sp/L2     │alt │fn3 | │ < │ v │ > │
    * └────┴────┴────┴────────┴────┴──────────┴────┴────┴─┴───┴───┴───┘
    */
    [0] = LAYOUT_all(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_INS,   KC_DEL,   KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,
        KC_LSFT,  _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
        KC_ESC,   KC_LGUI,  KC_LALT,  BS_L1,    KC_LCTL,  SP_L2,    KC_RALT,  TG_L3,    _______,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
    /* layer 1 - arrows
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │   │
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │     │   │   │   │   │   │   │hom│ ^ │end│Pup│   │   │   |     │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┴─┬───┤
    * │      │shf│gui│alt│ctl│   │   │ < | v │ > │Pdn│   │        |   │
    * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * │    │   │und│cut│cpy│pst│   │   │   │   │   │   │      │   |   │
    * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
    * │    │    │    │        │    │    del   │    │    │ │   │   │   │
    * └────┴────┴────┴────────┴────┴──────────┴────┴────┴─┴───┴───┴───┘
    */
    [1] = LAYOUT_all(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  _______,  _______,  _______,  _______,
        _______,  KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,  _______,  _______,  _______,
        _______,  _______,  UNDO,     CUT,      COPY,     PASTE,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  KC_DEL,   _______,  _______,  _______,  _______,  _______,  _______
    ),
    /* layer 2 - mouse
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │RST│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │   │
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │     │   │   │   │   │   │   │b1 │ ^ │b2 │wUp│   │   │   |     │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┴─┬───┤
    * │      │   │   │   │   │   │   │ < | v │ > │wDn│   │        |   │
    * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * │    │   │   │   │   │   │   │   │   │   │   │   │      │   |   │
    * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
    * │    │    │    │        │    │          │    │    │ │   │   │   │
    * └────┴────┴────┴────────┴────┴──────────┴────┴────┴─┴───┴───┴───┘
    */
    [2] = LAYOUT_all(
        RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_ACL0,  KC_ACL1,  KC_ACL2,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
    /* layer 4 - no fn toggle
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
    * │     │   │   │   │   │   │   │   │   │   |   │   │   │   |     │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┴─┬───┤
    * │      │   │   │   │   │   │   │   |   │   │   │   │        |   │
    * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * │    │   │   │   │   │   │   │   │   │   │   │   │      │   |   │
    * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
    * │    │    │    │ bk sp  │    │  space   │    │    │ │   │   │   │
    * └────┴────┴────┴────────┴────┴──────────┴────┴────┴─┴───┴───┴───┘
    */
    [3] = LAYOUT_all(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  KC_BSPC,  _______,  KC_SPC,   _______,  TG_L0,    _______,  _______,  _______,  _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


// layer-activated RGB underglow
void matrix_scan_user(void) {

  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 1;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    switch (new_layer) {
      case 0:
        rgblight_sethsv_noeeprom_azure();
        break;
      case 1:
        rgblight_sethsv_noeeprom_coral();
        break;
      case 2:
        rgblight_sethsv_noeeprom_gold();
        break;
      case 3:
        rgblight_sethsv_noeeprom_purple();
        break;
      case 4:
        rgblight_sethsv_noeeprom_yellow();
        break;
      default:
        rgblight_sethsv_noeeprom_azure();
    }

    old_layer = new_layer;
  }

  #endif //RGBLIGHT_ENABLE

}

void matrix_init_user(void) {
}

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
  rgblight_sethsv_noeeprom_azure();
  #endif //RGBLIGHT_ENABLE
}

void led_set_user(uint8_t usb_led) {
}
