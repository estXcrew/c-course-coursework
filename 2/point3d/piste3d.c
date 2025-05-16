#include "piste3d.h"
#include <math.h>
#include <stdio.h>
#ifdef LIVE

int main(){
    return 0;

}

#endif

double etaisyys(Piste3D p1, Piste3D p2)
{
    double inter;
    inter = d_sq(p1.x, p2.x) + d_sq(p1.y, p2.y) + d_sq(p1.z, p2.z);
    return sqrt(inter);
}

void tulosta(Piste3D p1, int tarkkuus)
{
    printf("(%.*f, %.*f, %.*f)", tarkkuus, p1.x, tarkkuus, p1.y, tarkkuus, p1.z);
}

double d_sq(double v1, double v2)
{
    return (v1*v1) - (2*v1*v2) + (v2*v2);
}