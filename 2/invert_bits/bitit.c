#include "bitit.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>


int main() {
    signed char chr = 5;
    short int shrtint = 30;
    int rglrint = 200;
    long int longint = 10000;

    kaannaScharBitit(&chr);
    kaannaShortBitit(&shrtint);
    kaannaIntBitit(&rglrint);
    kaannaLongBitit(&longint);

    return 0;
}

void kaannaScharBitit(signed char *x)
{
    int i;
    signed char res = 0;


    for(i = 0; i<(int)(sizeof(signed char)*8U); i++)
    {
        res = res << 1UL;
        res |= (*x & 1U);
        *x = *x >> 1UL;
    }

    *x = res;
}

void kaannaShortBitit(short *x)
{
    int i;
    short int res = 0;

    for(i = 0; i<(int)(sizeof(short unsigned int)*8U); i++)
    {
        res = res << 1UL;
        res |= (*x & 1U);
        *x = *x >> 1UL;
    }

    *x = res;
}


void kaannaIntBitit(int *x)
{
    int i;
    unsigned int res = 0;

    for(i = 0; i<(int)(sizeof(unsigned int)*8U); i++)
    {
        res = res << 1UL;
        res |= (*x & 1U);
        *x = *x >> 1UL;
    }

    *x = res;
}

void kaannaLongBitit(long *x)
{
    int i;
    long unsigned int res = 0;


    for(i = 0; i<(int)(sizeof(long unsigned int)*8U); i++)
    {
        res = res << 1UL;
        res |= (*x & 1U);
        *x = *x >> 1UL;
    }

    *x = res;
}

