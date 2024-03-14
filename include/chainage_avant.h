#ifndef CHAINAGE_AVANT_H
#define CHAINAGE_AVANT_H

#include "rule.h"
#include "fact.h"

#include <stdio.h>
#include <stdint.h>

void forward_chaining(Rule *rules, Fact **facts);

#endif // CHAINAGE_AVANT_H