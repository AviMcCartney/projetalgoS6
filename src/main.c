#include <stdio.h>
#include <stdbool.h>

#define MAX_FACTS 10
#define MAX_RULES 10

// Structure pour une règle
typedef struct
{
    bool antecedents[MAX_FACTS]; // Antécédents de la règle
    bool consequent;             // Conséquent de la règle
} Rule;

// Fonction de chaînage arrière récursive
bool backwardChaining(bool facts[], Rule rules[], int numRules, int numFacts, int goal)
{
    // Vérifier si le but est déjà un fait
    if (facts[goal])
    {
        return true;
    }

    // Parcourir les règles
    for (int i = 0; i < numRules; ++i)
    {
        if (rules[i].consequent == goal)
        {
            // Vérifier les antécédents de la règle
            bool valid = true;
            for (int j = 0; j < numFacts; ++j)
            {
                if (rules[i].antecedents[j] && !facts[j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                // Tester chaque antécédent de la règle
                for (int j = 0; j < numFacts; ++j)
                {
                    if (rules[i].antecedents[j] && !backwardChaining(facts, rules, numRules, numFacts, j))
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }

    return false;
}

int main()
{
    // Initialisation des faits
    bool facts[MAX_FACTS] = {false}; // Initialisation à false
    facts[0] = true;                 // a est vrai
    facts[2] = true;                 // c est vrai

    // Définition des règles
    Rule rules[MAX_RULES];
    rules[0].antecedents[0] = true; // a
    rules[0].antecedents[1] = true; // b
    rules[0].consequent = true;     // f

    rules[1].antecedents[0] = true; // c
    rules[1].antecedents[2] = true; // a
    rules[1].consequent = true;     // e

    int numRules = 2;
    int numFacts = 3;

    // Tester le chaînage arrière pour chaque fait
    for (int i = 0; i < numFacts; ++i)
    {
        bool goal = facts[i];
        bool result = backwardChaining(facts, rules, numRules, numFacts, goal);

        if (result)
        {
            printf("Le fait %c est vrai.\n", 'a' + i);
        }
        else
        {
            printf("Le fait %c n'est pas prouvé.\n", 'a' + i);
        }
    }

    return 0;
}