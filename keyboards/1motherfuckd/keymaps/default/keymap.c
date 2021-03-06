/* Copyright 2020 coolkenny
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
 * You should have received a copy of the GNU General Public 78License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

float my_song[][2] = SONG(QWERTY_SOUND);
float my_song2[][2] = SONG(DVORAK_SOUND);

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_1,    KC_2,   
        KC_3,    KC_4,
        KC_5,   KC_6,
        KC_7,   KC_8
    )
};


*/



/*

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        RGB_HUI,    RGB_SAI,   RGB_VAI,   RGB_TOG  ,
        RGB_HUD,    RGB_SAD,  RGB_VAD,   RGB_MOD
          51
    )
};

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,   RGB_TOG,   RESET  ,
        KC_3,    KC_4 ,  RGB_MOD,   KC_6
          
    )
};








enum custom_keycodes {
RGB_SLD = SAFE_RANGE
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_W:
    if (record->event.pressed) {
      PLAY_SONG(my_song2);

    }
    break;
    case KC_Q:
    if (record->event.pressed) {
      PLAY_SONG(my_song);

    }
    break;

  }
  return true;
}




/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
