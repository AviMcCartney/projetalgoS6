/**
 * @file menu.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier menu.c contenant la procédure pour créer le menu.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Affiche un menu à l'utilisateur et récupère son choix.
 *
 * Cette fonction affiche un menu avec différentes options à l'utilisateur, puis lit son choix à partir de l'entrée standard.
 *
 * @return int Retourne le choix de l'utilisateur sous forme d'un entier.
 */
int menu()
{
    int nb = -1;
    printf("\n(0) Quitter\n");
    printf("(1) Chainage avant\n");
    printf("(2) Chainage arrière\n");
    printf("Votre choix: ");
    scanf("%d", &nb);
    printf("\n");
    return nb;
}