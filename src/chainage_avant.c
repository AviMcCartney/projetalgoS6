// forward_chaining.c
#include "rule.h"
#include "fact.h"
#include "memoire.h"
#include <string.h>

void forward_chaining(Rule *rules, Fact **facts)
{
    Rule *rule;
    Fact *fact;
    int new_facts_added = 1;

    while (new_facts_added)
    {
        new_facts_added = 0;

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
    }
}
