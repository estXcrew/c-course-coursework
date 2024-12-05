#include "caesar.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

void caesarKoodaa(char mj[], char aakkosto[], char korvaavat[])
{
    int i;
    int in_len;
    int alphabet_len;
    int pos;

    char res[UCHAR_MAX + 1];

    in_len = strlen(mj) - 1;
    alphabet_len = strlen(aakkosto) - 1;

    pos = 0;

    while(pos <= in_len)
    {
        if(isspace(mj[pos])){
            res[pos] = mj[pos];
            pos++;
        }
        /* find pos of target in key alphabet */
        for(i=0; i<alphabet_len; i++)
        {
            if((aakkosto[i] == mj[pos]))
            {
                /*printf("%c\n", mj[pos]);
                printf("FOUND, %d\n\n", i);*/
                break;
            }
        }
        
        
        /*printf("replace %c with %c\r\n", mj[pos], korvaavat[i]);*/
        res[pos] = korvaavat[i];

        /*printf("incr\r\n");*/
        pos++;
    }

    printf("%s\n", res);
    
    strncpy(mj, res, in_len+1);
}
