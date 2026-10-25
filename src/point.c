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
