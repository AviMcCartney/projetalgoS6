#include "lectureV2.h"
#include "memoireV2.h" // Ajout de l'inclusion de memoireV2.h

char *lire_donnees_kbs(FILE *fichier) {
    int taille = 1024;
    char *buffer = (char *)allouer_malloc(taille * sizeof(char));
    int index = 0;
    char c;
    while ((c = fgetc(fichier)) != EOF) {
        if (index >= taille) {
            taille *= 2;
            buffer = (char *)realloc(buffer, taille * sizeof(char));
            if (buffer == NULL) {
                fprintf(stderr, "Erreur de réallocation de mémoire\n");
                exit(EXIT_FAILURE);
            }
        }
        buffer[index++] = c;
    }
    buffer[index] = '\0';

    return buffer;
}
