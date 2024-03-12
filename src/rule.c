#include "rule.h"

void construct_rule(FILE *chemin_fichier)
{
    char *buffer = lire_donnes_kbs(chemin_fichier);
    int i;
    while (i < sizeof(buffer))
    {
        while (buffer[i] != ';')
        {
        }
    }
}