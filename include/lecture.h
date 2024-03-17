/**
 * @file lecture.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la lecture de fichier et le stockage de données.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LECTURE_H
#define LECTURE_H

#include <stdio.h>
#include <stdint.h>

/**
 * @brief Ouvre un fichier.
 * @param chemin_fichier Le chemin vers le fichier à ouvrir.
 * @param option Les options d'ouverture du fichier (par exemple, "r" pour lire, "w" pour écrire).
 * @return Un pointeur vers le fichier ouvert.
 */
FILE *ouvrir_fichier(const char *chemin_fichier, char *option);

#endif // LECTURE_H