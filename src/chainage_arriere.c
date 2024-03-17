#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_arriere.h"
#include "lecture.h"

int ChainageArriere(const char *file, Faits *liste_faits, char *but)
{
    FILE *fichier = ouvrir_fichier(file, "r");

    char ligne[100];
    int but_atteint = 0;
    while (fgets(ligne, sizeof(ligne), fichier))
    {
        char ligne_copie[100];
        strcpy(ligne_copie, ligne);
        char *premisses = strtok(ligne_copie, "->\n");
        char *consequences = strtok(NULL, "->\n");
        if (premisses == NULL || consequences == NULL)
        {
            printf("Ligne invalide: %s\n", ligne);
            continue;
        }
        if (strstr(consequences, but) != NULL) // permet de comaparer 2 char *
        {
            int toutes_prouvees = 1;
            char *caractere = strtok(premisses, "; \n");
            while (caractere != NULL)
            {
                if (!FaitPresent(liste_faits, caractere))
                {
                    if (!ChainageArriere(file, liste_faits, caractere))
                    {
                        toutes_prouvees = 0;
                        break;
                    }
                }
                caractere = strtok(NULL, "; \n");
            }
            if (toutes_prouvees)
            {
                but_atteint = 1;
                break;
            }
        }
    }

    fclose(fichier);

    if (but_atteint)
    {
        printf("Le but \"%s\" est atteint !\n", but);
        return 1;
    }
    else
    {
        printf("Le but \"%s\" n'est pas atteint\n", but);
        return 0;
    }
}