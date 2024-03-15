/**
 * @file fact.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier fact.c contenant les procédures pour créer des faits, les ajouter, les supprimer, les afficher et les libérer.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdlib.h>
#include <string.h>
#include "fact.h"
#include "memoire.h"

/**
 * @brief Crée un nouveau fait.
 * @param fact Le fait à créer.
 * @return Un pointeur vers le nouveau fait.
 */
Fact *create_fact(char *fact)
{
    Fact *new_fact = (Fact *)allouer_malloc(sizeof(Fact));
    new_fact->fact = strdup(fact);
    new_fact->next = NULL;
    return new_fact;
}

/**
 * @brief Ajoute un fait à la tête de la liste des faits.
 * @param head Un pointeur vers la tête de la liste des faits.
 * @param fact Le fait à ajouter.
 */
void add_fact(Fact **head, char *fact)
{
    Fact *new_fact = create_fact(fact);
    new_fact->next = *head;
    *head = new_fact;
}

/**
 * @brief Libère la mémoire allouée pour une liste de faits.
 * @param head La tête de la liste de faits.
 */
void free_facts(Fact *head)
{
    Fact *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp->fact);
        free(tmp);
    }
}

/**
 * @brief Affiche une liste de faits.
 * @param head La tête de la liste de faits.
 */
void print_facts(Fact *head)
{
    printf("Liste de faits :\n");
    Fact *current = head;
    while (current != NULL)
    {
        printf("%s\n", current->fact);
        current = current->next;
    }
}