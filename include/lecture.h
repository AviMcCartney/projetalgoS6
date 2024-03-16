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

FILE *ouvrir_fichier(const char *chemin_fichier, char *option);

#endif // LECTURE_H