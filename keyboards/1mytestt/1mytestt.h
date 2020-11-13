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
#pragma once

//#include "1mytest.h"
#include "quantum.h"

#define LAYOUT( \
K0, 	     	K1, 	K2, 	K3, 	K4, 	K5, 	K6, 	K7, 	K8, 	K9, 	K10, 	K11, 	K12, 	K13, 	K14, 	K15, 	                     	     \
K16, 	K17, 	K18, 	K19, 	K20, 	K21, 	K22, 	K23, 	K24, 	K25, 	K26, 	K27, 	K28, 	K29, 	K30, 	K31, 	K32, 	K33, 	K34, 	K35, 	K36, \
K37, 	K38, 	K39, 	K40, 	K41, 	K42, 	K43, 	K44, 	K45, 	K46, 	K47, 	K48, 	K49, 	K50, 	K51, 	K52, 	K53, 	K54, 	K55, 	K56, 	K57, \
K58, 	K59, 	K60, 	K61, 	K62, 	K63, 	K64, 	K65, 	K66, 	K67, 	K68, 	K69, 	     	K70, 	     	             	K71, 	K72, 	K73, 	     \
K74, 	K75, 	K76, 	K77, 	K78, 	K79, 	K80, 	K81, 	K82, 	K83, 	K84, 	     	     	K85, 	     	K86, 	     	K87, 	K88, 	K89, 	K90, \
K91, 	K92, 	K93, 	K94, 	                                     	     	K95, 	K96, 	K97, 	K98, 	K99, 	K100, 	K101, 	K102, 	     	K103 	     \
) \
{ \
    { K0, 	KC_NO, 	K1, 	K2, 	K3, 	K4, 	K5, 	K6, 	K7, 	K8, 	K9, 	K10, 	K11, 	K12, 	K13, 	K14, 	K15, 	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO   }, \
    { K16, 	K17, 	K18, 	K19, 	K20, 	K21, 	K22, 	K23, 	K24, 	K25, 	K26, 	K27, 	K28, 	K29, 	K30, 	K31, 	K32, 	K33, 	K34, 	K35, 	K36   }, \
    { K37, 	K38, 	K39, 	K40, 	K41, 	K42, 	K43, 	K44, 	K45, 	K46, 	K47, 	K48, 	K49, 	K50, 	K51, 	K52, 	K53, 	K54, 	K55, 	K56, 	K57   }, \
    { K58, 	K59, 	K60, 	K61, 	K62, 	K63, 	K64, 	K65, 	K66, 	K67, 	K68, 	K69, 	KC_NO, 	K70, 	KC_NO, 	KC_NO, 	KC_NO, 	K71, 	K72, 	K73, 	KC_NO  }, \
    { K74, 	K75, 	K76, 	K77, 	K78, 	K79, 	K80, 	K81, 	K82, 	K83, 	K84, 	KC_NO, 	KC_NO, 	K85, 	KC_NO, 	K86, 	KC_NO, 	K87, 	K88, 	K89, 	K90   }, \
    { K91, 	K92, 	K93, 	K94, 	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 	K95, 	K96, 	K97, 	K98, 	K99, 	K100, 	K101, 	K102, 	KC_NO, 	K103, 	KC_NO   } \
}


void planck_ez_right_led_on(void);
void planck_ez_right_led_off(void);
void planck_ez_right_led_level(uint8_t level);
void planck_ez_left_led_on(void);
void planck_ez_left_led_off(void);
void planck_ez_left_led_level(uint8_t level);

enum planck_ez_keycodes {
    LED_LEVEL = SAFE_RANGE,
    TOGGLE_LAYER_COLOR,
    EZ_SAFE_RANGE,
};

#ifndef WEBUSB_ENABLE
#    define WEBUSB_PAIR KC_NO
#endif

typedef union {
  uint32_t raw;
  struct {
    uint8_t      led_level :3;
    bool         disable_layer_led   :1;
    bool         rgb_matrix_enable   :1;
  };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;
