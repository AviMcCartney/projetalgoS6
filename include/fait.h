#ifndef FAIT_H
#define FAIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Faits
{
    int nombre_faits;
    char *identifiant;
    struct Faits *suiv;
} Faits;

Faits *CreerFaits();
Faits *InsererFaits(Faits *tete, Faits *f);
Faits *AjouterFaits();
Faits *AjouterFaitsSuite(Faits *liste, const char *nouveauFait);
void AfficherFaits(Faits *tete);
void LibererFaits(Faits *tete);
int FaitPresent(Faits *liste_faits, const char *but);

#endif // FAIT_H