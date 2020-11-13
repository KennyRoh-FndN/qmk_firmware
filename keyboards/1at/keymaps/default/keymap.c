





/* Copyright 2020 Kenny
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
    _FN
};

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  MTF,
  MACR_1,
  MACR_2,
  MACR_3,
  MACR_4,
  MACR_5,
  ATK,
  RENC,
  LENC
};



bool is_alt_tab_active = true;
bool is_ctl_tab_active = true;

uint16_t alt_tab_timer = 0;



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MTF:
    if (record->event.pressed) {
      SEND_STRING("make 1motherfuckd:default" SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case MACR_1:
    if (record->event.pressed) {
      SEND_STRING("앙기모띠 시뱅 이거 한글되는 거 맞아" SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case MACR_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_H)) SS_DELAY(10) SS_TAP(X_M) SS_DELAY(10) SS_TAP(X_C));//병합

    }
    break;
    case MACR_3:
    if (record->event.pressed) {
      SEND_STRING("asd9348" SS_TAP(X_TAB) "asd9348" SS_TAP(X_ENTER));

    }
    break;
    case MACR_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_R)) "C:\\Program Files (x86)\\XYplorer\\XYplorer.exe" SS_TAP(X_ENTER));

    }
    break;
    case MACR_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_A)) SS_DELAY(5000) SS_TAP(X_TAB) SS_DELAY(500) SS_TAP(X_DOWN)SS_DELAY(500) SS_TAP(X_DOWN) SS_DELAY(500)SS_TAP(X_ENTER)SS_DELAY(500) SS_TAP(X_TAB)SS_DELAY(500)SS_TAP(X_TAB)SS_DELAY(500)SS_TAP(X_ENTER));

    }
    break;
    case ATK:
    if (record->event.pressed) {
      SEND_STRING("make 1at:default" SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;

        case RENC:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed 

                if (is_alt_tab_active) {   
                unregister_code(KC_LALT);
                is_alt_tab_active = false;
                } else {
                    register_code(KC_LALT);
                    tap_code16(KC_TAB);
                is_alt_tab_active = true;
                        }
            } else {
                // when keycode QMKBEST is released
            }
            break;

        case LENC:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                if (is_ctl_tab_active) {   
                unregister_code(KC_LCTL);
                is_ctl_tab_active = false;
                } else {
                    register_code(KC_LCTL);
                    tap_code16(KC_TAB);
                    is_ctl_tab_active = true;
                    }
            } else {
                // when keycode QMKURL is released
            }
            break;

    case KC_ENTER:
    if (record->event.pressed) {
    // when keycode QMKURL is pressed
        unregister_code(KC_LCTL);
                            unregister_code(KC_LALT);


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
                    unregister_code(KC_LALT);

                    is_ctl_tab_active = false;

                is_alt_tab_active = false;
            } else {
                // when keycode QMKURL is released
            }
            break;



  }
  return true;
}



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Tap Dance declarations
enum {
    N_EQUAL,
    PAREN,
    BRACKET,
    CURLY,
    MULTI_D,
    PLUS_M
};



typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    TRIPLE_SINGLE_TAP,
    QUADRA_TAP
}; 



static tap tap_state = {
    .is_press_action = true,
    .state = 0
};

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) { 
 //       if (state->interrupted || !state->pressed) return SINGLE_TAP;
        if (state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
      else if (state->count == 3) {
        if (state->interrupted) return TRIPLE_SINGLE_TAP;
        if (!state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    }
      if (state->count == 4) return QUADRA_TAP;
      
      
      //else if (state->count == 5) return PENTA_TAP;
     
    else return 8;
}

uint8_t cur_dance_for_single(qk_tap_dance_state_t *state) {
    if (state->count == 1) { 

        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    else return 8;
}


uint8_t cur_dance_for_custom_autoshift(qk_tap_dance_state_t *state) {
    if (state->count == 1) { 
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } 
    else return 8;
}


void PLUS_M_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_KP_PLUS);
            break;
        case SINGLE_HOLD:
            register_code16(KC_KP_PLUS);
            break;
        case DOUBLE_TAP:
            tap_code(KC_KP_MINUS);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_KP_MINUS);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_KP_PLUS); 
            register_code(KC_KP_PLUS);
            break;
    }
}

void PLUS_M_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_KP_PLUS);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_KP_MINUS);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_KP_PLUS);
    }
        tap_state.state = 0;

}

void MULTI_D_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_KP_ASTERISK);
            break;
        case SINGLE_HOLD:
            register_code16(KC_KP_ASTERISK);
            break;
        case DOUBLE_TAP:
            tap_code(KC_KP_SLASH);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_KP_SLASH);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_KP_ASTERISK); 
            register_code(KC_KP_ASTERISK);
            break;
    }

}

void MULTI_D_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_KP_ASTERISK);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_KP_SLASH);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_KP_ASTERISK);
    }
        tap_state.state = 0;

}



void CURLY_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_LBRC);
            unregister_code(KC_LSHIFT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LSHIFT);
            tap_code(KC_RBRC);
            unregister_code(KC_LSHIFT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_LBRC);
            tap_code(KC_RBRC);
            unregister_code(KC_LSHIFT);
            tap_code(KC_LEFT);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_LSHIFT);
            tap_code(KC_LBRC);
            tap_code(KC_RBRC);
            unregister_code(KC_LSHIFT);
            tap_code(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_LBRC);
            unregister_code(KC_LSHIFT);
            register_code16(KC_LSHIFT);
            register_code16(KC_LBRC);
            unregister_code(KC_LSHIFT);
            break;
    }
}

void CURLY_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_LBRC);
    }
        tap_state.state = 0;

}



void BRACKET_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_LBRC);
            break;
        case SINGLE_HOLD:
            tap_code(KC_RBRC);
            break;
        case DOUBLE_TAP:
            tap_code(KC_LBRC);
            tap_code(KC_RBRC);
            tap_code(KC_LEFT);
            break;
        case DOUBLE_HOLD:
            tap_code(KC_LBRC);
            tap_code(KC_RBRC);
            tap_code(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_LBRC);
            register_code16(KC_LBRC);
            break;
    }
}

void BRACKET_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_LBRC);
    }
        tap_state.state = 0;

}



void PAREN_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_9);
            unregister_code(KC_LSHIFT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LSHIFT);
            tap_code(KC_0);
            unregister_code(KC_LSHIFT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_9);
            tap_code(KC_0);
            unregister_code(KC_LSHIFT);
            tap_code(KC_LEFT);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_LSHIFT);
            tap_code(KC_9);
            tap_code(KC_0);
            unregister_code(KC_LSHIFT);
            tap_code(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_9);
            unregister_code(KC_LSHIFT);
            register_code16(KC_LSHIFT);
            register_code16(KC_9);
            unregister_code(KC_LSHIFT);
            break;
    }
}

void PAREN_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_9);
    }
        tap_state.state = 0;

}




void N_EQUAL_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_COMMA);
            unregister_code(KC_LSHIFT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LSHIFT);
            tap_code(KC_DOT);
            unregister_code(KC_LSHIFT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_COMMA);
            tap_code(KC_DOT);
            unregister_code(KC_LSHIFT);
            tap_code(KC_LEFT);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_LSHIFT);
            tap_code(KC_COMMA);
            tap_code(KC_DOT);
            unregister_code(KC_LSHIFT);
            tap_code(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            register_code16(KC_LSHIFT);
            tap_code(KC_COMMA);
            unregister_code(KC_LSHIFT);
            register_code16(KC_LSHIFT);
            register_code16(KC_DOT);
            unregister_code(KC_LSHIFT);
            break;
    }
}

void N_EQUAL_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_COMMA);
    }
        tap_state.state = 0;

}


qk_tap_dance_action_t tap_dance_actions[] = {
    [PLUS_M] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, PLUS_M_finished, PLUS_M_reset, 200),
    [MULTI_D] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, MULTI_D_finished, MULTI_D_reset, 200),
    [CURLY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, CURLY_finished, CURLY_reset, 200),
    [BRACKET] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, BRACKET_finished, BRACKET_reset, 200),
    [PAREN] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, PAREN_finished, PAREN_reset, 200),
    [N_EQUAL] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, N_EQUAL_finished, N_EQUAL_reset, 200),

};

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





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
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)

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
    KC_ESCAPE,      MO(3),           KC_2,           KC_3,           KC_PC_UNDO,           KC_DEL,          KC_LSHIFT,                                           KC_DEL,           KC_8,           KC_9,           KC_0,           KC_MINUS,       KC_EQUAL,       KC_AUDIO_VOL_UP,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_PC_COPY,                                     KC_PC_UNDO,     KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_AUDIO_VOL_DOWN,
    KC_CAPS,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_AUDIO_MUTE,
    KC_PSCR,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_PC_PASTE,                                   KC_PC_UNUNDO,    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RCTRL,
    KC_ASTG,           KC_ASTG,        MACR_1,       MTF,          ATK,                                                                                                        KC_LEFT,        KC_RIGHT,       KC_UP,          KC_DOWN,        KC_I,
                                                                                                    LCTL_T(KC_LEAD),       KC_LALT,        KC_LALT, MO(2),
                                                                                                                    KC_LGUI,        KC_LANG1,
                                                                                        KC_BSPC,      MO(1),          RENC,         LENC,  KC_ENTER,       KC_SPACE
  ),     
  [1] = LAYOUT_ergodox_pretty(
    ______________, ______________, KC_HASH,        KC_DLR,         KC_PERC,        KC_AMPR,        ______________,                                 ______________, TD(BRACKET),    KC_TILDE,       KC_UNDS,        KC_BSLASH,      ______________, ______________,
    ______________, ______________, KC_7,           KC_8,           KC_9,           TD(PLUS_M),     ______________,                                 ______________, TD(CURLY) ,     KC_DQUO,        KC_UP,          KC_QUOTE,       ______________, ______________,
    ______________, ______________, KC_4,           KC_5,           KC_6,           TD(MULTI_D),                                                                    TD(PAREN) ,     KC_LEFT,        KC_DOWN,        KC_RIGHT,       ______________, ______________,
    ______________, ______________, KC_1,           KC_2,           KC_3,           KC_EQUAL,       ______________,                                 ______________, TD(N_EQUAL) ,   EXCLM,          QUES,           AT,             ______________, ______________,
    ______________, ______________, KC_KP_0,        KC_KP_0,        KC_KP_DOT,                                                                                                      ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    ______________, ______________, ______________, ______________, ______________, ______________
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_SLEP,          ______________, KC_F10,         KC_F11,         KC_F12,         ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    KC_PWR,         ______________, KC_F7,          KC_F8,          KC_F9,          ______________, ______________,                                 ______________, KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     ______________, ______________,
    RESET,        ______________, KC_F4,          KC_F5,          KC_F6,          ______________,                                                                  KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    ______________, ______________,
    ______________, ______________, KC_F1,          KC_F2,          KC_F3,          ______________, ______________,                                 ______________, ______________, ______________, ______________, ______________, ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    ______________, ______________, ______________, ______________, ______________, ______________
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_SYSTEM_SLEEP,RESET,         RESET, ______________, ______________, ______________, ______________,                                           ______________, RGB_TOG       , ______________,   ______________,   ______________,   ______________, RESET,
    KC_SYSTEM_POWER,______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, RGB_MOD       , RGB_HUI,          RGB_SAI,          RGB_VAI,          ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________,                                                                 RGB_RMOD      , RGB_HUD,          RGB_SAD,          RGB_VAD,          ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, KC_F1,          KC_F2,          KC_F3,          ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    ______________, ______________, ______________, ______________, ______________, ______________
  )

};



/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/




//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 36, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {36, 36, HSV_WHITE}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 71, HSV_AZURE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 71, HSV_MAGENTA}
);
// etc..
const rgblight_segment_t PROGMEM default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 71, HSV_WHITE}
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
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}



layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

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
                    is_zlt_tab_active = true;
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
                
                if (is_ctl_tab_active) {        
                    tap_code16(S(KC_TAB));
                } else {
                    register_code(KC_LCTL);
                    tap_code16(S(KC_TAB));
                    is_ctl_tab_active = true;
                        }       

                }

            }
    else if (index == 1) {
        if (clockwise) {
                                                                                
                if (is_alt_tab_active) {   
                    tap_code16(KC_TAB);
                } else {
                    register_code(KC_LALT);
                    tap_code16(KC_TAB);
                    is_alt_tab_active = true;
                        }

        } else {
                
                if (is_alt_tab_active) {
                    tap_code16(S(KC_TAB));
                } else {
                    register_code(KC_LALT);
                    tap_code16(S(KC_TAB));
                    is_alt_tab_active = true;
                        }       

                }

    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_D) {
      // Anything you can do in a macro.
      tap_code16(OSM(MOD_LSFT));
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING("QMK is awesome.dd");
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("QMK is awesome.ddddd");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}
