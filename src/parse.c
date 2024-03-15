/**
 * @file parse.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier parse.c contenant les procédures nécessaires permettant de parser les informations du .kbs dans une structure
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule.h"
#include "fact.h"
#include "memoire.h"
#include "lecture.h"

/**
 * @brief Analyse les données et remplit les listes de règles et de faits.
 * @param donnees Les données à analyser.
 * @param rules Un pointeur vers la tête de la liste des règles.
 * @param facts Un pointeur vers la tête de la liste des faits.
 */
void parse_kbs(char *donnees, Rule **rules, Fact **facts)
{
    int nombre_de_lignes = get_ligne(donnees);
    char *regle = strtok(donnees, ";");

    for (int i = 0; i < nombre_de_lignes; i++)
    {
        if (regle != NULL)
        {
            char *premises = strtok(regle, "->");
            char *conclusion = strtok(NULL, "->");

            add_rule(rules, premises, conclusion);

            // Si la prémisse est un fait connu, l'ajouter à la liste de faits
            if (strstr(premises, " ") == NULL)
            {
                add_fact(facts, premises);
            }
        }
        regle = strtok(NULL, ";");
    }
}
