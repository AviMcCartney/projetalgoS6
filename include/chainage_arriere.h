/**
 * @file chainage_arriere.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la gestion du chaînage arrière.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef CHAINAGE_ARRIERE_H
#define CHAINAGE_ARRIERE_H

#include "rule.h"
#include "fact.h"
#include "chainage_avant.h"

#include <stdio.h>
#include <stdint.h>

int backward_chaining(Rule *rules, Fact **facts, char *goal);

#endif // CHAINAGE_ARRIERE_H