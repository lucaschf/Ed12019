#include <stdlib.h>
#include "list.h"

List *createList() {
    List *l;

    l = (List *) malloc(sizeof(List));

    if (l) {
        l->size = 0;
        l->first = NULL;
        l->last = NULL;
    }

    return l;
}

int insertStart(List *l, Point point) {
    Node *node;

    if (!l)
        return 0;

    node = (Node *) malloc(sizeof(Node));

    if (!node)
        return 0;

    node->info = point;

    node->next = l->first;
    l->first = node;

    if (l->size == 0)
        l->last = node;

    l->size++;

    return 1;
}

int insertEnd(List *l, Point point) {
    Node *node;

    if (!l)
        return 0;

    if (l->size == 0)
        return insertStart(l, point);

    node = (Node *) malloc(sizeof(Node));

    if (!node)
        return 0;

    node->info = point;

    l->last->next = node;
    l->last = node;
    node->next = NULL;
    l->size++;

    return 1;
}

int getItem(List *l, int position, Point *point) {
    int i;
    Node *node;

    if (position < 0 || position >= l->size)
        return 0;

    i = 0;
    node = l->first;

    while (i < position) {
        node = node->next;
        i++;
    }

    *point = node->info;

    return 1;
}

int contains(List *l, Point point) {
    if (l->size == 0)
        return 0;

    Node *node = l->first;

    int i = 0;

    while (i < l->size) {

        if (isSamePoint(node->info, point))
            return 1;

        node = node->next;
        i++;
    }

    return 0;
}

int isEmptyList(List *l) {
    return l ? l->size == 0 : 1;
}

int getListSize(List *l) {
    return l ? l->size : 0;
}

void destroyList(List *l) {
    clearList(l);
    free(l);
}

void clearList(List *l) {
    int i;
    Node *node;

    for (i = 0; i < l->size; i++) {
        node = l->first;
        l->first = node->next;
        free(node);
    }

    l->size = 0;
}

const Point *peekList(List *l) {
    return l ? &l->last->info : NULL;
}
