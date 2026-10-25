#ifndef POINT_H
#define POINT_H

#define NEIGHBOURS 8

typedef struct point {
    int x, y;
} point;

int contains(struct point points[], int points_n, struct point);
int alive_neighbours(struct point p, struct point points[], int points_n);

#endif //POINT_H
