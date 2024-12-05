#include <stdio.h>
#include <string.h>
#include "anagrammit.h"


int main(int argc, char* argv[]){

    printf("anagrams, exp \"1, 0, 0\"\r\n");
    printf("output: %d, %d, %d", 
        anagrammeja("abcd", "bcad"), 
        anagrammeja("bcaa", "abcd"),
        anagrammeja("abc",  "abba")
    );
    return 0;
}