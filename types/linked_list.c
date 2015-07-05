#include "linked_list.h"


List* New_List( dataptr data, size_t size, void ( *Free )( void *data ) )
{
    List *new;

    new = C_New( List, 1 );
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

    return new;
}


void Append_To_List( List *list, dataptr data, size_t size, void ( *Free )( void *data ) )
{
    List *new, *end;

    Return_If_Fail( list );

    new = New_List( data, size, Free );
    Return_If_Fail( new );

    end = End_Of_List( list );
    end->next = new;
}


void Prepend_To_List( List **list, dataptr data, size_t size, void ( *Free )( void *data ) )
{
    List *new;

    Return_If_Fail( list );
    Return_If_Fail( *list );

    new = New_List( data, size, Free );
    Return_If_Fail( new );

    new->next = *list;
    *list = new;
}


void Insert_Into_List( List **list, uint32 index, dataptr data, size_t size, void ( *Free )( void *data ) )
{
    List *new, *temp;
    uint32 i;

    Return_If_Fail( list );
    Return_If_Fail( *list );
    Return_If_Fail( index < 0 );

    if( index == 0 )
    {
	Prepend_To_List( list, data, size, Free );
	return;
    }

    new = New_List( data, size, Free );
    Return_If_Fail( new );

    temp = *list;
    i = 1;

    while( temp )
    {
	if( i == index )
	{
	    new->next = temp->next;
	    temp->next = new;
	    break;
	}

	i++;
	temp = temp->next;
    }
}


List* Find_In_List( List *list, dataptr data )
{
    Return_Val_If_Fail( list, NULL );

    while( list )
    {
	if( list->data == data ) break;
	list = list->next;
    }
    
    return list;
}


List* End_Of_List( List *list )
{
    Return_Val_If_Fail( list, NULL );

    while( list->next )
    {
	list = list->next;
    }

    return list;
}


uint32 Length_Of_List( List *list )
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


List* Duplicate_List( List *list )
{
    List *dup, *temp;

    Return_Val_If_Fail( list, NULL );

    dup = New_List( list->data, list->alloc, list->Free );
    Return_Val_If_Fail( dup, NULL );

    temp = list;
    list = list->next;

    while( list )
    {
	Append_To_List( dup, list->data, list->alloc, list->Free );
	list = list->next;
    }

    if( ( Length_Of_List( dup ) != Length_Of_List( temp ) ) )
    {
	Free_List( &dup );
	return NULL;
    }

    return dup;
}


void Remove_List_Segment( List **list, List *seg )
{
    List *temp;

    Return_If_Fail( list );
    Return_If_Fail( *list );
    Return_If_Fail( seg );

    temp = *list;

    if( temp == seg )
    {
	*list = temp->next;
    }
    else
    {
	while( temp && temp->next && ( temp->next != seg ) )
	{
	    temp = temp->next;
	}

	Return_If_Fail( temp );

	temp->next = seg->next;
    }

    Free_List_Segment( &seg );
}


void Remove_From_List( List **list, dataptr rm, Bool all )
{
    List *temp, *prev;

    Return_If_Fail( list );
    Return_If_Fail( *list );

    temp = *list;
    prev = temp;

    while( temp  )
    {
	if( temp->data == rm )
	{
	    if( prev == temp ) *list = temp->next;
	    else prev->next = temp->next;

	    free( temp );

	    if( !all ) break;
	}

	prev = temp;
	temp = temp->next;
    }
}


void Free_List_Segment( List **seg )
{
    List *temp;

    Return_If_Fail( seg );
    Return_If_Fail( *seg );

    temp = *seg;

    if( temp->Free ) temp->Free( temp->data );
    else free( temp->data );

    free( temp );
    *seg = NULL;
}


void Free_List( List **list )
{
    List *temp, *next;

    Return_If_Fail( list );
    Return_If_Fail( *list );

    temp = *list;

    while( temp )
    {
	next = temp->next;
	Free_List_Segment( &temp );
	temp = next;
    }

    *list = NULL;
}


/*eof*/
