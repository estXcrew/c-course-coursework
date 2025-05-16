#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "kertotaulu.h"

#ifdef LIVE

int main () {

    Kertotaulu* k;
    int i, j;
    int dx, dy;

    const uint s_x = 2;
    const uint e_x = 9;
    const uint s_y = 11;
    const uint e_y = 17;

    k = luoKertotaulu(s_x, e_x, s_y, e_y);

    dx = e_x-s_x;
    dy = e_y-s_y;

    printf("printing arr vals from main loop (dx = %d, dy = %d)..\n", dx, dy);

    for(i=0; i<dx; i++)
    {
        for(j=0; j<dy;j++)
        {
            printf("%12u", k->kertotaulu[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}

#endif

Kertotaulu* luoKertotaulu(uint a, uint b, uint c, uint d)
{
    Kertotaulu* krt;

    size_t dim_rows;
    size_t dim_cols;
    uint temp_val;

    unsigned int i;
    unsigned int j;


    if(a > b || c > d)
    {
        return NULL;
    }

    krt = (Kertotaulu*) malloc(sizeof(Kertotaulu));
    krt->a = a;
    krt->b = b;
    krt->c = c;
    krt->d = d;

    /* allocate table itself */
    dim_cols = (krt->b) - (krt->a) + 2; 
    dim_rows = (krt->d) - (krt->c) + 2; 

    /* allocate row pointers */
    /*[row][col]*/
    krt->kertotaulu = (uint**)malloc(sizeof(uint**)*dim_rows);
    /* allocate short 1d column memory for each row*/
    for(i=0; i<dim_cols; i++)
    {
        krt->kertotaulu[i] = (uint*)malloc(sizeof(uint*)*dim_cols);
    }

    /* now we can access the regular 2d row-major array: kertotaulu[row][col]*/
    krt->kertotaulu[0][0] = 0;
    /* first row, cols 1-d*/
    for(i=0; i<(dim_rows-1); i++)
    {
        krt->kertotaulu[0][i+1] = i+a;
    }
    /* row n+1 - m, col 0*/
    for(i=0; i<(dim_cols-1); i++)
    {
        krt->kertotaulu[i+1][0] = i+c;
    }

    /* calculate values*/
    for(i=1; i<dim_rows; i++)
    {
        for(j=1; j<dim_cols;j++)
        {
            temp_val = krt->kertotaulu[0][j] * krt->kertotaulu[i][0];
            krt->kertotaulu[i][j] = temp_val;
        }
    }


    return krt;
}

void tuhoaKertotaulu(Kertotaulu *kt)
{
    int i;
    for(i=0; i<(kt->b-kt->a)+2; i++)
    {
        free(kt->kertotaulu[i]);
    }
    free(kt->kertotaulu);
    free(kt);
}
