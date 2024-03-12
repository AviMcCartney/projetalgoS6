#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"

int main()
{
    FILE *fichier;
    fichier = fopen("test.kbs", "r");

    if (fichier == NULL)
    {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");
        return EXIT_FAILURE;
    }

    char *header = lire_donnes_kbs(fichier);
    printf("FIchier lu %s\n", header);

    free(header);
    fclose(fichier);

    return EXIT_SUCCESS;
}