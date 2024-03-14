// fact.c
#include <stdlib.h>
#include <string.h>
#include "fact.h"
#include "memoire.h"

Fact *create_fact(char *fact)
{
    Fact *new_fact = (Fact *)allouer_malloc(sizeof(Fact));
    new_fact->fact = strdup(fact);
    new_fact->next = NULL;
    return new_fact;
}

void add_fact(Fact **head, char *fact)
{
    Fact *new_fact = create_fact(fact);
    new_fact->next = *head;
    *head = new_fact;
}

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
