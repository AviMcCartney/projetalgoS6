#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Structure pour une règle
typedef struct Rule {
    char antecedent[MAX_LENGTH]; // Partie antécédente de la règle
    char consequent[MAX_LENGTH]; // Partie conséquente de la règle
    int ruleNumber; // Numéro de la règle
    struct Rule *next; // Pointeur vers la prochaine règle
} Rule;

// Structure pour un fait
typedef struct Fact {
    char fact[MAX_LENGTH]; // Le fait
    int ruleNumber; // Numéro de la règle qui a déduit ce fait
    struct Fact *next; // Pointeur vers le prochain fait
} Fact;

Rule *ruleList = NULL; // Liste de règles
Fact *factList = NULL; // Liste de faits

// Fonction pour ajouter une règle
void addRule(char* antecedent, char* consequent, int ruleNumber) {
    Rule *newRule = (Rule*)malloc(sizeof(Rule)); // Allouer de la mémoire pour une nouvelle règle
    if (newRule == NULL) { // Vérifier si l'allocation a réussi
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newRule->antecedent, antecedent); // Copier l'antécédent
    strcpy(newRule->consequent, consequent); // Copier le conséquent
    newRule->ruleNumber = ruleNumber; // Affecter le numéro de la règle
    newRule->next = ruleList; // Ajouter la nouvelle règle à la liste
    ruleList = newRule;
}

// Fonction pour ajouter un fait
void addFact(char* fact, int ruleNumber) {
    Fact *newFact = (Fact*)malloc(sizeof(Fact)); // Allouer de la mémoire pour un nouveau fait
    if (newFact == NULL) { // Vérifier si l'allocation a réussi
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newFact->fact, fact); // Copier le fait
    newFact->ruleNumber = ruleNumber; // Affecter le numéro de la règle associée
    newFact->next = factList; // Ajouter le nouveau fait à la liste
    factList = newFact;
}

// Fonction pour inférer de nouveaux faits
void infer() {
    int newFactAdded = 1; // Indicateur pour vérifier si de nouveaux faits ont été ajoutés

    while (newFactAdded) { // Boucle jusqu'à ce qu'aucun nouveau fait ne soit ajouté
        newFactAdded = 0; // Réinitialiser l'indicateur à chaque itération

        Rule *currentRule = ruleList; // Parcourir la liste des règles
        while (currentRule != NULL) { // Parcourir toutes les règles
            int antecedentMatch = 1; // Indicateur pour vérifier si l'antécédent de la règle est satisfait
            char *antecedentToken = strtok(currentRule->antecedent, " "); // Découper l'antécédent en tokens
            while (antecedentToken != NULL) { // Parcourir tous les tokens de l'antécédent
                Fact *currentFact = factList; // Parcourir la liste des faits
                int found = 0; // Indicateur pour vérifier si le token actuel est trouvé parmi les faits
                while (currentFact != NULL) { // Parcourir tous les faits
                    if (strcmp(antecedentToken, currentFact->fact) == 0) { // Vérifier si le token correspond à un fait
                        found = 1; // Marquer comme trouvé
                        break; // Sortir de la boucle
                    }
                    currentFact = currentFact->next; // Passer au prochain fait
                }
                if (!found) { // Si le token n'est pas trouvé parmi les faits
                    antecedentMatch = 0; // Marquer l'antécédent comme non satisfait
                    break; // Sortir de la boucle
                }
                antecedentToken = strtok(NULL, " "); // Passer au prochain token
            }
            if (antecedentMatch) { // Si l'antécédent est satisfait
                char *consequentToken = strtok(currentRule->consequent, " "); // Découper le conséquent en tokens
                while (consequentToken != NULL) { // Parcourir tous les tokens du conséquent
                    Fact *currentFact = factList; // Parcourir la liste des faits
                    int found = 0; // Indicateur pour vérifier si le token actuel est déjà un fait
                    while (currentFact != NULL) { // Parcourir tous les faits
                        if (strcmp(consequentToken, currentFact->fact) == 0) { // Vérifier si le token est déjà un fait
                            found = 1; // Marquer comme trouvé
                            break; // Sortir de la boucle
                        }
                        currentFact = currentFact->next; // Passer au prochain fait
                    }
                    if (!found) { // Si le token n'est pas déjà un fait
                        addFact(consequentToken, currentRule->ruleNumber); // Ajouter le token comme nouveau fait
                        newFactAdded = 1; // Marquer qu'un nouveau fait a été ajouté
                    }
                    consequentToken = strtok(NULL, " "); // Passer au prochain token du conséquent
                }
            }
            currentRule = currentRule->next; // Passer à la règle suivante
        }
    }
}

// Fonction pour afficher les faits déduits
void printFacts() {
    printf("Facts added:\n");
    Fact *currentFact = factList; // Parcourir la liste des faits
    Fact **factArray = (Fact**)malloc(sizeof(Fact*) * 100); // Tableau temporaire de pointeurs de faits
    int index = 0; // Indice pour parcourir le tableau

    while (currentFact != NULL) { // Parcourir tous les faits
        if (currentFact->ruleNumber != 0) { // Ignorer les faits initiaux
            factArray[index++] = currentFact; // Ajouter le fait au tableau
        }
        currentFact = currentFact->next; // Passer au prochain fait
    }

    // Affichage des faits dans l'ordre inverse
    for (int i = index - 1; i >= 0; i--) {
        printf("R%d %s\n", factArray[i]->ruleNumber, factArray[i]->fact);
    }

    free(factArray); // Libérer la mémoire allouée pour le tableau
}

// Fonction pour libérer la mémoire allouée pour les règles
void freeRules() {
    Rule *tempRule;
    while (ruleList != NULL) { // Parcourir la liste des règles
        tempRule = ruleList; // Stocker temporairement la règle actuelle
        ruleList = ruleList->next; // Passer à la règle suivante
        free(tempRule); // Libérer la mémoire de la règle
    }
}

// Fonction pour libérer la mémoire allouée pour les faits
void freeFacts() {
    Fact *tempFact;
    while (factList != NULL) { // Parcourir la liste des faits
        tempFact = factList; // Stocker temporairement le fait actuel
        factList = factList->next; // Passer au fait suivant
        free(tempFact); // Libérer la mémoire du fait
    }
}

int main() {
    // Ajouter des règles
    addRule("b d e", "f", 1);
    addRule("g d", "a", 2);
    addRule("f c", "a", 3);
    addRule("b", "x", 4);
    addRule("e", "d", 5);
    addRule("a x", "h", 6);
    addRule("c", "d", 7);
    addRule("x c", "a", 8);
    addRule("x b", "d", 9);

    // Ajouter des faits initiaux
    addFact("b", 0);
    addFact("c", 0);

    // Inférer de nouveaux faits
    infer();

    // Afficher les faits déduits
    printFacts();

    // Libérer la mémoire allouée pour les règles et les faits
    freeRules();
    freeFacts();

    return 0;
}
