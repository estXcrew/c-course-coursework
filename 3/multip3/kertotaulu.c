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
    const uint e_y = 13;

    k = luoKertotaulu(s_x, e_x, s_y, e_y);

    dx = e_x-s_x+2;
    dy = e_y-s_y+2;

    printf("printing arr vals from main loop (dx = %d, dy = %d)..\n", dx, dy);

    for(i=0; i<dy; i++)
    {
        for(j=0; j<dx;j++)
        {
            printf("%7u", k->kertotaulu[i][j]);
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
    /* +1 for delta offset and +1 for standard edge ints */
    dim_cols = (krt->b) - (krt->a) +2; 
    dim_rows = (krt->d) - (krt->c) +2; 

    #ifdef LIVE 
        printf("Needed cols:%4d, rows:%4d\n\n", dim_cols, dim_rows);
    #endif

    /* pointer for pointer to the first item in each row*/
    krt->kertotaulu = (uint**) malloc(sizeof(uint*)*dim_rows);
    #ifdef LIVE     
     printf("Allocated %d bytes for %d rows \n", sizeof(uint**)*dim_rows, dim_rows);
    #endif
    /* allocate column in row indices --> count #rows, depth #cols */
    for(i=0; i<dim_rows; i++){
        krt->kertotaulu[i] = (uint*) malloc(sizeof(uint)*dim_cols);
        #ifdef LIVE     
         printf("Allocated %d bytes for %d columns \n", sizeof(uint*)*dim_cols, dim_cols);
        #endif
    }

    krt->kertotaulu[0][0] = 0;

    /* fill row edge; col0*/
    for(i=0; (i+1) < dim_rows; i++){
        krt->kertotaulu[i+1][0] = i+c;
    }

    /* fill col edge; row0*/
    for(i=0; (i+1) < dim_cols; i++){
        krt->kertotaulu[0][i+1] = i+a;
    }

    /* fill table center*/
    for(i=1; i<dim_rows; i++){
        for(j=1; j<dim_cols; j++)
        {
            krt->kertotaulu[i][j] = krt->kertotaulu[0][j] * krt->kertotaulu[i][0];
        }
    }

    return krt;
}

void tuhoaKertotaulu(Kertotaulu *kt)
{
    uint i;
    for(i=0; i < (kt->d - kt->c + 2); i++)
    {
        free(kt->kertotaulu[i]);
    }
    free(kt->kertotaulu);
    free(kt);
}
