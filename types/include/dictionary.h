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
    dataptr         name;          /**< the key */
    CTypes          nameType;      /**< the key type */
    dataptr         val;           /**< the value */
    CTypes          valType;       /**< the value type */
    FreeNotify      destroy;       /**< the free function to use */
}Charm;


/**< the dictionary type */
typedef struct Bracelet_s
{
    DList      *charms;       /**< a DList of charms to hold key/value pairs */
    uint32     count;         /**< the number of charms in the DList */
}Bracelet;


END_DECLS


#endif
