#include "caesar.h"
#include <stdio.h>

/*int main(int argc, char* argv[])
{
    char* input = "OHJELMOINNIN TEKNIIKKA\0";
    caesarKoodaa(input, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "OIUGENYMSWXVALPKHBQCZDFJRT");
    printf("%s\n", input);

    return 0;
}*/

int main()
{
    char text[50] = "Hello World!";
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char replacement[] = "bcdefghijklmnopqrstuvwxyzaBCDEFGHIJKLMNOPQRSTUVWXYZA";

    caesarKoodaa(text, alphabet, replacement);

    printf("Encoded: %s\n", text);

    return 0;
}
