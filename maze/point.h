#ifndef MAZE_POINT_H
#define MAZE_POINT_H

/**
 * Represents a point coordinates.
 */
typedef struct point {
    unsigned int x;
    unsigned int y;
    int distance;
    const struct point *parent;
} Point;

typedef struct node {
    Point info;
    struct node *next;
} Node;

/**
 * Compare two points.
 *
 * @param point the point to compare.
 * @param anotherPoint the point with which the point will be compared.
 * @return 1 if the points are equals, 0 otherwise.
 */
int isSamePoint(Point point, Point anotherPoint);

#endif //MAZE_POINT_H
