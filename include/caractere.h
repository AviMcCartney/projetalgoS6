#ifndef CARACTERE_H
#define CARACTERE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fait.h"

int CaractereDansListe(Faits *tete, char caractere);
Faits *AjouterCaractereSiAbsent(Faits *liste, char caractere);

#endif // CARACTERE_H