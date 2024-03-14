#ifndef CHAINAGE_AVANT_H
#define CHAINAGE_AVANT_H

// Inclure les bibliothèques nécessaires
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définir la longueur maximale des chaînes
#define LEN 100

// Déclaration des structures
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

// Déclaration des prototypes de fonction
void CreerFaits_av(char* fact, int nb_regles);
void MoteurInference_av();
void AfficheFaits();
void freeRegles();
void freeFaits();

#endif /* CHAINAGE_AVANT_H */
