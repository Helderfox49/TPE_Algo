#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bibliotheque.h"

#define ROUGE  "\033[31m"
#define VERT   "\033[32m"
#define RESET  "\033[0m"


int main(void) {
    int choix;

    do {
        // Affichage du menu
        printf("\n================ MENU ================\n");
        printf("1. Calcul de la puissance d'un nombre\n");
        printf("2. Calcul du factoriel d'un nombre\n");
        printf("3. Permutation des valeurs de 2 variables\n");
        printf("4. Résolution d'une équation du second degré\n");
        printf("5. Déterminer si un nombre est premier\n");
        printf("6. Calculer la distance entre deux points\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide.\n");
            exit(EXIT_FAILURE);
        }

        // Traitement du choix de l'utilisateur
        switch (choix) {
            case 1: {
                unsigned int n, p, r;
                printf("Entrer un nombre entier : ");
                scanf("%u", &n);
                printf("Entrer la puissance : ");
                scanf("%u", &p);
                r = power(n,p);

                printf("La puissance de %s%u%s par %s%u%s vaut : %s%u%s\n", VERT, n, RESET, VERT, p, RESET, ROUGE, r, RESET  );
                break;
            }

            case 2: {
                unsigned int m, f;
                printf("Entrer un nombre entier : ");
                scanf("%u", &m);

                f = fact(m);
                printf("Le factoriel de %s%u%s est : %s%u%s\n", VERT, m, RESET, ROUGE, f, RESET);
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
                printf("Entrer les valeurs de a b et c (séparées par des espaces): ");
                scanf("%lf %lf %lf", &a, &b, &c);
                resolve_equation(a, b, c);

                break;
            }
            case 5:{
                int n;
                printf("Entrer un nombre entier : ");
                scanf("%d", &n);
                if(is_prime(n)){
                    printf("Le nombre %s%d%s est %spremier%s\n", VERT, n, RESET, ROUGE, RESET);
                } else {
                    printf("Le nombre %s%d%s est %sn'est pas premier%s\n", VERT, n, RESET, ROUGE, RESET); 
                }
                break;
            }
            case 6:{
                double w,x,y,z;

                printf("Entrer les coordonnées du point A (séparées par des virgules) Exemple : 10,1 : ");
                scanf("%lf , %lf", &w, &x);

                printf("Entrer les coordonnées du point B (séparées par des virgules) Exemple : 2,4 : ");
                scanf("%lf , %lf", &y, &z);

                Point A = create_point(w,x);
                Point B = create_point(y,z);
                
                //Calcul de la distance AB
                double d = distance(&A, &B);

                printf("La distance AB entre les points \033[32mA(%.1lf, %.1lf)\033[0m ", A.x, A.y);
                printf("et \033[32mB(%.1lf, %.1lf)\033[0m ", B.x, B.y);
                printf("vaut \033[31m%.2lf\033[0m. \n", d);
                break;
            }
            case 0:
                printf("Merci d'avoir utilisé le programme. À bientôt !\n");
                break;
                
            default:
                printf("Choix invalide. Veuillez entrer un numéro valide.\n");
        }
    } while (choix != 0);

    return 0;
}