#ifndef __LINKED_LIST__
#define __LINKED_LIST__


/**
 * @file linked_list.h
 *
 * @brief contains support for linked lists
 *
 * Linked List Type - List
 *
 * Create Function - New_List()
 * Add To Functions - Append_To_List(), Prepend_To_List(), Insert_Into_List()
 * Remove From Functions - Remove_List_Segment(), Remove_From_List()
 * Util Functions - Find_In_List(), End_Of_List(), Length_Of_List(), Duplicate_List()
 * Free Functions - Free_List_Segment(), Free_List()
 *
 * WARNING: USERS WILL BE RESPONSIBLE FOR ALLOCATING MEMORY FOR NON-STANDARD C DATA TYPES
 * WARNING: MAKE SURE YOU HAVE NO POINTERS TO LIST DATA WHEN FREEING A LIST
 */


#include <string.h>
#include "stdmacros.h"
#include "stdfuncs.h"
#include "stdtypes.h"
#include "platforms.h"
#include "boolean.h"


START_DECLS


/**< the linked list struct */
typedef struct list_s
{
    dataptr         data;     /**< the data in the List segment */
    CTypes          type;     /**< the data type of the data */
    struct list_s   *next;    /**< the next segment in the List */

    void            ( *Free )( dataptr data );    /**< function pointer for custom free functions */
}List;


/**
 * @brief initializes a new List
 *
 * @param data the data to put in the List
 * @param type the data type of the data
 * @param Free a pointer to the data's custom free function
 *
 * @return a pointer to the newly created List
 */
List* New_List( dataptr data, CTypes type, void ( *Free )( void *data ) );

/**
 * @brief appends data to a List
 *
 * @param list the List to append to
 * @param data the data to put in the List
 * @param type the data type of the data 
 * @param Free a pointer to the data's custom free function
 *
 * @return TRUE if append was successful, FALSE if else
 */
Bool Append_To_List( List *list, dataptr data, CTypes type, void ( *Free )( void *data ) );

/**
 * @brief prepends data to a List
 *
 * @param list the List to prepend to
 * @param data the data to put in the List
 * @param type the data type of the data
 * @param Free a pointer to the data's custom free function
 *
 * @return TRUE if prepend was successful, FALSE if else
 */
Bool Prepend_To_List( List **list, dataptr data, CTypes type, void ( *Free )( void *data ) );

/**
 * @brief inserts data into a List at an index
 *
 * @param list the List to insert into
 * @param index the index to insert into
 * @param data the data to put in the List
 * @param type the data type of the data
 * @param Free a pointer to the data's custom free function
 *
 * @return TRUE if insert was successful, FALSE if else
 */
Bool Insert_Into_List( List **list, uint32 index, dataptr data, CTypes type, void ( *Free )( void *data ) );

/**
 * @brief finds data in a List
 *
 * @param list the List to search
 * @param data the data to search for
 *
 * @return a pointer to the List segment the data is in
 */
List* Find_In_List( List *list, dataptr data );

/**
 * @brief finds the last segment in a List
 *
 * @param list the List to use
 *
 * @return a pointer to the last segment in the List
 */
List* End_Of_List( List *list );

/**
 * @brief finds the number of elements in a List
 *
 * @param list the List to use
 *
 * @return the number of elements in the List
 */
uint32 Length_Of_List( List *list );

/**
 * @brief duplicates a List
 *
 * @param list the List to duplicate
 *
 * @return a pointer to the duplicate List
 */
List* Duplicate_List( List *list );

/**
 * @brief removes a segment from a List
 *
 * @param list the List to remove from
 * @param seg the segment to remove
 */
void Remove_List_Segment( List **list, List *seg );

/**
 * @brief removes data from a List
 *
 * @param list the List to remove from
 * @param rm the data to remove
 * @param all determines whether to remove all the rm or just the 1st instance
 */
void Remove_From_List( List **list, dataptr rm, Bool all );

/**
 * @brief frees the memory from a segment of a List
 *
 * @param seg a pointer to a pointer of the segment to free
 */
void Free_List_Segment( List **seg );

/**
 * @brief frees the memory of a List
 *
 * @param list a pointer to a pointer of the List to free
 */
void Free_List( List **list );


END_DECLS


#endif
