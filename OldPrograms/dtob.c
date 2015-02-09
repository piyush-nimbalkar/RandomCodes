// Integer to Binary : C Program

#include <stdio.h>

void dtob(double number)
{
    int int_part, i = 0;
    int int_size, dec_size;
    int int_bits[32];
    int dec_bits[32];
    double dec_part;

    int_part = (int)number;
    dec_part = number - (double)int_part;

    while(int_part) {
        int_bits[i] = int_part % 2;
        i++;
        int_part /= 2;
    }
    int_size = i;

    i = 0;
    while(i < 32) {
        dec_part *= 2;
        if(dec_part >= 1) {
            dec_bits[i] = 1;
            dec_part -= 1;
        } else
            dec_bits[i] = 0;
        i++;
        if(dec_part == 0.0)
            break;
    }
    dec_size = i;

    for(i = int_size-1; i >= 0; i--)
        printf("%d", int_bits[i]);
    printf(".");
    for(i = 0; i < dec_size; i++)
        printf("%d", dec_bits[i]);
    printf("\n");
}

main()
{
    double number = 31.375;
    dtob(number);
    return 0;
}
