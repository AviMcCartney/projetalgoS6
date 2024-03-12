#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"

char *lire_donnes_kbs(FILE *fichier)
{
    int taille = 1024;
    char *buffer = (char *)malloc(taille * sizeof(char));
    if (buffer == NULL)
    {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

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