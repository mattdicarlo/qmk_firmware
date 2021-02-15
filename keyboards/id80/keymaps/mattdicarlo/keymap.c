#include QMK_KEYBOARD_H

enum md_layers {
    MAC = 0,    // Base layer with Mac OS layout
    FN,         // Function layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                    KC_RGUI, MO(1),                     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MFFD, KC_MPLY, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
        _______, RGB_TOG, _______, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, KC_VOLD,
        KC_CAPS, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  NK_TOGG, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______,          KC_PGUP,
        _______, _______, _______,                   _______,                   _______, _______,                   KC_HOME, KC_PGDN, KC_END
    ),
};


void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);

    // QMK uses 8bit vals for HSV, so we need to convert them from
    // 360º hue and percentage sat and val.
    rgblight_sethsv((266.0 / 360.0) * 255,
                    0.47 * 255,
                    0.49 * 255);
    //rgblight_sethsv((169.0 / 360.0) * 255,
    //                0.55 * 255,
    //                0.81 * 255);
#endif //RGBLIGHT_ENABLE
}


uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
        case MAC:
            rgblight_sethsv((266.0 / 360.0) * 255,
                    0.47 * 255,
                    0.49 * 255);

            break;
        case FN:
            rgblight_sethsv((169.0 / 360.0) * 255,
                            0.55 * 255,
                            0.81 * 255);
            break;

        default:
            break;
    }
#endif // RGBLIGHT_ENABLE

    return state;
}
