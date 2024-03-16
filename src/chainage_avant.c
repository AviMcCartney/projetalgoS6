#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_avant.h"
#include "lecture.h"

Faits *ChainageAvant(const char *file, Faits *liste_faits)
{
    FILE *fichier = ouvrir_fichier(file, "r");

    char ligne[100];
    int ajout = 1;

    char but[100];
    printf("Saisir le but à atteindre: ");
    scanf("%s", but);

    while (ajout)
    {
        ajout = 0;
        fseek(fichier, 0, SEEK_SET);
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
            int toutes_presentes = 1;
            for (int i = 0; i < strlen(premisses); i++)
            {
                char caractere = premisses[i];
                if (!CaractereDansListe(liste_faits, caractere) && caractere != ' ')
                {
                    toutes_presentes = 0;
                    break;
                }
            }
            if (toutes_presentes)
            {
                for (int i = 0; i < strlen(consequences); i++)
                {
                    char caractere = consequences[i];
                    if (caractere == ';' || caractere == ' ')
                        continue;
                    if (!CaractereDansListe(liste_faits, caractere))
                    {
                        liste_faits = AjouterCaractereSiAbsent(liste_faits, caractere);
                        ajout = 1;
                    }
                }
            }
        }
    }
    if (FaitPresent(liste_faits, but))
        printf("Le but \"%s\" est atteint !\n", but);
    else
        printf("Le but \"%s\" n'est pas atteint\n", but);
    fclose(fichier);
    return liste_faits;
}