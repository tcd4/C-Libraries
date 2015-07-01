#include "boolean.h"


Bool String_To_Bool( char *str )
{
    Return_Val_If_Fail( str, FALSE );

    if( String_To_True( str ) )
    {
	return TRUE;
    }
    
    return FALSE;
}


Bool String_To_True( char *str )
{
    Return_Val_If_Fail( str, FALSE );

    if( ( strcmp( str, "true" ) == 0 ) ||
	( strcmp( str, "True" ) == 0 ) ||
	( strcmp( str, "TRUE" ) == 0 ) )
    {
	return TRUE;
    }
   
    return FALSE;
}


Bool String_To_False( char *str )
{
    Return_Val_If_Fail( str, TRUE );

    if( ( strcmp( str, "false" ) == 0 ) ||
	( strcmp( str, "False" ) == 0 ) ||
	( strcmp( str, "FALSE" ) == 0 ) )
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
