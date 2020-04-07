#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define KC_TAB LGUI(KC_TAB)
#define KC_MSN_CTRL LCTL(KC_UP)
#define KC_MV_RIGHT LCTL(KC_RIGHT)
#define KC_MV_LEFT LCTL(KC_LEFT)
#define KC_COPY_MAC LGUI(KC_C)
#define KC_PASTE_MAC LGUI(KC_V)

    /*
     * ,------------------------------------------------------------------,
     * |  LEFT MOVE  |  CMD + TAB  |  CMD + TAB + RIGHT  |   RIGHT MOVE   |
     * |-------------+-------------+---------------------+----------------|
     * |  7          |      8      |         9           |      PASTE     |
     * |-------------+-------------+---------------------+----------------|
     * |  4          |      5      |         6           |      COPY      |
     * |-------------+-------------+---------------------+----------------|
     * |  1          |      2      |         3           |  MISSION CTRL  |
     * `------------------------------------------------------------------'
     */
    LAYOUT_ortho_4x4(KC_MV_LEFT, KC_TAB, KC_F11, KC_MV_RIGHT, KC_P7, KC_P8, KC_P9, KC_PASTE_MAC, KC_P4, KC_P5, KC_P6, KC_COPY_MAC, KC_P1, KC_P2, KC_P3, KC_MSN_CTRL)

};

// Set led state during powerup
void keyboard_post_init_user(void) { writePinHigh(LED_RED); }

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // First encoder - top left
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RIGHT);
        }
    } else if (index == 1) {  // Second encoder - top right
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
}
