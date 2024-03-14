// backward_chaining.c
#include "rule.h"
#include "fact.h"
#include "chainage_arriere.h"
#include <string.h>
#include <stdlib.h>

int backward_chaining(Rule *rules, Fact **facts, char *goal)
{
    Fact *current_fact = *facts;

    // Vérifie si le but est déjà un fait connu
    while (current_fact != NULL)
    {
        if (strcmp(current_fact->fact, goal) == 0)
        {
            return 1; // Le fait est déjà dans la liste des faits
        }
        current_fact = current_fact->next;
    }

    // Parcourt les règles pour trouver celle qui a le but comme conclusion
    Rule *current_rule = rules;
    while (current_rule != NULL)
    {
        if (strcmp(current_rule->conclusion, goal) == 0)
        {
            int hypothesis = 1;
            char *token = strtok(current_rule->premises, " ");

            // Pour chaque prémisse de la règle
            while (token != NULL)
            {
                int found = 0;
                Fact *fact_ptr = *facts;

                // Vérifie si la prémisse est un fait connu
                while (fact_ptr != NULL)
                {
                    if (strcmp(token, fact_ptr->fact) == 0)
                    {
                        found = 1;
                        break;
                    }
                    fact_ptr = fact_ptr->next;
                }

                // Si la prémisse n'est pas un fait connu, vérifie récursivement
                if (!found)
                {
                    hypothesis = backward_chaining(rules, facts, token);
                    if (!hypothesis)
                        break; // Si une prémisse n'est pas prouvée, sort de la boucle
                }

                token = strtok(NULL, " ");
            }

            // Si toutes les hypothèses sont vérifiées, ajoute le fait à la liste
            if (hypothesis)
            {
                add_fact(facts, goal);
                return 1;
            }
        }
        current_rule = current_rule->next;
    }

    // Si aucune règle ne permet de prouver le but
    return 0;
}