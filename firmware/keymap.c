#include QMK_KEYBOARD_H

// Default Layer 0 Layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_1,    KC_2,    KC_3, 
        KC_4,    KC_5,    KC_6, 
        KC_7,    KC_8,    KC_MUTE  // KC_MUTE is the Encoder Push-Button
    )
};

// Rotary Encoder Logic
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First (and only) encoder
        if (clockwise) {
            tap_code(KC_VOLU); // Volume Up
        } else {
            tap_code(KC_VOLD); // Volume Down
        }
    }
    return false;
}
#endif

// OLED Screen Logic
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Clear the screen if needed and print text
    oled_write_P(PSTR("================\n"), false);
    oled_write_P(PSTR("   MY HACKPAD   \n"), false);
    oled_write_P(PSTR("================\n\n"), false);
    oled_write_P(PSTR(" Status: Active \n"), false);
    oled_write_P(PSTR(" Layer:  0      \n"), false);
    return false;
}
#endif