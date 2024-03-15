/**
 * @file fact.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la gestion des faits.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef FACT_H
#define FACT_H

typedef struct Fact
{
    char *fact;
    struct Fact *next;
} Fact;

Fact *create_fact(char *fact);
void add_fact(Fact **head, char *fact);
void free_facts(Fact *head);
void print_facts(Fact *head);

#endif // FACT_H
