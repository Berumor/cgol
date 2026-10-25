#include "point.h"
#include "rules.h"

int should_live(struct point p, struct point points[], int points_n) {
   int alives = alive_neighbours(p, points, points_n);

   if(alives >= 2 && alives <= 3) return 1;
   else return 0;
}

int should_reproduce(struct point p, struct point points[], int points_n) {
    int alives = alive_neighbours(p, points, points_n);
    
    if (alives == 3) return 1;
    else return 0;
}

