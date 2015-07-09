#include <stdio.h>
#include "debug.h"
#include "boolean.h"
#include "linked_list.h"
#include "doubly_linked_list.h"
#include "queue.h"
#include "stack.h"
#include "dynamic_array.h"


void Pick();
void Test_All();
void Test_Specific( char *subjects );

void Bool_Test();
void List_Test();
void DList_Test();
void Queue_Test();
void Stack_Test();
void DArray_Test();


int main( int argc, char *argv[] )
{
    Pick();

    return 0;
}


void Pick()
{
    char *input;

    input = C_New( char, 32 );

    printf( "Pick a Test: all, bool, list, dlist, queue, stack, darray ( quit )\n" );
    scanf( "%s", input );

    if( strcmp( input, "all" ) == 0 ) Test_All();
    else Test_Specific( input );
}


void Test_All()
{
    Bool_Test();
    List_Test();
    DList_Test();
    Queue_Test();
}


void Test_Specific( char *subject )
{
    if( strcmp( subject, "bool" ) == 0 ) Bool_Test();
    else if( strcmp( subject, "list" ) == 0 ) List_Test();
    else if( strcmp( subject, "dlist" ) == 0 ) DList_Test();
    else if( strcmp( subject, "queue" ) == 0 ) Queue_Test();
    else if( strcmp( subject, "stack" ) == 0 ) Stack_Test();
    else if( strcmp( subject, "darray" ) == 0 ) DArray_Test();
    else if( strcmp( subject, "quit" ) == 0 ) return;
    else printf( "You Suck\n" );

    Pick();
}


void DArray_Test()
{
    printf( "\n##### DArray Test #####\n" );
    

    printf( "\nSuccess\n" );
}


void Stack_Test()
{
    Stack *stack, *dup;
    int a;
    dataptr p;

    printf( "\n##### Stack Test #####\n" );


    printf( "\nNew_Stack Test\n" );
    stack = New_Stack( INT, NULL, NULL );
    if( !stack )
    {
	printf( "failure\n" );
	return;
    }

    printf( "\nIs_Stack_Empty Test\n" );
    printf( "is empty: %s\n", Bool_To_String( Is_Stack_Empty( stack ) ) );


    printf( "\nPush_Stack Test\n" );
    for( a = 0; a < 5; a++ )
    {
	Push_Stack( stack, &a );
    }


    printf( "\nDuplicate_Stack Test\n" );
    dup = Duplicate_Stack( stack );
    while( ( p = Pop_Stack( dup ) ) )
    {
	printf( "popped: %i\n", *( int* )( p ) );
    }


    printf( "\nIs_Stack_Empty Test\n" );
    printf( "is empty: %s\n", Bool_To_String( Is_Stack_Empty( stack ) ) );


    printf( "\nPop_Stack Test\n" );
    while( ( p = Pop_Stack( stack ) ) )
    {
	printf( "popped: %i\n", *( int* )( p ) );
    }


    printf( "\nClear_Stack Test\n" );
    for( a = 0; a < 5; a++ )
    {
	Push_Stack( stack, &a );
    }
    Clear_Stack( stack );
    printf( "stack cleared: %s\n", Bool_To_String( Is_Stack_Empty( stack ) ) );

   
    printf( "\nFree_Stack Test\n" );
    for( a = 0; a < 5; a++ )
    {
	Push_Stack( stack, &a );
    }
    Free_Stack( &stack );
    if( stack ) printf( "Failure\n" );


    printf( "\nSuccess\n" );
}


void Queue_Test()
{
    Queue *queue, *dup;
    int a;
    dataptr p;

    printf( "\n##### Queue Test #####\n" );


    printf( "\nNew_Queue Test\n" );
    queue = New_Queue( INT, NULL, NULL );
    if( !queue )
    {
	printf( "failure\n" );
	return;
    }

    printf( "\nQueue_Is_Empty Test\n" );
    printf( "is empty: %s\n", Bool_To_String( Queue_Is_Empty( queue ) ) );


    printf( "\nPush_Queue Test\n" );
    for( a = 0; a < 5; a++ )
    {
	Push_Queue( queue, &a );
    }


    printf( "\nDuplicate_Queue Test\n" );
    dup = Duplicate_Queue( queue );
    while( ( p = Pop_Queue( dup ) ) )
    {
	printf( "popped: %i\n", *( int* )( p ) );
    }

    printf( "\nQueue_Is_Empty Test\n" );
    printf( "is empty: %s\n", Bool_To_String( Queue_Is_Empty( queue ) ) );


    printf( "\nPop_Queue Test\n" );
    while( ( p = Pop_Queue( queue ) ) )
    {
	printf( "popped: %i\n", *( int* )( p ) );
    }


    printf( "\nClear_Queue Test\n" );
    for( a = 0; a < 5; a++ )
    {
	Push_Queue( queue, &a );
    }
    Clear_Queue( queue );
    printf( "queue cleared: %s\n", Bool_To_String( Queue_Is_Empty( queue ) ) );

    
    printf( "\nFree_Queue Test\n" );
    Free_Queue( &dup );
    for( a = 0; a < 5; a++ )
    {
	Push_Queue( queue, &a );
    }
    Free_Queue( &queue );
    if( queue ) printf( "Failure\n" );

    printf( "\nSuccess\n" );
}


