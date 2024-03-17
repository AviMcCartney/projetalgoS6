/**
 * @file lecture.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier lecture.c contenant l'ensemble des fonctions pour la lecture de fichier et de données .kbs
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include <string.h>

/**
 * @brief Ouvre un fichier.
 * @param chemin_fichier Le chemin vers le fichier à ouvrir.
 * @param option Les options d'ouverture du fichier (par exemple, "r" pour lire, "w" pour écrire).
 * @return Un pointeur vers le fichier ouvert.
 */
FILE *ouvrir_fichier(const char *chemin_fichier, char *option)
{
    FILE *mon_fichier = fopen(chemin_fichier, option);

    if (mon_fichier == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", chemin_fichier);
        exit(EXIT_FAILURE);
    }
    return mon_fichier;
}