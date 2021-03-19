//
// Created by lucaschf on 25/09/2019.
//

#include <stdlib.h>
#include<stdio.h>
#include "lista.h"

list newList() {
    list l;

    l = (list) malloc(sizeof(TList));

    if (l) {
        l->count = 0;
        l->first = NULL;
        l->last = NULL;
    }

    return l;
}

int insertStart(list l, element e) {
    TNode *p;

    p = (TNode *) malloc(sizeof(TNode));

    if (!p)
        return 0;

    p->info = e;

    if (!l->first) {
        p->next = p;

        l->first = p;
        l->last = p;
        l->last->prev = p;
        l->last->next = p;
    }

    p->prev = l->last;
    p->next = l->first;

    l->last->next = p;
    l->first->prev = p;
    l->first = p;
    l->count++;

    return 1;
}

int insertEnd(list l, element e) {
    TNode *p;

    if (l->count == 0)
        return insertStart(l, e);

    p = (TNode *) malloc(sizeof(TNode));

    if (!p)
        return 0;

    p->info = e;

    p->next = l->first;
    p->prev = l->last;

    l->first->prev = p;
    l->last->next = p;
    l->last = p;

    l->count++;

    return 1;
}

int insertAt(list l, element e, int index) {
    int i;
    TNode *aux;
    TNode *p;

    if (index < 1 || index > l->count + 1)
        return 0;

    if (index == 1)
        return insertStart(l, e);

    if (index == l->count + 1)
        return insertEnd(l, e);

    p = (TNode *) malloc(sizeof(TNode));

    if (!p)
        return 0;

    aux = l->first;

    if (index <= l->count / 2)
        for (i = 1; i < index; i++)
            aux = aux->next;
    else
        for (i = l->count; i >= index; i--)
            aux = aux->prev;

    p->info = e;
    p->prev = aux->prev;
    p->next = aux;
    aux->prev = p;
    p->prev->next = p;

    l->count++;

    return 1;
}

int removeItem(list l, int index, element *e) {
    TNode *p;

    if (!l || isEmptyList(l))
        return 0;

    if (index < 1 || index > count(l))
        return 0;

    p = l->first;

    if (index <= l->count / 2) {
        for (int i = 1; i < index; i++)
            p = p->next;
    } else {
        for (int i = l->count; i > 0; i--)
            p = p->prev;
    }

    if (p == l->first)
        l->first = p->next;

    *e = p->info;
    p->prev->next = p->next;
    p->next->prev = p->prev;

    l->count--;
    free(p);

    return 1;
}

int isEmptyList(list l) {
    return l ? l->count == 0 : 1;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"

int isFullList(list l) {
    TNode *p;

    p = (TNode *) malloc(sizeof(TNode));

    if (p) {
        free(p);
        return 0;
    }

    return 1;
}

#pragma clang diagnostic pop

int count(list l) {
    return l ? l->count : 0;
}

void clearList(list l) {
    int i;
    Node node;

    for (i = 0; i < l->count; i++) {
        node = l->first;
        l->first = node->next;
        free(node);
    }

    free(l);
}

void printList(list l) {
    TNode *p;
    p = l->first;

    for (int i = 0; i < l->count; i++) {
        printf("\nELEMENT: %d", p->info.key);
        p = p->next;
    }
}

