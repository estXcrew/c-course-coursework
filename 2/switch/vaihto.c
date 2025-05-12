#include "vaihto.h"
#include <stdio.h>
#include <stdint.h>

#ifdef LIVE
int main()
{
    int aa = 4;
    int ab = 44;
    int ac = 65;
    int ad = 98764;

    printf("aa = %d; ab = %d\n", aa, ab);
    vaihda(&aa, &ab);
    printf("aa = %d; ab = %d\n", aa, ab);

    printf("ac = %d; ad = %d\n", ac, ad);
    vaihda(&ac, &ad);
    printf("ac = %d; ad = %d\n", ac, ad);

    printf("aa = %d; ab = %d, ac=%d\n", aa, ab, ac);
    jarjesta(&aa, &ab, &ac);
    printf("aa = %d; ab = %d, ac=%d\n", aa, ab, ac);

    printf("ad = %d; ac = %d, aa=%d\n", ad, ac, aa);
    jarjesta(&ad, &ac, &aa);
    printf("ad = %d; ac = %d, aa=%d\n", ad, ac, aa);

    return 0;

}

#endif

/* put a to b, b to a*/
void vaihda(int *a, int *b)
{
    int intermediate;

    intermediate = *a;
    *a = *b;
    *b = intermediate;
    
    return;
}

void jarjesta(int *a, int *b, int *c)
{
    if(*a>*b) {
        vaihda(a, b);
    }

    if(*b>*c) {
        vaihda(b, c);
    }

    if(*a>*b) {
        vaihda(a, b);
    }
    
}
