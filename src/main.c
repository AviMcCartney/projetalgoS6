#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lecture.h"
#include "rule.h"

int main()
{
    FILE *fichier;
    fichier = ouvrir_fichier("test.kbs", "r");
    int cpt = 0;
    char *buffer = lire_donnes_kbs(fichier);
    for (int i = 0; buffer[i]; i++)
    {
        cpt = buffer[i] == '\n' ? cpt + 1 : cpt;
    }

    int test = get_ligne(buffer);
    printf("FIchier lu \n%d\n", test);

    // char *test = get_ligne(fichier);
    // printf("FIchier lu \n%s\n", test);
    // char *test2 = get_ligne(fichier);
    // printf("FIchier lu \n%s\n", test2);

    fclose(fichier);

    return 0;
}