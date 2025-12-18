#ifndef __MY_MATH_LIB_H
#define __MY_MATH_LIB_H


// Définition de la fonction de calcul du factoriel.
unsigned int fact( unsigned int value );

// Défintion de la fonction de calcul de la puissance.
int power(int value, unsigned int pow);

//Définition d'une fonction qui résoud une équation du 2nd dégré
void resolve_equation(double a, double b, double c);

// Définition d'une fonction qui détermine si un nombre entier est premier
int is_prime(int n);

//Définition de la structure Point
typedef struct {
    double x;
    double y;
} Point;

//Défintion d'une fonction qui crèe un nouveau point
Point create_point(double x, double y);

//Définition d'une fonction qui calcule la distance entre 02 points
double distance(const Point *A, const Point *B);


#endif