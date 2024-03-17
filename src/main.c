/**
 * @file main.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier main.c contenant le code qui sera éxécuté par l'utilisateur.
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_avant.h"
#include "memoire.h"
#include "chainage_arriere.h"
#include "menu.h"

/**
 * @brief Point d'entrée principal du programme.
 *
 * Cette fonction affiche un menu à l'utilisateur et effectue des opérations basées sur le choix de l'utilisateur. Les opérations incluent l'ajout de faits à une liste, l'affichage de la liste de faits, et l'exécution d'un chaînage avant ou arrière sur la liste de faits pour atteindre un but spécifié par l'utilisateur.
 *
 * @return int Retourne 0 lorsque le programme se termine correctement.
 */
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
            puts("Pour le chainage avant, vous disposez d'une grande base règles (+ de 1500 comprenant des caractères spéciaux). Alors n'hésitez pas à tester beaucoup de faits ! (Easter egg : essayez d'obtenir le +)\n");
            liste = AjouterFaits();
            printf("Faits insérés: ");
            AfficherFaits(liste);
            ChainageAvant("regles_av.kbs", liste);
            printf("Chainage avant: ");
            AfficherFaits(liste);
            break;

        case 2:
            puts("Pour le chainage arriere, la base de règles disponible est celle du cahier des charges (i.e :b d e -> f)\n");
            liste = AjouterFaits();
            printf("Faits insérés: ");
            AfficherFaits(liste);
            printf("Saisir le but à atteindre: ");
            scanf("%s", but);
            ChainageArriere("regles_ar.kbs", liste, but);
            break;

        case 3:
            puts("Nom de l'école (en MAJ) ||| ou mettez en faits les quatre suivant : a,3,c / puis en but à atteindre : + ");
            puts("Pour l'école, dans Combien de faits voulez-vous ajouter ? Entrez 1, puis dans saisir fait : ISEN / but à atteindre : +\n");
            break;
        default:
            break;
        }
        choix = menu();
    }
    LibererFaits(liste);
    return 0;
}