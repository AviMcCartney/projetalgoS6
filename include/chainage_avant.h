/**
 * @file chainage_avant.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la fonction de chaînage avant.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef CHAINAGE_AVANT_H
#define CHAINAGE_AVANT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fait.h"
#include "caractere.h"

/**
 * @brief Effectue un chaînage avant sur une liste de faits.
 *
 * Cette fonction lit un fichier de règles et utilise un algorithme de chaînage avant pour déterminer si un but peut être atteint à partir d'une liste de faits initiale. Le but est atteint si toutes les conséquences d'une règle qui a le but comme prémisse sont présentes dans la liste de faits.
 *
 * @param file Le nom du fichier contenant les règles à utiliser pour le chaînage avant.
 * @param liste_faits Un pointeur vers le premier élément de la liste de faits initiale.
 * @return Faits* Retourne un pointeur vers le premier élément de la liste de faits mise à jour.
 */
Faits *ChainageAvant(const char *file, Faits *liste_faits);

#endif // CHAINAGE_AVANT_H