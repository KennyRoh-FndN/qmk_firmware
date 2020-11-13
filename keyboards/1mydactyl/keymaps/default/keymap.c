





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

#include "keymap_korean.h"
#include "version.h"


// Defines names for use in layer keycodes and the keymap
/*enum layer_names {
    _BASE,
    _FN
};
*/


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
#define AS_T(kc) MT(MOD_LSFT | MOD_LALT, kc) //알트 쉬프트
#define CS_T(kc) MT(MOD_LSFT | MOD_LCTL, kc)//컨트롤 쉬프트
#define CA_T(kc) MT(MOD_LCTL | MOD_LALT, kc)//컨트롤 알트


#define L_ARROW LCTL(LSFT(KC_LEFT))
#define R_ARROW LCTL(LSFT(KC_RIGHT))

#define QUES LSFT(KC_SLASH)
#define EXCLM LSFT(KC_1)
#define AT LSFT(KC_2)



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
  LENC,
  MYCOPY
};



bool is_alt_tab_active = true;
bool is_ctl_tab_active = true;

uint16_t alt_tab_timer = 0;



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MTF:
    if (record->event.pressed) {
      SEND_STRING("make 1mydactyl:default -j8" SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case MACR_1:
    if (record->event.pressed) {
      tap_code16(KC_MS_BTN1);
      SEND_STRING( SS_DELAY(1000));
      tap_code16(KC_MS_BTN1);
      SEND_STRING( SS_DELAY(150) SS_LCTL(SS_TAP(X_R)) SS_DELAY(150) SS_TAP(X_TAB) SS_DELAY(150) SS_TAP(X_TAB) SS_DELAY(150) SS_TAP(X_TAB) SS_DELAY(150) SS_TAP(X_ENTER));


    }
    break;
    case MACR_2:
    if (record->event.pressed) {
                    register_code(KC_LALT);
                    tap_code16(KC_TAB);
                unregister_code(KC_LALT);
      SEND_STRING( SS_DELAY(100) );
                    tap_code16(KC_S);

    }
    break;
    case MACR_3:
    if (record->event.pressed) {
      SEND_STRING("make 1attest:default -j4" SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case MACR_4:
    if (record->event.pressed) {
      SEND_STRING("make 1mytest:default -j8" SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case MACR_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_A)) SS_DELAY(5000) SS_TAP(X_TAB) SS_DELAY(500) SS_TAP(X_DOWN)SS_DELAY(500) SS_TAP(X_DOWN) SS_DELAY(500)SS_TAP(X_ENTER)SS_DELAY(500) SS_TAP(X_TAB)SS_DELAY(500)SS_TAP(X_TAB)SS_DELAY(500)SS_TAP(X_ENTER));

    }
    break;
    case ATK:
    if (record->event.pressed) {
      send_unicode_string("같은 사람아아아 이거 나오는 거 만자앙 존나 에러 같은데 좆다 시발 외쳐 유니코드");

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

        case MYCOPY:
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
    T_L_ALT,
    T_L_CTRL,
    T_L_LAY1,
    T_L_LAY2,
    T_L_WIN,
    T_R_ALT,
    T_R_CTRL,
    T_R_LAY1,
    T_R_LAY2,
    T_R_WIN,
    T_L_S_ARR,
    T_R_S_ARR,
    T_L_COPY,
    T_L_PASTE,
    T_R_UNDO,
    T_R_UNUNDO,
    PLUS_M,
    MULTI_D,
    CURLY,
    BRACKET,
    PAREN,
    N_EQUAL
};


typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    SINGLE_MOD,
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
        if (!state->pressed) return SINGLE_TAP;

        else if (state->interrupted) return SINGLE_MOD;
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




// Functions that control what our tap dance key does
void T_L_ALT_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_TAB);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case SINGLE_MOD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            tap_code16(LCTL(KC_V));
            break;
        case DOUBLE_HOLD:
            register_code(KC_LALT);
            register_code(KC_LSHIFT);
            break;
       case DOUBLE_SINGLE_TAP:
            register_code(KC_LALT);
            register_code(KC_LSHIFT);
            break;

       case TRIPLE_TAP:
            break;

      case TRIPLE_SINGLE_TAP:
            break;
      case QUADRA_TAP:
            tap_code(KC_LGUI);
            break;


    }
}

void T_L_ALT_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LALT);
    }
    if (tap_state.state == SINGLE_MOD) {
        unregister_code(KC_LALT);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LALT);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LALT);
    }
    tap_state.state = 0;
}

