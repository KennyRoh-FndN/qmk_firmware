/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
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

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER Kenny
#define PRODUCT 1mytestt
#define DESCRIPTION A custom keyboard

//#undef MATRIX_ROWS
//#undef MATRIX_COLS
/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 21

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define MATRIX_ROW_PINS { B12,B13, B14, B15,B11,B10 }
#define MATRIX_COL_PINS { A1,	A2,A3,	A6,	A7,A10,	A11,	A12,	A15,	C3,C2,C1,C0,C15,C14,	B2,	B1,	B0,	C5,	C4,	A0}
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { C12, B4 }
#define ENCODERS_PAD_B { B3, B5}

#define MUSIC_MAP
#undef AUDIO_VOICES
#undef C6_AUDIOa


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
// #define DEBOUNCE 6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 1

// #define WS2812_LED_N 2
// #define RGBLED_NUM WS2812_LED_N
// #define WS2812_TIM_N 2
// #define WS2812_TIM_CH 2
// #define PORT_WS2812     GPIOA
// #define PIN_WS2812      1
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA stream for TIMx_UP (look up in reference manual under DMA Channel selection)
//#define WS2812_DMA_CHANNEL 7                  // DMA channel for TIMx_UP
//#define WS2812_EXTERNAL_PULLUP
/*
#define DRIVER_ADDR_1 0b1010001
#define DRIVER_ADDR_2 0b1010000 // this is here for compliancy reasons.

#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 53
#define DRIVER_2_LED_TOTAL 51

#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
*/
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_DISABLE_WHEN_USB_SUSPENDED true

#define RGB_MATRIX_LED_PROCESS_LIMIT 5
#define RGB_MATRIX_LED_FLUSH_LIMIT 26


#include "config_led.h"

#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_TOGGLE  1

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0
