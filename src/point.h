#ifndef POINT_H
#define POINT_H

typedef struct point {
    int x, y;
} point;

int contains(struct point points[], int points_n, struct point);


#endif //POINT_H
