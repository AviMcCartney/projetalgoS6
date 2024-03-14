// backward_chaining.c
#include "rule.h"
#include "fact.h"
#include "memoire.h"
#include <string.h>

int backward_chaining(Rule *rules, Fact *facts, char *goal)
{
    Fact *fact;
    Rule *rule;

    for (fact = facts; fact != NULL; fact = fact->next)
    {
        if (strcmp(fact->fact, goal) == 0)
        {
            return 1;
        }
    }

    for (rule = rules; rule != NULL; rule = rule->next)
    {
        if (strcmp(rule->conclusion, goal) == 0)
        {
            char *premise = strtok(rule->premises, " ");
            while (premise != NULL)
            {
                if (!backward_chaining(rules, facts, premise))
                {
                    return 0;
                }
                premise = strtok(NULL, " ");
            }
            return 1;
        }
    }

    return 0;
}
