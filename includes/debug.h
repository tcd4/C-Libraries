#ifndef __DEBUG__
#define __DEBUG__


/**
 * @file debug.h
 *
 * @brief contains debugging tools
 *
 * Location Macros - HERE
 * 
 * Tracer Macros - TRACENUM(), TRACEFLOAT(), TRACESTR()
 */


#include <stdio.h>


/* location macros */
/**
 * @brief prints the line number and file to the console
 * WARNING: DO NOT USE A SEMI-COLON AFTER IT
 */
#define HERE                  printf( "You are on line %i in file %s\n", __LINE__, __FILE__ );


/* tracer macros */
/**
 * @brief traces the value of an int
 * 
 * @param name the name of the variable as a string
 * @param value the int value
 */
#define TRACEINT( name, value )   printf( "Tracing %s: %i\n", name, value )

/**
 * @brief traces the value of a float
 * 
 * @param name the name of the variable as a string
 * @param value the float value
 */
#define TRACEFLOAT( name, value )   printf( "Tracing %s: %f\n", name, value )

/**
 * @brief traces the value of a string/char* variable
 * 
 * @param name the name of the variable as a string
 * @param value the value of the variable
 */
#define TRACESTR( name, value )   printf( "Tracing %s: %s\n", name, value )


#endif
