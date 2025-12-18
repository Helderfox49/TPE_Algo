#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bibliotheque.h"


int main(void) {
    // int result = power( 2, 3 );
    // printf( "23 == %d\n", result );
    
    // result = fact( 6 );
    // printf( "6! == %d\n", result );

    double a, b, c;

    // printf("Enter les valeurs de a, b et c : ");
    // scanf("%lf %lf %lf", &a, &b, &c);

    // resolve_equation(a,b,c);

    /* Nombre premier */

    // int n;
    // printf("Entrer un nombre entier positif : ");
    // scanf("%d", &n);
    // if (is_prime(n)){
    //     printf("Le nombre %d est premier\n", n);
    // } else {
    //     printf("Le nombre %d n'est pas premier\n", n);
    // }

    double w,x,y,z;

    printf("Entrer les coordonnées du point A (séparées par des virgules) Ex 10,1 : ");
    scanf("%lf,%lf", &w, &x);

    printf("Entrer les coordonnées du point B (séparées par des virgules) Ex 2,4 : ");
    scanf("%lf,%lf", &y, &z);

    Point A = create_point(w,x);
    Point B = create_point(y,z);
    
    //Calcul de la distance AB
    double d = distance(&A, &B);

    printf("La distance AB entre les points \033[32mA(%.1f, %.1f)\033[0m et \033[32mB(%.1f, %.1f)\033[0m vaut \033[31m%.2f\033[0m. \n", A.x, A.y, B.x, B.y, d);
    return EXIT_SUCCESS;
}