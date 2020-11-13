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
#include <print.h>
//#include "1mytestt.h"


int myrgb_flag = (LED_FLAG_ALL);
int myrgb_save_default_mode;
int myrgb_save_default_h;
int myrgb_save_default_s;
int myrgb_save_default_v;
int myrgb_save_default_sp;
HSV myrgb_save_default_hsv;



//float my_song4[][2] = SONG(gimoddi4);
/*
enum custom_keycodes {
    UG_TOG = SAFE_RANGE,
    UG_MODE_FORWARD,
    RGB_UG,
    RGB_KL,a
    RGB_UGKL,
    RGB_ALL,
    RGB_NONE,
    RGB_IND,
    TOGG,
    TRUEONFF,
    MACR1,
    MYTEST,
    WINLOCK
};

*/
/*
enum layer_names {
    BASEdd,
    LOWERdd,
    RAISEdd,
    ADJUSTdd
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASEdd] = LAYOUT(
        RGB_UG,   RGB_MODE_FORWARD, WINLOCK, RGB_MODE_REVERSE,  KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        RGB_ALL,  RGB_SAI,  RGB_SPI, RGB_VAD, RGB_NONE,  TRUEONFF, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        KC_A, RGB_SAD, RGB_SPD,  MYTEST,   MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        MO(2),  MO(1),  RESET,  MO(2), KC_A, KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,   KC_A,       KC_A, KC_A, KC_A,
        KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,     KC_A,   KC_A,   KC_A, KC_A, KC_A, KC_A,
        RGB_HUD, KC_A, KC_A, KC_A,             KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,   KC_A
        ),
    [LOWERdd] = LAYOUT(
        TOGGLE_LAYER_COLOR,   RGB_MODE_FORWARD, KC_A, NK_TOGG,  KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        WINLOCK,  RGB_ALL,  TOGG, KC_A, MACR1,  TRUEONFF, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        KC_A, RGB_UG, RGB_SPD,  MYTEST,   MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        MO(2),  MO(1),  RESET,  MO(2), KC_A, KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,   KC_A,       KC_A, KC_A, KC_A,
        KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,     KC_A,   KC_A,   KC_A, KC_A, KC_A, KC_A,
        TOGG, KC_A, KC_A, KC_A,             KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,   KC_A
        ),
    [RAISEdd] = LAYOUT(
        TOGGLE_LAYER_COLOR,   RGB_MODE_FORWARD, KC_A, NK_TOGG,  KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        WINLOCK,  RGB_ALL,  TOGG, KC_A, MACR1,  TRUEONFF, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        KC_A, RGB_UG, RGB_SPD,  MYTEST,   MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        MO(2),  MO(1),  RESET,  MO(2), KC_A, KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,   KC_A,       KC_A, KC_A, KC_A,
        KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,     KC_A,   KC_A,   KC_A, KC_A, KC_A, KC_A,
        TOGG, KC_A, KC_A, KC_A,             KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,   KC_A
        ),
    [ADJUSTdd] = LAYOUT(
        TOGGLE_LAYER_COLOR,   RGB_MODE_FORWARD, KC_A, NK_TOGG,  KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        WINLOCK,  RGB_ALL,  TOGG, KC_A, MACR1,  TRUEONFF, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        KC_A, RGB_UG, RGB_SPD,  MYTEST,   MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
        MO(2),  MO(1),  RESET,  KC_A, KC_A, KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,   KC_A,       KC_A, KC_A, KC_A,
        KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,     KC_A,   KC_A,   KC_A, KC_A, KC_A, KC_A,
        TOGG, KC_A, KC_A, KC_A,             KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,   KC_A
        )
};




layer_state_t layer_state_set_user(layer_state_t state) {

    switch (biton32(layer_state)) {

        case BASEdd:
            myrgb_save_default_mode = rgb_matrix_get_mode();
            myrgb_save_default_sp = rgb_matrix_get_speed();
            myrgb_save_default_h = rgb_matrix_get_hue();
            myrgb_save_default_s = rgb_matrix_get_sat();
            myrgb_save_default_v = rgb_matrix_get_val();
        break;

        case LOWERdd:
        break;

        case RAISEdd:
        break;

        case ADJUSTdd:
        break;

        default: //  for any other layers, or the default layer
        break;
    }

    switch (get_highest_layer(state)) {

        case BASEdd:
            rgb_matrix_set_flags(myrgb_flag);
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_mode(myrgb_save_default_mode);
            rgb_matrix_set_speed(myrgb_save_default_sp);
            rgb_matrix_sethsv_noeeprom(myrgb_save_default_h,myrgb_save_default_s,myrgb_save_default_v);
        break;

        case LOWERdd:
            rgb_matrix_set_flags(myrgb_flag);
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_mode_noeeprom(5);
            rgb_matrix_sethsv_noeeprom(180, 255, 255);
            rgb_matrix_set_speed_noeeprom(50);
        break;

        case RAISEdd:
            rgb_matrix_set_flags(myrgb_flag);
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_mode_noeeprom(5);
            rgb_matrix_sethsv_noeeprom(0, 255, 255);
            rgb_matrix_set_speed_noeeprom(50);
        break;

        case ADJUSTdd:
        break;







void rgb_matrix_indicators_user(void) {

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(91, 0, 0, 255);
    } else {
        //rgb_matrix_set_color(91, 0, 0, 0);
    }

    if (keymap_config.no_gui) {
        rgb_matrix_set_color(5, 0, 0, 255);
    } else {
        //rgb_matrix_set_color(91, 0, 0, 0);
    }

    if (g_suspend_state || keyboard_config.disable_layer_led) { return; }


    switch (biton32(layer_state)) {

        case BASEdd:

        //set_layer_color(0);
        break;

        case LOWERdd:
        rgb_matrix_set_color(0,31,255,255);rgb_matrix_set_color(1,31,255,255);rgb_matrix_set_color(2,31,255,255);rgb_matrix_set_color(3,31,255,255);rgb_matrix_set_color(4,31,255,255);rgb_matrix_set_color(5,31,255,255);rgb_matrix_set_color(6,31,255,255);rgb_matrix_set_color(7,31,255,255);rgb_matrix_set_color(8,31,255,255);rgb_matrix_set_color(9,31,255,255);rgb_matrix_set_color(10,31,255,255);rgb_matrix_set_color(11,31,255,255);rgb_matrix_set_color(12,31,255,255);rgb_matrix_set_color(13,31,255,255);rgb_matrix_set_color(14,31,255,255);rgb_matrix_set_color(15,31,255,255);rgb_matrix_set_color(16,31,255,255);rgb_matrix_set_color(17,31,255,255);rgb_matrix_set_color(18,31,255,255);rgb_matrix_set_color(19,31,255,255);rgb_matrix_set_color(20,31,255,255);rgb_matrix_set_color(21,31,255,255);rgb_matrix_set_color(22,31,255,255);rgb_matrix_set_color(23,31,255,255);rgb_matrix_set_color(24,31,255,255);rgb_matrix_set_color(25,31,255,255);rgb_matrix_set_color(26,31,255,255);rgb_matrix_set_color(27,31,255,255);rgb_matrix_set_color(28,31,255,255);rgb_matrix_set_color(29,31,255,255);rgb_matrix_set_color(30,31,255,255);rgb_matrix_set_color(31,31,255,255);rgb_matrix_set_color(32,31,255,255);rgb_matrix_set_color(33,31,255,255);rgb_matrix_set_color(34,31,255,255);rgb_matrix_set_color(35,31,255,255);rgb_matrix_set_color(36,31,255,255);rgb_matrix_set_color(37,31,255,255);rgb_matrix_set_color(38,31,255,255);rgb_matrix_set_color(39,31,255,255);rgb_matrix_set_color(40,31,255,255);rgb_matrix_set_color(41,31,255,255);rgb_matrix_set_color(42,31,255,255);rgb_matrix_set_color(43,31,255,255);rgb_matrix_set_color(44,31,255,255);rgb_matrix_set_color(45,31,255,255);rgb_matrix_set_color(46,31,255,255);rgb_matrix_set_color(47,31,255,255);rgb_matrix_set_color(48,31,255,255);rgb_matrix_set_color(49,31,255,255);rgb_matrix_set_color(50,31,255,255);rgb_matrix_set_color(51,31,255,255);rgb_matrix_set_color(52,31,255,255);rgb_matrix_set_color(53,31,255,255);rgb_matrix_set_color(54,31,255,255);rgb_matrix_set_color(55,31,255,255);rgb_matrix_set_color(56,31,255,255);rgb_matrix_set_color(57,31,255,255);rgb_matrix_set_color(58,31,255,255);rgb_matrix_set_color(59,31,255,255);rgb_matrix_set_color(60,31,255,255);rgb_matrix_set_color(61,31,255,255);rgb_matrix_set_color(62,31,255,255);
        break;

        case RAISEdd:
        rgb_matrix_set_color(0,70,0,100);rgb_matrix_set_color(1,150,0,255);rgb_matrix_set_color(2,128,0,255);rgb_matrix_set_color(3,100,0,150);rgb_matrix_set_color(4,100,0,150);rgb_matrix_set_color(5,100,0,150);rgb_matrix_set_color(6,100,0,150);rgb_matrix_set_color(7,100,0,150);rgb_matrix_set_color(8,100,0,150);rgb_matrix_set_color(9,100,0,150);rgb_matrix_set_color(10,100,0,150);rgb_matrix_set_color(11,100,0,150);rgb_matrix_set_color(12,100,0,150);rgb_matrix_set_color(13,100,0,150);rgb_matrix_set_color(14,100,0,150);rgb_matrix_set_color(15,100,0,150);rgb_matrix_set_color(16,100,0,150);rgb_matrix_set_color(17,100,0,150);rgb_matrix_set_color(18,100,0,150);rgb_matrix_set_color(19,0,253,0);rgb_matrix_set_color(20,0,253,0);rgb_matrix_set_color(21,0,253,0);rgb_matrix_set_color(22,0,253,0);rgb_matrix_set_color(23,0,253,0);rgb_matrix_set_color(24,0,253,0);rgb_matrix_set_color(25,0,253,0);rgb_matrix_set_color(26,0,253,0);rgb_matrix_set_color(27,0,253,0);rgb_matrix_set_color(28,0,253,0);rgb_matrix_set_color(29,0,253,0);rgb_matrix_set_color(30,0,253,0);rgb_matrix_set_color(31,0,253,0);rgb_matrix_set_color(32,0,253,0);rgb_matrix_set_color(33,0,253,0);rgb_matrix_set_color(34,0,253,0);rgb_matrix_set_color(35,0,253,0);rgb_matrix_set_color(36,0,253,0);rgb_matrix_set_color(37,0,253,0);rgb_matrix_set_color(38,0,253,0);rgb_matrix_set_color(39,0,253,0);rgb_matrix_set_color(40,0,253,0);rgb_matrix_set_color(41,0,253,0);rgb_matrix_set_color(42,0,253,0);rgb_matrix_set_color(43,0,253,0);rgb_matrix_set_color(44,100,0,150);rgb_matrix_set_color(45,100,0,150);rgb_matrix_set_color(46,100,0,150);rgb_matrix_set_color(47,100,0,150);rgb_matrix_set_color(48,100,0,150);rgb_matrix_set_color(49,100,0,150);rgb_matrix_set_color(50,100,0,150);rgb_matrix_set_color(51,100,0,150);rgb_matrix_set_color(52,100,0,150);rgb_matrix_set_color(53,100,0,150);rgb_matrix_set_color(54,100,0,150);rgb_matrix_set_color(55,100,0,150);rgb_matrix_set_color(56,100,0,150);rgb_matrix_set_color(57,100,0,150);rgb_matrix_set_color(58,100,0,150);rgb_matrix_set_color(59,100,0,150);rgb_matrix_set_color(60,100,0,150);rgb_matrix_set_color(61,100,0,150);rgb_matrix_set_color(62,100,0,150);
        break;

        case ADJUSTdd:
            //set_layer_color(3);
        break;

        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE){
                rgb_matrix_set_color_all(0, 0, 0);
            }
        break;
    }

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(91, 0, 0, 255);
    } else {
        //rgb_matrix_set_color(91, 0, 0, 0);
    }

    if (keymap_config.no_gui) {
        rgb_matrix_set_color(5, 0, 0, 255);
    } else {
        //rgb_matrix_set_color(91, 0, 0, 0);
    }




}

*/

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
/*
    switch (keycode) {

        case UG_TOG:
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
        break;

        case MACR1:
            if (record -> event.pressed) {
                SEND_STRING("dlrjsanj qudtlseh dkslrh gksrmfxkwkfmf duftlagl dustmqgoQhqhehfhr gkwk dkdrlah" "El zkzpznfndl qhfaksgksp 4rl godqhrghlfh vnfrkehd;" SS_DELAY(100));
            }
        break;

        case MYTEST:
            if (record -> event.pressed) {
                SEND_STRING("make 1mytaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaest:default -j8" SS_DELAY(100)SS_DELAY(100)SS_TAP(X_ENTER));
            }
        break;

        case UG_MODE_FORWARD:
            //handleKeycodeRGB(shifted, rgblight_step, rgblight_step_reverse);
        break;

        case RGB_UG:
            if (record -> event.pressed) {
                rgb_matrix_set_flags(LED_FLAG_UNDERGLOW | LED_FLAG_INDICATOR);
                myrgb_flag = LED_FLAG_UNDERGLOW | LED_FLAG_INDICATOR;
                rgb_matrix_set_color_all(0, 0, 0);
            } else {
                    // when keycode QMKURL is released
            }
        break;

        case RGB_KL:
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR);
            myrgb_flag = LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR;
            myrgb_flag = LED_FLAG_UNDERGLOW;

            rgb_matrix_set_color_all(0, 0, 0);
        break;

        case RGB_UGKL:
            if (record -> event.pressed) {

                rgb_matrix_set_flags(
                    LED_FLAG_UNDERGLOW | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR
                    );
                myrgb_flag = LED_FLAG_UNDERGLOW | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR;
                rgb_matrix_set_color_all(0, 0, 0);
            } else {
                    // when keycode QMKURL is released
            }

        break;

        case RGB_IND:
            rgb_matrix_set_flags(LED_FLAG_INDICATOR);
            rgb_matrix_set_color_all(0, 0, 0);
        break;

        case RGB_ALL:
            rgb_matrix_set_flags(LED_FLAG_ALL);
            myrgb_flag = LED_FLAG_ALL;

            rgb_matrix_set_color_all(0, 0, 0);
        break;

        case RGB_NONE:
            rgb_matrix_set_flags(LED_FLAG_NONE);
            myrgb_flag = LED_FLAG_NONE;
            rgb_matrix_set_color_all(0, 0, 0);
        break;

        case TOGG:

            if (record -> event.pressed) {

                if (myrgb_enabled) {
                    myrgb_save = rgb_matrix_get_mode();
                    rgb_matrix_mode(39);
                        //rgb_matrix_step_reverse();
                    myrgb_enabled = false;
                } else {
                    rgb_matrix_mode(myrgb_save);
                    myrgb_enabled = true;
                }
            } else {
                    // when keycode QMKBEST is released
            }
        break;

        case WINLOCK:

            if (record -> event.pressed) {

                PLAY_SONG(my_song4);
                if (keymap_config.no_gui) {
                    keymap_config.no_gui = false;

                } else {
                    keymap_config.no_gui = true;
                }
            } else {
                    // when keycode QMKBEST is released
            }
        break;

        case TRUEONFF:
            if (record -> event.pressed) {
                rgb_matrix_toggle();
            }
        break;

    }


    */
        return true;
}







