#include "geometria.h"

const long double PII = 3.1415926535897932385L;

double ympyranAla(double sade)
{
    return (double)PII*sade*sade;
}

double pallonTilavuus(double sade)
{
    /*4/3 pi r^3 */
    return (double)((4*PII*sade*sade*sade)/3);
}