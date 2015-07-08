#include <stdio.h>
#include "stdmacros.h"
#include "stdtypes.h"
#include "stdfuncs.h"
#include "stdmath.h"


void Macros_Test();
void Funcs_Test();


int main( int argc, char *argv[] )
{
    Macros_Test();
    Funcs_Test();

    return 0;
}


void Macros_Test()
{
    printf( "\n#### Macros Test ####\n" );
}


void Funcs_Test()
{
    printf( "\n#### Funcs Test ####\n" );
}
