//
// Created by lucaschf on 25/09/2019.
//

#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

typedef struct {
    int key;
} element;

typedef struct Node {
    element info;
    struct Node *next;
    struct Node *prev;
} TNode;

typedef struct {
    int count;
    TNode *first;
    TNode *last;
} TList;

typedef TList *list;
typedef TNode *Node;

list newList();

int insertStart(list l, element e);

int insertEnd(list l, element e);

int insertAt(list l, element e, int index);

int removeItem(list l, int index, element *e);

int isEmptyList(list l);

int isFullList(list l);

int count(list l);

void clearList(list l);

void printList(list l);

#endif //CIRCULAR_LIST_H