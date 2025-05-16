#ifndef __PISTE3D_H__
#define __PISTE3D_H__


typedef struct
{
    double x;
    double y;
    double z;
} Piste3D ;

double d_sq(double v1, double v2);
double etaisyys(Piste3D p1, Piste3D p2);
void tulosta(Piste3D p1, int tarkkuus);

#endif
