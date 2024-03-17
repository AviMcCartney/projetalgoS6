/**
 * @file chainage_arriere.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier chainage_arriere.c contenant l'ensemble des procédures pour le chainage arrière.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_arriere.h"
#include "lecture.h"

/**
 * @brief Effectue un chaînage arrière sur une liste de faits pour atteindre un but.
 *
 * Cette fonction lit un fichier de règles et utilise un algorithme de chaînage arrière pour déterminer si un but peut être atteint à partir d'une liste de faits initiale. Le but est atteint si toutes les prémisses d'une règle qui a le but comme conséquence sont présentes dans la liste de faits.
 *
 * @param file Le nom du fichier contenant les règles à utiliser pour le chaînage arrière.
 * @param liste_faits Un pointeur vers le premier élément de la liste de faits initiale.
 * @param but La chaîne de caractères représentant le but à atteindre.
 * @return int Retourne 1 si le but est atteint, sinon retourne 0.
 */
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