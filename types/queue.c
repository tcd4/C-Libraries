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



void Push_Queue( Queue *queue, dataptr data )
{
    Return_If_Fail( queue );

    if( queue->start )
    {
	Append_To_List( queue->start, data, queue->alloc, queue->Free );
    }
    else
    {
	queue->start = New_List( data, queue->alloc, queue->Free );
    }

    queue->length = Length_Of_List( queue->start );
}


dataptr Pop_Queue( Queue *queue )
{
    dataptr temp;

    Return_Val_If_Fail( queue, NULL );
    Return_Val_If_Fail( queue->start, NULL );

    temp = queue->start->data;
    Remove_From_List( &queue->start, temp, FALSE );

    queue->length--;

    return temp;
}


void Clear_Queue( Queue *queue )
{
    Return_If_Fail( queue );

    Free_List( &queue->start );
    queue->length = 0;
}


Bool Queue_Is_Empty( Queue *queue )
{
    Return_Val_If_Fail( queue, FALSE );
    Return_Val_If_Fail( queue->start, TRUE );
    return FALSE;
}


Queue* Duplicate_Queue( Queue *queue )
{
    Queue *dup;
    
    Return_Val_If_Fail( queue, NULL );
    
    dup = New_Queue( queue->alloc, queue->Free );
    Return_Val_If_Fail( dup, NULL );

    dup->length = queue->length;

    if( !queue->start ) dup->start = NULL;
    else 
    {
	dup->start = Duplicate_List( queue->start );
        if( !dup->start )
	{
	    Free_Queue( &dup );
	    return NULL;
	}
    }

    return dup;
}


void Free_Queue( Queue **queue )
{
}



/*eof*/
