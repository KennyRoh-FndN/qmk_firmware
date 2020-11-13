/* Copyright 2020 coolkenny
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

#include "quantum.h"


#include <stddef.h>
#include <avr/io.h>
#include <avr/interrupt.h>



/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ---------- */
/*#define LAYOUT_ergodox_80(                                                                                           \
    k00,k01,k02,k03,k04,k05,k06,       				     k07,k08,k09,k0A,k0B,k0C,k0D,                                \
    k10,k11,k12,k13,k14,k15,k16,       				     k17,k18,k19,k1A,k1B,k1C,k1D,                                \
    k20,k21,k22,k23,k24,k25,           				         k28,k29,k2A,k2B,k2C,k2D,                                \
    k30,k31,k32,k33,k34,k35,k36,        				 k37,k38,k39,k3A,k3B,k3C,k3D,                                \
    k40,k41,k42,k43,k44,k45,k46,                         k47,k48,k49,k4A,k4B,k4C,k4D,                                \
     k51,k52,k53,k54,k55,k56,                                 k57,k58,k59,k5A,k5B,k5C                                  \
) { \
    { k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,k0A,k0B,k0C,k0D},   \
    { k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,k1A,k1B,k1C,k1D},   \
    { k20,k21,k22,k23,k24,k25,KC_NO,KC_NO,k28,k29,k2A,k2B,k2C,k2D},\
    { k30,k31,k32,k33,k34,k35,k36,k37,k38,k39,k3A,k3B,k3C,k3D},   \
    { k40,k41,k42,k43,k44,k45,k46,k47,k48,k49,k4A,k4B,k4C,k4D},   \
    { KC_NO,k51,k52,k53,k54,k55,k56,k57,k58,k59,k5A,k5B,k5C,KC_NO},\
   }

*/
/*
#define LAYOUT_ergodox_80(                                        \
    L00,L01,L02,L03,L04,L05,L06,             \
    L10,L11,L12,L13,L14,L15,L16,             \
    L20,L21,L22,L23,L24,L25,                    \
    L30,L31,L32,L33,L34,L35,L36,             \
    L40,L41,L42,L43,L44,                    \
                            L55,L56,                             \
                        L45,L46,L54,                         \
                        L53,L52,L51  )                     \
                                          \
    {                                     \
    { L00,L01,L02,L03,L04,L05,L06 },   \
    { L10,L11,L12,L13,L14,L15,L16 },     \
    { L20,L21,L22,L23,L24,L25, KC_NO },     \
    { L30,L31,L32,L33,L34,L35,L36 },     \
    { L40,L41,L42,L43,L44,L45,L46 },     \
    { KC_NO, L51, L52, L53, L54, L55, L56 }     \
    }

#define LAYOUT_ergodox80(                                                                           \
    k00,k01,k02,k03,k04,k05,k06,       				     k07,k08,k09,k0A,k0B,k0C,k0D,                                \
    k10,k11,k12,k13,k14,k15,k16,       				     k17,k18,k19,k1A,k1B,k1C,k1D,                                \
    k20,k21,k22,k23,k24,k25,           				         k28,k29,k2A,k2B,k2C,k2D,                                \
    k30,k31,k32,k33,k34,k35,k36,        				 k37,k38,k39,k3A,k3B,k3C,k3D,                                \
    k40,k41,k42,k43,k44,                                         k49,k4A,k4B,k4C,k4D,                                \
                     k55,k56,									k57,k58,                                          \
                 k45,k46,k54,                                 k59,k47,k48,                                  \
     			k53,k52,k51,                                 k5C,k5B,k5A                                  \
) { \
    { k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,k0A,k0B,k0C,k0D},   \
    { k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,k1A,k1B,k1C,k1D},   \
    { k20,k21,k22,k23,k24,k25,KC_NO,KC_NO,k28,k29,k2A,k2B,k2C,k2D},\
    { k30,k31,k32,k33,k34,k35,k36,k37,k38,k39,k3A,k3B,k3C,k3D},   \
    { k40,k41,k42,k43,k44,k45,k46,k47,k48,k49,k4A,k4B,k4C,k4D},   \
    { KC_NO,k51,k52,k53,k54,k55,k56,k57,k58,k59,k5A,k5B,k5C,KC_NO}\
   }

*/




