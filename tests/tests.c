#include <stdio.h>
#include "debug.h"
#include "boolean.h"
#include "linked_list.h"
#include "doubly_linked_list.h"


void Bool_Test();
void List_Test();
void DList_Test();


int main( int argc, char *argv[] )
{
    /*Bool_Test();*/
    /*List_Test();*/
    DList_Test();

    return 0;
}


void DList_Test()
{
    DList *list, *dup, *temp;
    int a;
    int *b;


    printf( "\n##### DList Test #####\n" );


    printf( "New_DList Test\n" );
    a = 5;
    list = New_DList( &a, sizeof( int ), NULL );
    if( !list )
    {
	printf( "failed to create DList\n" );
	return;
    }
    printf( "start data: %i\n", *( int* )( list->data ) );


    printf( "\nLength_Of_DList Test\n" );
    printf( "length: %i\n", ( int )( Length_Of_DList( list ) ) );


    printf( "\nPrepend_To_DList Test\n" );
    for( a = 4; a >= 0; a-- )
    {
	Prepend_To_DList( &list, &a, sizeof( int ), NULL );
	printf( "prepended: %i\n", *( int* )( list->data ) );
    }


    printf( "\nEnd_Of_DList Test\n" );
    temp = End_Of_DList( list );
    printf( "end data: %i\n", *( int* )( temp->data ) );


    printf( "\nAppend_To_DList Test\n" );
    for( a = 6; a <= 9; a++ )
    {
	Append_To_DList( list, &a, sizeof( int ), NULL );
	temp = End_Of_DList( list );
	printf( "appended: %i\n", *( int* )( temp->data ) );
    }


    printf( "\nInsert_Into_DList Test\n" );
    a = 6;
    Insert_Into_DList( &list, a, &a, sizeof( int ), NULL );
    a = 0;
    Insert_Into_DList( &list, a, &a, sizeof( int ), NULL );
    a = 32;
    Insert_Into_DList( &list, a, &a, sizeof( int ), NULL );


    printf( "\nLength_Of_DList Test\n" );
    printf( "length: %i\n", ( int )( Length_Of_DList( list ) ) );


    printf( "\nFind_In_DList Test\n" );
    b = &a;
    Insert_Into_DList( &list, 5, b, 0, NULL );
    if( Find_In_DList( list, b ) ) printf( "found it\n" );
    else printf( "didn't find it\n" );


    printf( "\nDList Check\n" );
    temp = list;
    while( temp )
    {
	printf( "check: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }


    printf( "\nDuplicate_DList Test\n" );
    dup = Duplicate_DList( list );
    temp = dup;
    while( temp )
    {
	printf( "dup: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }
}


void List_Test()
{
    List *list, *dup, *temp;
    int a;
    int *b;


    printf( "\n##### List Test #####\n" );


    printf( "New_List test\n" );
    a = 5;
    list = New_List( &a, sizeof( int ), NULL );
    if( !list ) 
    {
	printf( "failed to create List\n" );
	return;
    }
    printf( "start data: %i\n", *( int* )( list->data ) );


    printf( "\nLength_Of_List Test\n" );
    printf( "length: %i\n", ( int )( Length_Of_List( list ) ) );


    printf( "\nPrepend_To_List Test\n" );
    for( a = 4; a >= 0; a-- )
    {
	Prepend_To_List( &list, &a, sizeof( int ), NULL );
	printf( "prepended: %i\n", *( int* )( list->data ) );
    }


    printf( "\nEnd_Of_List Test\n" );
    temp = End_Of_List( list );
    printf( "end data: %i\n", *( int* )( temp->data ) );

   
    printf( "\nAppend_To_List Test\n" );
    for( a = 6; a <= 9; a++ )
    {
	Append_To_List( list, &a, sizeof( int ), NULL );
	temp = End_Of_List( list );
	printf( "appended: %i\n", *( int* )( temp->data ) );
    }


    printf( "\nInsert_Into_List Test\n" );
    a = 6;
    Insert_Into_List( &list, a, &a, sizeof( int ), NULL );
    a = 0;
    Insert_Into_List( &list, a, &a, sizeof( int ), NULL );
    a = 32;
    Insert_Into_List( &list, a, &a, sizeof( int ), NULL );

    printf( "\nFind_In_List Test\n" );
    b = &a;
    Insert_Into_List( &list, 5, b, 0, NULL );
    if( Find_In_List( list, b ) ) printf( "found it\n" );
    else printf( "didn't find it\n" ); 


    printf( "\nList Check\n" );
    temp = list;
    while( temp )
    {
	printf( "check: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }


    printf( "\nRemove_List_Segment and Free_List_Segment Tests\n" );
    temp = list->next->next;
    Remove_List_Segment( &list, temp );
    Remove_List_Segment( &list, list );


    printf( "\nRemove_From_List Test\n" );
    Remove_From_List( &list, b, FALSE );


    printf( "\nList Check\n" );
    temp = list;
    while( temp )
    {
	printf( "check: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }

 
    printf( "\nDuplicate_List Test\n" );
    dup = Duplicate_List( list );
    temp = dup;
    while( temp )
    {
	printf( "dup: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }
    

    printf( "\nFree_List Test\n" );
    b = NULL;
    Free_List( &list );
    Free_List( &dup );


    printf( "\nSuccess\n" );
}


void Bool_Test()
{
    Bool a, b, c, d, e;


    printf( "\n##### Bool Test #####\n" );


    a = TRUE;
    b = FALSE;
    c = 5;
    

    printf( "Bool_To_String Test\n" );
    printf( "a: %s\n", Bool_To_String( a ) );
    printf( "b: %s\n", Bool_To_String( b ) );
    printf( "c: %s\n", Bool_To_String( c ) );


    printf( "\nString_To_True Test\n" );
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


    printf( "\nString_To_False Test\n" );
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


    printf( "\nString_To_Bool Test\n" );
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
