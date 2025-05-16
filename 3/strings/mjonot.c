#include "mjonot.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef LIVE
int main() 
{
    char** copied_str;
    int i;
    int count;

    char* str[] = {"apple", "banana", "cherry"};

    count = sizeof(str) / sizeof(str[0]);

    printf("count = %d\n", count);

    copied_str = kopioi_mjt(str, count);

    for(i=0; i<count; i++){
        printf("%s -- %s\n", str[i], copied_str[i]);
    }


    return 0;
}
#endif

char** kopioi_mjt(char **mjt, size_t lkm)
{
    char** rv;
    unsigned int i;

    /* malloc charptr for each string */
    rv = (char **)malloc(sizeof(char *) * lkm);

    /*printf("rv char* malloc size = %ld\n", sizeof(char*)*lkm);*/

    if (!rv) { 
        printf("rv is NULL\n");

        return NULL;
    }

    for (i=0; i<lkm; i++) {
        /*printf("   %d\n", i);
         deep copy 
        printf("%s (len = %ld)\n", mjt[i], strlen(mjt[i]) + 1);
*/
        rv[i] = (char *) malloc((strlen(mjt[i]) + 1));
        
        if (rv[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for rv[%d]\n", i);
            return NULL;
        }

        strcpy(rv[i], mjt[i]);
        /*printf("rv[%d] = %s (address = %p)\n", i, rv[i], (void *)rv[i]);*/
    }

    return rv;
}