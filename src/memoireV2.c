/**
 * @file memoireV2.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief
 * @version 0.1
 * @date 2024-03-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "memoireV2.h"
#include <stdio.h>

void *allouer_malloc(int n) {
    void *pointeur = malloc(n);
    if (pointeur == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    return pointeur;
}


