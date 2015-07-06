#include "doubly_linked_list.h"


void Alloc_DList_Data( DList *list, dataptr data, CTypes type )
{
    switch( type )
    {
    case NONE:
	list->data = NULL;
	break;
    case VOID:
	list->data = data;
	break;
    case INT:
	list->data = malloc( sizeof( int32 ) );
	memcpy( list->data, data, sizeof( int32 ) );
	break;
    case UINT:
	list->data = malloc( sizeof( uint32 ) );
	memcpy( list->data, data, sizeof( uint32 ) );
	break;
    case FLOAT:
	list->data = malloc( sizeof( float ) );
	memcpy( list->data, data, sizeof( float ) );
	break;
    case DOUBLE:
	list->data = malloc( sizeof( double ) );
	memcpy( list->data, data, sizeof( double ) );
	break;
    case LONG:
	list->data = malloc( sizeof( long ) );
	memcpy( list->data, data, sizeof( long ) );
	break;
    case CHAR:
	list->data = malloc( sizeof( char ) );
	memcpy( list->data, data, sizeof( char ) );
	break;
    case WORD:
	list->data = malloc( sizeof( char ) * LINELEN );
	memcpy( list->data, data, sizeof( char ) * WORDLEN );
	break;
    case LINE:
	list->data = malloc( sizeof( char ) * LINELEN );
	memcpy( list->data, data, sizeof( char ) * LINELEN );
	break;
    case PAGE:
	list->data = malloc( sizeof( char ) * PAGELEN );
	memcpy( list->data, data, sizeof( char ) * PAGELEN );
	break;
    case CUSTOM:
	list->data = data;
	break;
    }
}


DList* New_DList( dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    DList *new;

    new = C_New( DList, 1 );
    Return_Val_If_Fail( new, NULL );

    memset( new, 0, sizeof( DList ) );
    Alloc_DList_Data( new, data, type );
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
