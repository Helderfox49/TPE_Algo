#include <stdio.h>
#include <math.h>
#include "bibliotheque.h"

// Définition d'une fonction de calcul de factorielle.
unsigned int fact( unsigned int value ) {
    unsigned int result = 1;
    while ( value > 1 ) {
        result *= value;
        value --;
    }
    return result;
}

// Définition d'une fonction d'élévation à une puissance données.
int power( int value, unsigned int pow ) {
    if ( pow == 0 ) return 1;
    if ( pow == 1 ) return value;
    int accumulator = 1;
        while( pow > 0 ) {
            accumulator *= value;
            pow--;
    }
    return accumulator;
}

// Fonction pour résoudre l'équation du second degré
void resolve_equation(double a, double b, double c) {
    double delta = b*b-4*a*c;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("L'équation a deux solutions réelles distinctes : x1 = %.2f et x2 = %.2f\n", x1, x2);
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("L'équation a une solution réelle unique : x = %.2f\n", x);
    } else if (delta < 0) {
        printf("Pas de solutions réelles\n");
    } else {
        printf("Le coefficient a doit être non nul\n");
    }
}

// Fonction qui détermine si un nombre entier est premier ou non
int is_prime(unsigned int n)
{
    int i;
    if (n <= 1)
        return 0;

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
} 