#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* recupererLigne(FILE *file, int numeroLigne) {
    char buffer[256];
    int numeroActuel = 0;


    while (numeroActuel < numeroLigne && fgets(buffer, sizeof(buffer), file) != NULL) {
        numeroActuel++;
    }

    if (numeroActuel == numeroLigne) {
        char *ligne = malloc(strlen(buffer) + 1);
        if (ligne == NULL) {
            perror("Erreur lors de l'allocation de mémoire");
            exit(EXIT_FAILURE);
        }
        strcpy(ligne, buffer);
        return ligne;
    } else {
        printf("La ligne spécifiée n'existe pas dans le fichier\n");
        return NULL;
    }
}

int main() {
    FILE *file = fopen("regles.kbs", "r");
    if (file == NULL) {
        perror("Impossible d'ouvrir le fichier");
        return 1;
    }

    int ligne = 6; 
    char *ligneRecuperee = recupererLigne(file, ligne);
    if (ligneRecuperee != NULL) {
        printf("%s", ligneRecuperee);
        free(ligneRecuperee); 
    }

    fclose(file);
    return 0;
}
