/**
 * @file caractere.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour les fonctions de manipulation des caractères.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CARACTERE_H
#define CARACTERE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fait.h"

/**
 * @brief Vérifie si un caractère est présent dans une liste de faits.
 *
 * @param tete Un pointeur vers le premier élément de la liste de faits.
 * @param caractere Le caractère à rechercher dans la liste de faits.
 * @return int Retourne 1 si le caractère est trouvé dans la liste, sinon retourne 0.
 */
int CaractereDansListe(Faits *tete, char caractere);

/**
 * @brief Ajoute un caractère à une liste de faits s'il n'est pas déjà présent.
 *
 * @param liste Un pointeur vers le premier élément de la liste de faits.
 * @param caractere Le caractère à ajouter à la liste de faits.
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
Faits *AjouterCaractereSiAbsent(Faits *liste, char caractere);

#endif // CARACTERE_H