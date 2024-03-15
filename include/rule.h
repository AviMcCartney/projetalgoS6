/**
 * @file rule.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la gestion des règles.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef RULE_H
#define RULE_H

typedef struct Rule
{
    char *premises;
    char *conclusion;
    struct Rule *next;
} Rule;

Rule *create_rule(char *premises, char *conclusion);
void add_rule(Rule **head, char *premises, char *conclusion);
void free_rules(Rule *head);
void print_rules(Rule *rules);

#endif // RULE_H
