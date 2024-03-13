#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_FACTS 100
#define MAX_LENGTH 100

typedef struct {
    char antecedent[MAX_LENGTH];
    char consequent[MAX_LENGTH];
    int ruleNumber;
} Rule;

int numRules = 0;
Rule rules[MAX_RULES];

int numFacts = 0;
char facts[MAX_FACTS][MAX_LENGTH];
int factRule[MAX_FACTS]; // Pour stocker le numéro de la règle qui a ajouté chaque fait

void addRule(char* antecedent, char* consequent) {
    if (numRules < MAX_RULES) {
        strcpy(rules[numRules].antecedent, antecedent);
        strcpy(rules[numRules].consequent, consequent);
        rules[numRules].ruleNumber = numRules + 1; // Numéro de règle commence à 1
        numRules++;
    } else {
        printf("Max rules exceeded!\n");
    }
}

void addFact(char* fact, int ruleNumber) {
    if (numFacts < MAX_FACTS) {
        strcpy(facts[numFacts], fact);
        factRule[numFacts] = ruleNumber;
        numFacts++;
    } else {
        printf("Max facts exceeded!\n");
    }
}

void infer() {
    int i, j;
    int newFactAdded = 1;

    while (newFactAdded) {
        newFactAdded = 0;

        for (i = 0; i < numRules; i++) {
            int antecedentMatch = 1;
            char *antecedentToken = strtok(rules[i].antecedent, " ");
            while (antecedentToken != NULL) {
                int found = 0;
                for (j = 0; j < numFacts; j++) {
                    if (strcmp(antecedentToken, facts[j]) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    antecedentMatch = 0;
                    break;
                }
                antecedentToken = strtok(NULL, " ");
            }
            if (antecedentMatch) {
                char *consequentToken = strtok(rules[i].consequent, " ");
                while (consequentToken != NULL) {
                    int found = 0;
                    for (j = 0; j < numFacts; j++) {
                        if (strcmp(consequentToken, facts[j]) == 0) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        addFact(consequentToken, i + 1); // Ajouter le numéro de la règle qui a ajouté le fait
                        newFactAdded = 1;
                    }
                    consequentToken = strtok(NULL, " ");
                }
            }
        }
    }
}

int main() {
    addRule("b d e", "f");
    addRule("g d", "a");
    addRule("f c", "a");
    addRule("b", "x");
    addRule("e", "d");
    addRule("a x", "h");
    addRule("c", "d");
    addRule("x c", "a");
    addRule("x b", "d");

    addFact("b", 0); // Le fait initial n'est pas ajouté par une règle
    addFact("c", 0); // Le fait initial n'est pas ajouté par une règle

    infer();

    printf("Facts added:\n");
    for (int i = 0; i < numFacts; i++) {
        if (factRule[i] != 0) { // Ignorer les faits initiaux
            printf("R%d %s\n", factRule[i], facts[i]);
        }
    }

    return 0;
}
