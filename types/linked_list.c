#include "linked_list.h"


void Alloc_List_Data( List *list, dataptr data, CTypes type )
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


List* New_List( dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    List *new;

    new = C_New( List, 1 );
    Return_Val_If_Fail( new, NULL );

    memset( new, 0, sizeof( List ) );
    Alloc_List_Data( new, data, type );
    new->type = type;
    new->Free = Free;

    return new;
}


Bool Append_To_List( List *list, dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    List *new, *end;

    Return_Val_If_Fail( list, FALSE );

    new = New_List( data, type, Free );
    Return_Val_If_Fail( new, FALSE );

    end = End_Of_List( list );
    end->next = new;

    return TRUE;
}


Bool Prepend_To_List( List **list, dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    List *new;

    Return_Val_If_Fail( list, FALSE );
    Return_Val_If_Fail( *list, FALSE );

    new = New_List( data, type, Free );
    Return_Val_If_Fail( new, FALSE );

    new->next = *list;
    *list = new;

    return TRUE;
}


Bool Insert_Into_List( List **list, uint32 index, dataptr data, CTypes type, void ( *Free )( void *data ) )
{
    List *new, *temp;
    uint32 i;

    Return_Val_If_Fail( list, FALSE );
    Return_Val_If_Fail( *list, FALSE );
    Return_Val_If_Succ( index >= Length_Of_List( *list ), FALSE );

    if( index == 0 ) return Prepend_To_List( list, data, type, Free );

    new = New_List( data, type, Free );
    Return_Val_If_Fail( new, FALSE );

    temp = *list;
    i = 0;

    while( i != index - 1 )
    {
	i++;
	temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;

    return TRUE;
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
    List *dup;

    Return_Val_If_Fail( list, NULL );

    dup = New_List( list->data, list->type, list->Free );
    Return_Val_If_Fail( dup, NULL );

    list = list->next;

    while( list )
    {
	if( !Append_To_List( dup, list->data, list->type, list->Free ) ) return NULL;
	list = list->next;
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
