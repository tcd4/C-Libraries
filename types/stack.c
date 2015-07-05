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

/*
void Push_Stack( Stack *stack, dataptr data )
{
}


dataptr Pop_Stack( Stack *stack )
{
}


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
