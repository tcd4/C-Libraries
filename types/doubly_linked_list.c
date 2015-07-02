#include "doubly_linked_list.h"


DList* New_DList( dataptr data, size_t size, void ( *Free )( void *data ) )
{
    DList *new;

    new = C_New( DList, 1 );
    Return_Val_If_Fail( new, NULL );

    if( size ) 
    {
	new->data = malloc( size );
	memcpy( new->data, data, size );
    }
    else
    {
	new->data = data;
    }

    if( Free ) 
    {
	new->Free = Free;
    }

    new->alloc = size;
    new->next = NULL;
    new->prev = NULL;

    return new;
}


void Prepend_To_DList( DList **list, dataptr data, size_t size, void ( *Free )( void *data ) )
{
    DList *new;

    Return_If_Fail( list );
    Return_If_Fail( *list );

    new = New_DList( data, size, Free );
    Return_If_Fail( new );

    new->next = *list;
    new->next->prev = new;
    *list = new;
}

/*eof*/
