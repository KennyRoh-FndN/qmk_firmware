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
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _dd,
    _d
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    fuck,
    fuck2,
    TOGGLE_LAYER_COLOR,
    RGB_SLD
};




#define ______________ KC_TRANSPARENT 

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_UNUNDO LCTL(KC_Y)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

#define BP_NDSH_MAC ALGR(KC_8)
#define AS_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define CS_T(kc) MT(MOD_LSFT | MOD_LCTL, kc)
#define CA_T(kc) MT(MOD_LCTL | MOD_LALT, kc)

#define L_ARROW LCTL(LSFT(KC_LEFT))
#define R_ARROW LCTL(LSFT(KC_RIGHT))

#define QUES LSFT(KC_SLASH)
#define EXCLM LSFT(KC_1)
#define AT LSFT(KC_2)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,              KC_3,         KC_4,          KC_5,            fuck,                            KC_PC_UNDO,     KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_AUDIO_VOL_DOWN,
    KC_ASTG,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_PC_COPY,                       KC_PC_UNDO,     KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_AUDIO_VOL_DOWN,                                
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                              KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_AUDIO_VOL_DOWN,                                                
    KC_PSCREEN,     KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_PC_PASTE,                        KC_PC_UNDO,     KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_AUDIO_VOL_DOWN,                                
    KC_CAPSLOCK,     KC_CAPSLOCK,     KC_CAPSLOCK,KC_CAPSLOCK,     KC_CAPSLOCK,                                                                              KC_U,           KC_I,           KC_O,           KC_P,           KC_AUDIO_VOL_DOWN,                                                             
                                                                                                    KC_5,   KC_T,                         KC_5,   KC_T,                   
                                                                                    KC_PC_PASTE,    KC_3,    KC_4,                  KC_PC_PASTE,    KC_3,    KC_4,
                                                                                    KC_BSPC,        KC_1,   KC_2,                    KC_BSPC,        KC_1,   KC_2 
  )

};


/*
    [0] = LAYOUT_ergodox_80(
RGB_MODE_PLAIN,RGB_MODE_BREATHE,RGB_MODE_BREATHE,RGB_M_SW,RGB_MODE_SNAKE,fuck ,RESET,                                KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
RGB_HUI,RGB_SAD,RGB_SAI,VLK_TOG,KC_G,KC_H,KC_J,                                                               KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
RGB_HUD,RGB_SAD,RGB_SAD,RGB_TOG,KC_B,KC_N,                                                                           KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
TOGGLE_LAYER_COLOR,RGB_SLD,RGB_SLD,KC_NLCK,KC_G,KC_H,KC_J,                                               KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
MO(0),MO(1),MO(2),KC_ENTER ,KC_SPC  ,                                                                                 KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
                     KC_Q,KC_Q,                                   KC_Q,KC_Q,
                 KC_Q,KC_Q,KC_Q,                                 KC_Q,KC_Q,KC_Q,                                  
                KC_Q,KC_Q,QMKURL,                                 KC_Q,KC_Q,KC_Q),
    [1] = LAYOUT_ergodox_80(
RGB_MODE_PLAIN,RGB_MODE_BREATHE,RGB_M_R,RGB_M_SW,RGB_MODE_SNAKE,KC_Y,KC_U,                                KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
RGB_HUI,RGB_HUD,KC_D,KC_F,KC_G,KC_H,KC_J,                                KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
RGB_SAI,RGB_SAD,KC_C,KC_V,KC_B,KC_N,                                          KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
RGB_VAI,RGB_VAD,KC_CLCK,KC_NLCK,KC_G,KC_H,KC_J,                                KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
MO(0),MO(1),MO(2),KC_F,KC_G,                                                    KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
                     KC_Q,KC_Q,                                   KC_Q,KC_Q,
                 KC_Q,KC_Q,KC_Q,                                 KC_Q,KC_Q,KC_Q,                                  
                KC_Q,KC_Q,KC_Q,                                 KC_Q,KC_Q,KC_Q),                                  
    [2] = LAYOUT_ergodox_80(
RGB_MODE_PLAIN,RGB_MODE_BREATHE,RGB_M_R,RGB_M_SW,RGB_MODE_SNAKE,KC_Y,KC_U,                                KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
RGB_HUI,RGB_HUD,KC_D,KC_F,KC_G,KC_H,KC_J,                                KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
RGB_SAI,RGB_SAD,KC_C,KC_V,KC_B,KC_N,                                          KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
RGB_VAI,RGB_VAD,KC_D,KC_F,KC_G,KC_H,KC_J,                                KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
MO(0),MO(1),MO(2),KC_F,KC_G,                                                    KC_Q,KC_Q,KC_Q,KC_Q,KC_Q,
                     KC_Q,KC_Q,                                   KC_Q,KC_Q,
                 KC_Q,KC_Q,KC_Q,                                 KC_Q,KC_Q,KC_Q,                                  
                KC_Q,KC_Q,KC_Q,                                 KC_Q,KC_Q,KC_Q)                                  
*/


