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
            case 1:menu_puissance(); break;
            case 2: menu_factoriel(); break;
            case 3:menu_permutation(); break;
            case 4: menu_resolution(); break;
            case 5:menu_premier(); break;
            case 6:menu_distance(); break;
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