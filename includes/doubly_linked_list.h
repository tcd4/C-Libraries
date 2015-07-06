#ifndef __DOUBLY_LINKED_LIST__
#define __DOUBLY_LINKED_LIST__


/**
 * @file doubly_linked_list.h
 *
 * @brief contains support for doubly linked lists
 *
 * Doubly Linked List Type - DList
 *
 * Create Function - New_DList()
 * Add To Functions - Append_To_DList(), Prepend_To_DList(), Insert_Into_DList()
 * Remove From Functions - Remove_From_DList(), Remove_DList_Segment()
 * Util Functions - Find_In_DList(), End_Of_DList(), Length_Of_DList(), Duplicate_DList()
 * Free Functions - Free_DList_Segment(), Free_DList()
 *
 * WARNING: USERS WILL BE RESPONSIBLE FOR ALLOCATING MEMORY FOR NON-STANDARD C DATA TYPES
 * WARNING: MAKE SURE YOU HAVE NO POINTERS TO LIST DATA WHEN FREEING A DLIST
 */


#include <string.h>
#include "stdmacros.h"
#include "stdtypes.h"
#include "platforms.h"
#include "boolean.h"


START_DECLS


/**< the doubly linked list struct */
typedef struct dlist_s
{
    dataptr         data;                    /**< the data in the DList segment */
    size_t          type;                    /**< the data type of the data */
    struct dlist_s  *next;                   /**< the next segment in the DList */
    struct dlist_s  *prev;                   /**< the previous segment in the DList */

    void            ( *Free )( void *data ); /**< function pointer for the data's custom free function */

}DList;


/**
 * @brief initializes a new DList
 *
 * @param data the data to put in the DList
 * @param type the data type of the data
 * @param Free a pointer to the data's custom free function
 *
 * @return a pointer to the newly created DList
 */
DList* New_DList( dataptr data, CTypes type, void ( *Free )( void *data ) );

/**
 * @brief allocates the data for a DList
 *
 * @param list the DList to alloc the data for
 * @param data the data to alloc for
 * @param type the data type to allocate for
 */
void Alloc_DList_Data( DList *list, dataptr data, CTypes type );

/**
 * @brief appends data to a DList
 *
 * @param list the DList to append to
 * @param data the data to put in the DList
 * @param type the data type of the data
 * @param Free a pointer to the data's custom free function
 *
 * @return TRUE if append was successful, FALSE if else
 */
Bool Append_To_DList( DList *list, dataptr data, CTypes type, void ( *Free )( void *data ) );

/**
 * @brief prepends data to a DList
 *
 * @param list the DList to prepend to
 * @param data the data to put in the DList
 * @param type the data type of the data
 * @param Free a pointer to the data's custom free function
 *
 * @return TRUE if prepend was successful, FALSE if else
 */
Bool Prepend_To_DList( DList **list, dataptr data, CTypes type, void ( *Free )( void *data ) );

/**
 * @brief inserts data into a DList at an index
 *
 * @param list the DList to insert into
 * @param index the index to insert into
 * @param data the data to put in the DList
 * @param type the data type of the data
 * @param Free a pointer to the data's custom free function
 *
 * @return TRUE if insert was successful, FALSE if else
 */
Bool Insert_Into_DList( DList **list, uint32 index, dataptr data, CTypes type, void ( *Free )( void *data ) );

/**
 * @brief finds data in a DList
 *
 * @param list the DList to search
 * @param data the data to search for
 *
 * @return a pointer to the DList segment the data is in
 */
DList* Find_In_DList( DList *list, dataptr data );

/**
 * @brief finds the last segment in a DList
 *
 * @param list the DList to use
 *
 * @return a pointer to the last segment in the DList
 */
DList* End_Of_DList( DList *list );

/**
 * @brief finds the number of elements in a DList
 *
 * @param list the DList to use
 *
 * @return the number of elements in the DList
 */
uint32 Length_Of_DList( DList *list );

/**
 * @brief duplicates a DList
 *
 * @param list the DList to duplicate
 *
 * @return a pointer to the duplicate DList
 */
DList* Duplicate_DList( DList *list );


/**
 * @brief removes a segment from a DList
 *
 * @param list the DList to remove from
 * @param seg the segment to remove
 */
void Remove_DList_Segment( DList **list, DList *seg );

/**
 * @brief removes data from a DList
 *
 * @param list the DList to remove from
 * @param rm the data to remove
 * @param all determines whether to remove all the rm or just the 1st instance
 */
void Remove_From_DList( DList **list, dataptr rm, Bool all );

/**
 * @brief frees the memory from a segment of a DList
 *
 * @param seg a pointer to a pointer of the segment to free
 */
void Free_DList_Segment( DList **seg );


/**
 * @brief frees the memory of a DList
 *
 * @param list a pointer to a pointer of the DList to free
 */
void Free_DList( DList **list );


END_DECLS


#endif
