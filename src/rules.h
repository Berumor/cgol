#ifndef RULES_H
#define RULES_H

#include "point.h"

int should_live(struct point p, struct point points[], int points_n);
int should_reproduce(struct point p, struct point points[], int points_n);

#endif // RULES_H
