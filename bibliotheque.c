#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "bibliotheque.h"

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
        printf("Le coefficient a doit être non nul\n");
        exit(0);
    }

    double delta = b*b-4*a*c;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Deux solutions reelles distinctes : x1 = %.2f, x2 = %.2f\n", x1, x2);
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("Une solution reelle unique : x = %.2f\n", x);
    } else if (delta < 0) {
        printf("Pas de solutions reelles\n");
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

//Fonction du menu pour le calcul de la puissance
void menu_puissance(void){
    unsigned int n, p;
    char reponse;

    do{
        printf("Entrer un nombre entier : ");
        while(scanf("%u", &n) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }
        
        printf("Entrer la puissance : ");
        while(scanf("%u", &p) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }

        printf("La puissance de %u par %u vaut : %u\n",  n, p, power(n,p) );

        printf("Voulez vous continuez (O/N) avec cette fonction : ");
        empty_buffer();
        scanf("%c", &reponse);
    }while (reponse == 'O' || reponse == 'o');    
}

//Fonction du menu pour le calcul du factoriel
void menu_factoriel(void){
    unsigned int n;
    char reponse; 

    do{
        printf("Entrer un nombre entier : ");
        while(scanf("%u", &n) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }

        printf("Le factoriel de %u est : %u\n",  n, fact(n) );

        printf("Voulez vous continuez (O/N) avec cette fonction : ");
        empty_buffer();
        scanf("%c", &reponse);
    }while (reponse == 'O' || reponse == 'o'); 

}


//Fonction du menu pour la permutation de 02 nombres entiers
void menu_permutation(void){
    int a, b;
    char reponse;

    do{
        printf("Entrer la valeur de A : ");
        while(scanf("%u", &a) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }
        
        printf("Entrer la valeur de B : ");
        while(scanf("%u", &b) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }

        printf("Anciennes valeurs : A = %d, B = %d\n", a, b);
        swap(&a, &b);
        printf("Nouvelles valeurs : A = %d, B = %d\n",  a, b);

        printf("Voulez vous continuez (O/N) avec cette fonction : ");
        empty_buffer();
        scanf("%c", &reponse);   
    }while(reponse == 'O' || reponse == 'o');
}


//Fonction du menu pour la résolution d'une équation du second dégré
void menu_resolution(void){
    double a,b,c;
    char reponse;

    do{
        printf("Entrer les valeurs des coefficients a b et c (separees par des espaces): ");
        while (scanf("%lf %lf %lf", &a, &b, &c) != 3){printf("Erreur. Trois valeurs reelles requises : "); empty_buffer();}
        
        resolve_equation(a, b, c);   

        printf("Voulez vous continuez (O/N) avec cette fonction : ");
        empty_buffer();
        scanf("%c", &reponse);   
    }while(reponse == 'O' || reponse == 'o');
}


//Fonction du menu déterminer si un nombre est premier ou pas
void menu_premier(void){
    int n;
    char reponse;

    do{       
        printf("Entrer un nombre entier : ");
        while(scanf("%u", &n) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }

        if(is_prime(n)){
            printf("Le nombre %d est premier\n", n );
        } else {
            printf("Le nombre %d n'est pas premier\n", n ); 
        }

        printf("Voulez vous continuez (O/N) avec cette fonction : ");
        empty_buffer();
        scanf("%c", &reponse);   
    }while(reponse == 'O' || reponse == 'o');

}


//Fonction du menu pour le calcul de la distance entre 02 points
void menu_distance(void){
    double w,x,y,z;
    char reponse;

    do {
        printf("Entrer les coordonnees du point A (separees par des virgules) Exemple 10,1 : ");
        scanf("%lf , %lf", &w, &x);

        printf("Entrer les coordonnees du point B (separees par des virgules) Exemple  2,4 : ");
        scanf("%lf , %lf", &y, &z);

        Point A = create_point(w,x);
        Point B = create_point(y,z);
        
        //Calcul de la distance AB
        double d = distance(&A, &B);

        printf("La distance AB entre les points A(%.1lf, %.1lf) ", A.x, A.y);
        printf("et B(%.1lf, %.1lf) ", B.x, B.y);
        printf("vaut %.2lf. \n", d);

        printf("Voulez vous continuez (O/N) avec cette fonction : ");
        empty_buffer();
        scanf("%c", &reponse);   
    }while(reponse == 'O' || reponse == 'o');
    
}
