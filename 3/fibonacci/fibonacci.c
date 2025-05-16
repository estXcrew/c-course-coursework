#include "fibonacci.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#ifdef LIVE
int main() 
{
    unsigned int *fibonacci = fib_jono(15); /* 15 ensimmäistä fibonaccin lukua. */
    int i = 0;
    for(i = 0; i < 15; ++i)
    {
        printf(" %u", fibonacci[i]);
    }
    printf("\n");
    free(fibonacci); /* Dynaamisesti varatun muistin vapautus. */
    return 0;
}
#endif

unsigned int *fib_jono(unsigned int depth)
{
    unsigned int i;
    unsigned int* start;

    i=0;

    start = (unsigned int*)malloc(sizeof(unsigned int)*depth);

    /* depth is at least 2 */

    *(start) = 0;

    if(depth <= 1){
        return start;
    }

    *(start+1) = 1;

    for(i=2; i<depth; i++){
        *(start+i) =  *(start+(i-1)) + *(start+(i-2));
    }
    return start;
}
