#include "queue.h"


Queue* New_Queue( CTypes type, CloneNotify clone, FreeNotify destroy )
{
    Queue *new;

    new = C_New( Queue, 1 );
    Return_Val_If_Fail( new, NULL );

    memset( new, 0, sizeof( Queue ) );
    new->type = type;
    new->destroy = destroy;

    return new;
}


Bool Push_Queue( Queue *queue, dataptr data )
{
    Return_Val_If_Fail( queue, FALSE );

    if( queue->start )
    {
	Return_Val_If_Fail( Append_To_List( queue->start, data, queue->type, queue->clone, queue->destroy ), FALSE );
    }
    else
    {
	queue->start = New_List( data, queue->type, queue->clone, queue->destroy );
	Return_Val_If_Fail( queue->start, FALSE );
    }

    queue->length++;

    return TRUE;
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
    
    dup = New_Queue( queue->type, queue->clone, queue->destroy );
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
    Queue *temp;

    Return_If_Fail( queue );
    Return_If_Fail( *queue );

    temp = *queue;

    Free_List( &temp->start );
    free( temp );
    *queue = NULL;
}


/*eof*/
