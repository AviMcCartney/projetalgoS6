#ifndef STRUCT_CHAINAGE_H
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

extern Regles *liste_de_regles; // Déclaration de la variable externe liste_de_regles
extern Fait *liste_de_faits; // Déclaration de la variable externe liste_de_faits

// Déclarations des fonctions
Regles *CreerRegles(char *antecedent, char *consequent, int nb_regles);
Fait *CreerFaits(char *fact, int nb_regles);
void AjouterRegle(char *antecedent, char *consequent, int nb_regles);
void AjouterFait(char *fact, int nb_regles);
int MoteurInference_ar(char *but, char *resultatFait);
void MoteurInference_av();
void AfficheFaits();
void freeRegles();
void freeFaits();

#endif /* STRUCT_CHAINAGE_H */