/*  [_BASE] = LAYOUT_ergodox_80(
KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,                                
KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,                               
KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,                                       
KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,                               
KC_A,KC_S,KC_D,KC_F,KC_G,                                    
                                      KC_Q,KC_Q,                       
                                    KC_Q,KC_Q,KC_Q,
                                    KC_Q,KC_Q,KC_Q
                         )*/



/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/


bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;

uint16_t alt_tab_timer = 0;

/*
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
                                                                                
                if (is_alt_tab_active) {   
                    tap_code16(KC_TAB);
                } else {
                    tap_code16(C(A(KC_TAB)));
                    is_alt_tab_active = true;
                        }

        } else {
                
                if (is_alt_tab_active) {
                    tap_code16(S(KC_TAB));
                } else {
                    tap_code16(C(A(S(KC_TAB))));
                    is_alt_tab_active = true;
                        }       

                }
    }
}

*/


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
                                                                                
                if (is_ctl_tab_active) {   
                    tap_code16(KC_TAB);
                } else {
                    register_code(KC_LCTL);
                    tap_code16(KC_TAB);
                    is_ctl_tab_active = true;
                        }

        } else {
                
                if (is_alt_tab_active) {
                    tap_code16(S(KC_TAB));
                } else {
                    register_code(KC_LCTL);
                    tap_code16(S(KC_TAB));
                    is_ctl_tab_active = true;
                        }       

                }
    }
}


rgblight_config_t rgblight_config;
bool disable_layer_color = 0;
bool is_enabled = 0;

bool suspended = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                tap_code16(KC_ENTER);
                is_alt_tab_active = false;
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                    unregister_code(KC_LCTL);

                    is_ctl_tab_active = false;
            } else {
                // when keycode QMKURL is released
            }
            break;
        case KC_ENTER:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                    unregister_code(KC_LCTL);

                    is_ctl_tab_active = false;

                is_alt_tab_active = false;
            } else {
                // when keycode QMKURL is released
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                    unregister_code(KC_LCTL);

                    is_ctl_tab_active = false;

                is_alt_tab_active = false;
            } else {
                // when keycode QMKURL is released
            }
            break;
        case fuck:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("make 1motherfuck:default" SS_TAP(X_ENTER));
                is_alt_tab_active = false;
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case fuck2:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                tap_code16(KC_ENTER);
                is_alt_tab_active = false;
            } else {
                // when keycode QMKBEST is released
            }
            break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
      

    }
    return true;
}


/*
#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_GOLDENROD);
  rgblight_mode_noeeprom(my_capslock_layer);
 // rgblight_mode_noeeprom(RGBLIGHT_MODE_TWINKLE+0);
}
#endif
*/





