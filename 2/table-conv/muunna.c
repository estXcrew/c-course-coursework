#include "muunna.h"
#include <stdint.h>
#include <stdio.h>

#ifdef LIVE

int main() 
{
    int i;
    double arr[10] = {1.1, 2.2, 3.1, 4.1, 5.1, 6.3, 7.3, 8.3, 9.3, 0.3};
    for(i=0; i<10; i++){
        printf("%-8.3f ", arr[i]);
    }

    muunnaTaulu(10, arr, triple);

    printf("\n\n");

    for(i=0; i<10; i++){
        printf("%-8.3f", arr[i]);
    }

    printf("\n\n");


    return 0;
}

#endif

void muunnaTaulu(unsigned int koko, double *taulu, double muunnos(double))
{
    unsigned int i;
    for(i=0; i<koko; i++)
    {
        taulu[i] = muunnos(taulu[i]);
    }
}

double triple(double in)
{
    return 3*in;  
}