#ifndef CHAINAGE_ARRIERE_H
#define CHAINAGE_ARRIERE_H

#include "rule.h"
#include "fact.h"
#include "chainage_avant.h"

#include <stdio.h>
#include <stdint.h>

int backward_chaining(Rule *rules, Fact *facts, char *goal);

#endif // CHAINAGE_ARRIERE_H