/*
int enable_rgb_effects = 0;

        if(enable_rgb_effects){
                switch (biton32(layer_state)) {
                    case _base:
                    set_layer_color(_base)
                }
        }
*/


// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient
//const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 10}; // Set the last one to 10ms for some speedy swirls







/*
//uint8_t prev = _BASE;
uint32_t check;
uint32_t desired = 2;

void matrix_init_user() {
    rgblight_mode_noeeprom(8);
          rgblight_setrgb(0,0,255);
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
//  if (prev!=_d) {
      switch (layer) {
        case _BASE:
//          rgblight_mode_noeeprom(desired);
          break;
        
        case _dd: // If we're in swirl mode, then speed up the swirls, otherwise breathe
//          check = rgblight_get_mode();
//          if (check > 15 && check < 8) {
//            rgblight_mode_noeeprom(14);
                rgblight_mode_noeeprom(1);

          rgblight_setrgb(0,255,0);
//          } else {yyyy
            //rgblight_mode(check);
//          }d
//  prev = layer;
  return state;
}

*/


/*


uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=_L3) {
      switch (layer) {
        case _BASE:
          rgblight_sethsv(180, 255, 128);
          rgblight_mode(1);
          if (host_keyboard_leds()  & (1<<USB_LED_CAPS_LOCK) ) {
            rgblight_sethsv_at(39, 255, 255, 0);
            rgblight_sethsv_at(39, 255, 255, 1);
          }
          break;

        case _dd:
          rgblight_mode(1);
          rgblight_sethsv(150, 255, 255);
          break;

        case _d:
          rgblight_mode(1);
          rgblight_sethsv( 16, 176, 255);
          break;

      }
  } else {
      desired = rgblight_get_mode();
      get_hsv();
  }
  prev = layer;
  return state;
}

*/









/*
// RGB LED Indicators
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}     // Light 1 LED, starting with LED 0
);
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_ORANGE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_numlock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
*/


/*

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,223,252}, {0,223,252}, {0,223,252}, {31,208,234}, {31,208,234}, {97,231,230}, {97,231,230},{31,208,234} },

    [1] = { {255,246,238}, {255,246,238}, {255,246,238}, {255,246,238}, {255,246,238}, {166,240,228}, {0,183,238},  {42,248,240} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {82,247,246}, {82,247,246}, {178,231,238}, {0,242,205}, {0,0,0} }

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
void set_layer1_effects(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {

        hsv.h = hsv.h +50


        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

int enable_rgb_effects = 0;


void set_layer_color_custom(int layer) {
    if(enable_rgb_effects){
  switch (layer) {
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
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;

    }else{
      switch (layer) {
        case 0:
          set_layer_color(0);
          break;
        case 1:
          set_layer_color(1);
          break;
        case 2:
          set_layer_color(2);
          break;
       default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
          rgb_matrix_set_color_all(0, 0, 0);
        break;




    }

}


void matrix_scan_user(void){

    if (rgb_matrix_get_flags() == LED_FLAG_NONE){
        rgb_matrix_set_color_all(0,0,0);

    }else{

            set_layer_color_custom(biton32(layer_state))


    }
  }







}
*/



uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);


    switch (layer) {
      case 0:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(rgblight_get_mode());
          rgblight_sethsv_noeeprom(HSV_RED);
        }
        break;
      case 1:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(rgblight_get_mode());
          rgblight_sethsv_noeeprom(HSV_PURPLE);
        }
        break;
      case 2:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(rgblight_get_mode());
          rgblight_sethsv_noeeprom(HSV_CYAN);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }



    return state;


};


// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {2, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_PURPLE}
);
// etc..
const rgblight_segment_t PROGMEM default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 5, HSV_RED}
);
// etc..

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,
    default_layer

         // Overrides other layers
);





void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(HSV_WHITE); // sets the color to teal/cyan without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE); // sets mode to Fast breathing without saving
      rgblight_layers = my_rgb_layers;
}

