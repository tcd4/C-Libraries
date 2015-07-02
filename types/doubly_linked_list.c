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


void Append_To_DList( DList *list, dataptr data, size_t size, void ( *Free )( void *data ) )
{
    DList *new, *end;

    Return_If_Fail( list );

    new = New_DList( data, size, Free );
    Return_If_Fail( new );

    end = End_Of_DList( list );
    end->next = new;
    new->prev = end;
}


void Insert_Into_DList( DList **list, uint32 index, dataptr data, size_t size, void ( *Free )( void *data ) )
{
    DList *new, *temp;
    uint32 i;

    Return_If_Fail( list );
    Return_If_Fail( *list );
    Return_If_Fail( index < 0 );

    if( index == 0 )
    {
	Prepend_To_DList( list, data, size, Free );
	return;
    }

    new = New_DList( data, size, Free );
    Return_If_Fail( new );

    temp = *list;
    temp = temp->next;
    i = 1;
    
    while( temp )
    {
	if( i == index )
	{
	    new->next = temp;
	    new->prev = temp->prev;
	    temp->prev->next = new;

	    break;
	}

	i++;
	temp = temp->next;
    }
}


DList* End_Of_DList( DList *list )
{
    Return_Val_If_Fail( list, NULL );

    while( list->next )
    {
	list = list->next;
    }

    return list;
}


uint32 Length_Of_DList( DList *list )
{
    uint32 i = 0;

    Return_Val_If_Fail( list, 0 );

    while( list )
    {
	i++;
	list = list->next;
    }

    return i;
}


DList* Find_In_DList( DList *list, dataptr data )
{
    Return_Val_If_Fail( list, NULL );

    while( list )
    {
	if( list->data == data ) break;
	list = list->next;
    }
    
    return list;
}


DList* Duplicate_DList( DList *list )
{
    DList *dup;

    Return_Val_If_Fail( list, NULL );

    dup = New_DList( list->data, list->alloc, list->Free );
    list = list->next;

    while( list )
    {
	Append_To_DList( dup, list->data, list->alloc, list->Free );
	list = list->next;
    }

    return dup;
}



/*eof*/
