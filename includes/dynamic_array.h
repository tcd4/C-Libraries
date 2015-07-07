#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__


/**
 * @file dynamic_array.h
 *
 * @brief contains support for dynamically sized arrays
 *
 * Dynamic Array Type - DArray
 *
 * Create Function - New_DArray()
 * Insert Functions - Insert_Into_DArray(), Prepend_To_DArray(), Append_To_DArray()
 * Util Functions - Element_At(), Resize_DArray(), Remove_Element_At(), Clear_DArray()
 * Free Function - Free_DArray()
 *
 * WARNING: DARRAYS SHOULD ONLY CONTAIN 1 DATA TYPE
 * WARNING: USERS WILL BE RESPONSIBLE FOR ALLOCATING MEMORY FOR NON-STANDARD C DATA TYPES
 * WARNING: MAKE SURE YOU HAVE NO POINTERS TO DARRAY DATA WHEN FREEING A DARRAY
 */


#include <string.h>
#include "stdmacros.h"
#include "stdfuncs.h"
#include "platforms.h"
#include "boolean.h"


typedef struct DArray_s       DArray;        /**< the dynamic array type */
typedef struct RealArray_s    RealArray;     /**< the backend type for the dynamic arrays */


struct RealArray_s
{
    dataptr    data;                         /**< the data in the array */
    uint32     length;                       /**< the number of elements in the array */
    uint32     alloc;                        /**< the allocated memory of the array */
    size_t     eltsize;                      /**< the element size */
    CTypes     type;                         /**< the data type of the array */

    void       ( *Free )( dataptr data );    /**< function pointer for the data's custom free function */
};


struct DArray_s
{
    dataptr    data;     /**< the data in the DArray */
    uint32     length;   /**< the number of elements in the DArray */
    CTypes     type;     /**< the data type of the DArray */
};


/**
 * @brief creates a new DArray
 *
 * @param type the data type of the DArray
 * @param length the number of starting elements the DArray can hold
 * @param Free a function pointer to the data's custom free function
 *
 * @return a pointer to the new DArray
 */
DArray* New_DArray( CTypes type, uint32 length, void ( *Free )( dataptr data ) );

/**
 * @brief resizes a DArray
 *
 * @param arr the DArray to resize
 * @param length the length to resize to
 *
 * @return TRUE if the DArray was resized, FALSE if else
 */
Bool Resize_DArray( DArray *arr, uint32 length );

/**
 * @brief prepends data onto a DArray
 *
 * @param arr the DArray to prepend onto
 * @param data the data to prepend
 *
 * @return TRUE if the data was prepended, FALSE if else
 */
Bool Prepend_To_DArray( DArray *arr, dataptr data );

/**
 * @brief appends data onto a DArray
 *
 * @param arr the DArray to append onto
 * @param data the data to append
 *
 * @return TRUE if the data was appened, FALSE if else
 */
Bool Append_To_DArray( DArray *arr, dataptr data );

/**
 * @brief
 *
 * @param arr the DArray to insert into
 * @param data the data to insert
 *
 * @return TRUE if the data was inserted, FALSE if else
 */
Bool Insert_Into_DArray( DArray *arr, dataptr data );

/**
 * @brief finds data in a DArray at an index
 *
 * @param arr the DArray to look in
 * @param index the index to lookup
 *
 * @return a pointer to the data at the index
 */
dataptr Element_At( DArray *arr, uint32 index );

/**
 * @brief removes data in a DArray at an index
 *
 * @param arr the DArray to remove from
 * @param index the index to remove
 */
void Remove_Element_At( DArray *arr, uint32 index );

/**
 * @brief clears all data from a DArray
 * does NOT resize the DArray
 *
 * @param arr the DArray to clear;
 */
void Clear_DArray( DArray *arr );

/**
 * @brief free the memory from a DArray
 *
 * @param arr the DArray to free
 */
void Free_DArray( DArray **arr );


#endif
