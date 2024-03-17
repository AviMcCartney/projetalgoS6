/**
 * @file chainage_arriere.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la fonction de chaînage arrière.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef CHAINAGE_ARRIERE_H
#define CHAINAGE_ARRIERE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fait.h"
#include "caractere.h"

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
int ChainageArriere(const char *file, Faits *liste_faits, char *but);

#endif // CHAINAGE_ARRIERE_H