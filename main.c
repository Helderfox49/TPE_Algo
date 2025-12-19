#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bibliotheque.h"

int main(void) {

    printf("\n\n");

    printf("\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t+     Programme écris par : MBOTTO GUY ROBERT ULRICH     +\n");
    printf("\t\t+            Matricule : CM-UMa-25ENSPM0020              +\n");
    printf("\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    int choix;
    char continuer;

    do {
        // Affichage du menu
        printf("\n\t\t======================== MENU ========================\n");
        printf("\t\t1. Calcul de la puissance\n");
        printf("\t\t2. Calcul du factoriel\n");
        printf("\t\t3. Permutation des valeurs de deux nombres entiers\n");
        printf("\t\t4. Equation du second degré\n");
        printf("\t\t5. Nombre Premier\n");
        printf("\t\t6. Distance entre deux points\n");
        printf("\t\t0. ou Autre valeur pour Quitter");
        printf("\n\t\t======================================================\n");
        printf("\nVotre choix : ");
        
        if (scanf("%d", &choix) != 1) {
            empty_buffer();
            choix = 0;   // Force la sortie du nombre si l'utilisateur n'entre pas un nombre
        }

        switch (choix) {
            case 1: {
                unsigned int n, p;
                printf("Entrer un nombre entier : ");
                while(scanf("%u", &n) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }
                
                printf("Entrer la puissance : ");
                while(scanf("%u", &p) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }

                printf("La puissance de %u par %u vaut : %u\n",  n, p, power(n,p) );
                break;
            }

            case 2: {
                unsigned int n;
                printf("Entrer un nombre entier : ");
                while(scanf("%u", &n) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }

                printf("Le factoriel de %u est : %u\n",  n, fact(n) );
                break;
            }
            case 3: {
                int a, b;
                printf("Entrer la valeur de A : ");
                while(scanf("%u", &a) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }
                
                printf("Entrer la valeur de B : ");
                while(scanf("%u", &b) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }

                printf("Anciennes valeurs : A = %d, B = %d\n", a, b);
                swap(&a, &b);
                printf("Nouvelles valeurs : A = %d, B = %d\n",  a, b);

                break;
            } 
            case 4: {
                double a,b,c;
                printf("Entrer les valeurs des coefficients a b et c (separees par des espaces): ");
                while (scanf("%lf %lf %lf", &a, &b, &c) != 3){printf("Erreur. Trois valeurs reelles requises : "); empty_buffer();}
                
                resolve_equation(a, b, c);

                break;
            }
            case 5:{
                int n;
                printf("Entrer un nombre entier : ");
                while(scanf("%u", &n) != 1) { printf("Erreur. Entier requis : "); empty_buffer(); }

                if(is_prime(n)){
                    printf("Le nombre %d est premier\n", n );
                } else {
                    printf("Le nombre %d n'est pas premier\n", n ); 
                }

                break;
            }
            case 6:{
                double w,x,y,z;

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
                break;
            }
            default:
                printf("Merci d'avoir utilise le programme. A bientot !\n");
                return 0;
        }

        // --- Phase de confirmation ---
        printf("\nVoulez-vous continuer ? (O/N) : ");
        empty_buffer(); // Nettoie le tampon avant de lire un caractère
        scanf("%c", &continuer);

        if (continuer != 'O' && continuer != 'o') {
            printf("Merci d'avoir utilise le programme. A bientot !\n");
            choix = 0; // Casse la boucle do...while
        }

    } while (choix != 0);

    return 0;
}