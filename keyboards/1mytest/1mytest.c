/* Copyright 2018 Jack Humbert <jack.humb@gmail.com>
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
#include "1mytest.h"
#include "ch.h"
#include "hal.h"



keyboard_config_t keyboard_config;

#ifdef RGB_MATRIX_ENABLE
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
{0, B_1, A_1, C_1},
{0, H_1, G_1, I_1},
{0, K_1, J_1, L_1},
{0, B_7, A_7, C_7},
{0, E_7, D_7, F_7},
{0, H_7, G_7, I_7},
{0, K_7, J_7, L_7},
{0, B_12, A_12, C_12},
{0, E_12, D_12, F_12},
{1, B_1, A_1, C_1},
{1, E_1, D_1, F_1},
{1, H_1, G_1, I_1},
{1, K_1, J_1, L_1},
{1, B_7, A_7, C_7},
{1, E_7, D_7, F_7},
{1, H_7, G_7, I_7},
{0, B_2, A_2, C_2},
{0, E_2, D_2, F_2},
{0, H_2, G_2, I_2},
{0, K_2, J_2, L_2},
{0, B_8, A_8, C_8},
{0, E_8, D_8, F_8},
{0, H_8, G_8, I_8},
{0, K_8, J_8, L_8},
{0, B_13, A_13, C_13},
{0, E_13, D_13, F_13},
{1, B_2, A_2, C_2},
{1, E_2, D_2, F_2},
{1, H_2, G_2, I_2},
{1, K_2, J_2, L_2},
{1, B_8, A_8, C_8},
{1, E_8, D_8, F_8},
{1, H_8, G_8, I_8},
{1, B_12, A_12, C_12},
{1, E_12, D_12, F_12},
{1, H_12, G_12, I_12},
{1, K_12, J_12, L_12},
{0, B_3, A_3, C_3},
{0, E_3, D_3, F_3},
{0, H_3, G_3, I_3},
{0, K_3, J_3, L_3},
{0, B_9, A_9, C_9},
{0, E_9, D_9, F_9},
{0, H_9, G_9, I_9},
{0, K_9, J_9, L_9},
{0, B_14, A_14, C_14},
{0, E_14, D_14, F_14},
{1, B_3, A_3, C_3},
{1, E_3, D_3, F_3},
{1, H_3, G_3, I_3},
{1, K_3, J_3, L_3},
{1, B_9, A_9, C_9},
{1, E_9, D_9, F_9},
{1, H_9, G_9, I_9},
{1, B_13, A_13, C_13},
{1, E_13, D_13, F_13},
{1, H_13, G_13, I_13},
{1, K_13, J_13, L_13},
{0, B_4, A_4, C_4},
{0, E_4, D_4, F_4},
{0, H_4, G_4, I_4},
{0, K_4, J_4, L_4},
{0, B_10, A_10, C_10},
{0, E_10, D_10, F_10},
{0, H_10, G_10, I_10},
{0, K_10, J_10, L_10},
{0, B_15, A_15, C_15},
{0, E_15, D_15, F_15},
{1, B_4, A_4, C_4},
{1, E_4, D_4, F_4},
{1, K_4, J_4, L_4},
{1, B_14, A_14, C_14},
{1, E_14, D_14, F_14},
{1, H_14, G_14, I_14},
{0, B_5, A_5, C_5},
{0, E_5, D_5, F_5},
{0, H_5, G_5, I_5},
{0, K_5, J_5, L_5},
{0, B_11, A_11, C_11},
{0, E_11, D_11, F_11},
{0, H_11, G_11, I_11},
{0, K_11, J_11, L_11},
{0, B_16, A_16, C_16},
{0, E_16, D_16, F_16},
{1, B_5, A_5, C_5},
{1, K_5, J_5, L_5},
{1, E_10, D_10, F_10},
{1, B_15, A_15, C_15},
{1, E_15, D_15, F_15},
{1, H_15, G_15, I_15},
{1, K_15, J_15, L_15},
{0, B_6, A_6, C_6},
{0, E_6, D_6, F_6},
{0, H_6, G_6, I_6},
{0, K_6, J_6, L_6},
{1, B_6, A_6, C_6},
{1, E_6, D_6, F_6},
{1, H_6, G_6, I_6},
{1, K_6, J_6, L_6},
{1, B_11, A_11, C_11},
{1, E_11, D_11, F_11},
{1, H_11, G_11, I_11},
{1, B_16, A_16, C_16},
{1, H_16, G_16, I_16}



};

led_config_t g_led_config = { {
    {   NO_LED, 	NO_LED, 1, 	2, 	3, 	4, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	13, 	14, 	15, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED  },
    {  16, 	17, 		NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	26, 	27, 	28, 	29, 	30, 	31, 	32, 	33, 	34, 	35, 	36  },
    {  37, 	38, 	39, 	40, 	41, 	42, 	43, 	44, 	45, 	46, 	47, 	48, 	49, 	50, 	51, 	52, 	53, 	54, 	55, 	56, 	57  },
    {  58, 	59, 	60, 	61, 	62, 	63, 	64, 	65, 	66, 	67, 	68, 	69, 	NO_LED, 	70, 	NO_LED, 	NO_LED, 	NO_LED, 	71, 	72, 	73, 	NO_LED },
    {  74, 	75, 	76, 	77, 	78, 	79, 	80, 	81, 	82, 	83, 	84, 	NO_LED, 	NO_LED, 	85, 	NO_LED, 	86, 	NO_LED, 	87, 	88, 	89, 	90  },
    {  91, 	92, 	93, 	94, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	NO_LED, 	95, 	96, 	97, 	98, 	99, 	100, 	101, 	102, 	NO_LED, 	103, 	NO_LED  }
}, {
{0,0},		{21,0},	{32,0},	{42,0},	{53,0},	{69,0},	{79,0},	{89,0},	{100,0},	{116,0},	{126,0},	{138,0},	{147,0},	{160,0},	{171,0},	{181,0},
{0,13},	{11,13},	{21,13},	{32,13},	{42,13},	{53,13},	{63,13},	{74,13},	{84,13},	{95,13},	{105,13},	{116,13},	{126,13},	{142,13},	{160,13},	{171,13},	{181,13},	{194,13},	{205,13},	{215,13},	{225,13},
{3,23},	{16,23},	{27,23},	{37,23},	{48,23},	{58,23},	{68,23},	{79,23},	{89,23},	{100,23},	{110,23},	{121,23},	{131,23},	{144,23},	{160,23},	{171,23},	{181,23},	{194,23},	{205,23},	{215,23},	{225,23},
{4,39},	{19,39},	{29,39},	{40,39},	{50,39},	{61,39},	{71,39},	{82,39},	{92,39},	{103,39},	{113,39},	{123,39},		{140,39},				{194,39},	{205,39},	{215,39},
{7,52},	{24,52},	{35,52},	{45,52},	{55,52},	{66,52},	{76,52},	{87,52},	{97,52},	{108,52},	{118,52},			{138,52},		{171,52},		{194,52},	{205,52},	{215,52},	{225,52},
{2,63},	{15,63},	{28,63},	{67,63},							{106,63},	{120,63},	{133,63},	{146,63},	{160,63},	{171,63},	{181,63},	{194,63},		{215,63},
}, {
2,		2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,
2,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	1,	4,	4,	4,	4,	4,	4,	4,
2,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	1,	4,	4,	4,	4,	4,	4,	4,
2,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,		1,				4,	4,	4,
2,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,			1,		4,		4,	4,	4,	4,
8,	1,	1,	1,							1,	1,	1,	1,	2,	2,	2,	4,		4
} };


/*
const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
0, 	 	1, 	2, 	3, 	4, 	5, 	6, 	7, 	8, 	9, 	10, 	11, 	12, 	13, 	14, 	15,
16, 	17, 	18, 	19, 	20, 	21, 	22, 	23, 	24, 	25, 	26, 	27, 	28, 	29, 	30, 	31, 	32, 	33, 	34, 	35, 	36,
37, 	38, 	39, 	40, 	41, 	42, 	43, 	44, 	45, 	46, 	47, 	48, 	49, 	50, 	51, 	52, 	53, 	54, 	55, 	56, 	57,
58, 	59, 	60, 	61, 	62, 	63, 	64, 	65, 	66, 	67, 	68, 	69, 	 	70, 	 	71, 	72, 	73,
74, 	75, 	76, 	77, 	78, 	79, 	80, 	81, 	82, 	83, 	84, 	 	85, 	 	86, 	 	87, 	88, 	89, 	90,
91, 	92, 	93, 	94, 	 	95, 	96, 	97, 	98, 	99, 	100, 	101, 	102, 	 	103
);
*/





