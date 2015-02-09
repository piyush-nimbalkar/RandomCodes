#include <stdio.h>

int main()
{
    int N = 41;
    int i, j, spaces;

    for (i = 1; i <= N; i += 2) {
        for (spaces = N - i; spaces > 0; spaces -= 2)
            printf("  ");
        for (j = 0; j < i; j++)
            printf("* ");
        printf("\n");
    }

    for (i = N - 2; i > 0; i -= 2) {
        for (spaces = N - i; spaces > 0; spaces -= 2)
            printf("  ");
        for (j = 0; j < i; j++)
            printf("* ");
        printf("\n");
    }

    return 0;
}
