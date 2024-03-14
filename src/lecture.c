#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"
#include "rule.h"
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

int get_ligne(char *buffer)
{
    int cpt = 0;
    for (int i = 0; buffer[i]; i++)
    {
        cpt = buffer[i] == '\n' ? cpt + 1 : cpt;
        printf("%c%s", buffer[i], buffer[i] == '\n' ? "true" : "");
    }
    return cpt;
}