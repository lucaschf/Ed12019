#ifndef MAZE_LIST_H
#define MAZE_LIST_H

#include "point.h"

typedef struct {
    int size;
    Node *first;
    Node *last;
} List;

List *createList();

int insertStart(List *l, Point point);

int insertEnd(List *l, Point point);

int contains(List *l, Point point);

int getItem(List *l, int position, Point *point);

int isEmptyList(List *l);

int getListSize(List *l);

void destroyList(List *l);

void clearList(List *l);

const Point *peekList(List *l);

#endif //MAZE_LIST_H
