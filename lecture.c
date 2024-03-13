#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memoire.h"
#include "rule.h"

FILE *mon_fichier;

char *lire_donnes_kbs(FILE *fichier)
{
    Rule regle;
    int taille = 1024;
    char *buffer = (char *)malloc(taille * sizeof(char));
    if (buffer == NULL)
    {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    char c;
    int nb_hypo_current;
    char *hypotheses=NULL;
    int taille_hypo;
    while ((c = fgetc(fichier)) != EOF)
    {
        puts("cou");
        hypotheses = realloc(hypotheses, (taille_hypo + 2) * sizeof(char));
        puts("coucou");
        if (c != '-')
        {
            regle.Conclusion=fgetc(fichier+3);
            fichier+=4;
        }
        else
        {
            if (c == ' ')
            {
                ///regle->Hypotheses=hypotheses;
                nb_hypo_current+=1;
                char *hypotheses;
            }

        hypotheses[taille_hypo] = c;
        taille++;
        hypotheses[taille_hypo] = '\0';

        }
        if (index >= taille)
        {
            taille *= 2;
            buffer = (char *)realloc(buffer, taille * sizeof(char));
            if (buffer == NULL)
            {
                fprintf(stderr, "Erreur de réallocation de mémoire\n");
                exit(EXIT_FAILURE);
            }
        }
        buffer[index++] = c;
    }
    regle.nb_hypotheses=nb_hypo_current;
    buffer[index] = '\0';

    return buffer;
}

FILE *ouvrir_fichier(char *chemin_fichier/*, char *option*/)
{
    mon_fichier = fopen(chemin_fichier, "r");

    if (mon_fichier == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", chemin_fichier);
        exit(EXIT_FAILURE);
    }
    return mon_fichier;
}

int main(){
    ouvrir_fichier("oui.kbs");
    lire_donnes_kbs(mon_fichier);
    return 0;
}