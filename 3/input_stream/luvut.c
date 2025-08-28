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
    size_t buf_size = 2;
    size_t used_bufs = 0;
    double rdr = 0;

    size_t i;
    double sum = 0;
    double avg = 0;

    char temp_storage_iobuf[50];

    double* buf = malloc(sizeof(double)*buf_size);

    while(keep_running) {
        if(fgets(temp_storage_iobuf, sizeof(temp_storage_iobuf), stdin) != NULL){
            if (sscanf(temp_storage_iobuf, "%lf", &rdr) != 1) {
                keep_running = 0;
            }

            if(buf_size <= used_bufs){
                /*printf("realloc\r\n");*/
                buf_size *= 2;
                buf = realloc(buf, buf_size*sizeof(double));
            }

            *(buf+used_bufs) = rdr;
            /*printf("stored %f (rb = %f)\n", rdr, *(buf+used_bufs));*/

            if(keep_running) {
                used_bufs++;
            }
        }
    }
    
    printf("final realloc!\n");
    buf = realloc(buf, used_bufs*sizeof(double));

    printf("buf size: %ld\n", used_bufs*sizeof(double));

    qsort(buf, used_bufs, sizeof(double), comp_doubles);

    printf("Luettiin %d lukua: ", (int)used_bufs);
    
    for(i=0; i<used_bufs; i++) {
        printf("%.3f ",*(buf+i));
        sum += *(buf+i);
    }
    printf("\n");

    avg = sum / (double)used_bufs;

    printf("Summa: %.3f\n", sum);
    printf("Keskiarvo: %.3f\n", avg);

    free(buf);

    return 0;
}