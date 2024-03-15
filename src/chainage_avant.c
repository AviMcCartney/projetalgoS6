/**
 * @file chainage_avant.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier chainage_avant.c contenant la procedure forward_chaining()
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "rule.h"
#include "fact.h"
#include "memoire.h"
#include <string.h>

/**
 * @brief Effectue un chaînage avant sur une liste de règles et de faits.
 * @param rules La liste de règles.
 * @param facts Un pointeur vers la liste de faits.
 * @return 1 si de nouveaux faits ont été ajoutés à la liste de faits, 0 sinon.
 */
int forward_chaining(Rule *rules, Fact **facts)
{
    Rule *rule;
    Fact *fact;
    int new_facts_added = 0;

    for (rule = rules; rule != NULL; rule = rule->next)
    {
        for (fact = *facts; fact != NULL; fact = fact->next)
        {
            if (strstr(rule->premises, fact->fact) != NULL)
            {
                add_fact(facts, rule->conclusion);
                new_facts_added = 1;
            }
        }
    }
    return new_facts_added;
}
