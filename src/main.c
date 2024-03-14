#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chainage_avant.h" // Inclure le fichier d'en-tête contenant les déclarations de fonction

// Déclaration du prototype de la fonction chargerReglesDepuisFichier
void chargerReglesDepuisFichier(const char *nomFichier);

int main() {
    // Charger les règles depuis le fichier kbs
    chargerReglesDepuisFichier("regles.kbs");

    // Chainage arrière
    printf("Chainage arrière: \n\n");
    char but[LEN];
    char resultatFait[LEN * 10] = "";

    printf("Entrez le but: ");
    fgets(but, LEN, stdin);
    but[strcspn(but, "\n")] = '\0';

    AjouterFait("b", 0);
    AjouterFait("c", 0);

    if (MoteurInference(but, resultatFait)) {
        printf("%s est vrai.\n", but);
        printf("Fait ajouté: %s\n", resultatFait);
    } else {
        printf("%s n'est pas prouvé.\n", but);
    }
    
    // Chainage avant
    printf("\nChainage avant: \n\n");
    CreerFaits_av("b", 0);
    CreerFaits_av("c", 0);

    MoteurInference_av();
    AfficheFaits();
    
    freeRegles();
    freeFaits();
   
    chargerReglesDepuisFichier("regles.kbs");

    return 0;
}
