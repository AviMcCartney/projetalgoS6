#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Définition de la structure d'une règle
typedef struct RuleNode {
    char Conclusion;
    char Hypotheses[3];
    int nb_hypotheses;
    struct RuleNode *next;
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
            // Vérification de toutes les hypothèses de la règle
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
    // Déclaration et initialisation des bases de règles et de faits
    RuleNode *Base_de_regles = NULL;
    FactNode *Base_de_faits = NULL;

    // Ajout des règles
    RuleNode *rule1 = (RuleNode *)malloc(sizeof(RuleNode));
    rule1->Conclusion = 'f';
    rule1->Hypotheses[0] = 'b';
    rule1->Hypotheses[1] = 'd';
    rule1->Hypotheses[2] = 'e';
    rule1->nb_hypotheses = 3;
    rule1->next = NULL;
    Base_de_regles = rule1;

    // Ajout des faits
    FactNode *fact1 = (FactNode *)malloc(sizeof(FactNode));
    fact1->fact = 'b';
    fact1->next = NULL;
    Base_de_faits = fact1;

    // Choix du but à atteindre
    char But;
    printf("Entrez le but à atteindre : ");
    scanf(" %c", &But);

    // Appel de la fonction Chaînage arrière avec le but spécifié
    bool resultat = ChainageArriere(But, Base_de_regles, Base_de_faits);

    // Affichage du résultat
    if (resultat)
        printf("Le but est atteignable.\n");
    else
        printf("Le but n'est pas atteignable.\n");

    // Libération de la mémoire allouée
    while (Base_de_regles != NULL) {
        RuleNode *temp = Base_de_regles;
        Base_de_regles = Base_de_regles->next;
        free(temp);
    }

    while (Base_de_faits != NULL) {
        FactNode *temp = Base_de_faits;
        Base_de_faits = Base_de_faits->next;
        free(temp);
    }

    return 0;
}