void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    myrgb_save_default_mode= rgb_matrix_get_mode();
    myrgb_save_default_sp = rgb_matrix_get_speed();
    myrgb_save_default_h = rgb_matrix_get_hue();
    myrgb_save_default_s = rgb_matrix_get_sat();
    myrgb_save_default_v = rgb_matrix_get_val();
    layer_state_set_user(layer_state);

}



/*
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
[0]  =  { {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {15, 224, 255}, {15, 224, 255}, {15, 224, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}  },
[1] = { {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255} },
[2]  =  { {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {104, 255, 176}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {10, 215, 247}, {15, 224, 255}, {15, 224, 255}, {15, 224, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}, {212, 255, 255}  },
[3]  = { {31,255,255},  {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255},   {31,255,255} }
};
*/

//#define _LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)





/*


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


*/






/*

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
case _LOWER:
return false;
default:
return true;
}
}
#endif
*/
#ifdef ENCODER_ENABLE


void encoder_update_user(uint8_t index, bool clockwise) {
/* With an if statement we can check which encoder was turned. */
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code16(KC_AUDIO_VOL_UP);
        } else {
            tap_code16(KC_AUDIO_VOL_DOWN);
        }
    }
}
#endif




//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################



enum layer_names {
    buut1,
    bunn2,
    bunn3
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [buut1] = LAYOUT(TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, WINLOCK, RGB_MODE_REVERSE, TRUEONFF, TOGGLE_LAYER_COLOR, TOGGLE_LAYER_COLOR, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_SPD, RGB_SPI, RGB_ALL, RGB_NONE, TRUEONFF, MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_VAI, RGB_HUI, RGB_SAI, KC_A, KC_A, KC_A, KC_A, RGB_SAD, RGB_ALL, RGB_UG, MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_VAD, RGB_HUD, RGB_SAD, KC_A, KC_A, KC_A, KC_A, KC_A, TT(1), RESET, TT(2), KC_A, KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A),
    [bunn2] = LAYOUT(TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, WINLOCK, RGB_MODE_REVERSE, TRUEONFF, TOGGLE_LAYER_COLOR, TOGGLE_LAYER_COLOR, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_SPD, RGB_SPI, RGB_ALL, RGB_NONE, TRUEONFF, MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_VAI, RGB_HUI, RGB_SAI, KC_A, KC_A, KC_A, KC_A, RGB_SAD, RGB_ALL, RGB_UG, MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_VAD, RGB_HUD, RGB_SAD, KC_A, KC_A, KC_A, KC_A, KC_A, TT(1), RESET, TT(2), KC_A, KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A),
    [bunn3] = LAYOUT(TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, WINLOCK, RGB_MODE_REVERSE, TRUEONFF, TOGGLE_LAYER_COLOR, TOGGLE_LAYER_COLOR, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_SPD, RGB_SPI, RGB_ALL, RGB_NONE, TRUEONFF, MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_VAI, RGB_HUI, RGB_SAI, KC_A, KC_A, KC_A, KC_A, RGB_SAD, RGB_ALL, RGB_UG, MYTEST, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, RGB_VAD, RGB_HUD, RGB_SAD, KC_A, KC_A, KC_A, KC_A, KC_A, TT(1), RESET, TT(2), KC_A, KC_B, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A)
};
layer_state_t layer_state_set_user(layer_state_t state) {

    switch (biton32(layer_state)) {
        case buut1:
            myrgb_save_default_mode = rgb_matrix_get_mode();
            myrgb_save_default_sp = rgb_matrix_get_speed();
            myrgb_save_default_h = rgb_matrix_get_hue();
            myrgb_save_default_s = rgb_matrix_get_sat();
            myrgb_save_default_v = rgb_matrix_get_val();
        break;

        case bunn2:
        break;

        case bunn3:
        break;

		default: //  for any other layers, or the default layer
		break;
	}

	switch (get_highest_layer(state)) {

        case buut1:

            rgb_matrix_set_flags(myrgb_flag);
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_mode(myrgb_save_default_mode);
            rgb_matrix_set_speed(myrgb_save_default_sp);
            rgb_matrix_sethsv_noeeprom(myrgb_save_default_h,myrgb_save_default_s,myrgb_save_default_v);
        break;

        case bunn2:
            rgb_matrix_set_flags(myrgb_flag);
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_mode_noeeprom(5);
            rgb_matrix_sethsv_noeeprom(180, 255, 255);
            rgb_matrix_set_speed_noeeprom(50);
        break;

        case bunn3:
            rgb_matrix_set_flags(myrgb_flag);
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_mode_noeeprom(5);
            rgb_matrix_sethsv_noeeprom(180, 255, 255);
            rgb_matrix_set_speed_noeeprom(50);
        break;

        default: //  for any other layers, or the default layer
        break;
    }

    return state;
}void rgb_matrix_indicators_user(void) {

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(91, 0, 0, 255);
    } else {
        //rgb_matrix_set_color(91, 0, 0, 0);
    }

    if (keymap_config.no_gui) {
        rgb_matrix_set_color(5, 0, 0, 255);
    } else {
        //rgb_matrix_set_color(91, 0, 0, 0);
    }

    if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

    switch (biton32(layer_state)) {

        case buut1:
            rgb_matrix_set_color(0, 181, 83, 255);rgb_matrix_set_color(1, 62, 0, 108);rgb_matrix_set_color(2, 98, 0, 172);rgb_matrix_set_color(3, 150, 9, 255);rgb_matrix_set_color(5, 210, 151, 255);rgb_matrix_set_color(6, 234, 205, 255);rgb_matrix_set_color(7, 9, 255, 56);rgb_matrix_set_color(8, 9, 255, 56);rgb_matrix_set_color(9, 255, 255, 255);rgb_matrix_set_color(10, 255, 255, 255);rgb_matrix_set_color(11, 255, 255, 255);rgb_matrix_set_color(12, 255, 255, 255);rgb_matrix_set_color(30, 169, 208, 142);rgb_matrix_set_color(31, 169, 208, 142);rgb_matrix_set_color(32, 169, 208, 142);rgb_matrix_set_color(51, 169, 208, 142);rgb_matrix_set_color(52, 169, 208, 142);rgb_matrix_set_color(53, 169, 208, 142);rgb_matrix_set_color(57, 0, 176, 80);rgb_matrix_set_color(90, 0, 0, 255);rgb_matrix_set_color(102, 255, 0, 255);
        break;

        case bunn2:
            rgb_matrix_set_color(0, 181, 83, 255);rgb_matrix_set_color(1, 62, 0, 108);rgb_matrix_set_color(2, 98, 0, 172);rgb_matrix_set_color(3, 150, 9, 255);rgb_matrix_set_color(5, 210, 151, 255);rgb_matrix_set_color(6, 234, 205, 255);rgb_matrix_set_color(7, 9, 255, 56);rgb_matrix_set_color(8, 9, 255, 56);rgb_matrix_set_color(9, 255, 255, 255);rgb_matrix_set_color(10, 255, 255, 255);rgb_matrix_set_color(11, 255, 255, 255);rgb_matrix_set_color(12, 255, 255, 255);rgb_matrix_set_color(30, 169, 208, 142);rgb_matrix_set_color(31, 169, 208, 142);rgb_matrix_set_color(32, 169, 208, 142);rgb_matrix_set_color(51, 169, 208, 142);rgb_matrix_set_color(52, 169, 208, 142);rgb_matrix_set_color(53, 169, 208, 142);rgb_matrix_set_color(57, 0, 176, 80);rgb_matrix_set_color(90, 0, 0, 255);rgb_matrix_set_color(102, 255, 0, 255);
        break;

        case bunn3:
            rgb_matrix_set_color(0, 181, 83, 255);rgb_matrix_set_color(1, 62, 0, 108);rgb_matrix_set_color(2, 98, 0, 172);rgb_matrix_set_color(3, 150, 9, 255);rgb_matrix_set_color(5, 210, 151, 255);rgb_matrix_set_color(6, 234, 205, 255);rgb_matrix_set_color(7, 9, 255, 56);rgb_matrix_set_color(8, 9, 255, 56);rgb_matrix_set_color(9, 255, 255, 255);rgb_matrix_set_color(10, 255, 255, 255);rgb_matrix_set_color(11, 255, 255, 255);rgb_matrix_set_color(12, 255, 255, 255);rgb_matrix_set_color(30, 169, 208, 142);rgb_matrix_set_color(31, 169, 208, 142);rgb_matrix_set_color(32, 169, 208, 142);rgb_matrix_set_color(51, 169, 208, 142);rgb_matrix_set_color(52, 169, 208, 142);rgb_matrix_set_color(53, 169, 208, 142);rgb_matrix_set_color(57, 0, 176, 80);rgb_matrix_set_color(90, 0, 0, 255);rgb_matrix_set_color(102, 255, 0, 255);
        break;


		default:
			if (rgb_matrix_get_flags() == LED_FLAG_NONE){
				rgb_matrix_set_color_all(0, 0, 0);
			}
		break;
	}

	if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
		rgb_matrix_set_color(91, 0, 0, 255);
	} else {
		//rgb_matrix_set_color(91, 0, 0, 0);
	}

	if (keymap_config.no_gui) {
		rgb_matrix_set_color(5, 0, 0, 255);
	} else {
		//rgb_matrix_set_color(91, 0, 0, 0);
	}

}


//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################
//########################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################



