#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Définition de la structure d'une règle
typedef struct RuleNode {
    char Conclusion;
    char Hypotheses[3];
    int nb_hypotheses;
    struct RuleNode *next; // Pointeur vers le prochain nœud de règle
} RuleNode;

// Fonction pour vérifier si une règle est applicable
bool RegleApplicable(RuleNode *rule, char *Base_de_faits) {
    for (int i = 0; i < rule->nb_hypotheses; i++) {
        bool trouve = false;
        for (int j = 0; j < 3; j++) {
            if (rule->Hypotheses[i] == Base_de_faits[j]) {
                trouve = true;
                break;
            }
        }
        if (!trouve) {
            return false;
        }
    }
    return true;
}

// Fonction de chaînage avant
void ChainageAvant(RuleNode *Base_de_regles, char *Base_de_faits) {
    bool faits_ajoutes = true;
    char nouveaux_faits[3];
    int nb_nouveaux_faits = 0;

    // Boucle principale du chaînage avant
    while (faits_ajoutes) {
        faits_ajoutes = false;
        RuleNode *rulePtr = Base_de_regles;
        while (rulePtr != NULL) {
            // Vérification si la règle est applicable
            if (RegleApplicable(rulePtr, Base_de_faits)) {
                // Vérification si la conclusion de la règle est déjà dans les faits
                bool trouve = false;
                for (int j = 0; j < 3; j++) {
                    if (rulePtr->Conclusion == Base_de_faits[j]) {
                        trouve = true;
                        break;
                    }
                }
                // Si la conclusion n'est pas dans les faits, l'ajouter
                if (!trouve) {
                    for (int k = 0; k < 3; k++) {
                        if (Base_de_faits[k] == '\0') {
                            Base_de_faits[k] = rulePtr->Conclusion;
                            nouveaux_faits[nb_nouveaux_faits++] = rulePtr->Conclusion;
                            faits_ajoutes = true;
                            break;
                        }
                    }
                }
            }
            rulePtr = rulePtr->next;
        }
    }

    // Afficher les nouveaux faits ajoutés
    printf("Nouveaux faits ajoutés : ");
    for (int i = 0; i < nb_nouveaux_faits; i++) {
        printf("%c ", nouveaux_faits[i]);
    }
    printf("\n");
}

// Fonction pour ajouter une règle à la base de règles
void AjouterRegle(char conclusion, char hypotheses[], int nb_hypotheses, RuleNode **Base_de_regles) {
    RuleNode *newRule = (RuleNode *)malloc(sizeof(RuleNode));
    newRule->Conclusion = conclusion;
    for (int i = 0; i < nb_hypotheses; i++) {
        newRule->Hypotheses[i] = hypotheses[i];
    }
    newRule->nb_hypotheses = nb_hypotheses;
    newRule->next = NULL;

    if (*Base_de_regles == NULL) {
        *Base_de_regles = newRule;
    } else {
        RuleNode *temp = *Base_de_regles;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRule;
    }
}

// Fonction pour libérer la mémoire utilisée par la base de règles
void LibererMemoire(RuleNode *Base_de_regles) {
    RuleNode *temp;
    while (Base_de_regles != NULL) {
        temp = Base_de_regles;
        Base_de_regles = Base_de_regles->next;
        free(temp);
    }
}

int main() {
    // Déclaration et initialisation de la base de règles et de faits
    RuleNode *Base_de_regles = NULL;
    char Base_de_faits[3] = { 'b', 'c', '\0' }; // Utilisation de '\0' pour marquer la fin des faits

    // Ajout des règles à la base de règles
    AjouterRegle('f', (char[]){'b', 'd', 'e'}, 3, &Base_de_regles);
    AjouterRegle('a', (char[]){'g', 'd'}, 2, &Base_de_regles);
    AjouterRegle('a', (char[]){'f', 'c'}, 2, &Base_de_regles);
    AjouterRegle('x', (char[]){'b'}, 1, &Base_de_regles);
    AjouterRegle('d', (char[]){'e'}, 1, &Base_de_regles);
    AjouterRegle('h', (char[]){'a', 'x'}, 2, &Base_de_regles);
    AjouterRegle('d', (char[]){'c'}, 1, &Base_de_regles);
    AjouterRegle('a', (char[]){'x', 'c'}, 2, &Base_de_regles);
    AjouterRegle('d', (char[]){'x', 'b'}, 2, &Base_de_regles);

    // Appel de la fonction de chaînage avant
    ChainageAvant(Base_de_regles, Base_de_faits);

    // Vérification si le but est atteint
    bool but_atteint = false;
    for (int i = 0; i < 3; i++) {
        if (Base_de_faits[i] == 'h') {
            but_atteint = true;
            break;
        }
    }

    // Affichage du résultat
    if (but_atteint) {
        printf("Le but est atteint.\n");
    } else {
        printf("Le but n'est pas atteint.\n");
    }

    // Libérer la mémoire utilisée par la base de règles
    LibererMemoire(Base_de_regles);

    return 0;
}
