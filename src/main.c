#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_avant.h"
#include "memoire.h"
#include "chainage_arriere.h"
#include "menu.h"

int main()
{
    Faits *liste = NULL;
    char *but = (char *)allouer_malloc(sizeof(char));
    int choix = menu();
    while (choix != 0)
    {
        switch (choix)
        {
        case 1:
            liste = AjouterFaits();
            printf("Faits insérés: ");
            AfficherFaits(liste);
            ChainageAvant("regles1.kbs", liste);
            printf("Chainage avant: ");
            AfficherFaits(liste);
            break;

        case 2:
            liste = AjouterFaits();
            printf("Faits insérés: ");
            AfficherFaits(liste);
            printf("Saisir le but à atteindre: ");
            scanf("%s", but);
            ChainageArriere("regles1.kbs", liste, but);
            printf("Chainage arriere: ");
            AfficherFaits(liste);
            break;

        default:
            printf("Nombre incorrect, saisir à nouveau\n");
            break;
        }
        choix = menu();
    }
    LibererFaits(liste);
    return 0;
}