#ifndef __BOOLEAN__
#define __BOOLEAN__


/**
 * @file boolean.h
 *
 * @brief contains support for the standard boolean type
 */


#include <string.h>
#include "stdmacros.h"
#include "stdtypes.h"


START_DECLS


/*< the boolean type */
typedef uint8 Bool;


/**
 * @brief converts a string representation of true or false to a Bool
 * accepts "true", "True", "TRUE" or "false", "False", "FALSE"
 *
 * @param s the string to convert
 *
 * @return TRUE if "true" or FALSE if anything else
 */
Bool String_To_Bool( char *s );

/**
 * @brief converts a string representation of true to a Bool
 * accepts "true", "True", or "TRUE"
 *
 * @param s the string to convert
 *
 * @return TRUE if "true" or FALSE if anything else
 */
Bool String_To_True( char *s );

/**
 * @brief converts a string representation of false to a Bool
 * accepts "false", "False", or "FALSE"
 *
 * @param s the string to convert
 *
 * @return FALSE if "false" or TRUE if anything else
 */
Bool String_To_False( char *s );

/**
 * @brief converts a Bool value to a string representation
 *
 * @param b the Bool to convert
 *
 * @return "true" if TRUE, "false" if FALSE, or NULL if anything else
 */
char* Bool_To_String( Bool b );


END_DECLS


#endif
