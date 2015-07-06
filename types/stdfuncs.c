#include "stdfuncs.h"


dataptr Alloc_Type( CTypes type )
{
    dataptr new;

    switch( type )
    {
    case NONE:
	new = NULL;
	break;
    case VOID:
	new = NULL;
	break;
    case INT:
	new = malloc( sizeof( int32 ) );
	break;
    case UINT:
	new = malloc( sizeof( uint32 ) );
	break;
    case FLOAT:
	new = malloc( sizeof( float ) );
	break;
    case DOUBLE:
	new = malloc( sizeof( double ) );
	break;
    case LONG:
	new = malloc( sizeof( long ) );
	break;
    case CHAR:
	new = malloc( sizeof( char ) );
	break;
    case WORD:
	new = malloc( sizeof( char ) * LINELEN );
	break;
    case LINE:
	new = malloc( sizeof( char ) * LINELEN );
	break;
    case PAGE:
	new = malloc( sizeof( char ) * PAGELEN );
	break;
    case CUSTOM:
	new = NULL;
	break;
    }

    return new;
}


dataptr Alloc_And_Set( dataptr data, CTypes type )
{
    dataptr new;

    switch( type )
    {
    case NONE:
	new = NULL;
	break;
    case VOID:
	new = data;
	break;
    case INT:
	new = malloc( sizeof( int32 ) );
	memcpy( new, data, sizeof( int32 ) );
	break;
    case UINT:
	new = malloc( sizeof( uint32 ) );
	memcpy( new, data, sizeof( uint32 ) );
	break;
    case FLOAT:
	new = malloc( sizeof( float ) );
	memcpy( new, data, sizeof( float ) );
	break;
    case DOUBLE:
	new = malloc( sizeof( double ) );
	memcpy( new, data, sizeof( double ) );
	break;
    case LONG:
	new = malloc( sizeof( long ) );
	memcpy( new, data, sizeof( long ) );
	break;
    case CHAR:
	new = malloc( sizeof( char ) );
	memcpy( new, data, sizeof( char ) );
	break;
    case WORD:
	new = malloc( sizeof( char ) * LINELEN );
	memcpy( new, data, sizeof( char ) * WORDLEN );
	break;
    case LINE:
	new = malloc( sizeof( char ) * LINELEN );
	memcpy( new, data, sizeof( char ) * LINELEN );
	break;
    case PAGE:
	new = malloc( sizeof( char ) * PAGELEN );
	memcpy( new, data, sizeof( char ) * PAGELEN );
	break;
    case CUSTOM:
	new = data;
	break;
    }

    return new;
}


/*eof*/
