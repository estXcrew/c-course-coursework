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
    return digits;
}
char **luo_kertotaulu_mjt(uint a, uint b, uint c, uint d)
{
    uint col_widest_val;
    uint32_t i, j;
    const uint32_t NR_COLS = (b - a + 1) + 1; /* include header */
    const uint32_t NR_ROWS = (d - c + 1) + 1; /* include header */
    uint32_t line_width = 0; 
    char **row_table;
    char *p;

    uint *cols_w = (uint *)malloc(sizeof(uint) * NR_COLS);

    cols_w[0] = count_digits(d); /* width of row header */
    for (j = 1; j < NR_COLS; j++) {
        col_widest_val = (uint)(d * (a + j - 1));
        cols_w[j] = count_digits(col_widest_val) +1;
        line_width += cols_w[j];
    }
    line_width += cols_w[0];

    /* allocate table of row char-pointers */
    row_table = (char **)malloc(NR_ROWS * sizeof(char *));
    for (i = 0; i < NR_ROWS; i++) {
        row_table[i] = malloc(sizeof(char) * (line_width + 1)); /* +1 for '\0' */
    }

    /* top header row */
    p = row_table[0];
    p += sprintf(p, "%*s", cols_w[0], "");
    for (j = a; j <= b; j++) {
        p += sprintf(p, "%*u", cols_w[j - a + 1], (uint)j);
    }
    *p = '\0';

    /* data rows */
    for (i = c; i <= d; i++) {
        char *q = row_table[i - c + 1];
        q += sprintf(q, "%*u", cols_w[0], (uint)i);
        for (j = a; j <= b; j++) {
            q += sprintf(q, "%*u", cols_w[j - a + 1], (uint)(i * j));
        }
        *q = '\0';
    }

    free(cols_w);
    return row_table;
}
