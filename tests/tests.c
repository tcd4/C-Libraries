#include <stdio.h>
#include "debug.h"
#include "boolean.h"


void Bool_Test();


int main( int argc, char *argv[] )
{
    Bool_Test();

    return 0;
}


void Bool_Test()
{
    Bool a, b, c, d, e;

    printf( "\n##### Bool Test #####\n" );
    a = TRUE;
    b = FALSE;
    c = 5;
    
    printf( "Bool_To_String test\n" );
    printf( "a: %s\n", Bool_To_String( a ) );
    printf( "b: %s\n", Bool_To_String( b ) );
    printf( "c: %s\n", Bool_To_String( c ) );

    printf( "\nString_To_True test\n" );
    a = String_To_True( "true" );
    b = String_To_True( "True" );
    c = String_To_True( "TRUE" );
    d = String_To_True( NULL );
    e = String_To_True( "Sugar Song to Bitter Step" );

    printf( "a: %s\n", Bool_To_String( a ) );
    printf( "b: %s\n", Bool_To_String( b ) );
    printf( "c: %s\n", Bool_To_String( c ) );
    printf( "d: %s\n", Bool_To_String( d ) );
    printf( "e: %s\n", Bool_To_String( e ) );

    printf( "\nString_To_False test\n" );
    a = String_To_False( "false" );
    b = String_To_False( "False" );
    c = String_To_False( "FALSE" );
    d = String_To_False( NULL );
    e = String_To_False( "Unison Square Garden" );

    printf( "a: %s\n", Bool_To_String( a ) );
    printf( "b: %s\n", Bool_To_String( b ) );
    printf( "c: %s\n", Bool_To_String( c ) );
    printf( "d: %s\n", Bool_To_String( d ) );
    printf( "e: %s\n", Bool_To_String( e ) );

    printf( "\nString_To_Bool test\n" );
    a = String_To_Bool( "true" );
    b = String_To_Bool( "True" );
    c = String_To_Bool( "Kekkai Sensen" );
    d = String_To_Bool( NULL );
    e = String_To_Bool( "false" );

    printf( "a: %s\n", Bool_To_String( a ) );
    printf( "b: %s\n", Bool_To_String( b ) );
    printf( "c: %s\n", Bool_To_String( c ) );
    printf( "d: %s\n", Bool_To_String( d ) );
    printf( "e: %s\n", Bool_To_String( e ) );

    printf( "\nSuccess\n" );
}
