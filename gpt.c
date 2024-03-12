#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct RuleNode {
    char Conclusion;
    char Hypotheses[3];
    int nb_hypotheses;
    struct RuleNode *next; // Pointeur vers le prochain nœud de règle
} RuleNode;

// Définition de la structure d'une base de faits
typedef struct FactNode {
    char Fact;
    struct FactNode *next; // Pointeur vers le prochain nœud de fait
} FactNode;

// Fonction pour vérifier si une règle est applicable
bool RegleApplicable(RuleNode *rule, FactNode *Base_de_faits) {
    while (rule != NULL) {
        int nb_hypotheses_satisfaites = 0;
        for (int i = 0; i < rule->nb_hypotheses; i++) {
            char hyp = rule->Hypotheses[i];
            FactNode *factPtr = Base_de_faits;
            bool trouve = false;
            while (factPtr != NULL) {
                if (factPtr->Fact == hyp) {
                    trouve = true;
                    break;
                }
                factPtr = factPtr->next;
            }
            if (trouve) {
                nb_hypotheses_satisfaites++;
            } else {
                break;
            }
        }
        if (nb_hypotheses_satisfaites == rule->nb_hypotheses) {
            return true;
        }
        rule = rule->next;
    }
    return false;
}

// Fonction pour ajouter un fait à la base de faits
void AjouterFait(char fait, FactNode **Base_de_faits) {
    FactNode *newFact = (FactNode *)malloc(sizeof(FactNode));
    newFact->Fact = fait;
    newFact->next = NULL;

    if (*Base_de_faits == NULL) {
        *Base_de_faits = newFact;
    } else {
        FactNode *temp = *Base_de_faits;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newFact;
    }
}

// Fonction de chaînage avant
void ChainageAvant(RuleNode *Base_de_regles, FactNode **Base_de_faits) {
    bool faits_ajoutes = true;
    bool but_atteint = false;

    // Boucle principale du chaînage avant
    while (faits_ajoutes && !but_atteint) {
        faits_ajoutes = false;
        RuleNode *rulePtr = Base_de_regles;
        while (rulePtr != NULL) {
            // Vérification si la règle est applicable
            if (RegleApplicable(rulePtr, *Base_de_faits)) {
                // Vérification si la conclusion de la règle est déjà dans les faits
                bool trouve = false;
                FactNode *factPtr = *Base_de_faits;
                while (factPtr != NULL) {
                    if (factPtr->Fact == rulePtr->Conclusion) {
                        trouve = true;
                        break;
                    }
                    factPtr = factPtr->next;
                }
                // Si la conclusion n'est pas dans les faits, l'ajouter
                if (!trouve) {
                    AjouterFait(rulePtr->Conclusion, Base_de_faits);
                    faits_ajoutes = true;
                    printf("Nouveau fait ajouté : %c\n", rulePtr->Conclusion);
                    if (rulePtr->Conclusion == 'h') {
                        but_atteint = true;
                    }
                }
            }
            rulePtr = rulePtr->next;
        }
    }

    // Vérification si le but est atteint
    if (but_atteint) {
        printf("Le but est atteint.\n");
    } else {
        printf("Le but n'est pas atteint.\n");
    }
}

// Définition de la fonction Chaînage arrière
bool ChainageArriere(char But, RuleNode *Base_de_regles, FactNode *Base_de_faits) {
    // Vérification si le but est déjà dans la base de faits
    FactNode *factPtr = Base_de_faits;
    while (factPtr != NULL) {
        if (factPtr->Fact == But) {
            return true;
        }
        factPtr = factPtr->next;
    }

    // Parcourir les règles dans la base de règles
    RuleNode *rulePtr = Base_de_regles;
    while (rulePtr != NULL) {
        // Vérification si la conclusion de la règle correspond au but
        if (rulePtr->Conclusion == But) {
            // Vérification de toutes les hypothèses de la règle
            bool Resultat = true;
            for (int i = 0; i < rulePtr->nb_hypotheses; i++) {
                // Appel récursif pour vérifier les hypothèses
                Resultat = Resultat && ChainageArriere(rulePtr->Hypotheses[i], Base_de_regles, Base_de_faits);
            }
            // Si toutes les hypothèses sont satisfaites, la conclusion est satisfaites
            // Sinon, la conclusion n'est pas satisfaite
            return Resultat;
        }
        rulePtr = rulePtr->next;
    }
    // Retourne le résultat final
    return false;
}

// Fonction pour libérer la mémoire utilisée par la base de faits
void LibererMemoire(FactNode *Base_de_faits) {
    FactNode *temp;
    while (Base_de_faits != NULL) {
        temp = Base_de_faits;
        Base_de_faits = Base_de_faits->next;
        free(temp);
    }
}

int main() {
    // Déclaration et initialisation des bases de règles et de faits
    RuleNode *Base_de_regles = NULL;
    FactNode *Base_de_faits = NULL;

    // Ajout des règles à la base de règles
    RuleNode *regle1 = (RuleNode *)malloc(sizeof(RuleNode));
    regle1->Conclusion = 'f';
    regle1->Hypotheses[0] = 'b';
    regle1->Hypotheses[1] = 'd';
    regle1->Hypotheses[2] = 'e';
    regle1->nb_hypotheses = 3;
    regle1->next = NULL;

    RuleNode *regle2 = (RuleNode *)malloc(sizeof(RuleNode));
    regle2->Conclusion = 'a';
    regle2->Hypotheses[0] = 'g';
    regle2->Hypotheses[1] = 'd';
    regle2->nb_hypotheses = 2;
    regle2->next = NULL;

    
    if (Base_de_regles == NULL) {
        Base_de_regles = regle1;
    }

    regle1->next = regle2;

    // Choix du mode de chaînage
    int choix;
    printf("Choisissez le mode de chaînage (1: avant, 2: arrière): ");
    scanf("%d", &choix);

    // Appel de la fonction de chaînage en fonction du choix
    switch (choix) {
        case 1:
            printf("----- Chaînage avant -----\n");
            ChainageAvant(Base_de_regles, &Base_de_faits);
            break;
        case 2:
            {
                char But;
                printf("Entrez le but a atteindre : ");
                scanf(" %c", &But);

                bool resultat = ChainageArriere(But, Base_de_regles, Base_de_faits);

                if (resultat)
                    printf("Le but est atteignable.\n");
                else
                    printf("Le but n'est pas atteignable.\n");
            }
            break;
        default:
            printf("Choix invalide.\n");
    }

    // Libérer la mémoire utilisée par la base de faits
    LibererMemoire(Base_de_faits);

    return 0;
}