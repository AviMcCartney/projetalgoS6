/**
 * @file test.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier test.c contenant la procedure test() permettant de tester à la volée les différentes procédures de chaînage
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "rule.h"
#include "fact.h"
#include "memoire.h"
#include "lecture.h"
#include "parse.h"
#include "chainage_arriere.h"
#include "chainage_avant.h"

/**
 * @brief Procédure pour tester les chainages avec des valeurs en "dur"
 *
 * @return void
 */
void test()
{
    // Initialisation des listes de règles et de faits
    Rule *rules = NULL;
    Fact *facts = NULL;

    // Ajout des règles
    add_rule(&rules, "a b c", "g");
    add_rule(&rules, "b d", "e");
    add_rule(&rules, "b d e", "f");
    add_rule(&rules, "g d", "a");
    add_rule(&rules, "f c", "a");
    add_rule(&rules, "b", "x");
    add_rule(&rules, "e", "d");
    add_rule(&rules, "a x", "h");
    add_rule(&rules, "c", "d");
    add_rule(&rules, "x c", "a");
    add_rule(&rules, "x b", "d");
    add_rule(&rules, "a b c", "g");
    // add_fact(&facts, "e");
    // add_fact(&facts, "g");
    print_facts(facts);
    print_rules(rules);

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
    char *goal = "h"; // Remplacez "h" par le fait qu'on veut prouver
    if (backward_chaining(rules, &facts, goal))
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
}