// Associate our tap dance key with its functionality
//qk_tap_dancze_action_t tap_dance_actions[] = {
//    [lay1] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, tap1_finished, tap1_reset, 200)
//};




//kkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkk   lay2
// Initialize tap structure associated with example tap dance key
//static tap tap_state = {
//    .is_press_action = true,
//    .state = 0
//};


// Functions that control what our tap dance key does
void T_L_CTRL_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LCTRL);
            break;
        case SINGLE_MOD:
            register_code(KC_LCTRL);
            break;
        case DOUBLE_TAP:
            tap_code16(LCTL(KC_C));
            break;
        case DOUBLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            break;
       case DOUBLE_SINGLE_TAP:
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            break;

       case TRIPLE_TAP:
            break;

      case TRIPLE_SINGLE_TAP:
            break;
      case QUADRA_TAP:
            tap_code(KC_LGUI);
            break;

    }
}

void T_L_CTRL_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LCTRL);
    }
    if (tap_state.state == SINGLE_MOD) {
        unregister_code(KC_LCTRL);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LCTRL);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LCTRL);
    }
    tap_state.state = 0;
}

// Associate our tap dance key with its functionality
//qk_tap_dance_action_t tap_dance_actions[] = {
//    [lay2] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, tap2_finished, tap2_reset, 150)
//};
//kkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkk   lay3

//static tap tap_state = {
//    .is_press_action = true,
//    .state = 0
//};

// Functions that control what our tap dance key does
void T_L_LAY1_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code16(KC_DEL);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LSHIFT);
            //layer_on(2);
            break;
        case SINGLE_MOD:
            register_code16(KC_LSHIFT);
            //layer_on(2);
            break;
        case DOUBLE_TAP:
            tap_code16(C(KC_A));
            tap_code16(KC_BSPC);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_LCTL);
            register_code16(KC_LALT);
            break;
       case DOUBLE_SINGLE_TAP:
            register_code16(KC_LCTL);
            register_code16(KC_LALT);
            break;

        case TRIPLE_TAP:
            layer_invert(2);
            break;

    }
}

void T_L_LAY1_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code16(KC_LSHIFT);
    }
    if (tap_state.state == SINGLE_MOD) {
        unregister_code16(KC_LSHIFT);
    }

    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code16(KC_LCTL);
        unregister_code16(KC_LALT);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code16(KC_LCTL);
        unregister_code16(KC_LALT);
    }
    tap_state.state = 0;
}

// Associate our tap dance key with its functionality
//qk_tap_dance_action_t tap_dance_actions[] = {
//    [lay3] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, tap3_finished, tap3_reset, 200)
//};

//kkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkkkkkkkkkkkKkkkkkkkKkkkkkkkkkk   lay4
//static tap tap_state = {
//    .is_press_action = true,
//    .state = 0
//};


// Functions that control what our tap dance key does
void T_L_LAY2_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
        layer_on(1);
            break;
        case SINGLE_HOLD:
        layer_on(1);
            break;
        case SINGLE_MOD:
        layer_on(1);
            break;
        case DOUBLE_TAP:
        layer_on(1);
            break;
        case DOUBLE_HOLD:
        layer_on(1);
            break;
        case DOUBLE_SINGLE_TAP:
        layer_on(1);
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            break;
        case QUADRA_TAP:
            break;


    }
}

void T_L_LAY2_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_TAP) {
        layer_off(1);
    }
    if (tap_state.state == SINGLE_HOLD) {
        layer_off(1);
    }
    if (tap_state.state == SINGLE_MOD) {
        layer_off(1);
    }
    if (tap_state.state == DOUBLE_TAP) {
        layer_off(1);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        layer_off(1);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        layer_off(1);
    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
    }
    tap_state.state = 0;
}


void T_L_WIN_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code16(KC_LGUI);
            break;
        case SINGLE_HOLD:
            layer_on(1);
            register_code16(KC_LGUI);
            break;
        case SINGLE_MOD:
            layer_on(1);
            register_code16(KC_LGUI);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            register_code16(KC_LGUI);
            break;
        case DOUBLE_SINGLE_TAP:
            register_code16(KC_LGUI);
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            break;
        case QUADRA_TAP:
            break;

    }
}

void T_L_WIN_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_HOLD) {
        layer_off(1);
        unregister_code16(KC_LGUI);
    }
    if (tap_state.state == SINGLE_MOD) {
        layer_off(1);
        unregister_code16(KC_LGUI);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code16(KC_LGUI);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code16(KC_LGUI);

    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
    }

    tap_state.state = 0;
}


