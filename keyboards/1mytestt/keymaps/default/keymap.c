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
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

// Defines names for use in layer keycodes and the keymap

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST

};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Defines names for use in layer keycodes and the keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
/*    [0] = LAYOUT(ahttps://qmk.fm/
TOGGLE_LAYER_COLOR,		RGB_TOG,	RGB_MODE_FORWARD,	RGB_MODE_REVERSE,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,				
RGB_HUI,	RGB_HUI,	RGB_SAI,	RGB_VAI,	RGB_VAI,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	RGB_HUD,	RGB_SAD,	RGB_VAD,		KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A,				KC_A,	KC_A,	KC_A,	
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,			KC_A,		KC_A,		KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,							KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A	
    ),
    */
        [0] = LAYOUT(
KC_A,		KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,				
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A,				KC_A,	KC_A,	KC_A,	
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,			KC_A,		KC_A,		KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,							KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A	
    ),
    [1] = LAYOUT(
KC_A,		KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,				
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A,				KC_A,	KC_A,	KC_A,	
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,			KC_A,		KC_A,		KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,							KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A	
    ),
    [2] = LAYOUT(
KC_A,		KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,				
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A,				KC_A,	KC_A,	KC_A,	
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,			KC_A,		KC_A,		KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,							KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A	
    ),
    [3] = LAYOUT(
KC_A,		KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,				
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A,				KC_A,	KC_A,	KC_A,	
KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,			KC_A,		KC_A,		KC_A,	KC_A,	KC_A,	KC_A,
KC_A,	KC_A,	KC_A,	KC_A,							KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,	KC_A,		KC_A	
    )
};




const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255} },

    [1] = { {31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255} },

    [2] = { {31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255} },

    [3]  = { {31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255},	{31,255,255} },

};



void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}






#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;








void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}







bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif














uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}








void encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* First encoder */
    /* And with another if statement we can check the direction. */
    if (clockwise) {
      /* This is where the actual magic happens: this bit of code taps on the
         Page Down key. You can do anything QMK allows you to do here.
         You'll want to replace these lines with the things you want your
         encoders to do. */
      tap_code(KC_PGDN);
    } else {
      /* And likewise for the other direction, this time Page Down is pressed. */
      tap_code(KC_PGUP);
    }
  /* You can copy the code and change the index for every encoder you have. Most
     keyboards will only have two, so this piece of code will suffice. */
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
}





