/**
 * @file rule.c
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier rule.c contenant les procédures pour créer des règles, les ajouter, les supprimer, les afficher et les libérer.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdlib.h>
#include <string.h>
#include "rule.h"
#include "memoire.h"

/**
 * @brief Crée une nouvelle règle.
 * @param premises Les prémisses de la règle.
 * @param conclusion La conclusion de la règle.
 * @return Un pointeur vers la nouvelle règle.
 */
Rule *create_rule(char *premises, char *conclusion)
{
    Rule *new_rule = (Rule *)allouer_malloc(sizeof(Rule));
    new_rule->premises = strdup(premises);
    new_rule->conclusion = strdup(conclusion);
    new_rule->next = NULL;
    return new_rule;
}

/**
 * @brief Ajoute une nouvelle règle à la tête de la liste des règles.
 * @param head Un pointeur vers la tête de la liste des règles.
 * @param premises Les prémisses de la nouvelle règle.
 * @param conclusion La conclusion de la nouvelle règle.
 */
void add_rule(Rule **head, char *premises, char *conclusion)
{
    Rule *new_rule = create_rule(premises, conclusion);
    new_rule->next = *head;
    *head = new_rule;
}

/**
 * @brief Libère la mémoire allouée pour une liste de règles.
 * @param head La tête de la liste de règles.
 */
void free_rules(Rule *head)
{
    Rule *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp->premises);
        free(tmp->conclusion);
        free(tmp);
    }
}

/**
 * @brief Affiche une liste de règles.
 * @param rules La tête de la liste de règles.
 */
void print_rules(Rule *rules)
{
    printf("Liste des règles :\n");
    Rule *current_rule = rules;
    int rule_number = 1;
    while (current_rule != NULL)
    {
        printf("%d. Si %s alors %s\n", rule_number, current_rule->premises, current_rule->conclusion);
        current_rule = current_rule->next;
        rule_number++;
    }
    printf("\n");
}