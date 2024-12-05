#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "geometria.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i;
    char *endptr;
    double radius;

    printf("Piin arvo: %.19Lf\n", PII);

    for(i=1; i<argc; i++)
    {
        radius = strtod(argv[i], &endptr);

/*        if (endptr == argv[i]) {
            printf("Error converting argument %Lf: '%s' is not a valid number.\n", i, argv[i]);
            return 1;
        }*/
    
        /*Säteen 1.500000 omaavan ympyrän ala ja pallon tilavuus: 7.0685834706 ja 14.1371669412*/
        printf("Säteen %.6f omaavan ympyrän ala ja pallon tilavuus: %.10f ja %.10f\n", 
                                            radius, ympyranAla(radius), pallonTilavuus(radius));

        printf("Säteen %.6f omaavan ympyrän piiri on %.10Lf\n", radius, 2*PII*radius);
    }
    return 0;
}