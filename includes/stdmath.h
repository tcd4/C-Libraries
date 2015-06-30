#ifndef __STDMATH__
#define __STDMATH__


/**
 * @file stdmath.h
 *
 * @brief contains standard math functions and defines
 *
 * Constants - PI, TAU
 * Conversion Constants - TODEG, TORAD
 * 
 * Conversion Macros - Angle_To_Deg( angle ), Angle_To_Rad( angle )
 * RNG Macros - Random(), CRandom()
 */


#include <stdlib.h>
#include <math.h>


/* constant defines */
/*< PI define */
#define PI 3.14159265

/*< TAU define */
#define TAU 6.283185308


/* conversion constants */
/*< radian to degree conversion constant */
#define TODEG 57.2957795

/*< degree to radian conversion constant */
#define TORAD 0.0174532925


/* conversion macros */
/*< converts an angle from radians to degrees */
#define Angle_To_Deg( a )                       ( a * TODEG )

/*< converts an angle from degrees to radians */
#define Angle_To_Rad( a )                       ( a * TORAD )


/**
 * @brief random macro from Id Software's Quake 2 Source
 * This macro makes rand() more random
 *
 * @return a random float from 0 to 1.0
 */
#define Random()	( ( rand() & 0x7fff ) / ( ( float )0x7fff ) )

/**
 * @brief random macro from Id Software's Quake 2 Source
 * 
 * @return a random float from -1.0 to 1.0
 */
#define CRandom()	( 2.0 * ( random() - 0.5 ) )


#endif