bool myrgb_enabled = true;
int myrgb_save;
bool mywin_locked = false;

int myrgb_flag_kb = (LED_FLAG_ALL);




//float my_song4[][2] = SONG(gimoddi4);










void suspend_power_down_kb(void) {
    rgb_matrix_set_color_all(0, 0, 0);
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

 void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif



void keyboard_pre_init_kb(void) {
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }
    // read kb settings from eeprom
    keyboard_config.raw = eeconfig_read_kb();
    keyboard_pre_init_user();
}





#if defined(RGB_MATRIX_ENABLE) && defined(ORYX_CONFIGURATOR)
void keyboard_post_init_kb(void) {
    rgb_matrix_enable_noeeprom();
            for (uint16_t i = 255; i > 0; i--) {
            rgblight_sethsv_noeeprom( ( i + old_hue) % 255, 255, 255);
            }
    keyboard_post_init_user();
}
#endif

void eeconfig_init_kb(void) {  // EEPROM is getting reset!
    keyboard_config.raw = 0;
    keyboard_config.rgb_matrix_enable = true;
    eeconfig_update_kb(keyboard_config.raw);
    eeconfig_init_user();
}

#ifdef RGB_MATRIX_ENABLE


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOGGLE_LAYER_COLOR:
            if (record->event.pressed) {
                keyboard_config.disable_layer_led ^= 1;
                if (keyboard_config.disable_layer_led)
                    rgb_matrix_set_color_all(0, 0, 0);
                eeconfig_update_kb(keyboard_config.raw);
            }
            break;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);//doriginally none
                    keyboard_config.rgb_matrix_enable = false;
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;

                case LED_FLAG_MODIFIER: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);//doriginally none
                    keyboard_config.rgb_matrix_enable = false;
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);//doriginally none
                    keyboard_config.rgb_matrix_enable = false;
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);//doriginally none
                    keyboard_config.rgb_matrix_enable = false;
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_INDICATOR: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);//doriginally none
                    keyboard_config.rgb_matrix_enable = true;
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;


                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);//doriginally alll
                    keyboard_config.rgb_matrix_enable = true;
                  }
                  break;
              }
              eeconfig_update_kb(keyboard_config.raw);
            }
            return false;

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
                myrgb_flag_kb = LED_FLAG_UNDERGLOW | LED_FLAG_INDICATOR;
                rgb_matrix_set_color_all(0, 0, 0);
            } else {
                    // when keycode QMKURL is released
            }
        break;

        case RGB_KL:
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR);
            myrgb_flag_kb = LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR;
            myrgb_flag_kb = LED_FLAG_UNDERGLOW;

            rgb_matrix_set_color_all(0, 0, 0);
        break;

        case RGB_UGKL:
            if (record -> event.pressed) {

                rgb_matrix_set_flags(
                    LED_FLAG_UNDERGLOW | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR
                    );
                myrgb_flag_kb = LED_FLAG_UNDERGLOW | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR;
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
            myrgb_flag_kb = LED_FLAG_ALL;

            rgb_matrix_set_color_all(0, 0, 0);
        break;

        case RGB_NONE:
            rgb_matrix_set_flags(LED_FLAG_NONE);
            myrgb_flag_kb = LED_FLAG_NONE;
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

                //PLAY_SONG(my_song4);
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
    return process_record_user(keycode, record);
}

#endif

/*
#ifdef AUDIO_ENABLE
bool music_mask_kb(uint16_t keycode) {
    switch (keycode) {
    case QK_LAYER_TAP ... QK_ONE_SHOT_LAYER_MAX:
    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_MOD_MAX:
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case AU_ON ... MUV_DE:
    case RESET:
    case EEP_RST:
        return false;
    default:
        return music_mask_user(keycode);
    }
}
#endif
*/



