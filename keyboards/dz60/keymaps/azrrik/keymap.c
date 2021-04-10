#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define L1 MO(1)
#define L2 MO(2)
#define L3 MO(3)
#define L4 MO(4)
#define BS_L1 LT(1, KC_BSPC)
#define SP_L2 LT(2, KC_SPACE)
#define TG_L0 TO(0)
#define TG_L3 TO(3)
#define TG_L4 TO(4)

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
    KC_LSFT,  KC_SLSH,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_RSFT,  KC_UP,    L4,
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
    _______,  _______,  UNDO,     CUT,      COPY,     PASTE,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
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
  ),
  /* layer 4 - RBG
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │   │   │   │   │   │   │   │   │   │        │
   * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
   * │    │   │   │   │   │   │   │   │   │   │   │      |mod│   │
   * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │        │    │          │   │tog│hui│sai│vai│
   * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
  */
  [4] = LAYOUT_AZ(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_MOD,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI
  )
};

// layer-activated RGB underglow
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, 0, 200, 200},
    {14, 3, 0, 200, 200}
);
const rgblight_segment_t PROGMEM layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 11, 176, 200}
);
const rgblight_segment_t PROGMEM layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 128, 255, 200}
);
const rgblight_segment_t PROGMEM layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 191, 255, 200}
);
const rgblight_segment_t PROGMEM layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 106, 255, 200}
);
const rgblight_segment_t PROGMEM layer4[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 43, 255, 200
    }
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer0,
    layer1,
    layer2,
    layer3,
    layer4,
    capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(5, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // TODO - reflash with this uncommented
    // rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    // rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}
