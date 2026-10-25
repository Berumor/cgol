#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "grid.h"
#include "util.h"

/* Rules
* 1. Any live cell with fewer that two live neighbours dies, as if by underpopulation.
* 2. Any live cell with two or three live neighbourns lives on the next generation.
* 3. Any live cell with more than three live neighbourns dies, as if by overpopulation.
* 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

int main(void) {
    int generation = 0;
    struct point alive[2] ={{.x=1, .y=1}, {.x=2, .y=2} };

    for(;;generation++){
        clear();

        int population = sizeof(alive) / sizeof(alive[0]);
        printf("Generation %d\n", generation);
        printf("Population %d\n\n", population);

        draw_grid(alive, population);
        
        sleep(1);
    }
    return 0;
}
