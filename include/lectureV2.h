#ifndef LECTURE_H
#define LECTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_chainageV2.h"

char *lire_donnees_kbs(FILE *fichier);
FILE *ouvrir_fichier(char *chemin_fichier, char *option);
int get_ligne(char *buffer);

#endif /* LECTURE_H */
