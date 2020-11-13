/*
Copyright 2020 coolkenny

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER coolkenny
#define PRODUCT 1motherfuckd
#define DESCRIPTION A custom keyboard






/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 2

/*
 * Keyboard Matrix Assignment1313s
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

#define MATRIX_ROW_PINS { B2, B3   }
#define MATRIX_COL_PINS { B6, F7    }

#define MATRIX_ROW_PINS_RIGHT {B7, B3  }
#define MATRIX_COL_PINS_RIGHT { F4, B4 }


/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW







#define ENCODERS_PAD_A { D4 }
#define ENCODERS_PAD_B { D5 }
#define ENCODERS_PAD_A_RIGHT { D4 }
#define ENCODERS_PAD_B_RIGHT { D5 }

#define ENCODER_RESOLUTION 4

//#define ENCODER_DIRECTION_FLIP



/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D0  // or D1, D2, D3, E6
//#define SPLIT_USB_TIMEOUT 2000
//#define SPLIT_USB_TIMEOUT_POLL 10
#define USE_SERIAL
//#define USE_I2C
//#define MASTER_LEFT
#define SPLIT_USB_DETECT

//#define SPLIT_HAND_PIN B4






/*

#define BACKLIGHT_PIN B5
 #define BACKLIGHT_BREATHING
 #define BACKLIGHT_LEVELS 8

*/



/* ws2812 RGB LED */
#define RGB_DI_PIN F1
#define RGBLED_NUM 32    // Number of LEDs
#define RGBLED_SPLIT { 16, 16 }

#define RGBLIGHT_SPLIT
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10

#define RGBLIGHT_LIMIT_VAL 120
/*
#define LED_LAYOUT( \
    L00, L01, L02, L03, \
    L04, L05, L06, L07) \
  { \
    L00, L01, L02, L03, \
     L04, L05, L06, L07 \
  }

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
    0, 1, 2, 3,   \
    4, 5, 6, 7)  \
*/
/*
#define LED_LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, L07, \
    L08, L09, L10, L11, L12, L13, L14, L15) \
  { \
    L00, L01, L02, L03, L04, L05, L06, L07, \
    L08, L09, L10, L11, L12, L13, L14, L15 \
  }

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
  0, 1, 2, 3, 4, 5, 6, 7,    \
 15, 14, 13, 12, 11, 10, 9, 8   )
*/


#define LED_LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, L07, L08, L09, L10, L11, L12, L13, L14, L15, \
    L16, L17, L18, L19, L20, L21, L22, L23, L24, L25, L26, L27, L28, L29, L30, L31)  \
  { \
    L00, L01, L02, L03, L04, L05, L06, L07, L08, L09, L10, L11, L12, L13, L14, L15, \
    L16, L17, L18, L19, L20, L21, L22, L23, L24, L25, L26, L27, L28, L29, L30, L31  \
  }

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
  0, 1, 2, 3, 4, 5, 6, 7,16, 17, 18, 19, 20, 21, 22, 23,       \
 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31   )




/* RGB LED logical order map */
/* Top->Bottom, Right->Left */


//#define RGBLIGHT_LED_MAP {7,6,5,4,3,2,1,0}


/*
#define RGBLIGHT_LED_MAP LED_LAYOUT( \
    0, 1,   \
    14, 15,   \
    2, 3,   \
    12, 13, \
    4, 5,   \
    10, 11, \
    6, 7,   \
    8, 9)  \
*/





 //#define RGB_DI_PIN C7
// #ifdef RGB_DI_PIN
//   #define RGBLED_NUM 16
//   #define RGBLIGHT_HUE_STEP 8
//   #define RGBLIGHT_SAT_STEP 8
//   #define RGBLIGHT_VAL_STEP 8
//   #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
//   #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== all animations enable ==*/
//   #define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
// /*== customize breathing effect ==*/
//   /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//   #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
//   /*==== use exp() and sin() ====*/
//   #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//   #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
// #endif


/* Title:            Fantaisie-Impromptu
 * Author/Composer:  Chopin
 * License:          Public Domain
 */
