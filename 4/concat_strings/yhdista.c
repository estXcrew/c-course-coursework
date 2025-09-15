#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yhdista.h"
#include <stdarg.h>

char* yhdista(const char *mj, ...){
    va_list variadics;
    int new_len;
    int extension_len;
    /* holds current iteration of new string*/
    char* new_string;
    /* temp variable to hold pointer of previous new string in the loop for strcpy*/
    char* new_string_r;

    char* ch;

    new_len = 1; /* \0 */
    new_len += strlen(mj);
    
    /* copy old mj to new allocated containers / variables */
    new_string = (char*) malloc(new_len * sizeof(char));
    strcpy(new_string, mj);

    va_start(variadics, mj);
    /* this contains 'new item' to be concatenated each iteration*/
    ch = va_arg(variadics, char*);

    /* new string is not empty at this point; memory ops not a problem */
    while (ch != NULL) {
        extension_len = strlen(ch);
        new_len += extension_len;
        new_string_r = new_string;
        /* allocate new string size */
        new_string = (char*) malloc(new_len);
        /* copy old string to new malloc'd region, free old pointer */
        strcpy(new_string, new_string_r);
        free(new_string_r);
        /* copy new bit to the end of malloc'd region */
        strcpy(new_string+(new_len-extension_len-1), ch);
        /* prepare next arg for next iter*/
        ch = va_arg(variadics, char*);
    }

    va_end(variadics);

    return new_string;
    
}

int main(int argc, char *argv[])
{
  int i = 0;
  char *mj = malloc(1);
  mj[0] = '\0';  /* Alussa vain tyhjä merkkijono. */
  for(i = 1; (i+3) <= argc; i += 3)
  { /* Yhdistetään aina 3 seuraavaa mj:n perään. */
    char *tmp = mj;
    mj = yhdista(tmp, argv[i], argv[i+1], argv[i+2], NULL);
    free(tmp); /* Vapautetaan edellinen mj. */
  }
  if((i+2) == argc) /* Jäikö vielä 2 liittämättä? */
  {
    char *tmp = mj;
    mj = yhdista(mj, argv[i], argv[i+1], NULL);
    free(tmp);
  }
  else if((i+1) == argc) /* Jäikö vielä 1 liittämättä? */
  {
    char *tmp = mj;
    mj = yhdista(mj, argv[i], NULL);
    free(tmp);
  }
  printf("Parametrien liitos: %s (pituus: %lu)\n", mj, (unsigned long) strlen(mj));
  free(mj);
  return 0;
}