#include "doubly_linked_list.h"


DList* New_DList( dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    DList *new;

    new = C_New( DList, 1 );
    Return_Val_If_Fail( new, NULL );

    memset( new, 0, sizeof( DList ) );
    new->data = Alloc_And_Set( data, type );
    new->type = type;
    new->Free = Free;

    return new;
}


Bool Prepend_To_DList( DList **list, dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    DList *new;


    Return_Val_If_Fail( list, FALSE );
    Return_Val_If_Fail( *list, FALSE );

    new = New_DList( data, type, Free );
    Return_Val_If_Fail( new, FALSE );

    new->next = *list;
    new->next->prev = new;
    *list = new;

    return TRUE;
}


Bool Append_To_DList( DList *list, dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    DList *new, *end;

    Return_Val_If_Fail( list, FALSE );

    new = New_DList( data, type, Free );
    Return_Val_If_Fail( new, FALSE );

    end = End_Of_DList( list );
    end->next = new;
    new->prev = end;

    return TRUE;
}


Bool Insert_Into_DList( DList **list, uint32 index, dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    DList *new, *temp;
    uint32 i;

    Return_Val_If_Fail( list, FALSE );
    Return_Val_If_Fail( *list, FALSE );
    Return_Val_If_Succ( index >= Length_Of_DList( *list ), FALSE );

    if( index == 0 ) return Prepend_To_DList( list, data, type, Free );
    new = New_DList( data, type, Free );
    Return_Val_If_Fail( new, FALSE );

    temp = *list;

    for( i = 0; i <= index - 1; i++ )
    {
	temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;
    new->prev = temp;
    new->next->prev = new;

    return TRUE;
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

    dup = New_DList( list->data, list->type, list->Free );
    Return_Val_If_Fail( dup, NULL );

    list = list->next;

    while( list )
    {
	if( !Append_To_DList( dup, list->data, list->type, list->Free ) ) 
	{
	    Free_DList( &dup );
	    return NULL;
	}
	list = list->next;
    }

    return dup;
}


void Remove_From_DList( DList **list, dataptr rm, Bool all )
{
    DList *temp;

    Return_If_Fail( list );
    Return_If_Fail( *list );

    temp = *list;

    while( temp  )
    {
	if( temp->data == rm )
	{
	    if( !temp->prev )
	    {
		*list = temp->next;
		temp->prev = NULL;
	    }
	    else
	    {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	    }

	    free( temp );

	    if( !all ) break;
	}

	temp = temp->next;
    }
}


void Remove_DList_Segment( DList **list, DList *seg )
{
    DList *temp;

    Return_If_Fail( list );
    Return_If_Fail( *list );
    Return_If_Fail( seg );

    temp = *list;

    if( temp == seg )
    {
	*list = temp->next;
	temp->prev = NULL;
    }
    else
    {
	while( temp && temp->next && ( temp->next != seg ) )
	{
	    temp = temp->next;
	}

	Return_If_Fail( temp );

	temp->next = seg->next;
	seg->next->prev = temp;
    }

    Free_DList_Segment( &seg );
}


void Free_DList_Segment( DList **seg )
{
    DList *temp;

    Return_If_Fail( seg );
    Return_If_Fail( *seg );

    temp = *seg;

    if( temp->Free ) temp->Free( temp->data );
    else free( temp->data );

    free( temp );
    *seg = NULL;
}


void Free_DList( DList **list )
{
    DList *temp, *next;

    Return_If_Fail( list );
    Return_If_Fail( *list );

    temp = *list;

    while( temp )
    {
	next = temp->next;
	Free_DList_Segment( &temp );
	temp = next;
    }

    *list = NULL;
}


/*eof*/