#define FANTASIE_IMPROMPTU                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   \
    E__NOTE(_GS4), E__NOTE(_A4), E__NOTE(_GS4), E__NOTE(_REST), E__NOTE(_GS4), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_C5), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_GS5), E__NOTE(_GS4), E__NOTE(_A4), E__NOTE(_GS4), E__NOTE(_REST), E__NOTE(_GS4), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_C5), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_GS5), E__NOTE(_A4), E__NOTE(_CS5), E__NOTE(_DS5), E__NOTE(_FS5), E__NOTE(_A5), E__NOTE(_CS6), E__NOTE(_DS6), E__NOTE(_B6), E__NOTE(_A6), E__NOTE(_GS6), E__NOTE(_FS6), E__NOTE(_E6), E__NOTE(_DS6), E__NOTE(_FS6), E__NOTE(_CS6), E__NOTE(_C5), E__NOTE(_DS6), E__NOTE(_A5), E__NOTE(_GS5), E__NOTE(_FS5), E__NOTE(_A5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_FS5), E__NOTE(_CS5), E__NOTE(_C5), E__NOTE(_DS5), E__NOTE(_A4), E__NOTE(_GS4), E__NOTE(_B4), E__NOTE(_A4), E__NOTE(_A4), E__NOTE(_GS4), E__NOTE(_A4), E__NOTE(_GS4), E__NOTE(_REST), E__NOTE(_GS4), \
        E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_C5), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_GS5), E__NOTE(_GS4), E__NOTE(_AS4), E__NOTE(_GS4), E__NOTE(_REST), E__NOTE(_GS4), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_C5), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_GS5), E__NOTE(_DS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_REST), E__NOTE(_DS5), E__NOTE(_B5), E__NOTE(_AS5), E__NOTE(_GS5), E__NOTE(_REST), E__NOTE(_E6), E__NOTE(_DS6), E__NOTE(_CS6), E__NOTE(_B5), E__NOTE(_AS5), E__NOTE(_GS5), E__NOTE(_REST), E__NOTE(_AS5), WD_NOTE(_GS5),


/* Title:            La Campanella
 * Author/Composer:  Frank Lizst
 * License:          Public Domain
 */
#define CAMPANELLA                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 \
    Q__NOTE(_DS4), E__NOTE(_DS4), E__NOTE(_DS5), Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_CS5), E__NOTE(_CS5), E__NOTE(_DS6), Q__NOTE(_B4), E__NOTE(_B4), E__NOTE(_DS6), Q__NOTE(_B4), E__NOTE(_B4), E__NOTE(_DS6), Q__NOTE(_AS4), E__NOTE(_AS4), E__NOTE(_DS6), Q__NOTE(_GS4), E__NOTE(_GS4), E__NOTE(_DS6), Q__NOTE(_G4), E__NOTE(_G4), E__NOTE(_DS6), Q__NOTE(_GS4), E__NOTE(_GS4), E__NOTE(_DS6), Q__NOTE(_AS4), E__NOTE(_AS4), E__NOTE(_DS6), Q__NOTE(_DS4), E__NOTE(_DS4), E__NOTE(_DS6), Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_E5), E__NOTE(_E5), E__NOTE(_DS6), Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_CS5), E__NOTE(_CS5), E__NOTE(_DS6), Q__NOTE(_B4), E__NOTE(_B4), E__NOTE(_DS6), Q__NOTE(_B4), E__NOTE(_B4), E__NOTE(_DS6), Q__NOTE(_AS4), E__NOTE(_AS4), E__NOTE(_DS6), Q__NOTE(_GS4), E__NOTE(_GS4), E__NOTE(_DS6), Q__NOTE(_G4), E__NOTE(_G4), E__NOTE(_DS6), Q__NOTE(_GS4), E__NOTE(_GS4), E__NOTE(_DS6), Q__NOTE(_AS4), \
        E__NOTE(_AS4), E__NOTE(_DS6), Q__NOTE(_DS4), E__NOTE(_DS4), E__NOTE(_DS5), Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_DS6), E__NOTE(_DS6), E__NOTE(_DS7), Q__NOTE(_DS6), E__NOTE(_DS6), E__NOTE(_DS7), Q__NOTE(_CS6), E__NOTE(_CS6), E__NOTE(_DS7), Q__NOTE(_B5), E__NOTE(_B5), E__NOTE(_DS7), Q__NOTE(_B5), E__NOTE(_B5), E__NOTE(_DS7), Q__NOTE(_AS5), E__NOTE(_AS5), E__NOTE(_DS7), Q__NOTE(_GS5), E__NOTE(_GS5), E__NOTE(_DS7), Q__NOTE(_G5), E__NOTE(_G5), E__NOTE(_DS7), Q__NOTE(_GS5), E__NOTE(_GS5), E__NOTE(_DS7), Q__NOTE(_AS5), E__NOTE(_AS5), E__NOTE(_DS7), Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS7), W__NOTE(_DS6), W__NOTE(_GS5),

