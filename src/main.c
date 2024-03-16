#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_avant.h"
#include "memoire.h"
#include "chainage_arriere.h"

int main()
{
    Faits *liste = NULL;
    liste = AjouterFaits();
    printf("Faits insérés: ");
    AfficherFaits(liste);

    // Chaînage avant
    // char *but_av = (char *)allouer_malloc(sizeof(char));

    ChainageAvant("regles_av.kbs", liste);
    printf("Chainage avant: ");
    AfficherFaits(liste);

    // Chaînage arrière
    char *but_ar = (char *)allouer_malloc(sizeof(char));
    printf("Saisir le but à atteindre: ");
    scanf(" %s", but_ar);
    ChainageArriere("regles_av.kbs", liste, but_ar);
    printf("Chainage arriere: ");
    AfficherFaits(liste);
    LibererFaits(liste);
    return 0;
}