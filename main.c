#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bibliotheque.h"

#define ROUGE  "\033[31m"
#define VERT   "\033[32m"
#define RESET  "\033[0m"


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
        printf("\t\t4. Équation du second degré\n");
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
                scanf("%u", &n);
                printf("Entrer la puissance : ");
                scanf("%u", &p);

                printf("La puissance de %s%u%s par %s%u%s vaut : %s%u%s\n", VERT, n, RESET, VERT, p, RESET, VERT, power(n,p), RESET  );
                break;
            }

            case 2: {
                unsigned int n;
                printf("Entrer un nombre entier : ");
                scanf("%u", &n);
                printf("Le factoriel de %s%u%s est : %s%u%s\n", VERT, n, RESET, VERT, fact(n), RESET);
                break;
            }
            case 3: {
                int a, b;
                printf("Entrer la valeur de A : ");
                scanf("%d", &a);
                printf("Entrer la valeur de B : ");
                scanf("%d", &b);

                printf("Anciennes valeurs : A = %d, B = %d\n", a, b);
                swap(&a, &b);
                printf("Nouvelles valeurs : %sA = %d, B = %d%s\n", VERT, a, b, RESET);
                break;
            } 
            case 4: {
                double a,b,c;
                printf("Entrer les valeurs des coefficients a b et c (séparées par des espaces): ");
                scanf("%lf %lf %lf", &a, &b, &c);
                resolve_equation(a, b, c);

                break;
            }
            case 5:{
                int n;
                printf("Entrer un nombre entier : ");
                scanf("%d", &n);
                if(is_prime(n)){
                    printf("Le nombre %d est %spremier%s\n", n, VERT, RESET);
                } else {
                    printf("Le nombre %d %sn'est pas premier%s\n", n, VERT, RESET); 
                }
                break;
            }
            case 6:{
                double w,x,y,z;

                printf("Entrer les coordonnées du point A (séparées par des virgules) Exemple 10,1 : ");
                scanf("%lf , %lf", &w, &x);

                printf("Entrer les coordonnées du point B (séparées par des virgules) Exemple  2,4 : ");
                scanf("%lf , %lf", &y, &z);

                Point A = create_point(w,x);
                Point B = create_point(y,z);
                
                //Calcul de la distance AB
                double d = distance(&A, &B);

                printf("La distance AB entre les points \033[32mA(%.1lf, %.1lf)\033[0m ", A.x, A.y);
                printf("et \033[32mB(%.1lf, %.1lf)\033[0m ", B.x, B.y);
                printf("vaut \033[32m%.2lf\033[0m. \n", d);
                break;
            }
            default:
                printf("Merci d'avoir utilisé le programme. À bientôt !\n");
                return 0;
        }

        // --- Phase de confirmation ---
        printf("\nVoulez-vous continuer ? (O/N) : ");
        empty_buffer(); // Nettoie le tampon avant de lire un caractère
        scanf("%c", &continuer);

        if (continuer != 'O' && continuer != 'o') {
            printf("Merci d'avoir utilisé le programme. À bientôt !\n");
            choix = 0; // Casse la boucle do...while
        }

    } while (choix != 0);

    return 0;
}