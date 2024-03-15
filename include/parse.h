/**
 * @file parse.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la gestion des données et le parsing.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
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