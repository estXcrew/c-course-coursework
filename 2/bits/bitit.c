#include "bitit.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>

int main() {
    scharBitit(5);
    shortBitit(5);
    intBitit(5);
    longBitit(5);

    return 0;
}

void scharBitit(signed char x)
{
    char binary[9]; 
    int count_ones = 0, count_zeros = 0, i = 0;

    sprintf(binary, BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));

    for (i = 0; i < 8; i++) {
        if (binary[i] == '1') {
            count_ones++;
        } else if (binary[i] == '0') {
            count_zeros++;
        }
    }

    printf("%d\n", x);
    printf("%s\n", binary);
    printf("%d\n", count_zeros);
    printf("%d\n", count_ones);}

void shortBitit(short int x)
{

    char binary[17]; 
    int count_ones = 0, count_zeros = 0, i = 0;

    sprintf(binary, BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x >> 8), BYTE_TO_BINARY(x));

    for (i = 0; i < 16; i++) {
        if (binary[i] == '1') {
            count_ones++;
        } else if (binary[i] == '0') {
            count_zeros++;
        }
    }

    printf("%d\n", x);
    printf("%s\n", binary);
    printf("%d\n", count_zeros);
    printf("%d\n", count_ones);
}

void intBitit(int x)
{
    char binary[33]; 
    int count_ones = 0, count_zeros = 0, i = 0;

    sprintf(binary, BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x >> 24), BYTE_TO_BINARY(x >> 16), BYTE_TO_BINARY(x >> 8), BYTE_TO_BINARY(x >> 0));

    for (i = 0; i < 32; i++) {
        if (binary[i] == '1') {
            count_ones++;
        } else if (binary[i] == '0') {
            count_zeros++;
        }
    }

    printf("%d\n", x);
    printf("%s\n", binary);
    printf("%d\n", count_zeros);
    printf("%d\n", count_ones);
}

void longBitit(long int x)
{
    char binary[65]; 
    int count_ones = 0, count_zeros = 0, i = 0;

    sprintf(binary, BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x >> 56), BYTE_TO_BINARY(x >> 48),BYTE_TO_BINARY(x >> 40), BYTE_TO_BINARY(x >> 32), BYTE_TO_BINARY(x >> 24), BYTE_TO_BINARY(x >> 16), BYTE_TO_BINARY(x >> 8), BYTE_TO_BINARY(x >> 0));

    for (i = 0; i < 64; i++) {
        if (binary[i] == '1') {
            count_ones++;
        } else if (binary[i] == '0') {
            count_zeros++;
        }
    }

    printf("%ld\n", x);
    printf("%s\n", binary);
    printf("%d\n", count_zeros);
    printf("%d\n", count_ones);
}

