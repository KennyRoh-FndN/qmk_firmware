/*
Copyright 2018 Massdrop Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//Define number of ISSI3733 drivers being used (1...16)
#define ISSI3733_DRIVER_COUNT 2
#define DRIVER_LED_TOTAL ISSI3733_LED_COUNT

//Hardware address of each driver (Refer to ISSI3733 pdf "Table 1 Slave Address" and keyboard schematic)
#define ISSI3773_DRIVER_ADDRESSES {  0xA0,0xBE }

//LED I2C bus speed
#define I2C_HZ 580000

//Count of LED bodies
#define ISSI3733_LED_COUNT 104

#define LED_GCR_MAX                 165         //Max GCR value (0 - 255) WARNING: Raising this value may overload the LED drivers and USB bus
#define LED_GCR_STEP                10          //GCR increment/decrement value

#ifdef USE_MASSDROP_CONFIGURATOR
#define ANIMATION_SPEED_STEP        1

#define BREATHE_STEP                1
#define BREATHE_MIN_STEP            0
#define BREATHE_MAX_STEP            255
#endif

//Default Global Current Register value (Default brightness 0 - 255)
#define ISSI3733_GCR_DEFAULT LED_GCR_MAX

//Automatic power rollback and recovery
#define V5_HIGH                     2540        //5V high level (After low power detect, point at which LEDs are allowed to use more power )
#define V5_LOW                      2480        //5V low level (LED power rolled back to stay above this limit)
#define V5_CAT                      2200        //5V catastrophic level (Host USB port potential to shut down)

//LED Mapping - More practically generated from a spreadsheet program
//id: ID of the LED (Sync with PCB callouts)
//x: Physical X coordinate of LED (units do not matter)
//y: Physical Y coordinate of LED (units do not matter)
//drv: 1-Based index of ISSI3773_DRIVER_ADDRESSES
//cs: Matrix wiring CS col (1-16)
//swr: Matrix wiring SW Red row (1-12)
//swg: Matrix wiring SW Green row (1-12)
//swb: Matrix wiring SW Blue row (1-12)
//scan: Associated key scancode if any
//Note: Origin 0,0 may be located anywhere as the software will do the final layout
#define ISSI3733_LED_MAP { \
{ .id =1, .x = 0, .y = 0, .adr = { .drv = 1, .cs = 1, .swr = 2, .swg = 1, .swb = 3 }, .scan = 0 }, \
{ .id =2, .x = 39, .y = 0, .adr = { .drv = 1, .cs = 1, .swr = 8, .swg = 7, .swb = 9 }, .scan = 1 }, \
{ .id =3, .x = 58, .y = 0, .adr = { .drv = 1, .cs = 1, .swr = 11, .swg = 10, .swb = 12 }, .scan = 2 }, \
{ .id =4, .x = 77, .y = 0, .adr = { .drv = 1, .cs = 7, .swr = 2, .swg = 1, .swb = 3 }, .scan = 3 }, \
{ .id =5, .x = 96, .y = 0, .adr = { .drv = 1, .cs = 7, .swr = 5, .swg = 4, .swb = 6 }, .scan = 4 }, \
{ .id =6, .x = 124, .y = 0, .adr = { .drv = 1, .cs = 7, .swr = 8, .swg = 7, .swb = 9 }, .scan = 5 }, \
{ .id =7, .x = 143, .y = 0, .adr = { .drv = 1, .cs = 7, .swr = 11, .swg = 10, .swb = 12 }, .scan = 6 }, \
{ .id =8, .x = 162, .y = 0, .adr = { .drv = 1, .cs = 12, .swr = 2, .swg = 1, .swb = 3 }, .scan = 7 }, \
{ .id =9, .x = 181, .y = 0, .adr = { .drv = 1, .cs = 12, .swr = 5, .swg = 4, .swb = 6 }, .scan = 8 }, \
{ .id =10, .x = 210, .y = 0, .adr = { .drv = 1, .cs = 1, .swr = 2, .swg = 1, .swb = 3 }, .scan = 9 }, \
{ .id =11, .x = 229, .y = 0, .adr = { .drv = 1, .cs = 1, .swr = 5, .swg = 4, .swb = 6 }, .scan = 10 }, \
{ .id =12, .x = 250, .y = 0, .adr = { .drv = 1, .cs = 1, .swr = 8, .swg = 7, .swb = 9 }, .scan = 11 }, \
{ .id =13, .x = 267, .y = 0, .adr = { .drv = 1, .cs = 1, .swr = 11, .swg = 10, .swb = 12 }, .scan = 12 }, \
{ .id =14, .x = 291, .y = 0, .adr = { .drv = 1, .cs = 7, .swr = 2, .swg = 1, .swb = 3 }, .scan = 13 }, \
{ .id =15, .x = 310, .y = 0, .adr = { .drv = 1, .cs = 7, .swr = 5, .swg = 4, .swb = 6 }, .scan = 14 }, \
{ .id =16, .x = 329, .y = 0, .adr = { .drv = 1, .cs = 7, .swr = 8, .swg = 7, .swb = 9 }, .scan = 15 }, \
{ .id =17, .x = 0, .y = 13, .adr = { .drv = 1, .cs = 2, .swr = 2, .swg = 1, .swb = 3 }, .scan = 16 }, \
{ .id =18, .x = 20, .y = 13, .adr = { .drv = 1, .cs = 2, .swr = 5, .swg = 4, .swb = 6 }, .scan = 17 }, \
{ .id =19, .x = 39, .y = 13, .adr = { .drv = 1, .cs = 2, .swr = 8, .swg = 7, .swb = 9 }, .scan = 18 }, \
{ .id =20, .x = 58, .y = 13, .adr = { .drv = 1, .cs = 2, .swr = 11, .swg = 10, .swb = 12 }, .scan = 19 }, \
{ .id =21, .x = 77, .y = 13, .adr = { .drv = 1, .cs = 8, .swr = 2, .swg = 1, .swb = 3 }, .scan = 20 }, \
{ .id =22, .x = 96, .y = 13, .adr = { .drv = 1, .cs = 8, .swr = 5, .swg = 4, .swb = 6 }, .scan = 21 }, \
{ .id =23, .x = 115, .y = 13, .adr = { .drv = 1, .cs = 8, .swr = 8, .swg = 7, .swb = 9 }, .scan = 22 }, \
{ .id =24, .x = 134, .y = 13, .adr = { .drv = 1, .cs = 8, .swr = 11, .swg = 10, .swb = 12 }, .scan = 23 }, \
{ .id =25, .x = 153, .y = 13, .adr = { .drv = 1, .cs = 13, .swr = 2, .swg = 1, .swb = 3 }, .scan = 24 }, \
{ .id =26, .x = 172, .y = 13, .adr = { .drv = 1, .cs = 13, .swr = 5, .swg = 4, .swb = 6 }, .scan = 25 }, \
{ .id =27, .x = 191, .y = 13, .adr = { .drv = 1, .cs = 2, .swr = 2, .swg = 1, .swb = 3 }, .scan = 26 }, \
{ .id =28, .x = 210, .y = 13, .adr = { .drv = 1, .cs = 2, .swr = 5, .swg = 4, .swb = 6 }, .scan = 27 }, \
{ .id =29, .x = 229, .y = 13, .adr = { .drv = 1, .cs = 2, .swr = 8, .swg = 7, .swb = 9 }, .scan = 28 }, \
{ .id =30, .x = 258, .y = 13, .adr = { .drv = 1, .cs = 2, .swr = 11, .swg = 10, .swb = 12 }, .scan = 29 }, \
{ .id =31, .x = 291, .y = 13, .adr = { .drv = 1, .cs = 8, .swr = 2, .swg = 1, .swb = 3 }, .scan = 30 }, \
{ .id =32, .x = 310, .y = 13, .adr = { .drv = 1, .cs = 8, .swr = 5, .swg = 4, .swb = 6 }, .scan = 31 }, \
{ .id =33, .x = 329, .y = 13, .adr = { .drv = 1, .cs = 8, .swr = 8, .swg = 7, .swb = 9 }, .scan = 32 }, \
{ .id =34, .x = 353, .y = 13, .adr = { .drv = 1, .cs = 12, .swr = 2, .swg = 1, .swb = 3 }, .scan = 33 }, \
{ .id =35, .x = 372, .y = 13, .adr = { .drv = 1, .cs = 12, .swr = 5, .swg = 4, .swb = 6 }, .scan = 34 }, \
{ .id =36, .x = 391, .y = 13, .adr = { .drv = 1, .cs = 12, .swr = 8, .swg = 7, .swb = 9 }, .scan = 35 }, \
{ .id =37, .x = 410, .y = 13, .adr = { .drv = 1, .cs = 12, .swr = 11, .swg = 10, .swb = 12 }, .scan = 36 }, \
{ .id =38, .x = 5, .y = 26, .adr = { .drv = 1, .cs = 3, .swr = 2, .swg = 1, .swb = 3 }, .scan = 37 }, \
{ .id =39, .x = 29, .y = 26, .adr = { .drv = 1, .cs = 3, .swr = 5, .swg = 4, .swb = 6 }, .scan = 38 }, \
{ .id =40, .x = 48, .y = 26, .adr = { .drv = 1, .cs = 3, .swr = 8, .swg = 7, .swb = 9 }, .scan = 39 }, \
{ .id =41, .x = 67, .y = 26, .adr = { .drv = 1, .cs = 3, .swr = 11, .swg = 10, .swb = 12 }, .scan = 40 }, \
{ .id =42, .x = 86, .y = 26, .adr = { .drv = 1, .cs = 9, .swr = 2, .swg = 1, .swb = 3 }, .scan = 41 }, \
{ .id =43, .x = 105, .y = 26, .adr = { .drv = 1, .cs = 9, .swr = 5, .swg = 4, .swb = 6 }, .scan = 42 }, \
{ .id =44, .x = 124, .y = 26, .adr = { .drv = 1, .cs = 9, .swr = 8, .swg = 7, .swb = 9 }, .scan = 43 }, \
{ .id =45, .x = 143, .y = 26, .adr = { .drv = 1, .cs = 9, .swr = 11, .swg = 10, .swb = 12 }, .scan = 44 }, \
{ .id =46, .x = 162, .y = 26, .adr = { .drv = 1, .cs = 14, .swr = 2, .swg = 1, .swb = 3 }, .scan = 45 }, \
{ .id =47, .x = 181, .y = 26, .adr = { .drv = 1, .cs = 14, .swr = 5, .swg = 4, .swb = 6 }, .scan = 46 }, \
{ .id =48, .x = 200, .y = 26, .adr = { .drv = 1, .cs = 3, .swr = 2, .swg = 1, .swb = 3 }, .scan = 47 }, \
{ .id =49, .x = 220, .y = 26, .adr = { .drv = 1, .cs = 3, .swr = 5, .swg = 4, .swb = 6 }, .scan = 48 }, \
{ .id =50, .x = 239, .y = 26, .adr = { .drv = 1, .cs = 3, .swr = 8, .swg = 7, .swb = 9 }, .scan = 49 }, \
{ .id =51, .x = 262, .y = 26, .adr = { .drv = 1, .cs = 3, .swr = 11, .swg = 10, .swb = 12 }, .scan = 50 }, \
{ .id =52, .x = 291, .y = 26, .adr = { .drv = 1, .cs = 9, .swr = 2, .swg = 1, .swb = 3 }, .scan = 51 }, \
{ .id =53, .x = 310, .y = 26, .adr = { .drv = 1, .cs = 9, .swr = 5, .swg = 4, .swb = 6 }, .scan = 52 }, \
{ .id =54, .x = 329, .y = 26, .adr = { .drv = 2, .cs = 9, .swr = 8, .swg = 7, .swb = 9 }, .scan = 53 }, \
{ .id =55, .x = 353, .y = 26, .adr = { .drv = 2, .cs = 13, .swr = 2, .swg = 1, .swb = 3 }, .scan = 54 }, \
{ .id =56, .x = 372, .y = 26, .adr = { .drv = 2, .cs = 13, .swr = 5, .swg = 4, .swb = 6 }, .scan = 55 }, \
{ .id =57, .x = 391, .y = 26, .adr = { .drv = 2, .cs = 13, .swr = 8, .swg = 7, .swb = 9 }, .scan = 56 }, \
{ .id =58, .x = 410, .y = 26, .adr = { .drv = 2, .cs = 13, .swr = 11, .swg = 10, .swb = 12 }, .scan = 57 }, \
{ .id =59, .x = 8, .y = 39, .adr = { .drv = 2, .cs = 4, .swr = 2, .swg = 1, .swb = 3 }, .scan = 58 }, \
{ .id =60, .x = 34, .y = 39, .adr = { .drv = 2, .cs = 4, .swr = 5, .swg = 4, .swb = 6 }, .scan = 59 }, \
{ .id =61, .x = 53, .y = 39, .adr = { .drv = 2, .cs = 4, .swr = 8, .swg = 7, .swb = 9 }, .scan = 60 }, \
{ .id =62, .x = 72, .y = 39, .adr = { .drv = 2, .cs = 4, .swr = 11, .swg = 10, .swb = 12 }, .scan = 61 }, \
{ .id =63, .x = 91, .y = 39, .adr = { .drv = 2, .cs = 10, .swr = 2, .swg = 1, .swb = 3 }, .scan = 62 }, \
{ .id =64, .x = 110, .y = 39, .adr = { .drv = 2, .cs = 10, .swr = 5, .swg = 4, .swb = 6 }, .scan = 63 }, \
{ .id =65, .x = 129, .y = 39, .adr = { .drv = 2, .cs = 10, .swr = 8, .swg = 7, .swb = 9 }, .scan = 64 }, \
{ .id =66, .x = 148, .y = 39, .adr = { .drv = 2, .cs = 10, .swr = 11, .swg = 10, .swb = 12 }, .scan = 65 }, \
{ .id =67, .x = 167, .y = 39, .adr = { .drv = 2, .cs = 15, .swr = 2, .swg = 1, .swb = 3 }, .scan = 66 }, \
{ .id =68, .x = 186, .y = 39, .adr = { .drv = 2, .cs = 15, .swr = 5, .swg = 4, .swb = 6 }, .scan = 67 }, \
{ .id =69, .x = 205, .y = 39, .adr = { .drv = 2, .cs = 4, .swr = 2, .swg = 1, .swb = 3 }, .scan = 68 }, \
{ .id =70, .x = 224, .y = 39, .adr = { .drv = 2, .cs = 4, .swr = 5, .swg = 4, .swb = 6 }, .scan = 69 }, \
{ .id =71, .x = 255, .y = 39, .adr = { .drv = 2, .cs = 4, .swr = 11, .swg = 10, .swb = 12 }, .scan = 70 }, \
{ .id =72, .x = 353, .y = 39, .adr = { .drv = 2, .cs = 14, .swr = 2, .swg = 1, .swb = 3 }, .scan = 71 }, \
{ .id =73, .x = 372, .y = 39, .adr = { .drv = 2, .cs = 14, .swr = 5, .swg = 4, .swb = 6 }, .scan = 72 }, \
{ .id =74, .x = 391, .y = 39, .adr = { .drv = 2, .cs = 14, .swr = 8, .swg = 7, .swb = 9 }, .scan = 73 }, \
{ .id =75, .x = 12, .y = 52, .adr = { .drv = 2, .cs = 5, .swr = 2, .swg = 1, .swb = 3 }, .scan = 74 }, \
{ .id =76, .x = 43, .y = 52, .adr = { .drv = 2, .cs = 5, .swr = 5, .swg = 4, .swb = 6 }, .scan = 75 }, \
{ .id =77, .x = 62, .y = 52, .adr = { .drv = 2, .cs = 5, .swr = 8, .swg = 7, .swb = 9 }, .scan = 76 }, \
{ .id =78, .x = 81, .y = 52, .adr = { .drv = 2, .cs = 5, .swr = 11, .swg = 10, .swb = 12 }, .scan = 77 }, \
{ .id =79, .x = 101, .y = 52, .adr = { .drv = 2, .cs = 11, .swr = 2, .swg = 1, .swb = 3 }, .scan = 78 }, \
{ .id =80, .x = 120, .y = 52, .adr = { .drv = 2, .cs = 11, .swr = 5, .swg = 4, .swb = 6 }, .scan = 79 }, \
{ .id =81, .x = 139, .y = 52, .adr = { .drv = 2, .cs = 11, .swr = 8, .swg = 7, .swb = 9 }, .scan = 80 }, \
{ .id =82, .x = 158, .y = 52, .adr = { .drv = 2, .cs = 11, .swr = 11, .swg = 10, .swb = 12 }, .scan = 81 }, \
{ .id =83, .x = 177, .y = 52, .adr = { .drv = 2, .cs = 16, .swr = 2, .swg = 1, .swb = 3 }, .scan = 82 }, \
{ .id =84, .x = 196, .y = 52, .adr = { .drv = 2, .cs = 16, .swr = 5, .swg = 4, .swb = 6 }, .scan = 83 }, \
{ .id =85, .x = 215, .y = 52, .adr = { .drv = 2, .cs = 5, .swr = 2, .swg = 1, .swb = 3 }, .scan = 84 }, \
{ .id =86, .x = 251, .y = 52, .adr = { .drv = 2, .cs = 5, .swr = 11, .swg = 10, .swb = 12 }, .scan = 85 }, \
{ .id =87, .x = 310, .y = 52, .adr = { .drv = 2, .cs = 10, .swr = 5, .swg = 4, .swb = 6 }, .scan = 86 }, \
{ .id =88, .x = 353, .y = 52, .adr = { .drv = 2, .cs = 15, .swr = 2, .swg = 1, .swb = 3 }, .scan = 87 }, \
{ .id =89, .x = 372, .y = 52, .adr = { .drv = 2, .cs = 15, .swr = 5, .swg = 4, .swb = 6 }, .scan = 88 }, \
{ .id =90, .x = 391, .y = 52, .adr = { .drv = 2, .cs = 15, .swr = 8, .swg = 7, .swb = 9 }, .scan = 89 }, \
{ .id =91, .x = 410, .y = 52, .adr = { .drv = 2, .cs = 15, .swr = 11, .swg = 10, .swb = 12 }, .scan = 90 }, \
{ .id =92, .x = 3, .y = 64, .adr = { .drv = 2, .cs = 6, .swr = 2, .swg = 1, .swb = 3 }, .scan = 91 }, \
{ .id =93, .x = 27, .y = 64, .adr = { .drv = 2, .cs = 6, .swr = 5, .swg = 4, .swb = 6 }, .scan = 92 }, \
{ .id =94, .x = 51, .y = 64, .adr = { .drv = 2, .cs = 6, .swr = 8, .swg = 7, .swb = 9 }, .scan = 93 }, \
{ .id =95, .x = 122, .y = 64, .adr = { .drv = 2, .cs = 6, .swr = 11, .swg = 10, .swb = 12 }, .scan = 94 }, \
{ .id =96, .x = 193, .y = 64, .adr = { .drv = 2, .cs = 6, .swr = 2, .swg = 1, .swb = 3 }, .scan = 95 }, \
{ .id =97, .x = 217, .y = 64, .adr = { .drv = 2, .cs = 6, .swr = 5, .swg = 4, .swb = 6 }, .scan = 96 }, \
{ .id =98, .x = 241, .y = 64, .adr = { .drv = 2, .cs = 6, .swr = 8, .swg = 7, .swb = 9 }, .scan = 97 }, \
{ .id =99, .x = 265, .y = 64, .adr = { .drv = 2, .cs = 6, .swr = 11, .swg = 10, .swb = 12 }, .scan = 98 }, \
{ .id =100, .x = 291, .y = 64, .adr = { .drv = 2, .cs = 11, .swr = 2, .swg = 1, .swb = 3 }, .scan = 99 }, \
{ .id =101, .x = 310, .y = 64, .adr = { .drv = 2, .cs = 11, .swr = 5, .swg = 4, .swb = 6 }, .scan = 100 }, \
{ .id =102, .x = 329, .y = 64, .adr = { .drv = 2, .cs = 11, .swr = 8, .swg = 7, .swb = 9 }, .scan = 101 }, \
{ .id =103, .x = 353, .y = 64, .adr = { .drv = 2, .cs = 16, .swr = 2, .swg = 1, .swb = 3 }, .scan = 102 }, \
{ .id =104, .x = 391, .y = 64, .adr = { .drv = 2, .cs = 16, .swr = 8, .swg = 7, .swb = 9 }, .scan = 103 }, \
};


#define USB_LED_INDICATOR_ENABLE    //Comment out to disable indicator functionality
#ifdef USB_LED_INDICATOR_ENABLE     //Scan codes refer to actual key matrix codes, not KC_* (255 to disable)
    #define USB_LED_NUM_LOCK_SCANCODE       255
    #define USB_LED_CAPS_LOCK_SCANCODE      30
    #define USB_LED_SCROLL_LOCK_SCANCODE    255
    #define USB_LED_COMPOSE_SCANCODE        255
    #define USB_LED_KANA_SCANCODE           255
#endif //USB_LED_INDICATOR_ENABLE
