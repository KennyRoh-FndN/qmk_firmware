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

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif
#endif
/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *11111
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */



#define LAYOUT( \
    K01, K02,     K03, K04,    \
    K05, K06,     K07, K08     \
) \
{ \
    { K01, K05 }, \
    { K02, K06 }, \
    { K03, K07 }, \
    { K04, K08 }  \
}


/*
#define LAYOUT( \
    K01, K02,     K03, K04,    \
    K05, K06,     K07, K08     \
) \
{ \
    { K03, K07 }, \
    { K04, K08 },  \
    { K01, K05 }, \
    { K02, K06 } \
}

*/





/*

#define LAYOUT( \
    K01, K02,    \
    K03, K04,    \
    K05, K06,    \
    K07, K08     \
) \
{ \
    { K01, K02 }, \
    { K02, K04 }, \
    { K03, K06 }, \
    { K04, K08 }  \
}

*/

/*

#define LAYOUT( \
    L00, L01, R00, R01,    \
    L10, L11, R10, R11     \
) \
{ \
    { L00, L01 }, \
    { L10, L11 }, \
    { R01, R00 }, \
    { R11, R10 }  \
}



**/

/*
#define LAYOUT( \
    K01, K02, K03, K04,    \
    K05, K06, K07, K08     \
) \
{ \
    { K01, K02, K03, K04 }, \
    { K05, K06, K07, K08 }  \
}
*/
