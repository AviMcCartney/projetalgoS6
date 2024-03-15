/**
 * @file chainage_avant.h
 * @author Alexandre, Tom, Yanis, Charlotte
 * @brief Fichier d'en-tête pour la gestion du chaînage avant.
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CHAINAGE_AVANT_H
#define CHAINAGE_AVANT_H

#include "rule.h"
#include "fact.h"

#include <stdio.h>
#include <stdint.h>

int forward_chaining(Rule *rules, Fact **facts);

#endif // CHAINAGE_AVANT_H