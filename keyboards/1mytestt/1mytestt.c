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
#include "1mytestt.h"
#include "ch.h"
#include "hal.h"
#include "rgb_matrix.h"
keyboard_config_t keyboard_config;

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


void suspend_power_down_kb(void) {
    rgb_matrix_set_color_all(0, 0, 0);
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

 void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}


/* Left B9   Right B8 */

// See http://jared.geek.nz/2013/feb/linear-led-pwm
static uint16_t cie_lightness(uint16_t v) {
  if (v <= 5243) // if below 8% of max
    return v / 9; // same as dividing by 900%
  else {
    uint32_t y = (((uint32_t) v + 10486) << 8) / (10486 + 0xFFFFUL); // add 16% of max and compare
    // to get a useful result with integer division, we shift left in the expression above
    // and revert what we've done again after squaring.
    y = y * y * y >> 8;
    if (y > 0xFFFFUL) // prevent overflow
      return 0xFFFFU;
    else
      return (uint16_t) y;
  }
}

static PWMConfig pwmCFG = {
    0xFFFF,/* PWM clock frequency  */
    256,/* initial PWM period (in ticks) 1S (1/10kHz=0.1mS 0.1ms*10000 ticks=1S) */
    NULL,
    {
        {PWM_OUTPUT_ACTIVE_HIGH, NULL},
        {PWM_OUTPUT_ACTIVE_HIGH, NULL},
        {PWM_OUTPUT_ACTIVE_HIGH, NULL},
        {PWM_OUTPUT_ACTIVE_HIGH, NULL}
    },
    0, /* HW dependent part.*/
    0
};

static uint32_t test_1_led_duty;
static uint32_t test_2_led_duty;
static uint32_t test_3_led_duty;
static uint32_t test_4_led_duty;




void test_1_led_level(uint8_t level) {
    test_1_led_duty = (uint32_t)(cie_lightness(0xFFFF * (uint32_t) level / 255));
    if (level == 0) {
        // Turn backlight off
        pwmDisableChannel(&PWMD4, 0);
    } else {
        // Turn backlight on
        pwmEnableChannel(&PWMD4, 0, PWM_FRACTION_TO_WIDTH(&PWMD4,0xFFFF,test_1_led_duty));
    }
}

void test_1_led_on(void){
    pwmEnableChannel(&PWMD4, 0, PWM_FRACTION_TO_WIDTH(&PWMD4,0xFFFF,test_1_led_duty));
}

void test_1_led_off(void){
    pwmDisableChannel(&PWMD4, 0);
}



void test_2_led_level(uint8_t level) {
    test_2_led_duty = (uint32_t)(cie_lightness(0xFFFF * (uint32_t) level / 255));
    if (level == 0) {
        // Turn backlight off
        pwmDisableChannel(&PWMD4, 1);
    } else {
        // Turn backlight on
        pwmEnableChannel(&PWMD4, 1, PWM_FRACTION_TO_WIDTH(&PWMD4,0xFFFF,test_2_led_duty));
    }
}

void test_2_led_on(void){
    pwmEnableChannel(&PWMD4, 1, PWM_FRACTION_TO_WIDTH(&PWMD4,0xFFFF,test_2_led_duty));
}

void test_2_led_off(void){
    pwmDisableChannel(&PWMD4, 1);
}



void test_3_led_level(uint8_t level) {
    test_3_led_duty = (uint32_t)(cie_lightness(0xFFFF * (uint32_t) level / 255));
    if (level == 0) {
        // Turn backlight off
        pwmDisableChannel(&PWMD4, 2);
    } else {
        // Turn backlight on
        pwmEnableChannel(&PWMD4, 2, PWM_FRACTION_TO_WIDTH(&PWMD4,0xFFFF,test_3_led_duty));
    }
}

void test_3_led_on(void){
    pwmEnableChannel(&PWMD4, 2, PWM_FRACTION_TO_WIDTH(&PWMD4,0xFFFF,test_3_led_duty));
}

void test_3_led_off(void){
    pwmDisableChannel(&PWMD4, 2);
}



