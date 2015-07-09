#ifndef __QUEUE__
#define __QUEUE__


/**
 * @file queue.h
 *
 * @brief contains support for queues
 *
 * Queue Type - Queue
 *
 * Create Function - New_Queue()
 * Push/Pop Functions - Queue_Push(), Queue_Pop()
 * Util Functions - Clear_Queue(), Is_Queue_Empty(), Duplicate_Queue()
 * Free Function - Free_Queue()
 *
 * WARNING: QUEUES SHOULD ONLY CONTAIN 1 DATA TYPE
 * WARNING: USERS WILL BE RESPONSIBLE FOR ALLOCATING MEMORY FOR NON-STANDARD C DATA TYPES
 *          IF A CLONE FUNCTION ISN'T PROVIDED
 * WARNING: MAKE SURE YOU HAVE NO POINTERS TO QUEUE DATA WHEN FREEING A QUEUE
 */


#include <string.h>
#include "stdmacros.h"
#include "stdtypes.h"
#include "platforms.h"
#include "boolean.h"
#include "linked_list.h"


START_DECLS


typedef struct
{
    List            *start;   /**< the first element in the queue */
    uint32          length;   /**< the number of elements in the queue */
    CTypes          type;     /**< the data type of the data */

    CloneNotify     clone;    /**< function pointer for custom duplicate functions */
    FreeNotify      destroy;  /**< function pointer for the data's custom free function */
}Queue;


/**
 * @brief creates a new Queue
 *
 * @param type the data type of the data
 * @param clone a pointer to the data's custom duplicate function
 * @param destroy a pointer to the data's custom free function
 *
 * @return a pointer to the new Queue
 */
Queue* New_Queue( CTypes type, CloneNotify clone, FreeNotify destroy );

/**
 * @brief adds data onto the end of a Queue
 *
 * @param queue the Queue to push onto
 * @param data the data to push onto the Queue
 *
 * @return TRUE if push succeeded, FALSE if else
 */
Bool Push_Queue( Queue *queue, dataptr data );

/**
 * @brief retrieves the data from the 1st element of the Queue and moves the Queue forward
 *
 * @param queue the Queue to pop off
 *
 * @return a pointer to the popped data
 */
dataptr Pop_Queue( Queue *queue );

/**
 * @brief clears all the data from a Queue
 *
 * @param queue the Queue to clear
 */
void Clear_Queue( Queue *queue );

/**
 * @brief checks if a Queue is empty
 *
 * @param queue the Queue to check
 *
 * @return True if the Queue is empty, False if else
 */
Bool Queue_Is_Empty( Queue *queue );

/**
 * @brief duplicates a Queue
 *
 * @param queue the Queue to duplicate
 *
 * @return a pointer to the duplicate Queue
 */
Queue* Duplicate_Queue( Queue *queue );

/**
 * @brief frees the memory of a Queue
 *
 * @param queue the Queue to free
 */
void Free_Queue( Queue **queue );


END_DECLS


#endif
