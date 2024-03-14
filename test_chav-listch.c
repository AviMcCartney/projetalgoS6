#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct Rule {
    char antecedent[MAX_LENGTH];
    char consequent[MAX_LENGTH];
    int ruleNumber;
    struct Rule *next;
} Rule;

typedef struct Fact {
    char fact[MAX_LENGTH];
    int ruleNumber;
    struct Fact *next;
} Fact;

Rule *ruleList = NULL;
Fact *factList = NULL;

void addRule(char* antecedent, char* consequent, int ruleNumber) {
    Rule *newRule = (Rule*)malloc(sizeof(Rule));
    if (newRule == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newRule->antecedent, antecedent);
    strcpy(newRule->consequent, consequent);
    newRule->ruleNumber = ruleNumber;
    newRule->next = ruleList;
    ruleList = newRule;
}

void addFact(char* fact, int ruleNumber) {
    Fact *newFact = (Fact*)malloc(sizeof(Fact));
    if (newFact == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newFact->fact, fact);
    newFact->ruleNumber = ruleNumber;
    newFact->next = factList;
    factList = newFact;
}

void infer() {
    int newFactAdded = 1;

    while (newFactAdded) {
        newFactAdded = 0;

        Rule *currentRule = ruleList;
        while (currentRule != NULL) {
            int antecedentMatch = 1;
            char *antecedentToken = strtok(currentRule->antecedent, " ");
            while (antecedentToken != NULL) {
                Fact *currentFact = factList;
                int found = 0;
                while (currentFact != NULL) {
                    if (strcmp(antecedentToken, currentFact->fact) == 0) {
                        found = 1;
                        break;
                    }
                    currentFact = currentFact->next;
                }
                if (!found) {
                    antecedentMatch = 0;
                    break;
                }
                antecedentToken = strtok(NULL, " ");
            }
            if (antecedentMatch) {
                char *consequentToken = strtok(currentRule->consequent, " ");
                while (consequentToken != NULL) {
                    Fact *currentFact = factList;
                    int found = 0;
                    while (currentFact != NULL) {
                        if (strcmp(consequentToken, currentFact->fact) == 0) {
                            found = 1;
                            break;
                        }
                        currentFact = currentFact->next;
                    }
                    if (!found) {
                        addFact(consequentToken, currentRule->ruleNumber);
                        newFactAdded = 1;
                    }
                    consequentToken = strtok(NULL, " ");
                }
            }
            currentRule = currentRule->next;
        }
    }
}

void printFacts() {
    printf("Facts added:\n");
    Fact *currentFact = factList;
    Fact **factArray = (Fact**)malloc(sizeof(Fact*) * 100); // tableau temporaire de pointeurs de faits
    int index = 0;

    while (currentFact != NULL) {
        if (currentFact->ruleNumber != 0) { // Ignorer les faits initiaux
            factArray[index++] = currentFact;
        }
        currentFact = currentFact->next;
    }

    // Affichage des faits dans l'ordre inverse
    for (int i = index - 1; i >= 0; i--) {
        printf("R%d %s\n", factArray[i]->ruleNumber, factArray[i]->fact);
    }

    free(factArray);
}

void freeRules() {
    Rule *tempRule;
    while (ruleList != NULL) {
        tempRule = ruleList;
        ruleList = ruleList->next;
        free(tempRule);
    }
}

void freeFacts() {
    Fact *tempFact;
    while (factList != NULL) {
        tempFact = factList;
        factList = factList->next;
        free(tempFact);
    }
}

int main() {
    addRule("b d e", "f", 1);
    addRule("g d", "a", 2);
    addRule("f c", "a", 3);
    addRule("b", "x", 4);
    addRule("e", "d", 5);
    addRule("a x", "h", 6);
    addRule("c", "d", 7);
    addRule("x c", "a", 8);
    addRule("x b", "d", 9);

    addFact("b", 0); // Le fait initial n'est pas ajouté par une règle
    addFact("c", 0); // Le fait initial n'est pas ajouté par une règle

    infer();
    printFacts();

    // Libérer la mémoire allouée pour les règles et les faits
    freeRules();
    freeFacts();

    return 0;
}
