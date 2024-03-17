/**
 * @file caractere.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier caractere.c contenant l'ensemble des fonctions pour les opérations concernant les opérations sur les caractères.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caractere.h"

/**
 * @brief Vérifie si un caractère est présent dans une liste de faits.
 *
 * @param tete Pointeur vers le premier élément de la liste de faits.
 * @param caractere Le caractère à rechercher dans la liste de faits.
 * @return int Retourne 1 si le caractère est trouvé dans la liste, sinon retourne
 */
int CaractereDansListe(Faits *tete, char caractere)
{
    Faits *courant = tete;
    while (courant != NULL)
    {
        char *identifiant = courant->identifiant;
        while (*identifiant != '\0')
        {
            if (*identifiant == caractere)
                return 1;
            identifiant++;
        }
        courant = courant->suiv;
    }
    return 0;
}

/**
 * @brief Ajoute un caractère à une liste de faits s'il n'est pas déjà présent.
 *
 * @param liste Pointeur vers le premier élément de la liste de faits.
 * @param caractere Le caractère à ajouter à la liste de faits.
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits
 */
Faits *AjouterCaractereSiAbsent(Faits *liste, char caractere)
{
    if (!CaractereDansListe(liste, caractere))
    {
        char identifiant[100];
        identifiant[0] = caractere;
        identifiant[1] = '\0';
        liste = AjouterFaitsSuite(liste, identifiant);
    }
    return liste;
}