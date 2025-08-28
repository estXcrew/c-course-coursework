#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int comp_doubles(const void *a, const void *b)
{
    double da = *(double*)a;
    double db = *(double*)b;
    return da>db;
}

int main(void)
{
    int keep_running = 1;
    size_t koko = 2;  
    size_t used_bufs = 0;
    double rdr = 0;
    size_t i;
    double sum = 0;
    double avg = 0;
    double* buf = malloc(sizeof(double)*koko);
    
    while(keep_running) {
        if(scanf("%lf", &rdr) != 1) {
            keep_running = 0;
        }
        else {
            if(koko <= used_bufs){
                /*printf("realloc\r\n");*/
                koko *= 2;
                buf = realloc(buf, koko*sizeof(double));
            }
            *(buf+used_bufs) = rdr;
            /*printf("stored %f (rb = %f)\n", rdr, *(buf+used_bufs));*/
            used_bufs++;
        }
    }
    
    buf = realloc(buf, used_bufs*sizeof(double));

    qsort(buf, used_bufs, sizeof(double), comp_doubles);

    printf("Luettiin %d lukua: ", (int)used_bufs);

    for(i=0; i<used_bufs-1; i++) {
        printf("%.3f ",*(buf+i));
        sum += *(buf+i);
    }

    printf("%.3f",*(buf+(used_bufs-1)));
    sum += *(buf+(used_bufs-1));


    printf("\n");
    avg = sum / (double)used_bufs;

    printf("Summa: %.3f\n", sum);
    printf("Keskiarvo: %.3f\n", avg);

    free(buf);
    return 0;
}