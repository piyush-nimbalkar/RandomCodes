#include <stdio.h>

int foo(int a)
{
    printf ("Hello Foo\n");
    return 0;
}

int foo()
{
    printf ("Hello Bar\n");
}


int main(int argc, char *argv[])
{
    foo(1);
    foo();
    return 0;
}
