#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fait.h"
#include "memoire.h"

Faits *CreerFaits()
{
    Faits *nouveau = allouer_malloc(sizeof(Faits));
    nouveau->nombre_faits = 0;
    nouveau->identifiant = NULL;
    nouveau->suiv = NULL;
    return nouveau;
}

Faits *InsererFaits(Faits *tete, Faits *f)
{
    if (tete == NULL)
        return f;
    else
        tete->suiv = InsererFaits(tete->suiv, f);
    return tete;
}

Faits *AjouterFaits()
{
    Faits *liste = NULL;
    int nombre_faits;
    printf("Combien de faits voulez-vous ajouter ? ");
    scanf("%d", &nombre_faits);
    for (int i = 0; i < nombre_faits; i++)
    {
        char identifiant[100];
        printf("Saisir un fait: ");
        scanf("%s", identifiant);
        Faits *nouveau = CreerFaits();
        nouveau->identifiant = strdup(identifiant);
        liste = InsererFaits(liste, nouveau);
    }
    return liste;
}

Faits *AjouterFaitsSuite(Faits *liste, const char *nouveauFait)
{
    Faits *nouveau = CreerFaits();
    nouveau->identifiant = strdup(nouveauFait);
    return InsererFaits(liste, nouveau);
}

void AfficherFaits(Faits *tete)
{
    Faits *courant = tete;
    while (courant != NULL)
    {
        printf("%s -> ", courant->identifiant);
        courant = courant->suiv;
    }
    printf("NULL\n");
}

void LibererFaits(Faits *tete)
{
    Faits *courant = tete;
    while (courant != NULL)
    {
        Faits *suivant = courant->suiv;
        free(courant->identifiant);
        free(courant);
        courant = suivant;
    }
}

int FaitPresent(Faits *liste_faits, const char *but)
{
    Faits *courant = liste_faits;
    while (courant != NULL)
    {
        if (strcmp(courant->identifiant, but) == 0)
        {
            return 1;
        }
        courant = courant->suiv;
    }
    return 0;
}