#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
    if (a == 0.0) {
        printf("Le coefficient a doit être non nul\n");
        exit(0);
    }

    double delta = b*b-4*a*c;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("L'équation a deux solutions réelles distinctes : x1 = \033[31m%.2f\033[0m et x2 = \033[31m%.2f\033[0m\n", x1, x2);
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("L'équation a une solution réelle unique : x = \033[31m%.2f\033[0m\n", x);
    } else if (delta < 0) {
        printf("Pas de solutions réelles\n");
    }
}

// Fonction qui détermine si un nombre entier est premier ou non
int is_prime( int n)
{
    int i;
    if (n <= 1)return 0;

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
} 

//Fonction qui crée un nouveau point
Point create_point(double x, double y){
    Point P;
    P.x=x;
    P.y=y;
    return P;
}


//fonction qui calcule la distance entre 02 points
double distance(const Point *A, const Point *B){
    if (A == NULL || B == NULL) {
        fprintf(stderr, "Erreur: pointeur NULL dans la fonction distance\n");
        return -1.0;
    }

    double dx = B->x-A->x;
    double dy = B->y-A->y;

    return sqrt(dx*dx + dy+dy);
}


