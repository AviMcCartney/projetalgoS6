// parse.h
#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule.h"
#include "fact.h"
#include "memoire.h"

void parse_kbs(char *donnees, Rule **rules, Fact **facts);

#endif // PARSE_H