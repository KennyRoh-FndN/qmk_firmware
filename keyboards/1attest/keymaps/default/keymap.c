/* Copyright 2020 kenny
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


// Defines names for use in layer keycodes and the keymap
/* Copyright 2020 kenny
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

#include "keymap_korean.h"
#include "version.h"
#include <print.h>
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
};

// Defines the keycodes used by our macros in process_record_user

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A  
        KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A  
        KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A  
    )
};
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
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