void test_4_led_level(uint8_t level) {
    test_4_led_duty = (uint32_t)(cie_lightness(0xFFFF * (uint32_t) level / 255));
    if (level == 0) {
        // Turn backlight off
        pwmDisableChannel(&PWMD4, 3);
    } else {
        // Turn backlight on
        pwmEnableChannel(&PWMD4, 3, PWM_FRACTION_TO_WIDTH(&PWMD4,0xFFFF,test_4_led_duty));
    }
}

void test_4_led_on(void){
    pwmEnableChannel(&PWMD4, 3, PWM_FRACTION_TO_WIDTH(&PWMD4,0xFFFF,test_4_led_duty));
}

void test_4_led_off(void){
    pwmDisableChannel(&PWMD4, 3);
}



void led_initialize_hardware(void) {
    pwmStart(&PWMD4, &pwmCFG);

    // set up defaults
    test_1_led_level((uint8_t)keyboard_config.led_level * 255 / 4 );
    palSetPadMode(GPIOB, 6, PAL_MODE_ALTERNATE(2));
    test_2_led_level((uint8_t)keyboard_config.led_level * 255 / 4 );
    palSetPadMode(GPIOB, 7, PAL_MODE_ALTERNATE(2));
    test_3_led_level((uint8_t)keyboard_config.led_level * 255 / 4 );
    palSetPadMode(GPIOB, 8, PAL_MODE_ALTERNATE(2));
    test_4_led_level((uint8_t)keyboard_config.led_level * 255 / 4 );
    palSetPadMode(GPIOB, 9, PAL_MODE_ALTERNATE(2));


    // turn LEDs off by default
    test_1_led_off();
    test_2_led_off();
    test_3_led_off();
    test_4_led_off();
}



void keyboard_pre_init_kb(void) {
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }
    // read kb settings from eeprom
    keyboard_config.raw = eeconfig_read_kb();
#if defined(RGB_MATRIX_ENABLE)
    if (keyboard_config.rgb_matrix_enable) {
        rgb_matrix_set_flags(LED_FLAG_ALL);
    } else {
        rgb_matrix_set_flags(LED_FLAG_NONE);
    }
#endif
    led_initialize_hardware();
    keyboard_pre_init_user();
}





#if defined(RGB_MATRIX_ENABLE)
void keyboard_post_init_kb(void) {
    rgb_matrix_enable_noeeprom();
    keyboard_post_init_user();
}
#endif

void eeconfig_init_kb(void) {  // EEPROM is getting reset!
    keyboard_config.raw = 0;
    keyboard_config.rgb_matrix_enable = true;
    keyboard_config.led_level = 4;
    eeconfig_update_kb(keyboard_config.raw);
    eeconfig_init_user();
}


enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST

};


layer_state_t layer_state_set_kb(layer_state_t state) {
    test_1_led_off();
    test_2_led_off();
    test_3_led_off();
    test_4_led_off();
    state = layer_state_set_user(state);
    uint8_t layer = biton32(state);
    switch (layer) {
        case _BASE:
            test_1_led_on();
            break;
        case _LOWER:
            test_2_led_on();
            break;
        case _RAISE:
            test_1_led_on();
            test_2_led_on();
            break;
        default:
            break;
    }
    return state;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LED_LEVEL:
            if (record->event.pressed) {
                 keyboard_config.led_level++;
                 if (keyboard_config.led_level > 4) {
                    keyboard_config.led_level = 0;
                 }
                 test_1_led_level((uint8_t)keyboard_config.led_level * 255 / 4 );
                 test_2_led_level((uint8_t)keyboard_config.led_level * 255 / 4 );
                 test_3_led_level((uint8_t)keyboard_config.led_level * 255 / 4 );
                 test_4_led_level((uint8_t)keyboard_config.led_level * 255 / 4 );
                 eeconfig_update_kb(keyboard_config.raw);
                 layer_state_set_kb(layer_state);
            }
            break;
#ifdef RGB_MATRIX_ENABLE
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
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    keyboard_config.rgb_matrix_enable = false;
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    keyboard_config.rgb_matrix_enable = true;
                  }
                  break;
              }
              eeconfig_update_kb(keyboard_config.raw);
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
}


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




