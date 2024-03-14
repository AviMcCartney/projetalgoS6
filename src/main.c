// main.c
#include <stdio.h>
#include <stdlib.h>

#include "rule.h"
#include "fact.h"
#include "memoire.h"
#include "lecture.h"
#include "parse.h"
#include "chainage_arriere.h"
#include "chainage_avant.h"

int main()
{
    FILE *fichier = ouvrir_fichier("test.kbs", "r");
    char *donnees = lire_donnes_kbs(fichier);
    fclose(fichier);

    // Initialisation des listes de règles et de faits
    Rule *rules = NULL;
    Fact *facts = NULL;

    // Analyse des données et remplissage des listes de règles et de faits
    parse_kbs(donnees, &rules, &facts);

    // Test du chaînage avant
    forward_chaining(rules, &facts);

    // Test du chaînage arrière
    char *goal = "h";
    if (backward_chaining(rules, facts, goal))
    {
        printf("Le fait %s peut être prouvé.\n", goal);
    }
    else
    {
        printf("Le fait %s ne peut pas être prouvé.\n", goal);
    }

    // Libération de la mémoire
    free_rules(rules);
    free_facts(facts);
    free(donnees);

    return 0;
}
