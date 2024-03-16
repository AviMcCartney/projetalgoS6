#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caractere.h"

int CaractereDansListe(Faits *tete, char caractere)
{
    Faits *courant = tete;
    while (courant != NULL)
    {
        char *identifiant = courant->identifiant;
        while (*identifiant != '\0')
        {
            if (*identifiant == caractere)
                return 1;
            identifiant++;
        }
        courant = courant->suiv;
    }
    return 0;
}

Faits *AjouterCaractereSiAbsent(Faits *liste, char caractere)
{
    if (!CaractereDansListe(liste, caractere))
    {
        char identifiant[100];
        identifiant[0] = caractere;
        identifiant[1] = '\0';
        liste = AjouterFaitsSuite(liste, identifiant);
    }
    return liste;
}