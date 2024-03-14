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

Rule* createRule(char* antecedent, char* consequent, int ruleNumber) {
    Rule *newRule = (Rule*)malloc(sizeof(Rule));
    if (newRule == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newRule->antecedent, antecedent);
    strcpy(newRule->consequent, consequent);
    newRule->ruleNumber = ruleNumber;
    newRule->next = NULL;
    return newRule;
}

Fact* createFact(char* fact, int ruleNumber) {
    Fact *newFact = (Fact*)malloc(sizeof(Fact));
    if (newFact == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newFact->fact, fact);
    newFact->ruleNumber = ruleNumber;
    newFact->next = NULL;
    return newFact;
}

void addRule(char* antecedent, char* consequent, int ruleNumber) {
    Rule *newRule = createRule(antecedent, consequent, ruleNumber);
    newRule->next = ruleList;
    ruleList = newRule;
}

void addFact(char* fact, int ruleNumber) {
    Fact *newFact = createFact(fact, ruleNumber);
    newFact->next = factList;
    factList = newFact;
}

int infer(char* targetFact, char *resultFacts) {
    int i, j;
    int result = 0;
    Fact *currentFact = factList;

    // Vérifier d'abord si le fait est déjà dans la base de faits
    while (currentFact != NULL) {
        if (strcmp(targetFact, currentFact->fact) == 0) {
            return 1; // Le fait est déjà prouvé, pas besoin de l'inférer
        }
        currentFact = currentFact->next;
    }

    // Recherche dans les règles
    Rule *currentRule = ruleList;
    while (currentRule != NULL) {
        if (strcmp(targetFact, currentRule->consequent) == 0) {
            int hypothesisVerified = 1;
            char *hypothesisToken = strtok(currentRule->antecedent, " ");
            while (hypothesisToken != NULL) {
                int found = 0;
                currentFact = factList;
                while (currentFact != NULL) {
                    if (strcmp(hypothesisToken, currentFact->fact) == 0) {
                        found = 1;
                        break;
                    }
                    currentFact = currentFact->next;
                }
                if (!found) {
                    hypothesisVerified = infer(hypothesisToken, resultFacts);
                    if (!hypothesisVerified)
                        break;
                }
                hypothesisToken = strtok(NULL, " ");
            }
            if (hypothesisVerified) {
                addFact(targetFact, currentRule->ruleNumber); // Ajouter le numéro de la règle qui a ajouté le fait
                if (strlen(resultFacts) > 0) {
                    strcat(resultFacts, " > ");
                }
                strcat(resultFacts, "R");
                char ruleNumStr[10];
                sprintf(ruleNumStr, "%d", currentRule->ruleNumber);
                strcat(resultFacts, ruleNumStr);
                strcat(resultFacts, "-");
                strcat(resultFacts, targetFact);
                result = 1;
                break; // Sortir de la boucle dès qu'une règle applicable est trouvée
            }
        }
        currentRule = currentRule->next;
    }

    return result;
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
    // Ajout d'une variable pour stocker le fait cible
    char targetFact[MAX_LENGTH];
    char resultFacts[MAX_LENGTH * 10] = "";

    // Demandez à l'utilisateur d'entrer le fait cible
    printf("Entrez le fait cible : ");
    fgets(targetFact, MAX_LENGTH, stdin);
    targetFact[strcspn(targetFact, "\n")] = '\0'; // Supprimer le retour à la ligne

    // Ajoutez les règles comme auparavant
    addRule("b d e", "f", 1);
    addRule("g d", "a", 2);
    addRule("f c", "a", 3);
    addRule("b", "x", 4);
    addRule("e", "d", 5);
    addRule("a x", "h", 6);
    addRule("c", "d", 7);
    addRule("x c", "a", 8);
    addRule("x b", "d", 9);

    // Ajoutez les faits initiaux comme auparavant
    addFact("b", 0); // Le fait initial n'est pas ajouté par une règle
    addFact("c", 0); // Le fait initial n'est pas ajouté par une règle

    // Vérifiez si le fait cible peut être prouvé
    if (infer(targetFact, resultFacts)) {
        printf("%s est vrai.\n", targetFact);
        printf("Facts added: %s\n", resultFacts);
    } else {
        printf("%s n'est pas prouvé.\n", targetFact);
    }

    // Libérer la mémoire allouée pour les règles et les faits
    freeRules();
    freeFacts();

    return 0;
}
