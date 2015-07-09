#ifndef __BASIC__
#define __BASIC__


/**
 * @file basics.h
 *
 * @brief contains standard type definitions for C
 *
 * Types Enum - CTypes
 * Integer Types - 8bit, 16bit, 32bit, 64bit signed and unsiged
 * Char Types - word, line, page
 * Pointer Types - void * and const void * typedefs
 *
 * NULL define
 * TRUE and FALSE defines
 *
 * Function Pointers - FreeNotify, CloneNotify, CompareNotify
 */


/**< data types enum */
typedef enum CTypes
{
    NONE,
    VOID,
    INT,
    UINT,
    FLOAT,
    DOUBLE,
    LONG,
    CHAR,
    WORD,      /**< 32 bit char * */
    LINE,      /**< 128 bit char * */
    PAGE,      /**< 1024 bit char * */
    BOOL,
    LIST,
    DLIST,
    QUEUE,
    STACK,
    CUSTOM     /**< user created data */
}CTypes;


/* unsigned sized int defines */
typedef unsigned char uint8;             /**< unsigned 8 bit integer  */
typedef unsigned short uint16;           /**< unsigned 16 bit integer */
typedef unsigned int uint32;             /**< unsigned 32 bit integer */
typedef unsigned long uint64;            /**< unsigned 64 bit integer */

/* signed sized int defines */
typedef signed char int8;                /**< signed 8 bit integer  */
typedef signed short int16;              /**< signed 16 bit integer */
typedef signed int int32;                /**< signed 32 bit integer */
typedef signed long int64;               /**< signed 64 bit integer */


/* char defines */
#define WORDLEN 32
typedef char word[ WORDLEN ];

#define LINELEN 128
typedef char line[ LINELEN ];

#define PAGELEN 1024
typedef char page[ PAGELEN ];


/* NULL define */
#ifndef NULL

#ifdef __cplusplus
#define NULL 0                           /**< NULL for c++ */
#else
#define NULL ((void *) 0)                /**< NULL for c */
#endif

#endif


/* data pointer defines */
typedef void* dataptr;                   /**< void pointer data type */
typedef const void* constdataptr;        /**< constant void pointer data type */


/* TRUE/FALSE defines */
#ifndef FALSE
#define FALSE ( 0 )                      /**< false define */
#endif

#ifndef TRUE
#define TRUE (!FALSE)                    /**< true define */
#endif


/* function pointer defines */
typedef void ( *FreeNotify )( dataptr *data );                   /**< free function pointer */
typedef dataptr ( *CloneNotify )( dataptr data );                /**< duplicate function pointer */
typedef uint8 ( *CompareNotify )( dataptr d1, dataptr d2 );       /**< compare function pointer */


#endif
