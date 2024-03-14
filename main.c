#include <stdio.h>
#include <stdlib.h>
#include "struct_chainageV2.h"
#include "lectureV2.h" // Inclure le fichier pour la lecture des règles depuis le fichier KBS

int main() {
    FILE *fichier_kbs = ouvrir_fichier("regles.kbs", "r"); // Ouvre le fichier KBS en mode lecture

    char *regles_str = lire_donnees_kbs(fichier_kbs); // Lit les règles depuis le fichier KBS
    fclose(fichier_kbs); // Ferme le fichier après lecture

    // Récupère les règles à partir de la chaîne de caractères lue depuis le fichier KBS
    int nb_regles = get_ligne(regles_str);
    // Ajoute les règles à la liste de règles existantes en utilisant les fonctions de ton programme
    // Par exemple, pour chaque règle, tu peux les ajouter en utilisant AjouterRegle(...)

    // Chainage arrière
    printf("Chainage arrière: \n\n");
    char but[LEN];
    char resultatFait[LEN * 10] = "";

    printf("Entrez le but: ");
    fgets(but, LEN, stdin);
    but[strcspn(but, "\n")] = '\0';

    // Utilise le moteur d'inférence à chaînage arrière avec les règles récupérées depuis le fichier KBS
    if (MoteurInference_ar(but, resultatFait)) {
        printf("%s est vrai.\n", but);
        printf("Fait ajouté: %s\n", resultatFait);
    } else {
        printf("%s n'est pas prouvé.\n", but);
    }

    // Chainage avant
    printf("\nChainage avant: \n\n");
    // Crée les faits initiaux (s'ils ne sont pas lus depuis le fichier KBS)
    // Utilise le moteur d'inférence à chaînage avant avec les règles récupérées depuis le fichier KBS
    MoteurInference_av();
    // Affiche les faits après le chaînage avant
    AfficheFaits();

    // Libère la mémoire utilisée pour les règles et les faits
    freeRegles();
    freeFaits();

    // Libère la mémoire allouée pour la chaîne de caractères des règles lues depuis le fichier KBS
    free(regles_str);

    return 0;
}