void T_R_ALT_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_HOME);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            register_code(KC_LALT);
            register_code(KC_LSHIFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_HOME);
            register_code(KC_HOME);
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            break;
        case QUADRA_TAP:
            break;
    }
}

void T_R_ALT_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LALT);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_LALT);
        unregister_code(KC_LSHIFT);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_HOME);
    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
    }
    tap_state.state = 0;
}


void T_R_CTRL_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_END);
            break;
        case SINGLE_HOLD:
            register_code(KC_LCTRL);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_END);
            register_code(KC_END);
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            break;
        case QUADRA_TAP:
            break;

    }
}

void T_R_CTRL_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LCTRL);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_LCTRL);
        unregister_code(KC_LSHIFT);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_END);
    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
    }
    tap_state.state = 0;
}


void T_R_LAY1_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_LANG1);
            break;
        case SINGLE_HOLD:
            layer_on(2);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            break;
        case DOUBLE_SINGLE_TAP:
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            break;
        case QUADRA_TAP:
            break;

    }
}

void T_R_LAY1_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_HOLD) {
        layer_off(2);
    }
    if (tap_state.state == DOUBLE_HOLD) {
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {

    }    tap_state.state = 0;
}


void T_R_LAY2_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_LANG1);
            break;
        case SINGLE_HOLD:
            layer_on(1);
            break;
        case DOUBLE_TAP:
            register_code(KC_LCTRL);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCTRL);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_RIGHT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_LANG1);
            register_code(KC_LANG1);
            break;
        case TRIPLE_TAP:
            register_code(KC_LCTRL);
            tap_code(KC_RIGHT);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCTRL);
            break;
        case TRIPLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_RIGHT);
            break;
        case TRIPLE_SINGLE_TAP:
            tap_code(KC_RIGHT);
            tap_code(KC_RIGHT);
            register_code(KC_RIGHT);
            break;
        case QUADRA_TAP:
            register_code(KC_LCTRL);
            tap_code(KC_RIGHT);
            tap_code(KC_RIGHT);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCTRL);
            break;


    }
}

void T_R_LAY2_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (tap_state.state == SINGLE_HOLD) {
        layer_off(1);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_RIGHT);
        unregister_code(KC_LCTRL);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_LANG1);
    }
    if (tap_state.state == TRIPLE_HOLD) {
        unregister_code(KC_RIGHT);
        unregister_code(KC_LCTRL);
    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
        unregister_code(KC_RIGHT);
    }    tap_state.state = 0;
}










void T_R_WIN_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code16(KC_LGUI);
            break;
        case SINGLE_HOLD:
            layer_on(1);
            register_code16(KC_LGUI);
            register_code16(KC_LCTL);

            break;
        case SINGLE_MOD:
            layer_on(1);
            register_code16(KC_LGUI);
            register_code16(KC_LCTL);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_on(1);
            register_code16(KC_LGUI);
            register_code16(KC_LCTL);
            break;
        case DOUBLE_SINGLE_TAP:
            layer_on(1);
            register_code16(KC_LGUI);
            register_code16(KC_LCTL);
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            break;
        case QUADRA_TAP:
            break;
    }
}

void T_R_WIN_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {
        layer_off(1);
        unregister_code16(KC_LGUI);
        unregister_code16(KC_LCTL);
    }
    if (tap_state.state == SINGLE_MOD) {
        layer_off(1);
        unregister_code16(KC_LGUI);
        unregister_code16(KC_LCTL);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        layer_off(1);
        unregister_code16(KC_LGUI);
        unregister_code16(KC_LCTL);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        layer_off(1);
        unregister_code16(KC_LGUI);
        unregister_code16(KC_LCTL);

    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
    }

    tap_state.state = 0;

}





void T_L_S_ARR_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            tap_code(KC_LEFT);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_LCTRL);
            break;
        case SINGLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            register_code(KC_LEFT);
            break;

    }
}

void T_L_S_ARR_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LCTRL);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LEFT);
    }

}





void T_R_S_ARR_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            tap_code(KC_RIGHT);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_LCTRL);
            break;
        case SINGLE_HOLD:
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            register_code(KC_RIGHT);
            break;

    }
}


void T_R_S_ARR_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LCTRL);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_RIGHT);
    }

}





