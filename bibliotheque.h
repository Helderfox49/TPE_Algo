#ifndef __MY_MATH_LIB_H
#define __MY_MATH_LIB_H

unsigned int fact( unsigned int value );
int power(int value, unsigned int pow);
void resolve_equation(double a, double b, double c);
int is_prime(int n);

typedef struct {
    double x;
    double y;
} Point;

Point create_point(double x, double y);
double distance(const Point *A, const Point *B);
void swap(int *a, int *b);
void empty_buffer(void);

//Fonctions d'interfaces pour le menu
void menu_puissance(void);
void menu_factoriel(void);
void menu_permutation(void);
void menu_resolution(void);
void menu_premier(void);
void menu_distance(void);

#endif