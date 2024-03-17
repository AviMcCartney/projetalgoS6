/**
 * @file chainage_avant.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier chainage_avant.c contenant l'ensemble des procédures pour le chainage avant.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_avant.h"
#include "lecture.h"

/**
 * @brief Effectue un chaînage avant sur une liste de faits pour atteindre un but.
 *
 * Cette fonction lit un fichier de règles et utilise un algorithme de chaînage avant pour déterminer si un but peut être atteint à partir d'une liste de faits initiale. Le but est atteint si toutes les conséquences d'une règle qui a le but comme prémisse sont présentes dans la liste de faits.
 *
 * @param file Le nom du fichier contenant les règles à utiliser pour le chaînage avant.
 * @param liste_faits Un pointeur vers le premier élément de la liste de faits initiale.
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
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