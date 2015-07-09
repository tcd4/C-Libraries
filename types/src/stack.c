#include "stack.h"
#include "debug.h"

Stack* New_Stack( CTypes type, CloneNotify clone, FreeNotify destroy  )
{
    Stack *new;

    new = C_New( Stack, 1 );
    Return_Val_If_Fail( new, NULL );

    memset( new, 0, sizeof( Stack ) );
    new->type = type;
    new->destroy = destroy;

    return new;
}


Bool Push_Stack( Stack *stack, dataptr data )
{
    Return_Val_If_Fail( stack, FALSE );


    if( stack->start )
    {
	Return_Val_If_Fail( Append_To_List( stack->start, data, stack->type, stack->clone, stack->destroy ), 
			    FALSE );
    }
    else
    {
	stack->start = New_List( data, stack->type, stack->clone, stack->destroy );
	Return_Val_If_Fail( stack->start, FALSE );
    }

    stack->end = End_Of_List( stack->start );
    stack->length++;

    return TRUE;
}


dataptr Pop_Stack( Stack *stack )
{
    dataptr temp;

    Return_Val_If_Fail( stack, NULL );
    Return_Val_If_Fail( stack->end, NULL );

    temp = stack->end->data;
    Remove_From_List( &stack->start, temp, FALSE );
    
    stack->end = End_Of_List( stack->start );
    stack->length--;

    return temp;
}


void Clear_Stack( Stack *stack )
{
    Return_If_Fail( stack );

    Free_List( &stack->start );
    stack->end = NULL;
    stack->length = 0;
}


Bool Is_Stack_Empty( Stack *stack )
{
    Return_Val_If_Fail( stack, FALSE );
    Return_Val_If_Fail( stack->start, TRUE );
    return FALSE;
}


Stack* Duplicate_Stack( Stack *stack )
{
    Stack *dup;

    Return_Val_If_Fail( stack, NULL );

    dup = New_Stack( stack->type, stack->clone, stack->destroy );
    Return_Val_If_Fail( dup, NULL );

    if( !stack->start ) dup->start = NULL;
    else
    {
	dup->start = Duplicate_List( stack->start );
	if( !dup->start )
	{
	    Free_Stack( &dup );
	    return NULL;
	}
    }

    dup->length = stack->length;
    dup->end = End_Of_List( dup->start );

    return dup;
}


void Free_Stack( Stack **stack )
{
    Stack *temp;

    Return_If_Fail( stack );
    Return_If_Fail( *stack );

    temp = *stack;

    Free_List( &temp->start );
    free( temp );
    *stack = NULL;
}


/*eof*/
