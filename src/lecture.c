#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"

char *lire_donnes_kbs(FILE *fichier)
{
    char *buffer = (char *)allouer_malloc(sizeof(char));
    int index = 0;
    char c;
    while ((c = fgetc(fichier)) != EOF && c != '\n')
    {
        buffer[index++] = c;
    }
    buffer[index] = '\0';

    return buffer;
}