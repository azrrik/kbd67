// using as reference
// https://docs.qmk.fm/#/keymap

// thanks to atlacat, hailbreno, itsaferbie and weeheavy...

// and special thanks to  AGausmann and drashna for the layer-activated RGB underglow
// https://www.reddit.com/r/olkb/comments/6t1vdu/update_layeractivated_rgb_underglow/
// https://github.com/AGausmann/qmk_firmware/blob/agausmann-v3.x/keyboards/nyquist/keymaps/agausmann/keymap.c

#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define L1 MO(1)
#define L2 MO(2)
#define L3 MO(3)
#define BS_L1 LT(1, KC_BSPC)
#define SP_L2 LT(2, KC_SPACE)
#define TG_L0 TO(0)
#define TG_L3 TO(3)

#define CUT   LCTL(KC_X)
#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO  LCTL(KC_Z)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* base
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ins│del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │ tab │ q │ w │ e │ r │ t │ y │ u │ i │ o │ p │ [ │ ] │ |\  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │ caps │ a │ s │ d │ f │ g │ h │ j | k │ l │ ; │ ' │ enter  │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
   * │shif│ / │ z │ x │ c │ v │ b │ n │ m │ , │ . │shift | ^ │ / │
   * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬───┼───┼───┤
   * │esc │gui │alt │bksp/fn1│ctrl│sp/fn2    │alt│tg3│ < │ v │ > │
   * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
  */
  [0] = LAYOUT_AZ(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_INS,   KC_DEL,
    KC_TAB ,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_LSFT,  KC_SLSH,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_RSFT,  KC_UP,    KC_SLSH,
    KC_ESC,   KC_LGUI,  KC_LALT,  BS_L1,    KC_LCTL,  SP_L2,    KC_RALT,  TG_L3,    KC_LEFT,  KC_DOWN,  KC_RIGHT
  ),
  /* layer 1 - arrows
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │   │   │   │   │   │   │hom│ ^ │end│Pup│   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │shf│ctl│pst│alt│   │   │ < | v │ > │Pdn│   │        │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
   * │    │   │und│cut│cpy|pst│   │   │   │   │   │      |   │   │
   * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │        │    │    del   │   │   │   │   │   │
   * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
  */
  [1] = LAYOUT_AZ(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  _______,  _______,  _______,
    _______,  KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,  _______,  _______,
    _______,  UNDO,     CUT,      COPY,     PASTE,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_DEL,   _______,  _______,  _______,  _______,  _______
  ),
  /* layer 2 - mouse
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │RST│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │   │   │   │   │   │   │b1 │ ^ │b2 │wUp│   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │   │   │   │   │ < | v │ > │wDn│   │        │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
   * │    │   │   │   │   │   │   │   │ac0│ac1│ac2│      │   │   │
   * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │        │    │          │   │   │   │   │   │
   * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
  */
  [2] = LAYOUT_AZ(
    RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_ACL0,  KC_ACL1,  KC_ACL2,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  /* layer 3 - no fn toggle
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │   │   │   │   │   │   │   │   │   │        │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
   * │    │   │   │   │   │   │   │   │   │   │   │      |   │   │
   * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │ bk sp  │    │  space   │   │   │   │   │   │
   * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
  */
  [3] = LAYOUT_AZ(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  KC_BSPC,  _______,  KC_SPC,   _______,  TG_L0,    _______,  _______,  _______
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
        rgblight_sethsv_noeeprom_turquoise();
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
