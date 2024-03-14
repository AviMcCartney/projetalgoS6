#ifndef STRUCT_H
#define STRUCT_CHAINAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100 // Longueur maximale des chaînes de caractères
typedef struct Regles {
    char antecedent[LEN];
    char consequent[LEN];
    int nb_regles;
    struct Regles *suiv;
} Regles;

typedef struct Fait {
    char fait[LEN];
    int nb_regles;
    struct Fait *suiv;
} Fait;
#endif /* STRUCT_CHAINAGE_H */
