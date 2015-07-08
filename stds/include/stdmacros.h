#ifndef __STDMACROS__
#define __STDMACROS__


/**
 * @file stdmacros.h
 *
 * @brief contains macros for commonly used functions
 *
 * C Macro Statements - STMT_START, STMT_END
 *
 * Return Macros - Return_If_Fail( expr ), Return_Val_If_Fail( expr, value ), Return_If_Succ( expr ),  Return_Val_If_Succ( expr, value )
 *
 * Memory Allocation Macros - C_New( type, number ), C_New_Zeroed( type, number ), C_Realloc( location, type, number )
 */


#include <stdlib.h>


/* macro statements */
/**< begins a statement for creating macros */
#define STMT_START   do{
/**< ends a statement for creating macros */
#define STMT_END     }while(0)


/* function return macros */
/**
 * @brief ends a function if an expression fails
 *
 * @param expr the expression to check
 */
#define Return_If_Fail( expr )   \
    STMT_START                   \
    if( !expr ) {return;};	 \
    STMT_END

/**
 * @brief ends a function if an expression fails
 *
 * @param expr the expression to check
 * @param value the value the function should return
 *
 * @return value
 */
#define Return_Val_If_Fail( expr, value )	\
    STMT_START                                  \
    if( !expr ) {return value;};                \
    STMT_END

/**
 * @brief ends a function if an expression succeeds
 *
 * @param expr the expression to check
 */
#define Return_If_Succ( expr )   \
    STMT_START                   \
    if( expr ) {return;};        \
    STMT_END

/**
 * @brief ends a function if an expression succeeds
 *
 * @param expr the expression to check
 * @param value the value the function should return
 *
 * @return value
 */
#define Return_Val_If_Succ( expr, value )	\
    STMT_START                                  \
    if( expr ) {return value;};                 \
    STMT_END


/* memory allocation macros */
/**
 * @brief allocates memory
 *
 * @param type     the type to allocate
 * @param number   the number of the type to allocate for
 */
#define C_New( type, number )                ( ( type* ) malloc( sizeof( type ) * number ) )

/**
 * @brief allocates memory and zeroes it
 *
 * @param type     the type to allocate
 * @param number   the number of the type to allocate for
 */
#define C_New_Zeroed( type, number )         ( ( type* ) calloc( number, sizeof( type ) ) )

/**
 * @brief reallocates memory
 *
 * @param location   a pointer to the memory space
 * @param type       the type to reallocate to
 * @param number     the number of the type to allocate for
 */
#define C_Realloc( location, type, number )  ( ( type* ) realloc( location, sizeof( type ) * number ) ) 


#endif
