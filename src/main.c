#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_avant.h"
#include "chainage_arriere.h"

int main()
{
    Faits *liste = NULL;
    liste = AjouterFaits();
    printf("Faits insérés: ");
    AfficherFaits(liste);

    // Chaînage avant
    liste = ChainageAvant("regles.kbs", liste);
    printf("Chainage avant: ");
    AfficherFaits(liste);

    // Chaînage arrière
    char but;
    printf("Saisir le but à atteindre: ");
    scanf(" %c", &but); // %c pour lire un caractère unique
    ChainageArriere("regles.kbs", liste, but);

    LibererFaits(liste);
    return 0;
}