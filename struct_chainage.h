#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LEN 100

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