// parse.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule.h"
#include "fact.h"
#include "memoire.h"

void parse_kbs(char *donnees, Rule **rules, Fact **facts)
{
    char *ligne = strtok(donnees, "\n");

    while (ligne != NULL)
    {
        char *premises = strtok(ligne, "->");
        char *conclusion = strtok(NULL, "->");

        add_rule(rules, premises, conclusion);

        // Si la prémisse est un fait connu, l'ajouter à la liste de faits
        if (strstr(premises, " ") == NULL)
        {
            add_fact(facts, premises);
        }

        ligne = strtok(NULL, "\n");
        printf("%s%s", premises, conclusion);
    }
}
