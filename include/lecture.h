
#ifndef LECTURE_H
#define LECTURE_H
#include <stdio.h>
#include <stdint.h>
#include "rule.h"

char *lire_donnes_kbs(FILE *fichier);
FILE *ouvrir_fichier(char *chemin_fichier, char *option);
int get_ligne(char *buffer);

#endif // LECTURE_H