#include <stdio.h>

#include "point.h"

int contains(struct point points[], int points_n, struct point point) {
    for(int i = 0; i < points_n; i++) {
        if(points[i].x == point.x && points[i].y == point.y){
            return 1;
        }
    }

    return 0;
}

int alive_neighbours(struct point p, struct point points[], int points_n) {
    struct point neighbours[8] = {
         {.x = p.x-1, .y = p.y-1},
         {.x = p.x-1, .y = p.y },
         {.x = p.x-1, .y = p.y+1},
         {.x = p.x, .y = p.y-1 },
         {.x = p.x, .y = p.y+1 },
         {.x = p.x+1 , .y = p.y-1},
         {.x = p.x+1 , .y = p.y},
         {.x = p.x+1, .y = p.y+1}
    };

    int alive_neighbours = 0;
    for(int i = 0; i < NEIGHBOURS; i++) {
        if(contains(points, points_n, neighbours[i]) == 1) {
            alive_neighbours++;
        }
    }

    return alive_neighbours;
}


