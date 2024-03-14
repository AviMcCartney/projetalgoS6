// fact.h
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

#endif // FACT_H
