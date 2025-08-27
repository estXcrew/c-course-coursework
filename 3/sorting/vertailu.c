#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "rectangle.h"

#ifdef LIVE
int main(int argc, char* argv[])
{

}

#endif

int rectAlaVrt(const void *a, const void *b)
{
    /* pointers go to rectangles */
    Rectangle **rectA = (Rectangle**)a;
    Rectangle **rectB = (Rectangle**)b;
    
    /* get areas of target triangles*/
    int areaA = getArea(*rectA);
    int areaB = getArea(*rectB);

    return areaA-areaB;
}

int rectXyVrt(const void *a, const void *b)
{
    /* pointers go to rectangles */
    const Rectangle *ra = *(const Rectangle * const *)a;
    const Rectangle *rb = *(const Rectangle * const *)b;

    if (ra->origin.x != rb->origin.x) {
        return ra->origin.x - rb->origin.x;  
    }
    return ra->origin.y - rb->origin.y; 
}

int rectLeveysVrt(const void *a, const void *b) {
    /* pointers go to rectangles */
    Rectangle **rectA = (Rectangle**)a;
    Rectangle **rectB = (Rectangle**)b;

    return (*rectB)->width - (*rectA)->width;

}
/*
int mjPitAakkosVrt(const void *a, const void *b) {
    char* arrA = (char*) a;
    char* arrB = (char*) b;

    int strlen_a = strlen(arrA);
    int strlen_b = strlen(arrB);

    if(strlen_a != strlen_b)
    {
        return strlen_b-strlen_a;
    }

    return strcmp(arrB, arrA);

}*/

int mjPitAakkosVrt(const void *a, const void *b) {
    const char *arrA = *(const char * const *)a;
    const char *arrB = *(const char * const *)b;

    int strlen_a = strlen(arrA);
    int strlen_b = strlen(arrB);
    
    if(strlen_a != strlen_b) {
        return strlen_b - strlen_a;
    }

    return strcmp(arrA, arrB);
}