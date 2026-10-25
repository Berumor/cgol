#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "grid.h"
#include "rules.h"
#include "util.h"

/* Rules
* 1. Any live cell with fewer that two live neighbours dies, as if by underpopulation.
* 2. Any live cell with two or three live neighbourns lives on the next generation.
* 3. Any live cell with more than three live neighbourns dies, as if by overpopulation.
* 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

int next_generation(struct point points[], int point_n, struct point out[]);

int main(void) {
    int generation = 0;
    int population = 7;

    struct point alive[GRID_HEIGHT * GRID_WIDTH] = {
        {.x=5, .y=4}, 
        {.x=5, .y=5},
        {.x=4, .y=5},
        {.x=4, .y=6},
        {.x=6, .y=4},
        {.x=7, .y=4},
        {.x=7, .y=3},
    };

    struct point next[GRID_HEIGHT * GRID_WIDTH] = {};

    for(;;generation++){
        clear();

        printf("Generation %d\n", generation);
        printf("Population %d\n\n", population);

        draw_grid(alive, population);
        population = next_generation(alive, population, next);

        for(int i = 0; i < population; i++) {
            alive[i] = next[i];
        }
        
        sleep(1);
    }
    return 0;
}


int next_generation(struct point points[], int point_n, struct point out[]) {
   int next_population = 0;

   for(int i = 0; i < GRID_HEIGHT; i++) {
       for(int j = 0; j < GRID_WIDTH; j++) {
           struct point p = {.x = i, .y = j};
           if(contains(points, point_n, p)) {
               if(should_live(p, points, point_n)) out[next_population++] = p;
           } else {
               if(should_reproduce(p, points, point_n)) out[next_population++] = p;
           }
       }
   }

   return next_population;
}




