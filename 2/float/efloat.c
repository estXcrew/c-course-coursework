#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) 
{
    int i;

    double output_sum = 0;
    double decimal_part = 1.000000;
    long int exponent = -127;

    printf("Exponent: %ld\n", exponent);

    char *binaryString = argv[1];

    /* ASSUMPTION: 32b wide input
    / figure out exponent
    / offset 8. weird indexing in calculation loop because char interpretation endianness is bizarre for floats..
    */
    for(i=1; i<=8; i++){
       // printf("ch:%c\n", binaryString[i]);
        exponent += (binaryString[i] == '1' ? pow(2, 8-i) : 0);
    }

    printf("Exponent: %ld\n", exponent);

    /* mantissa, 22-0 idx bits*/s



    return 0;
}

