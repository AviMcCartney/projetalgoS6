// rule.c
#include <stdlib.h>
#include <string.h>
#include "rule.h"
#include "memoire.h"

Rule *create_rule(char *premises, char *conclusion)
{
    Rule *new_rule = (Rule *)allouer_malloc(sizeof(Rule));
    new_rule->premises = strdup(premises);
    new_rule->conclusion = strdup(conclusion);
    new_rule->next = NULL;
    return new_rule;
}

void add_rule(Rule **head, char *premises, char *conclusion)
{
    Rule *new_rule = create_rule(premises, conclusion);
    new_rule->next = *head;
    *head = new_rule;
}

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
