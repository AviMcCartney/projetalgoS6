#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Définition de la structure d'une règle
typedef struct RuleNode {
    char Conclusion;
    char Hypotheses[3];
    int nb_hypotheses;
    struct RuleNode *next; // Pointeur vers le prochain nœud de règle
} RuleNode;

// Définition de la structure d'un fait
typedef struct FactNode {
    char fact;
    struct FactNode *next;
} FactNode;

// Fonction pour vérifier si une règle est applicable
bool RegleApplicable(RuleNode *rule, FactNode *Base_de_faits) {
    for (int i = 0; i < rule->nb_hypotheses; i++) {
        bool trouve = false;
        FactNode *current_fact = Base_de_faits;
        while (current_fact != NULL) {
            if (rule->Hypotheses[i] == current_fact->fact) {
                trouve = true;
                break;
            }
            current_fact = current_fact->next;
        }
        if (!trouve)
            return false;
    }
    return true;
}

// Fonction de chaînage avant
void ChainageAvant(RuleNode *Base_de_regles, FactNode *Base_de_faits) {
    bool faits_ajoutes = true;

    // Boucle principale du chaînage avant
    while (faits_ajoutes) {
        faits_ajoutes = false;
        RuleNode *rulePtr = Base_de_regles;
        while (rulePtr != NULL) {
            // Vérification si la règle est applicable
            if (RegleApplicable(rulePtr, Base_de_faits)) {
                // Vérification si la conclusion de la règle est déjà dans les faits
                bool trouve = false;
                FactNode *current_fact = Base_de_faits;
                while (current_fact != NULL) {
                    if (rulePtr->Conclusion == current_fact->fact) {
                        trouve = true;
                        break;
                    }
                    current_fact = current_fact->next;
                }
                // Si la conclusion n'est pas dans les faits, l'ajouter
                if (!trouve) {
                    FactNode *new_fact = (FactNode *)malloc(sizeof(FactNode));
                    new_fact->fact = rulePtr->Conclusion;
                    new_fact->next = Base_de_faits;
                    Base_de_faits = new_fact;
                    faits_ajoutes = true;
                    printf("Nouveau fait ajouté : %c\n", rulePtr->Conclusion);
                }
            }
            rulePtr = rulePtr->next;
        }
    }
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

// Fonction de chaînage arrière
bool ChainageArriere(char But, RuleNode *Base_de_regles, FactNode *Base_de_faits) {
    // Vérification si le but est déjà dans la base de faits
    FactNode *current_fact = Base_de_faits;
    while (current_fact != NULL) {
        if (But == current_fact->fact)
            return true;
        current_fact = current_fact->next;
    }

    // Parcourir les règles dans la base de règles
    RuleNode *current_rule = Base_de_regles;
    while (current_rule != NULL) {
        // Vérification si la conclusion de la règle correspond au but
        if (current_rule->Conclusion == But) {
            
            bool Resultat = true;
            for (int i = 0; i < current_rule->nb_hypotheses; i++) {
                Resultat = Resultat && ChainageArriere(current_rule->Hypotheses[i], Base_de_regles, Base_de_faits);
            }
            return Resultat;
        }
        current_rule = current_rule->next;
    }
    // Retourne le résultat final
    return false;
}

int main() {
    // Déclaration et initialisation de la base de règles et de faits
    RuleNode *Base_de_regles = NULL;
    FactNode *Base_de_faits = NULL;

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

    // Affichage du menu
    int choix;
    do {
        printf("Menu:\n");
        printf("1. Chaînage avant\n");
        printf("2. Chaînage arrière\n");
        printf("3. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ChainageAvant(Base_de_regles, Base_de_faits);
                break;
            case 2: {
                // Choix du but à atteindre
                char But;
                printf("Entrez le but à atteindre : ");
                scanf(" %c", &But);

                // Appel de la fonction ChainageArriere avec le but spécifié
                bool resultat = ChainageArriere(But, Base_de_regles, Base_de_faits);

                // Affichage du résultat
                if (resultat)
                    printf("Le but est atteignable.\n");
                else
                    printf("Le but n'est pas atteignable.\n");
            } break;
            case 3:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide! Veuillez choisir à nouveau.\n");
        }
    } while (choix != 3);

    // Libérer la mémoire utilisée par la base de règles
    LibererMemoire(Base_de_regles);

    // Libérer la mémoire utilisée par la base de faits
    FactNode *temp;
    while (Base_de_faits != NULL) {
        temp = Base_de_faits;
        Base_de_faits = Base_de_faits->next;
        free(temp);
    }

    return 0;
}

