#include <stdio.h>

int main(int argc, char *argv[])
{
    int q = 10;
    int *p;
    printf ("%p %p\n", &q, p);
    /* *p = 10; */

    /* printf ("%d\n", *p); */
    return 0;
}
