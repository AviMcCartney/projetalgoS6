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

// Définition de la fonction Chaînage arrière
bool ChainageArriere(char But, Rule *Base_de_regles, char *Base_de_faits, int nb_regles, int nb_faits) {
    bool Resultat = false;
    int i, j;

    // Vérification si le but est déjà dans la base de faits
    for (i = 0; i < nb_faits; i++) {
        if (But == Base_de_faits[i]) {
            Resultat = true;
            return Resultat;
        }
    }

    // Parcourir les règles dans la base de règles
    for (i = 0; i < nb_regles; i++) {
        // Vérification si la conclusion de la règle correspond au but
        if (Base_de_regles[i].Conclusion == But) {
            // Vérification de toutes les hypothèses de la règle
            Resultat = true;
            for (j = 0; j < Base_de_regles[i].nb_hypotheses; j++) {
                // Appel récursif pour vérifier les hypothèses
                Resultat = Resultat && ChainageArriere(Base_de_regles[i].Hypotheses[j], Base_de_regles, Base_de_faits, nb_regles, nb_faits);
            }
            // Si toutes les hypothèses sont satisfaites, la conclusion est satisfaites
            // Sinon, la conclusion n'est pas satisfaite
            return Resultat;
        }
    }
    // Retourne le résultat final
    return Resultat;
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
    int nb_faits = 2; // Initialisation à 2 car les faits sont 'b' et 'c'

    // Choix entre chaînage avant et arrière
    int choix;
    printf("Choisissez le mode de chaînage (1: avant, 2: arrière): ");
    scanf("%d", &choix);

    // Appel de la fonction de chaînage en fonction du choix
    switch (choix) {
        case 1:
            // Appel du chaînage avant
            ChainageAvant(Base_de_regles, Base_de_faits, nb_regles);
            break;
        case 2:
            {
                // Choix du but à atteindre pour le chaînage arrière
                char But;
                printf("Entrez le but a atteindre : ");
                scanf(" %c", &But);

                // Appel du chaînage arrière avec le but spécifié
                bool resultat = ChainageArriere(But, Base_de_regles, Base_de_faits, nb_regles, nb_faits);

                // Affichage du résultat
                if (resultat)
                    printf("Le but est atteignable.\n");
                else
                    printf("Le but n'est pas atteignable.\n");
            }
            break;
        default:
            printf("Choix invalide.\n");
    }

    return 0;
}