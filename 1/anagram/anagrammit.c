#include "anagrammit.h"
#include <stdio.h>
#include <string.h>



int anagrammeja(char mj1[], char mj2[])
{
    int i;
    size_t strlengths;
    char current_char;  /* current iterated char             */
    int str1_charcnt;   /* store # of 'current_char' in str1 */
    int str2_charcnt;   /* store # of 'current_char' in str2 */

    strlengths = strlen(mj1);
    
    /* prevent over-indexing, otherwise below for-loop would cover this case */
    if(strlengths != strlen(mj2)) {
        return 0;
    }

    for(i=0; i<(int)strlengths; i++)
    {
        current_char = mj1[i];

        /* iterate through mj1 */
        str1_charcnt = chars_in_str(mj1, strlengths, current_char);

        /* iterate through mj2 */
        str2_charcnt = chars_in_str(mj2, strlengths, current_char);

        if(str1_charcnt != str2_charcnt)
        {
            return 0;
        }
    }

    return 1;
}

int chars_in_str(char mj[], int charcnt, char target_char)
{
    int i;
    int target_count;

    target_count = 0;

    for(i=0; i<charcnt; i++)
    {
        if(mj[i] == target_char)
        {
            target_count++;
        }
    }

    return target_count;
}
