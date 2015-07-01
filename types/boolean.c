#include "boolean.h"


Bool String_To_Bool( char *s )
{
    Return_Val_If_Fail( s, FALSE );

    if( String_To_True( s ) )
    {
	return TRUE;
    }
    
    return FALSE;
}


Bool String_To_True( char *s )
{
    Return_Val_If_Fail( s, FALSE );

    if( ( strcmp( s, "true" ) == 0 ) ||
	( strcmp( s, "True" ) == 0 ) ||
	( strcmp( s, "TRUE" ) == 0 ) )
    {
	return TRUE;
    }
   
    return FALSE;
}


Bool String_To_False( char *s )
{
    Return_Val_If_Fail( s, TRUE );

    if( ( strcmp( s, "false" ) == 0 ) ||
	( strcmp( s, "False" ) == 0 ) ||
	( strcmp( s, "FALSE" ) == 0 ) )
    {
	return FALSE;
    }

    return TRUE;
}


char* Bool_To_String( Bool b )
{
    if( b == TRUE ) return "true";
    else if( b == FALSE ) return "false";
    else return NULL;
}

/*eof*/
