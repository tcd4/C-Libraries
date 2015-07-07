#include "dynamic_array.h"


DArray* New_DArray( CTypes type, uint32 length, void ( *Free )( dataptr data ) )
{
    RealArray *arr;

    Return_Val_If_Succ( length <= 0, NULL );
    Return_Val_If_Succ( ( ( type == NONE ) || ( type == VOID ) ), NULL );

    arr = C_New( RealArray, 1 );
    Return_Val_If_Fail( arr, NULL );

    memset( arr, 0, sizeof( RealArray ) );
    arr->type = type;
    arr->eltsize = Type_To_Size( type );
    arr->Free = Free;
    Return_Val_If_Fail( Resize_DArray( ( DArray* ) arr, length ), NULL );

    return ( DArray* ) arr;
}


Bool Resize_DArray( DArray *arr, uint32 length )
{
    RealArray *array = ( RealArray* ) arr;
    dataptr temp;
    
    Return_Val_If_Succ( length <= array->length, TRUE );
    
    temp = malloc(  array->eltsize * length );
    Return_Val_If_Fail( temp, FALSE );
    
    if( array->data ) memcpy( temp, array->data, array->eltsize * length );
    
    array->data = temp;
    array->length = length;
    array->alloc = array->eltsize * length;

    return TRUE;
}


/*eof*/
