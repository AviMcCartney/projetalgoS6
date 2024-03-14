// backward_chaining.c
#include "rule.h"
#include "fact.h"
#include "chainage_arriere.h"
#include <string.h>
#include <stdlib.h>

int backward_chaining(Rule *rules, Fact **facts, char *goal)
{
    Fact *currentFact = *facts;

    // Vérifie si le but est déjà un fait connu
    while (currentFact != NULL)
    {
        if (strcmp(goal, currentFact->fact) == 0)
            return 1;
        currentFact = currentFact->next;
    }

    // Parcourt les règles pour trouver une règle dont la conclusion est le but
    Rule *currentRule = rules;
    while (currentRule != NULL)
    {
        if (strcmp(goal, currentRule->conclusion) == 0)
        {
            int hypothesis = 1;
            char *premises = strdup(currentRule->premises); // Duplique les prémisses pour éviter de modifier la règle originale
            char *saveptr;
            char *token = strtok_r(premises, " ", &saveptr);
            while (token != NULL)
            {
                int found = 0;
                currentFact = *facts;
                while (currentFact != NULL)
                {
                    if (strcmp(token, currentFact->fact) == 0)
                    {
                        found = 1;
                        break;
                    }
                    currentFact = currentFact->next;
                }
                if (!found)
                {
                    hypothesis = backward_chaining(rules, facts, token);
                    if (!hypothesis)
                        break;
                }
                token = strtok_r(NULL, " ", &saveptr);
            }
            free(premises); // Libère la mémoire allouée pour les prémisses dupliquées
            if (hypothesis)
            {
                add_fact(facts, goal);
                return 1;
            }
        }
        currentRule = currentRule->next;
    }
    return 0;
}