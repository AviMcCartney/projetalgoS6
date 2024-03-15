/**
 * @file main.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier main.c contenant l'ensemble de nos procédures de tests
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "rule.h"
#include "fact.h"
#include "memoire.h"
#include "test.h"
#include "lecture.h"
#include "parse.h"
#include "chainage_arriere.h"
#include "chainage_avant.h"

int main()
{
    FILE *fichier = ouvrir_fichier("test.kbs", "r");
    char *donnees = lire_donnes_kbs(fichier);
    int nb_lignes = get_ligne(donnees);
    fclose(fichier);

    // Initialisation des listes de règles et de faits
    Rule *rules = NULL;
    Fact *facts = NULL;
    add_fact(&facts, "c");
    add_fact(&facts, "b");
    print_facts(facts);

    // Analyse des données et remplissage des listes de règles et de faits
    char *ligneRecuperee = (char *)malloc(sizeof(char) * nb_lignes);
    for (int i = 0; i < nb_lignes; i++)
    {
        if (i >= 1)
        {
            fichier = fopen("test.kbs", "r");
            ligneRecuperee = recupererLigne(fichier, i);
            printf("%s", ligneRecuperee);
            parse_kbs(ligneRecuperee, &rules, &facts);
            free(ligneRecuperee);
            fclose(fichier);
        }
    }
    print_rules(rules);

    // Test du chaînage avant
    int result = forward_chaining(rules, &facts);
    if (result)
    {
        printf("De nouveaux faits ont été ajoutés à la liste de faits.\n");
    }
    else
    {
        printf("Aucun nouveau fait n'a été ajouté à la liste de faits.\n");
    }

    // Test du chaînage arrière
    char *goal = "h";
    if (backward_chaining(rules, &facts, goal))
    {
        printf("Le fait %s peut être prouvé.\n", goal);
    }
    else
    {
        printf("Le fait %s ne peut pas être prouvé.\n", goal);
    }

    // Libération de la mémoire
    free_rules(rules);
    free_facts(facts);
    free(donnees);
    // test();
    return 0;
}