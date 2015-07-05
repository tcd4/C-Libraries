#include "stack.h"


Stack* New_Stack( size_t size, void ( *Free )( dataptr data ) )
{
    Stack *new;

    new = C_New( Stack, 1 );
    Return_Val_If_Fail( new, NULL );

    new->start = NULL;
    new->end = NULL;
    new->length = 0;
    new->alloc = size;
    new->Free = Free;

    return new;
}


void Push_Stack( Stack *stack, dataptr data )
{
    Return_If_Fail( stack );


    if( stack->start )
    {
	Append_To_List( stack->start, data, stack->alloc, stack->Free );
    }
    else
    {
	stack->start = New_List( data, stack->alloc, stack->Free );
    }

    stack->end = End_Of_List( stack->start );
    stack->length = Length_Of_List( stack->start );
}


dataptr Pop_Stack( Stack *stack )
{
    dataptr temp;

    Return_Val_If_Fail( stack, NULL );
    Return_Val_If_Fail( stack->end, NULL );

    temp = stack->end->data;
    Remove_From_List( &stack->start, temp, FALSE );

    stack->length--;

    return temp;
}

/*
void Clear_Stack( Stack *stack )
{
}


Bool Is_Stack_Empty( Stack *stack )
{
}


Stack* Duplicate_Stack( Stack *stack )
{
}


void Free_Stack( Stack **stack )
{
}
*/
/*eof*/
