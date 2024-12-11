#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
signed char, unsigned char, short int, unsigned short int ja int
 */

int main(int argc, char** argv)
{
    int printcomma;
    int i;
    int res;

    for(i=1; i<argc; i++)
    {
        printcomma = 0;

        res = atoi(argv[i]);
        printf("%d: ", res);


        if(res <= SCHAR_MAX && res >= SCHAR_MIN)
        {
            if(printcomma){
                printf(", ");
            } else {
                printcomma = 1;
            }

            printf("signed char");
        }

        if(res <= UCHAR_MAX && res >= 0)
        {
            if(printcomma){
                printf(", ");
            } else {
                printcomma = 1;
            }

            printf("unsigned char");
        }


        if(res <= SHRT_MAX && res >= SHRT_MIN)
        {
            if(printcomma){
                printf(", ");
            } else {
                printcomma = 1;
            }

            printf("short int");
        }

        if(res <= USHRT_MAX && res >= 0)
        {
            if(printcomma){
                printf(", ");
            } else {
                printcomma = 1;
            }

            printf("unsigned short int");
        }

        if(res <= INT_MAX && res >= INT_MIN)
        {
            if(printcomma){
                printf(", ");
            } else {
                printcomma = 1;
            }

            printf("int");
        }


        if(i+0 != argc){ 
            printf("\n");
        }
    }
    return 0;
}
