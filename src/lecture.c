/**
 * @file Fichier lecture.c contenant l'ensemble des fonctions pour la lecture de fichier et de données .kbs
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"
#include "rule.h"
#include <string.h>
/**
 * @brief Lis toutes les données du fichier .kbs
 * @param fichier
 * @return char*
 */
char *lire_donnes_kbs(FILE *fichier)
{
    int taille = 1024;
    char *buffer = (char *)allouer_malloc(taille * sizeof(char));
    int index = 0;
    char c;
    while ((c = fgetc(fichier)) != EOF)
    {
        if (index >= taille)
        {
            taille *= 2;
            buffer = (char *)realloc(buffer, taille * sizeof(char));
            if (buffer == NULL)
            {
                fprintf(stderr, "Erreur de réallocation de mémoire\n");
                exit(EXIT_FAILURE);
            }
        }
        buffer[index++] = c;
    }
    buffer[index] = '\0';

    return buffer;
}

/**
 * @brief Ouvre un fichier.
 * @param chemin_fichier Le chemin vers le fichier à ouvrir.
 * @param option Les options d'ouverture du fichier (par exemple, "r" pour lire, "w" pour écrire).
 * @return Un pointeur vers le fichier ouvert.
 */
FILE *ouvrir_fichier(char *chemin_fichier, char *option)
{
    FILE *mon_fichier = fopen(chemin_fichier, option);

    if (mon_fichier == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", chemin_fichier);
        exit(EXIT_FAILURE);
    }
    return mon_fichier;
}

/**
 * @brief Compte le nombre de lignes dans un buffer.
 * @param buffer Le buffer à analyser.
 * @return Le nombre de lignes dans le buffer.
 */
int get_ligne(char *buffer)
{
    int cpt = 0;
    for (int i = 0; buffer[i]; i++)
    {
        cpt = buffer[i] == '\n' ? cpt + 1 : cpt;
    }
    return cpt;
}

/**
 * @brief Récupère une ligne spécifique d'un fichier.
 * @param file Le fichier à lire.
 * @param numeroLigne Le numéro de la ligne à récupérer.
 * @return Un pointeur vers la ligne récupérée.
 */
char *recupererLigne(FILE *file, int numeroLigne)
{
    char buffer[256];
    int numeroActuel = 0;

    while (numeroActuel < numeroLigne && fgets(buffer, sizeof(buffer), file) != NULL)
    {
        numeroActuel++;
    }

    if (numeroActuel == numeroLigne)
    {
        char *ligne = allouer_malloc(strlen(buffer) + 1);
        strcpy(ligne, buffer);
        return ligne;
    }
    else
    {
        printf("La ligne spécifiée n'existe pas dans le fichier\n");
        return NULL;
    }
}