/*
#define LAYOUT_ergodox_80(                                        \
    k00,k01,k02,k03,k04,k05,k06,       				     k07,k08,k09,k0A,k0B,k0C,k0D,                                \
    k10,k11,k12,k13,k14,k15,k16,       				     k17,k18,k19,k1A,k1B,k1C,k1D,                                \
    k20,k21,k22,k23,k24,k25,           				         k28,k29,k2A,k2B,k2C,k2D,                                \
    k30,k31,k32,k33,k34,k35,k36,        				 k37,k38,k39,k3A,k3B,k3C,k3D,                                \
    k40,k41,k42,k43,k44,                                         k49,k4A,k4B,k4C,k4D,                                \
                     k55,k56,									k57,k58,                                          \
                 k45,k46,k54,                                 k59,k47,k48,                                  \
     			k53,k52,k51,                                 k5C,k5B,k5A                                  \
) { \
    { k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,k0A,k0B,k0C,k0D},   \
    { k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,k1A,k1B,k1C,k1D},   \
    { k20,k21,k22,k23,k24,k25,KC_NO,KC_NO,k28,k29,k2A,k2B,k2C,k2D},\
    { k30,k31,k32,k33,k34,k35,k36,k37,k38,k39,k3A,k3B,k3C,k3D},   \
    { k40,k41,k42,k43,k44,k45,k46,k47,k48,k49,k4A,k4B,k4C,k4D},   \
    { KC_NO,k51,k52,k53,k54,k55,k56,k57,k58,k59,k5A,k5B,k5C,KC_NO}\
   }



*/


/*
#define LAYOUT_ergodox_pretty(                                      \
                                                                \
    k00,k01,k02,k03,k04,k05,k06,                                \
    k10,k11,k12,k13,k14,k15,k16,                                \
    k20,k21,k22,k23,k24,k25,                                    \
    k30,k31,k32,k33,k34,k35,k36,                                \
    k40,k41,k42,k43,k44,                                        \
                            k55,k56,                            \
                        k45,k46,k54,                            \
                        k53,k52,k51                            \
) {                                                            \
    { k00, k10, k20, k30, k40, KC_NO },   \
    { k01, k11, k21, k31, k41, k51 },   \
    { k02, k12, k22, k32, k42, k52 },   \
    { k03, k13, k23, k33, k43, k53 },   \
    { k04, k14, k24, k34, k44, k54 },   \
    { k05, k15, k25, k35, k45, k55 },   \
    { k06, k16, KC_NO, k36, k46, k56 }  \
    }
*/

#define LAYOUT_ergodox_pretty(                                      \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
    L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                            L55,L56,   R50,R51,                          \
                        L45,L46,L54,   R52,R40,R41,                      \
                        L53,L52,L51,   R55,R54,R53                         \
) {                                                            \
    { L00, L10, L20, L30, L40, KC_NO },   \
    { L01, L11, L21, L31, L41, L51 },     \
    { L02, L12, L22, L32, L42, L52 },     \
    { L03, L13, L23, L33, L43, L53 },     \
    { L04, L14, L24, L34, L44, L54 },     \
    { L05, L15, L25, L35, L45, L55 },     \
    { L06, L16, KC_NO, L36, L46, L56 },   \
                                          \
    { R00, R10, KC_NO, R30, R40, R50 },   \
    { R01, R11, R21, R31, R41, R51 },     \
    { R02, R12, R22, R32, R42, R52 },     \
    { R03, R13, R23, R33, R43, R53 },     \
    { R04, R14, R24, R34, R44, R54 },     \
    { R05, R15, R25, R35, R45, R55 },     \
    { R06, R16, R26, R36, R46, KC_NO }    \
    }\

    