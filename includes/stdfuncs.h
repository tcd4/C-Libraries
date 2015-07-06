#ifndef __STDFUNCS__
#define __STDFUNCS__


/**
 * @file stdfuncs.h
 *
 * @brief contains commonly used functions for CLibs
 *
 * Memory Allocation Function - Alloc_Type(), Alloc_And_Set()
 */


#include <string.h>
#include <stdlib.h>
#include "stdtypes.h"
#include "stdmacros.h"


/**
 * @brief allocates memory for a given CTypes
 *
 * @param type the CTypes to allocate for
 *
 * @return a pointer to the allocated memory
 */
dataptr Alloc_Type( CTypes type );

/**
 * @brief allocates and sets memory
 *
 * @param data the data to set to
 * @param type the CTypes to allocate for
 *
 * @return a pointer to the allocated and set memory
 */ 
dataptr Alloc_And_Set( dataptr data, CTypes type );


#endif
