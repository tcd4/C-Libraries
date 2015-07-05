#ifndef __DEBUG__
#define __DEBUG__


/**
 * @file debug.h
 *
 * @brief contains debugging tools
 *
 * Location Macros - HERE
 * 
 * Tracer Macros - TRACENUM( name, value ), TRACESTR( name, value )
 */


/* location macros */
/**
 * @brief prints the line number and file to the console
 * WARNING: DO NOT USE A SEMI-COLON AFTER IT
 */
#define HERE                  printf( "You are on line %i in file %s\n", __LINE__, __FILE__ );


/* tracer macros */
/**
 * @brief traces the value of a number variable
 * 
 * @param name the name of the variable as a string
 * @param value the value of the variable
 */
#define TRACENUM( name, value )   printf( "Tracing %s: %s\n", name, ( char * )( &value ) )

/**
 * @brief traces the value of a string/char* variable
 * 
 * @param name the name of the variable as a string
 * @param value the value of the variable
 */
#define TRACESTR( name, value )   printf( "Tracing %s: %s\n", name, value )


#endif
