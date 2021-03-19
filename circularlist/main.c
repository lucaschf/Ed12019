#include <stdio.h>
#include "lista.h"

int main() {
    list l;

    l = newList();

    element e;
    e.key = 10;

    insertStart(l, e);

    printList(l);
    e.key = 11;
    insertStart(l, e);
    e.key = 8;
    insertStart(l, e);

    printf("\n");
    printList(l);
    printf("\n");

    e.key = 0;
    insertEnd(l, e);
    printList(l);

    e.key = 9000;
    insertAt(l, e, 2);
    printf("\n");
    printList(l);

    removeItem(l, 2, &e);
    printf("\n");
    printList(l);

    printf("\nIS FULL: %d", isFullList(l));
    clearList(l);
    printf("\n\nCleaned\n");

    return 0;
}