#ifndef RULE_H
#define RULE_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Conclusion[100];
    char Hypotheses[100];
    int ruleNumber;
    struct Rule *suivant;
} Rule;

#endif // RULE_H