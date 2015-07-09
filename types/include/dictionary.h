#ifndef __DICTIONARY__
#define __DICTIONARY__


/**
 * @file dictionary.h
 *
 * @brief contains support for dictionaries
 *
 * Dictionary Type - Bracelet
 */


#include "stdmacros.h"
#include "stdtypes.h"
#include "stdfuncs.h"
#include "platforms.h"
#include "boolean.h"
#include "linked_list.h"
#include "doubly_linked_list.h"
#include "queue.h"
#include "stack.h"


START_DECLS


/**< the key/value type */
typedef struct Charm_s
{
    word            key;           /**< the key */

    dataptr         val;           /**< the value */
    CTypes          valType;       /**< the value type */

    CloneNotify     valClone;      /**< the duplicate function for the value */
    FreeNotify      valDestroy;    /**< the free function for the value */  
}Charm;


/**< the dictionary type */
typedef struct Bracelet_s
{
    DList      *charms;       /**< a DList of charms to hold key/value pairs */
    uint32     count;         /**< the number of charms in the DList */
}Bracelet;


/**
 * @brief creates a new Bracelet
 *
 * @return a pointer to the new Bracelet
 */
Bracelet* New_Bracelet();

/**
 * @brief creates a new Charm
 *
 * @param key the key for the Charm
 * @param val the value for the Charm
 * @param valType the data type of the val
 * @param clone the duplicate function for the value
 * @param destroy the free function for the value
 *
 * @return a pointer to the new Charm
 */
Charm* New_Charm( word key, dataptr val, CTypes valType, CloneNotify clone, FreeNotify destroy );

/**
 * @brief adds a Charm to a Bracelet
 *
 * @param bracelet the Bracelet to add to
 * @param charm the Charm to add on
 *
 * @return TRUE if the charm was added, FALSE if else
 */
Bool Add_Charm( Bracelet *bracelet, Charm *charm );

/**
 * @brief removes a Charm from a Bracelet
 *
 * @param bracelet the Bracelet to remove from
 * @param charm the Charm to remove
 */
void Remove_Charm( Bracelet *bracelet, Charm *charm );

/**
 * @brief finds a Charm in a Bracelet
 *
 * @param bracelet the Bracelet to search in
 * @param key the key to search for
 *
 * @return a pointer to the found Charm or NULL if it's not found
 */
Charm* Find_Charm( Bracelet *bracelet, word key );

/**
 * @brief frees all the Charms from a Bracelet
 *
 * @param bracelet the Bracelet to clear
 */
void Clear_Bracelet( Bracelet *bracelet );

/**
 * @brief duplicates a Bracelet
 *
 * @param bracelet the Bracelet to duplicate
 *
 * @return a pointer to the duplicate Bracelet
 */
Bracelet* Duplicate_Bracelet( Bracelet *bracelet );

/**
 * @brief duplicates a Charm
 *
 * @param charm the Charm to duplicate
 *
 * @return a pointer to the duplicate Charm
 */
Charm* Duplicate_Charm( Charm *charm );

/**
 * @brief frees the allocated memory from a Charm
 *
 * @param charm the Charm to free
 */
void Free_Charm( Charm **charm );

/**
 * @brief frees the allocated memory from a Bracelet 
 *
 * @param bracelet the Bracelet to free
 */
void Free_Bracelet( Bracelet **bracelet );


END_DECLS


#endif
