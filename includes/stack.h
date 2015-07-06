#ifndef __STACK__
#define __STACK__


/**
 * @file stack.h
 *
 * @brief contains support for stacks
 *
 * Stack Type - Stack
 *
 * Create Function - New_Stack()
 * Push/Pop Functions - Stack_Push(), Stack_Pop()
 * Util Functions - Clear_Stack(), Is_Stack_Empty(), Duplicate_Stack()
 * Free Function - Free_Stack()
 *
 * WARNING - STACKS SHOULD ONLY CONTAIN 1 DATA TYPE
 * WARNING: USERS WILL BE RESPONSIBLE FOR ALLOCATING MEMORY FOR NON-STANDARD C DATA TYPES
 * WARNING: MAKE SURE YOU HAVE NO POINTERS TO STACK DATA WHEN FREEING A STACK
 */


#include <string.h>
#include "stdmacros.h"
#include "stdfuncs.h"
#include "stdtypes.h"
#include "platforms.h"
#include "boolean.h"
#include "linked_list.h"


START_DECLS


/**< the stack struct */
typedef struct
{
    List       *start;                       /**< the first element in the stack */
    List       *end;                         /**< the last element in the stack */ 
    uint32     length;                       /**< the number of elements in the stack */
    CTypes     type;                         /**< the data type of the data */

    void       ( *Free )( dataptr data );    /**< function pointer for the data's custom free function */
}Stack;


/**
 * @brief creates a new Stack
 *
 * @param type the data type of the data
 * @param Free a pointer to the data's custom free function
 *
 * @return a pointer to the new Stack
 */
Stack* New_Stack( CTypes types, void ( *Free )( dataptr data ) );

/**
 * @brief adds data onto the end of a Stack
 *
 * @param stack the Stack to push onto
 * @param data the data to push onto the Stack
 *
 * @return TRUE if push succeeded, FALSE if else
 */
Bool Push_Stack( Stack *stack, dataptr data );

/**
 * @brief retrieves the data from the last element of th Stack and removes it from the Stack
 *
 * @param stack the Stack to pop off of
 *
 * @return a pointer to the popped data
 */
dataptr Pop_Stack( Stack *stack );
/**
 * @brief clears all the data from a Stack
 *
 * @param stack the Stack to clear
 */
void Clear_Stack( Stack *stack );

/**
 * @brief checks if a Stack is empty
 *
 * @param stack the Stack to check
 *
 * @return TRUE if the Stack if empty, False if else
 */
Bool Is_Stack_Empty( Stack *stack );

/**
 * @brief duplicates a Stack
 *
 * @param stack the Stack to duplicated
 *
 * @return a pointer to the duplicate Stack
 */
Stack* Duplicate_Stack( Stack *stack );

/**
 * @brief frees the memory of a Stack
 *
 * @param stack the Stack to free
 */
void Free_Stack( Stack **stack );


END_DECLS


#endif