void DList_Test()
{
    DList *list, *temp, *dup;
    int a;
    int *b;


    printf( "\n##### DList Test #####\n" );


    printf( "New_DList test\n" );
    a = 5;
    list = New_DList( &a, INT, NULL, NULL );
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
	Prepend_To_DList( &list, &a, INT, NULL, NULL );
	printf( "prepended: %i\n", *( int* )( list->data ) );
    }


    printf( "\nEnd_Of_DList Test\n" );
    temp = End_Of_DList( list );
    printf( "end data: %i\n", *( int* )( temp->data ) );

   
    printf( "\nAppend_To_DList Test\n" );
    for( a = 6; a <= 9; a++ )
    {
	Append_To_DList( list, &a, INT, NULL, NULL );
	temp = End_Of_DList( list );
	printf( "appended: %i\n", *( int* )( temp->data ) );
    }


    printf( "\nDList Check\n" );
    temp = list;
    while( temp )
    {
	printf( "check: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }


    printf( "\nInsert_Into_DList Test\n" );
    a = 6;
    Insert_Into_DList( &list, a, &a, INT, NULL, NULL );
    a = 0;
    Insert_Into_DList( &list, a, &a, INT, NULL, NULL );
    a = 32;
    Insert_Into_DList( &list, a, &a, INT, NULL, NULL );


    printf( "\nDList Check\n" );
    temp = list;
    while( temp )
    {
	printf( "check: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }


    printf( "\nFind_In_DList Test\n" );
    b = &a;
    Prepend_To_DList( &list, b, CUSTOM, NULL, NULL );
    if( Find_In_DList( list, b ) ) printf( "found it\n" );
    else printf( "didn't find it\n" ); 


    printf( "\nDList Check\n" );
    temp = list;
    while( temp )
    {
	printf( "check: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }


    printf( "\nRemove_From_DList Test\n" );
    Remove_From_DList( &list, b, FALSE );


    printf( "\nRemove_DList_Segment and Free_DList_Segment Tests\n" );
    temp = list->next->next;
    Remove_DList_Segment( &list, temp );
    Remove_DList_Segment( &list, list );


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


    printf( "\nFree_DList Test\n" );
    Free_DList( &list );
    Free_DList( &dup );


    printf( "\nSuccess\n" );
}


void List_Test()
{
    List *list, *temp, *dup;
    int a;
    int *b;


    printf( "\n##### List Test #####\n" );


    printf( "New_List test\n" );
    a = 5;
    list = New_List( &a, INT, NULL, NULL );
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
	Prepend_To_List( &list, &a, INT, NULL, NULL );
	printf( "prepended: %i\n", *( int* )( list->data ) );
    }


    printf( "\nEnd_Of_List Test\n" );
    temp = End_Of_List( list );
    printf( "end data: %i\n", *( int* )( temp->data ) );

   
    printf( "\nAppend_To_List Test\n" );
    for( a = 6; a <= 9; a++ )
    {
	Append_To_List( list, &a, INT, NULL, NULL );
	temp = End_Of_List( list );
	printf( "appended: %i\n", *( int* )( temp->data ) );
    }

    printf( "\nList Check\n" );
    temp = list;
    while( temp )
    {
	printf( "check: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }


    printf( "\nInsert_Into_List Test\n" );
    a = 6;
    Insert_Into_List( &list, a, &a, INT, NULL, NULL );
    a = 0;
    Insert_Into_List( &list, a, &a, INT, NULL, NULL );
    a = 32;
    Insert_Into_List( &list, a, &a, INT, NULL, NULL );


    printf( "\nFind_In_List Test\n" );
    b = &a;
    Prepend_To_List( &list, b, CUSTOM, NULL, NULL );
    if( Find_In_List( list, b ) ) printf( "found it\n" );
    else printf( "didn't find it\n" ); 


    printf( "\nList Check\n" );
    temp = list;
    while( temp )
    {
	printf( "check: %i\n", *( int* )( temp->data ) );
	temp = temp->next;
    }


    printf( "\nRemove_From_List Test\n" );
    Remove_From_List( &list, b, FALSE );


    printf( "\nRemove_List_Segment and Free_List_Segment Tests\n" );
    temp = list->next->next;
    Remove_List_Segment( &list, temp );
    Remove_List_Segment( &list, list );


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
