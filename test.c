#include <stdio.h>
#include <stdbool.h>

// Définition de la structure d'une règle
typedef struct {
    char Conclusion;
    char Hypotheses[2];
    int nb_hypotheses;
} Rule;

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
            // Si toutes les hypothèses sont vérifiées, la conclusion est vérifiée
            // Sinon, la conclusion n'est pas vérifiée
            return Resultat;
        }
    }
    // Retourne le résultat final
    return Resultat;
}

int main() {
    // Déclaration et initialisation des bases de règles et de faits
    Rule Base_de_regles[] = {
        {'f', {'b', 'd'}, 2},
        {'a', {'g', 'd'}, 2},
        {'a', {'f', 'c'}, 2},
        {'x', {'b'}, 1},
        {'d', {'e'}, 1},
        {'h', {'a', 'x'}, 2},
        {'d', {'c'}, 1},
        {'a', {'x', 'c'}, 2},
        {'d', {'x', 'b'}, 2}
    };
    char Base_de_faits[] = {'b', 'c'};

    int nb_regles = sizeof(Base_de_regles) / sizeof(Base_de_regles[0]);
    int nb_faits = sizeof(Base_de_faits) / sizeof(Base_de_faits[0]);

    // Appel de la fonction Chaînage arrière avec le but spécifié
    bool resultat = ChainageArriere('h', Base_de_regles, Base_de_faits, nb_regles, nb_faits);

    // Affichage du résultat
    if (resultat)
        printf("Le but est atteignable.\n");
    else
        printf("Le but n'est pas atteignable.\n");

    return 0;
}
