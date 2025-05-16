#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#ifdef LIVE

int main() {
    return 0;
}

#endif

Rectangle *createRectangle(void)
{
    struct Point* p;
    struct Rectangle* r;

    p = (struct Point*) malloc(sizeof(struct Point));
    p -> x = 0;
    p -> y = 0;

    r = (struct Rectangle*) malloc(sizeof(struct Rectangle));
    r->height = 0;
    r->width = 0;
    r->origin = *p;

    return r;
}

Rectangle *createRectangle2(Point p)
{
    struct Rectangle* r;

    r = (struct Rectangle*) malloc(sizeof(struct Rectangle));

    r->height = 0;
    r->width = 0;
    r->origin = p;

    return r;
}

Rectangle *createRectangle3(int w, int h)
{
    struct Point* p;
    struct Rectangle* r;

    p = (struct Point*) malloc(sizeof(struct Point));
    r = (struct Rectangle*) malloc(sizeof(struct Rectangle));

    r->height = h;
    r->width = w;
    r->origin = *p;

    return r;
}

Rectangle *createRectangle4(Point p, int w, int h)
{
    struct Rectangle* r = (struct Rectangle*) malloc(sizeof(struct Rectangle));

    r->origin = p;
    r->height = h;
    r->width = w;

    return r;
}

void move(Rectangle *r, int x, int y)
{
    r ->origin.x = x;
    r ->origin.y = y;
}

int getArea(const Rectangle *r)
{
    return (r->height)*(r->width);
}
