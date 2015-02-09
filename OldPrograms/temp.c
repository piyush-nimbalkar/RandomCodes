#include <stdio.h>
#include <stdlib.h>


#define PRINT_ERROR_AND_FINISH() \
                      printf("function failed");\
                      goto done;
#define BOOL int
#define UINT32 int*
#define ERROR_SUCCESS 0

int Function1();
BOOL Function2(UINT32);


BOOL DoesSomething()
{
    BOOL status;
    UINT32 ptr;
    int err;

    ptr = (UINT32)malloc(1000);

    err = Function1();

    if ( err != ERROR_SUCCESS )
        PRINT_ERROR_AND_FINISH();
    else
        status = Function2(ptr);

    free((void*)ptr);

done:
    return status;
}

main ()
{}