void T_L_COPY_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance_for_single(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LCTRL);
            tap_code(KC_C);
            unregister_code(KC_LCTRL);
            break;
        case SINGLE_HOLD:
            register_code(KC_LCTRL);
            tap_code(KC_C);
            unregister_code(KC_LCTRL);
            break;
        case DOUBLE_TAP:
            register_code(KC_LCTRL);
            tap_code(KC_X);
            unregister_code(KC_LCTRL);
            break;
        case DOUBLE_HOLD:
            register_code(KC_LCTRL);
            tap_code(KC_X);
            unregister_code(KC_LCTRL);

    }
}

void T_L_COPY_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {

    }
    if (tap_state.state == DOUBLE_HOLD) {

    }
    tap_state.state = 0;

}





void T_L_PASTE_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_LGUI);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LGUI);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_on(0);
            register_code16(KC_LSHIFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_LGUI);
            register_code(KC_LGUI);
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            tap_code(KC_LGUI);
            tap_code(KC_LGUI);
            register_code(KC_LGUI);
            break;
        case QUADRA_TAP:
            break;
    }

}

void T_L_PASTE_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LGUI);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_LSHIFT);
        layer_off(0);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_LGUI);
    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
        unregister_code(KC_LGUI);

    }
        tap_state.state = 0;

}





void T_R_UNDO_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_LGUI);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LGUI);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_on(0);
            register_code16(KC_LSHIFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_LGUI);
            register_code(KC_LGUI);
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            tap_code(KC_LGUI);
            tap_code(KC_LGUI);
            register_code(KC_LGUI);
            break;
        case QUADRA_TAP:
            break;
    }
}

void T_R_UNDO_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LGUI);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_LSHIFT);
        layer_off(0);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_LGUI);
    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
        unregister_code(KC_LGUI);

    }
        tap_state.state = 0;

}





void T_R_UNUNDO_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_LGUI);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LGUI);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_on(0);
            register_code16(KC_LSHIFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_LGUI);
            register_code(KC_LGUI);
            break;
        case TRIPLE_TAP:
            break;
        case TRIPLE_HOLD:
            break;
        case TRIPLE_SINGLE_TAP:
            tap_code(KC_LGUI);
            tap_code(KC_LGUI);
            register_code(KC_LGUI);
            break;
        case QUADRA_TAP:
            break;
    }
}

void T_R_UNUNDO_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LGUI);
    }
    if (tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_LSHIFT);
        layer_off(0);
    }
    if (tap_state.state == DOUBLE_SINGLE_TAP) {
        unregister_code(KC_LGUI);
    }
    if (tap_state.state == TRIPLE_HOLD) {

    }
    if (tap_state.state == TRIPLE_SINGLE_TAP) {
        unregister_code(KC_LGUI);

    }
        tap_state.state = 0;

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




// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [T_L_ALT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_L_ALT_finished, T_L_ALT_reset, 160),
    [T_L_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_L_CTRL_finished, T_L_CTRL_reset, 160 ),
    [T_L_LAY1] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_L_LAY1_finished, T_L_LAY1_reset, 160),
    [T_L_LAY2] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_L_LAY2_finished, T_L_LAY2_reset, 160),
    [T_L_WIN] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_L_WIN_finished, T_L_WIN_reset, 160),
    [T_R_ALT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_R_ALT_finished, T_R_ALT_reset, 160),
    [T_R_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_R_CTRL_finished, T_R_CTRL_reset, 160),
    [T_R_LAY1] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_R_LAY1_finished, T_R_LAY1_reset, 160),
    [T_R_LAY2] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_R_LAY2_finished, T_R_LAY2_reset, 160),
    [T_R_WIN] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_R_WIN_finished, T_R_WIN_reset, 140),
    [T_L_S_ARR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_L_S_ARR_finished, T_L_S_ARR_reset, 100),
    [T_R_S_ARR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_R_S_ARR_finished, T_R_S_ARR_reset, 100),
    [T_L_COPY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_L_COPY_finished, T_L_COPY_reset, 140),
    [T_L_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_L_PASTE_finished, T_L_PASTE_reset, 140),
    [T_R_UNDO] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_R_UNDO_finished, T_R_UNDO_reset, 140),
    [T_R_UNUNDO] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, T_R_UNUNDO_finished, T_R_UNUNDO_reset, 140),
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
#define KC_DTLEFT LGUI(LCTL(KC_LEFT))
#define KC_DTRIGHT LGUI(LCTL(KC_RIGHT))
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
#define NEXT LCTL(KC_PGUP)
#define PRV LCTL(KC_PGDN)
#define BP_NDSH_MAC ALGR(KC_8)
#define AS_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define CS_T(kc) MT(MOD_LSFT | MOD_LCTL, kc)
#define CA_T(kc) MT(MOD_LCTL | MOD_LALT, kc)

