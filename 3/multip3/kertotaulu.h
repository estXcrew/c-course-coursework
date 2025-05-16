#ifndef __MULTIP3_H__
#define __MULTIP3_H__

typedef unsigned int uint;

/* ab dim l->r, cd dim top->down */
typedef struct {
    uint a;
    uint b;
    uint c;
    uint d;

    uint** kertotaulu;
} Kertotaulu;

Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d);

#endif
