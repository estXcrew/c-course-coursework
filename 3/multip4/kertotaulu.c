#include "kertotaulu.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int count_digits(unsigned int n) 
{
    int digits = 0;
    do {
        digits++;
        n /= 10;
    } while (n > 0);
    return digits+2;
}

char **luo_kertotaulu_mjt(uint a, uint b, uint c, uint d)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    uint col_widest_val;
    uint32_t i, j;
    const uint32_t NR_COLS = b-a + 2;
    const uint32_t NR_ROWS = d-c + 2;
    uint32_t line_width = 1u; 
    uint table_idx;
    uint snprint_retval = 0;
    char* chartable;
    uint** row_table;

    uint* cols_w = (uint*) malloc(sizeof(uint)*NR_COLS);

    cols_w[0] = count_digits(d);
    for(j=1; j<=NR_COLS; j++)
    {
        col_widest_val = (uint)(d*(a+j-1));
        cols_w[j] = count_digits(col_widest_val);
        line_width += cols_w[j];
        printf("width of widest val %d: %d\n", col_widest_val, cols_w[j]);
    }

    printf("line width %d!\r\n", line_width);
    printf("nr of lines: %d \r\n", NR_ROWS);
    printf("allocating buffer of %d bytes.. \r\n", NR_ROWS*line_width*sizeof(char) + 1);

    /* allocate table of row charpointers*/
    row_table = (char**)malloc(NR_ROWS*sizeof(char*));
    //chartable = (char*)malloc(NR_ROWS*line_width*sizeof(char) + 1);

    

    table_idx = 0;
    snprint_retval = sprintf(chartable + table_idx, "%*s", cols_w[0], "");
    table_idx += snprint_retval;

    for(j=a; j<=b; j++)
    {
        col_widest_val = j;
        printf("printing %d @ %d\r\n", col_widest_val, table_idx);
        snprint_retval = sprintf(chartable + table_idx, "%*d", cols_w[j], col_widest_val);
        table_idx += snprint_retval;
    }

    sprintf(chartable + table_idx, "\n");
    table_idx++;

    for(i=c; i<=d; i++)
    {
        col_widest_val = i;
        snprint_retval = sprintf(chartable + table_idx, "%*d", cols_w[0], col_widest_val);
        table_idx += snprint_retval;
        
        for(j=a; j<=b; j++)
        {
            col_widest_val = i*j;
            printf("printing %d @ %d\r\n", col_widest_val, table_idx);
            snprint_retval = sprintf(chartable + table_idx, "%*d", cols_w[j], col_widest_val);
            table_idx += snprint_retval;
        }

        sprintf(chartable + table_idx, "\n");
        table_idx++;

        printf("ended col at width %u..\r\n", table_idx);
    }

    free(cols_w);

    printf("%s\n", chartable);

    printf("returning ..\r\n");
    fflush(stdout);
    return &chartable;
}
