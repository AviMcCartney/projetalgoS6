#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_arriere.h"
#include "lecture.h"

int ChainageArriere(const char *file, Faits *liste_faits, char but)
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
        if (strchr(consequences, but) != NULL)
        {
            int toutes_prouvees = 1;
            for (int i = 0; i < strlen(premisses); i++)
            {
                char caractere = premisses[i];
                if (caractere == ';' || caractere == ' ' || caractere == '\n')
                    continue;
                if (!CaractereDansListe(liste_faits, caractere))
                {
                    if (!ChainageArriere(file, liste_faits, caractere))
                    {
                        toutes_prouvees = 0;
                        break;
                    }
                }
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
        printf("Le but \"%c\" est atteint !\n", but);
        return 1;
    }
    else
    {
        printf("Le but \"%c\" n'est pas atteint\n", but);
        return 0;
    }
}