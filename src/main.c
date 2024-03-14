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
    add_fact(&facts, "d");
    // Analyse des données et remplissage des listes de règles et de faits
    parse_kbs(donnees, &rules, &facts);

    // Test du chaînage avant
    int result = forward_chaining(rules, &facts);
    if (result)
    {
        printf("De nouveaux faits ont été ajoutés à la liste de faits.\n");
    }
    else
    {
        printf("Aucun nouveau fait n'a été ajouté à la liste de faits.\n");
    }

    // Test du chaînage arrière
    // char *goal = "h";
    // if (backward_chaining(rules, facts, goal))
    // {
    //     printf("Le fait %s peut être prouvé.\n", goal);
    // }
    // else
    // {
    //     printf("Le fait %s ne peut pas être prouvé.\n", goal);
    // }

    // Libération de la mémoire
    free_rules(rules);
    free_facts(facts);
    free(donnees);

    return 0;
}

// Procédure pour tester les chainages avec les valeurs en "dur"
//  int main()
//  {
//  Initialisation des listes de règles et de faits
//  Rule *rules = NULL;
//  Fact *facts = NULL;

// Ajout des règles
// add_rule(&rules, "a b c", "g");
// add_rule(&rules, "b d", "e");
// add_rule(&rules, "b d e", "f");
// add_rule(&rules, "g d", "a");
// add_rule(&rules, "f c", "a");
// add_rule(&rules, "b", "x");
// add_rule(&rules, "e", "d");
// add_rule(&rules, "a x", "h");
// add_rule(&rules, "c", "d");
// add_rule(&rules, "x c", "a");
// add_rule(&rules, "x b", "d");
// add_rule(&rules, "a b c", "g");
// add_fact(&facts, "c");

// Test du chaînage avant -- Fonctionne
// int result = forward_chaining(rules, &facts);
// if (result)
// {
//     printf("De nouveaux faits ont été ajoutés à la liste de faits.\n");
// }
// else
// {
//     printf("Aucun nouveau fait n'a été ajouté à la liste de faits.\n");
// }

// Test du chaînage arrière
//     char *goal = "h"; // Remplacez "h" par le fait que vous voulez prouver
//     if (backward_chaining(rules, &facts, goal))
//     {
//         printf("Le fait %s peut être prouvé.\n", goal);
//     }
//     else
//     {
//         printf("Le fait %s ne peut pas être prouvé.\n", goal);
//     }

//     // Libération de la mémoire
//     free_rules(rules);
//     free_facts(facts);

//     return 0;
// }