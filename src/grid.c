#include <stdio.h>

#include "grid.h"
#include "point.h"

void draw_grid(struct point alive[], int alive_size) {
   for(int i = 0; i < GRID_HEIGHT; i++) {
       for(int j = 0; j < GRID_WIDTH; j++) {
           struct point p = {.x = i, .y = j};
           if(contains(alive, alive_size, p)) {
               printf("\x24");
           } else {
               printf("\x2E");
           }
       }
       printf("\n");
   }
}
