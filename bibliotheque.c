#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "bibliotheque.h"

#define ROUGE  "\033[31m"
#define VERT   "\033[32m"
#define RESET  "\033[0m"


// Fonction de calcul du factoriel d'un nombre.
unsigned int fact( unsigned int value ) {
    unsigned int result = 1;
    while ( value > 1 ) {
        result *= value;
        value --;
    }
    return result;
}


// Fonction d'élévation à une puissance données.
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


// Fonction pour résoudre une équation équation du second degré
void resolve_equation(double a, double b, double c) {
    if (a == 0.0) {
        printf(ROUGE "Le coefficient a doit être non nul\n" RESET);
        exit(0);
    }

    double delta = b*b-4*a*c;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Deux solutions réelles distinctes : %s x1 = %.2f, x2 = %.2f %s\n", VERT, x1, x2, RESET);
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("Une solution réelle unique : %s x = %.2f %s\n", VERT, x, RESET);
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
    double dx = B->x-A->x;
    double dy = B->y-A->y;

    return sqrt(dx*dx + dy+dy);
}


// Fontion qui permute la valeur de 02 entiers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction  utilitaire pour vider le buffer
void empty_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}