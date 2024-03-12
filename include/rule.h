#ifndef RULE_H
#define RULE_H
#include <stdio.h>
#include <stdint.h>

typedef struct
{
    char Conclusion;
    char *Hypotheses;
    int nb_hypotheses;
    Rule *suivant;
} Rule;

void process_header(Rule *mon_header, char packet80);
Rule construct_rule(FILE *chemin_fichier);

#endif // RULE_H