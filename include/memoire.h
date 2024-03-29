/**
 * @file memoire.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la gestion de la mémoire.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MEMOIRE_H
#define MEMOIRE_H

#include <stdio.h>
#include <stdint.h>

/**
 * @brief Permet de faire un malloc tout en prenant en compte les erreurs de pointeurs NULL
 *
 * @param taille
 * @return void*
 */
void *allouer_malloc(int taille);

#endif // MEMOIRE_H