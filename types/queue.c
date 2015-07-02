#include "queue.h"


Queue* New_Queue( size_t size, void ( *Free )( dataptr data ) )
{
    Queue *new;

    new = C_New( Queue, 1 );
    Return_Val_If_Fail( new, NULL );

    new->start = NULL;
    new->length = 0;
    new->alloc = size;
    new->Free = Free;

    return new;
}


/*
void Push_Queue( Queue *queue, dataptr data )
{
}


dataptr Pop_Queue( Queue *queue )
{
}


void Clear_Queue( Queue *queue )
{
}


Bool Queue_Is_Empty( Queue *queue )
{
}


Queue* Duplicate_Queue( Queue *queue )
{
}


void Free_Queue( Queue **queue )
{
}
*/


/*eof*/
