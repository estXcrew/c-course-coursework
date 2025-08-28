#include <stdio.h>
#include <stdint.h>

int max2D(int **t2d, int kork, int lev) {
    int max = t2d[0][0];

    int i = 0;
    int j = 0;

    outer_loop:

        if(i>=kork) goto end;
        j=0;

        inner_loop:
            if(j>=lev) goto next_row;
            if(t2d[i][j] > max) goto set_new_val;
            j++;

            goto inner_loop;

        next_row:
            i++;
            goto outer_loop;

        set_new_val:
            max=t2d[i][j];
            j++;
            goto inner_loop; 
    
    end: 
        return max;
}

#ifdef LIVE
int main(void) {

    int max = 0;

    int r1[3] = {3,2,1};
    int r2[3] = {4,5,600};
    int r3[3] = {8,9,7};

    int* cols[3] = {r1, r2, r3};
    
    max = max2D(cols, 3, 3);

    printf("%d\n", max);
    
    return 0;
}
#endif