#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "kertotaulu.h"

#ifdef LIVE

int main () {

}

#endif

Kertotaulu* luoKertotaulu(uint a, uint b, uint c, uint d)
{
    Kertotaulu* krt;
    uint** table;

    size_t dim_x;
    size_t dim_y;

    size_t tbl_size;

    unsigned int i;
    unsigned int j;

    if(a > b || c > d)
    {
        return NULL;
    }

    /* allocate multiplication table struct */
    krt = (Kertotaulu*) malloc(sizeof(Kertotaulu));
    krt->a = a;
    krt->b = b;
    krt->c = c;
    krt->d = d;

    /* allocate table itself */
    dim_x = (krt->b) - (krt->a) + 1; /*# rows*/
    dim_y = (krt->d) - (krt->c) + 1; /*# cols*/
    /* allocate row pointers */
    krt->kertotaulu = (uint**)malloc(sizeof(uint)*dim_x);
    /* allocate short 1d column memory for each row*/
    for(int i=0; i<dim_x; i++)
    {
        krt->kertotaulu[i] = (uint*)malloc(sizeof(uint)*dim_y);
    }

    /* now we can access the regular 2d row-major array: kertotaulu[row][col]*/
    krt->kertotaulu[0] = 0;
    /* row 0, col a+1 - b*/
    for(i=0; i<(b-1); i++)
    {
        krt->kertotaulu[i+1] = i+a;
    }

    /* row n+1 - m, col 0*/
    for(i=0; i<(d-1); i++)
    {
        krt->kertotaulu[i+1][0] = i+c;
    }

    /* calculate values*/
    for(i=1; i<dim_x; i++)
    {
        for(j=1; j<dim_y; )
    }


    return krt;
}