#define L_ARROW LCTL(LSFT(KC_LEFT))
#define R_ARROW LCTL(LSFT(KC_RIGHT))

#define QUES LSFT(KC_SLASH)
#define EXCLM LSFT(KC_1)
#define AT LSFT(KC_2)

enum unicode_names {
    BANG,
    IRONY,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0xB9CC,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
};



void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
}





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    MACR_3,      MO(3),           MACR_4,           KC_PMNS,           KC_PPLS,           KC_TAB,     LGUI(KC_TAB),                                           KC_LCTRL,           KC_8,           KC_9,           KC_0,           KC_MINUS,       KC_EQUAL,       KC_AUDIO_VOL_UP,
    MACR_2,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           MACR_2,                                     NEXT,     KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_AUDIO_VOL_DOWN,
    KC_CAPS,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_AUDIO_MUTE,
    KC_PSCR,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_S,                                   PRV,    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,      KC_RCTRL,
    KC_ASTG,           MTF,        MO(4),       KC_DTLEFT,          KC_DTRIGHT,                                                                                                        KC_LEFT,        KC_RIGHT,       KC_UP,          KC_DOWN,        KC_I,
                                                                                             TD(T_L_CTRL),   TD(T_L_ALT),                KC_HOME   , KC_END,
                                                                                                                    TD(T_L_WIN),          TD(T_R_WIN),
                                                                                        KC_BSPC,      MO(1),      TD(T_L_LAY1) ,         TD(T_R_LAY1),  KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    ______________, ______________, KC_HASH,        KC_DLR,         KC_PERC,        KC_AMPR,        ______________,                                 ______________, TD(BRACKET),    KC_TILDE,       KC_UNDS,        KC_BSLASH,      ______________, ______________,
    ______________, ______________, KC_7,           KC_8,           KC_9,           TD(PLUS_M),     ______________,                                 ______________, TD(CURLY) ,     KC_DQUO,        KC_UP,          KC_QUOTE,       ______________, ______________,
    ______________, MACR_2,         KC_4,           KC_5,           KC_6,           TD(MULTI_D),                                                                    TD(PAREN) ,     KC_LEFT,        KC_DOWN,        KC_RIGHT,       ______________, ______________,
    ______________, MACR_1,         KC_1,           KC_2,           KC_3,           KC_KP_EQUAL,       ______________,                                 ______________, TD(N_EQUAL) ,   EXCLM,          QUES,           AT,             ______________, ______________,
    ______________, ______________, KC_0,        KC_0,        KC_KP_DOT,                                                                                                      ______________, ______________, ______________, ______________, ______________,
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
  ),
  [4] = LAYOUT_ergodox_pretty(
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                           ______________, RGB_TOG       , ______________,   ______________,   ______________,   ______________, RESET,
    ______________,______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, RGB_MOD       , RGB_HUI,          RGB_SAI,          RGB_VAI,          ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________,                                                                 RGB_RMOD      , RGB_HUD,          RGB_SAD,          RGB_VAD,          ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, KC_F1,          KC_F2,          KC_F3,          ______________, ______________,
    ______________, ______________, ______________, KC_ENTER,       KC_SPACE,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________,    ______________, ______________,
                                                                                                                    KC_UP,              ______________,
                                                                                    KC_LEFT,      KC_RIGHT,        KC_DOWN,              ______________, ______________, ______________
  ),
  [5] = LAYOUT_ergodox_pretty(
    KC_SYSTEM_SLEEP,RESET,         RESET, ______________, ______________, ______________, ______________,                                           ______________, RGB_TOG       , ______________,   ______________,   ______________,   ______________, RESET,
    KC_SYSTEM_POWER,______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, RGB_MOD       , RGB_HUI,          RGB_SAI,          RGB_VAI,          ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________,                                                                 RGB_RMOD      , RGB_HUD,          RGB_SAD,          RGB_VAD,          ______________, ______________,
    ______________, ______________, ______________, ______________, ______________, ______________, ______________,                                 ______________, ______________, KC_F1,          KC_F2,          KC_F3,          ______________, ______________,
    ______________, ______________, ______________, ______________, ______________,                                                                                                 ______________, ______________, ______________, ______________, ______________,
                                                                                                    ______________, ______________, ______________, ______________,
                                                                                                                    ______________, ______________,
                                                                                    ______________, ______________, ______________, ______________, ______________, ______________
  ),

  [6] = LAYOUT_ergodox_pretty(
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
