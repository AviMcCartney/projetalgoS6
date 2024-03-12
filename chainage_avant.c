#include <stdio.h>
#include <stdbool.h>

// Définition de la structure d'une règle
typedef struct {
    char Conclusion;
    char Hypotheses[3];
    int nb_hypotheses;
} Rule;

// Fonction pour vérifier si une règle est applicable
bool RegleApplicable(Rule rule, char *Base_de_faits) {
    for (int i = 0; i < rule.nb_hypotheses; i++) {
        bool trouve = false;
        for (int j = 0; j < 3; j++) {
            if (rule.Hypotheses[i] == Base_de_faits[j]) {
                trouve = true;
                break;
            }
        }
        if (!trouve)
            return false;
    }
    return true;
}

// Fonction de chaînage avant
void ChainageAvant(Rule *Base_de_regles, char *Base_de_faits, int nb_regles) {
    bool faits_ajoutes = true;

    while (faits_ajoutes) {
        faits_ajoutes = false;
        for (int i = 0; i < nb_regles; i++) {
            if (!RegleApplicable(Base_de_regles[i], Base_de_faits))
                continue;

            bool trouve = false;
            for (int j = 0; j < 3; j++) {
                if (Base_de_regles[i].Conclusion == Base_de_faits[j]) {
                    trouve = true;
                    break;
                }
            }
            if (!trouve) {
                for (int k = 0; k < 3; k++) {
                    if (Base_de_faits[k] == '\0') {
                        Base_de_faits[k] = Base_de_regles[i].Conclusion;
                        faits_ajoutes = true;
                        printf("Nouveau fait ajouté : %c\n", Base_de_regles[i].Conclusion);
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    // Déclaration et initialisation des bases de règles et de faits
    Rule Base_de_regles[] = {
        {'f', {'b', 'd', 'e'}, 3},
        {'a', {'g', 'd'}, 2},
        {'a', {'f', 'c'}, 2},
        {'x', {'b'}, 1},
        {'d', {'e'}, 1},
        {'h', {'a', 'x'}, 2},
        {'d', {'c'}, 1},
        {'a', {'x', 'c'}, 2},
        {'d', {'x', 'b'}, 2}
    };  
    char Base_de_faits[3] = { 'b', 'c', '\0' }; // Utilisation de '\0' pour marquer la fin des faits

    int nb_regles = sizeof(Base_de_regles) / sizeof(Base_de_regles[0]);

    // Appel de la fonction de chaînage avant
    ChainageAvant(Base_de_regles, Base_de_faits, nb_regles);

    // Vérification si le but est atteint
    bool but_atteint = false;
    for (int i = 0; i < 3; i++) {
        if (Base_de_faits[i] == 'h') {
            but_atteint = true;
            break;
        }
    }

    // Affichage du résultat
    if (but_atteint)
        printf("Le but est atteint.\n");
    else
        printf("Le but n'est pas atteint.\n");

    return 0;
}