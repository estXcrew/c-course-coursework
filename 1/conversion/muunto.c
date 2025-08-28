#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "muunto.h"

void muunna(char mj[])
{
    int start;
    int end;

    char sc;
    char ec;

    start = 0;
    end = strlen(mj) - 1; /* ignore \0 */

    while(start <= end){
        sc = mj[start];
        ec = mj[end];

        if(isupper(sc)){
            sc = tolower(sc);
        } else {
            sc = toupper(sc);
        }

        if(isupper(ec)){
            ec = tolower(ec);
        } else {
            ec = toupper(ec);
        }

        mj[start] = ec;
        mj[end] = sc;

        start++;
        end--;
    }
}
