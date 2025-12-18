#include <stdio.h>
#include <stdlib.h>
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


    unsigned int n;
    printf("Entrer un nombre entier positif : ");
    scanf("%u", &n);
    if (is_prime(n) == 1 ){
        printf("Le nombre %u est premier\n", n);
    } else {
        printf("Le nombre %u n'est pas premier\n", n);
    }
    
    return EXIT_SUCCESS;
}