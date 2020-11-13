/* Copyright 2020 kenny
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


/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
/*#define LAYOUT( \
    k00, k01, k02, \
      k10,  k11 , k12,   \
      k20,  k21 , k22   \
) \
{ \
    { k00, k01,   k02 }, \
    { k10,  k11 , k12 },  \
    { k20,  k21 , k22 }  \
}
*/




#define LAYOUT( \
    K00,	K10,	K20,	K30,	K40,	K50,	K60,	K70,	K80,	K90,	K100,	K110,	K120,	K130,	K140,	K150,	K160,	K170,	K180,	K190, \
    K01,	K11,	K21,	K31,	K41,	K51,	K61,	K71,	K81,	K91,	K101,	K111,	K121,	K131,	K141,	K151,	K161,	K171,	K181,	K191,   \
    K02,	K12,	K22,	K32,	K42,	K52,	K62,	K72,	K82,	K92,	K102,	K112,	K122,	K132,	K142,	K152,	K162,	K172,	K182,	K192   \
) \
{ \
    { K00,	K10,	K20,	K30,	K40,	K50,	K60,	K70,	K80,	K90,	K100,	K110,	K120,	K130,	K140,	K150,	K160,	K170,	K180,	K190}, \
    { K01,	K11,	K21,	K31,	K41,	K51,	K61,	K71,	K81,	K91,	K101,	K111,	K121,	K131,	K141,	K151,	K161,	K171,	K181,	K191},  \
    { K02,	K12,	K22,	K32,	K42,	K52,	K62,	K72,	K82,	K92,	K102,	K112,	K122,	K132,	K142,	K152,	K162,	K172,	K182,	K192 }   \
}





/*

#define LAYOUT( \
    K00,	K10,	K20,	K30,	K40,	K50,	K60,	K70,	K80,	K90,	K100,	K110,	K120,	K130,	K140,	K150,	K160,	K170,	K180,	K190   \
) \
{ \
    { K00,	K10,	K20,	K30,	K40,	K50,	K60,	K70,	K80,	K90,	K100,	K110,	K120,	K130,	K140,	K150,	K160,	K170,	K180,	K190 }   \
}


*/




/*
#define LAYOUT( \
K00,	K10,	K20,	K30,	K40,	K50,	K60,	K70,	K80,	K90,\
K01,	K11,	K21,	K31,	K41,	K51,	K61,	K71,	K81,	K91,\
K02,	K12,	K22,	K32,	K42,	K52,	K62,	K72,	K82,	K92,\
K03,	K13,	K23,	K33,	K43,	K53,	K63,	K73,	K83,	K93,\
K04,	K14,	K24,	K34,	K44,	K54,	K64,	K74,	K84,	K94,\
K05,	K15,	K25,	K35,	K45,	K55,	K65,	K75,	K85,	K95,\
K06,	K16,	K26,	K36,	K46,	K56,	K66,	K76,	K86,	K96,\
K07,	K17,	K27,	K37,	K47,	K57,	K67,	K77,	K87,	K97,\
K08,	K18,	K28,	K38,	K48,	K58,	K68,	K78,	K88,	K98,\
K09,	K19,	K29,	K39,	K49,	K59,	K69,	K79,	K89,	K99\
) \
{ \
    { K00,	K10,	K20,	K30,	K40,	K50,	K60,	K70,	K80,	K90	}, \
    { K01,	K11,	K21,	K31,	K41,	K51,	K61,	K71,	K81,	K91	},  \
    { K02,	K12,	K22,	K32,	K42,	K52,	K62,	K72,	K82,	K92	 } ,  \
    { K03,	K13,	K23,	K33,	K43,	K53,	K63,	K73,	K83,	K93 } ,  \
    { K04,	K14,	K24,	K34,	K44,	K54,	K64,	K74,	K84,	K94 } ,  \
    { K05,	K15,	K25,	K35,	K45,	K55,	K65,	K75,	K85,	K95} ,  \
    { K06,	K16,	K26,	K36,	K46,	K56,	K66,	K76,	K86,	K96 } ,  \
    { K07,	K17,	K27,	K37,	K47,	K57,	K67,	K77,	K87,	K97 } ,  \
    { K08,	K18,	K28,	K38,	K48,	K58,	K68,	K78,	K88,	K98 } ,  \
    { K09,	K19,	K29,	K39,	K49,	K59,	K69,	K79,	K89,	K99 } \
}

*/