#define QWERTY_SOUND E__NOTE(_GS6), E__NOTE(_A6), S__NOTE(_REST), Q__NOTE(_E7),
#define DVORAK_SOUND E__NOTE(_GS6), E__NOTE(_A6), S__NOTE(_REST), E__NOTE(_E7), S__NOTE(_REST), E__NOTE(_FS7), S__NOTE(_REST), E__NOTE(_E7),

#define B5_AUDIO

/*
#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(CAMPANELLA)
#endif

*/



/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
// #define GRAVE_ESC_CTRL_OVERRIDE

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
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* key combination for magic key command */
/* defined by default; to change, uncomment and set to the combination you want */
// #define IS_COMMAND() (get_mods() == MOD_MASK_SHIFT)

/* control how magic key switches layers */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM false

/* override magic key keymap */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM
//#define MAGIC_KEY_HELP           H
//#define MAGIC_KEY_HELP_ALT       SLASH
//#define MAGIC_KEY_DEBUG          D
//#define MAGIC_KEY_DEBUG_MATRIX   X
//#define MAGIC_KEY_DEBUG_KBD      K
//#define MAGIC_KEY_DEBUG_MOUSE    M
//#define MAGIC_KEY_VERSION        V
//#define MAGIC_KEY_STATUS         S
//#define MAGIC_KEY_CONSOLE        C
//#define MAGIC_KEY_LAYER0         0
//#define MAGIC_KEY_LAYER0_ALT     GRAVE
//#define MAGIC_KEY_LAYER1         1
//#define MAGIC_KEY_LAYER2         2
//#define MAGIC_KEY_LAYER3         3
//#define MAGIC_KEY_LAYER4         4
//#define MAGIC_KEY_LAYER5         5
//#define MAGIC_KEY_LAYER6         6
//#define MAGIC_KEY_LAYER7         7
//#define MAGIC_KEY_LAYER8         8
//#define MAGIC_KEY_LAYER9         9
//#define MAGIC_KEY_BOOTLOADER     B
//#define MAGIC_KEY_BOOTLOADER_ALT ESC
//#define MAGIC_KEY_LOCK           CAPS
//#define MAGIC_KEY_EEPROM         E
//#define MAGIC_KEY_EEPROM_CLEAR   BSPACE
//#define MAGIC_KEY_NKRO           N
//#define MAGIC_KEY_SLEEP_LED      Z

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

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

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

/*
 * HD44780 LCD Display Configuration
 */
/*
#define LCD_LINES           2     //< number of visible lines of the display
#define LCD_DISP_LENGTH    16     //< visibles characters per line of the display

#define LCD_IO_MODE      1            //< 0: memory mapped mode, 1: IO port mode

#if LCD_IO_MODE
#define LCD_PORT         PORTB        //< port for the LCD lines
#define LCD_DATA0_PORT   LCD_PORT     //< port for 4bit data bit 0
#define LCD_DATA1_PORT   LCD_PORT     //< port for 4bit data bit 1
#define LCD_DATA2_PORT   LCD_PORT     //< port for 4bit data bit 2
#define LCD_DATA3_PORT   LCD_PORT     //< port for 4bit data bit 3
#define LCD_DATA0_PIN    4            //< pin for 4bit data bit 0
#define LCD_DATA1_PIN    5            //< pin for 4bit data bit 1
#define LCD_DATA2_PIN    6            //< pin for 4bit data bit 2
#define LCD_DATA3_PIN    7            //< pin for 4bit data bit 3
#define LCD_RS_PORT      LCD_PORT     //< port for RS line
#define LCD_RS_PIN       3            //< pin  for RS line
#define LCD_RW_PORT      LCD_PORT     //< port for RW line
#define LCD_RW_PIN       2            //< pin  for RW line
#define LCD_E_PORT       LCD_PORT     //< port for Enable line
#define LCD_E_PIN        1            //< pin  for Enable line
#endif
*/

/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0
