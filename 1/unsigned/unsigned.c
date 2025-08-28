#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "unsigned.h"

/*Eli ensin tulostetaan arvo -sade = MAX - sade + 1, sitten -sade + askel = MAX - sade + 1 + askel,
     sitten -sade + 2*askel = MAX - sade + 1 + 2*askel, ja niin edelleen, kunnes intervallin loppuraja sade ylitetään. */

void ucharIntervalli(unsigned char sade, unsigned char askel){
    unsigned char value;

    value = -sade;

    /*printf("started on %lu (MAX = %lu)", value, UCHAR_MAX);*/

    printf("unsigned char: ");
    printf("%u", value);

    while(value != sade)
    {
        value += askel;

        if(value <=2UL*(unsigned long)sade) {
            printf(" %u", value);
        } else {
            break;
        }
    }
    /*printf("broke on %lu", value);*/
    printf("\n");
}


void ushortIntervalli(unsigned short sade, unsigned short askel){
    unsigned short value;

    value = -sade;

    /*printf("started on %lu (MAX = %lu)", value, UCHAR_MAX);*/

    printf("unsigned short: ");
    printf("%u", value);

    while(value != sade)
    {
        value += askel;

        if(value <= 2UL*(unsigned long)sade) {
            printf(" %u", value);
        } else {
            break;
        }
    }
    /*printf("broke on %lu", value);*/
    printf("\n");
}

void uintIntervalli(unsigned int sade, unsigned int askel){
    unsigned int value;

    value = -sade;

    /*printf("started on %lu (MAX = %lu)", value, UCHAR_MAX);*/

    printf("unsigned int: ");
    printf("%u", value);

    while(value != sade)
    {
        value += askel;

        if(value <= (2UL*(unsigned long)sade)) {
            printf(" %u", value);
        } else {
            break;
        }
    }
    /*printf("broke on %lu", value);*/
    printf("\n");
}

void ulongIntervalli(unsigned long sade, unsigned long askel){
    unsigned long value;

    value = -sade;

    /*printf("started on %lu (MAX = %lu)", value, UCHAR_MAX);*/

    printf("unsigned long: ");
    printf("%lu", value);

    while(value != sade)
    {
        value += askel;

        if(value <= (2UL*(unsigned long)sade)) {
            printf(" %lu", value);
        } else {
            break;
        }
    }
    /*printf("broke on %lu", value);*/
    printf("\n");
}


int main(){

    ucharIntervalli(150, 50);
    ushortIntervalli(45000, 15000);
    uintIntervalli(3300000000, 1100000000);
    ulongIntervalli(9000000000000000000, 3000000000000000000);


    ucharIntervalli(40, 75);
    ushortIntervalli(65535, 65535); 
    uintIntervalli(400000, 750000);
    ulongIntervalli(400000000, 1500000000);

    return 0;
}