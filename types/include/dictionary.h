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
    dataptr         key;           /**< the key */
    CTypes          keyType;       /**< the key type */

    CompareNotify   keyCompare;    /**< the compare function for the key */
    CloneNotify     keyClone;      /**< the duplicate function for the key */
    FreeNotify      keyDestroy;    /**< the free function for the key */

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


Bracelet* New_Bracelet();
Charm* New_Charm( dataptr key, CTypes keyType, dataptr val, CTypes valType );

void Set_Charm_Key_Funcs( Charm *charm, CompareNotify compare, CloneNotify clone, FreeNotify destroy );
void Set_Charm_Val_Funcs( Charm *charm, CloneNotify clone, FreeNotify destroy );

Bool Add_Charm( Bracelet *bracelet, Charm *charm );
void Remove_Charm( Bracelet *bracelet, Charm *charm );
Charm* Find_Charm( Bracelet *bracelet, dataptr data );

void Clear_Bracelet( Bracelet *bracelet );
Bracelet* Duplicate_Bracelet( Bracelet *bracelet );
Charm* Duplicate_Charm( Charm *charm );

void Free_Charm( Charm **charm );
void Free_Bracelet( Bracelet **bracelet );


END_DECLS


#endif
