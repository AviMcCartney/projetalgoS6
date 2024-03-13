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

int infer(char* targetFact) {
    int i, j;
    int result = 0;

    // Vérifier d'abord si le fait est déjà dans la base de faits
    for (i = 0; i < numFacts; i++) {
        if (strcmp(targetFact, facts[i]) == 0) {
            return 1; // Le fait est déjà prouvé, pas besoin de l'inférer
        }
    }

    // Recherche dans les règles
    for (i = 0; i < numRules; i++) {
        if (strcmp(targetFact, rules[i].consequent) == 0) {
            int hypothesisVerified = 1;
            char *hypothesisToken = strtok(rules[i].antecedent, " ");
            while (hypothesisToken != NULL) {
                int found = 0;
                for (j = 0; j < numFacts; j++) {
                    if (strcmp(hypothesisToken, facts[j]) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    hypothesisVerified = infer(hypothesisToken);
                    if (!hypothesisVerified)
                        break;
                }
                hypothesisToken = strtok(NULL, " ");
            }
            if (hypothesisVerified) {
                addFact(targetFact, i + 1); // Ajouter le numéro de la règle qui a ajouté le fait
                result = 1;
                break; // Sortir de la boucle dès qu'une règle applicable est trouvée
            }
        }
    }

    return result;
}

int main() {
    // Ajout d'une variable pour stocker le fait cible
    char targetFact[MAX_LENGTH];

    // Demandez à l'utilisateur d'entrer le fait cible
    printf("Entrez le fait cible : ");
    fgets(targetFact, MAX_LENGTH, stdin);
    targetFact[strcspn(targetFact, "\n")] = '\0'; // Supprimer le retour à la ligne

    // Ajoutez les règles comme auparavant
    addRule("b d e", "f");
    addRule("g d", "a");
    addRule("f c", "a");
    addRule("b", "x");
    addRule("e", "d");
    addRule("a x", "h");
    addRule("c", "d");
    addRule("x c", "a");
    addRule("x b", "d");

    // Ajoutez les faits initiaux comme auparavant
    addFact("b", 0); // Le fait initial n'est pas ajouté par une règle
    addFact("c", 0); // Le fait initial n'est pas ajouté par une règle

    // Vérifiez si le fait cible peut être prouvé
    if (infer(targetFact)) {
        printf("%s est vrai.\n", targetFact);
        printf("Faits ajoutés pour arriver à h en chainage arriere:\n");
        for (int i = 0; i < numFacts; i++) {
            if (factRule[i] != 0) { // Ignorer les faits initiaux
                printf("R%d %s\n", factRule[i], facts[i]);
            }
        }
    } else {
        printf("%s n'est pas prouvé.\n", targetFact);
    }

    return 0;
}
