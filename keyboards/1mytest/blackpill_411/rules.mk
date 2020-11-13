# MCU name


## chip/board settings
# the next two should match the directories in
#  <chibios>/os/hal/ports/$(MCU_FAMILY)/$(MCU_SERIES)
MCU_FAMILY = STM32
MCU_SERIES = STM32F4xx
# linker script to use
# it should exist either in <chibios>/os/common/ports/ARMCMx/compilers/GCC/ld/
#  or <this_dir>/ld/
MCU_LDSCRIPT = STM32F411xE
# startup code to use
# is should exist in <chibios>/os/common/ports/ARMCMx/compilers/GCC/mk/
MCU_STARTUP = stm32f4xx




#SRC += muse.c


# it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
BOARD = BLACKPILL_STM32_F411
# Cortex version
# Teensy LC is cortex-m0; Teensy 3.x are cortex-m4
MCU  = cortex-m4
# ARM version, CORTEX-M0/M1 are 6, CORTEX-M3/M4/M7 are 7
ARMV = 7
USE_FPU = yes
# Address of the booloader in system memory
STM32_BOOTLOADER_ADDRESS = 0x1FFF0000

# Options to pass to dfu-util when flashing
DFU_ARGS = -d 0483:df11 -a 0 -s 0x08000000:leave
DFU_SUFFIX_ARGS = -v 0483 -p df11

# Build Options
#   change yes to no to disable
#
KEYBOARD_SHARED_EP       = no



# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration
## (Note that for BOOTMAGIC on Teensy LC you have to use a custom .ld script.)
MOUSEKEY_ENABLE = yes     # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no       # Commands for debug and configuration
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no      # Enable WS2812 RGB underlight.
API_SYSEX_ENABLE = no

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = yes    # Breathing sleep LED during USB suspend
#SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend

CUSTOM_MATRIX = no # Custom matrix file
# SERIAL_LINK_ENABLE = yes
ENCODER_ENABLE = no
RGB_MATRIX_ENABLE = IS31FL3733

LAYOUTS_HAS_RGB = no


RGB_MATRIX_CUSTOM_USER = yes
