#include <stdlib.h>

#include "stack.h"

Stack *createStack() {
    Stack *stack;

    stack = (Stack *) malloc(sizeof(Stack));

    if (stack) {
        stack->top = NULL;
        stack->size = 0;
    }

    return stack;
}

int push(Stack *stack, Point point) {
    Node *node;

    node = (Node *) malloc(sizeof(Node));

    if (!node)
        return 0;

    node->info = point;
    node->next = stack->top;
    stack->top = node;
    stack->size++;

    return 1;
}

int pop(Stack *stack, Point *point) {
    Node *node;

    if (!stack->size)
        return 0;

    node = stack->top;
    *point = node->info;

    stack->top = stack->top->next;
    stack->size--;
    free(node);

    return 1;
}

int poll(Stack *stack, Stack *auxiliary, Point *point) {
    Point p;
    int result;

    if (!stack || !auxiliary)
        return 0;

    clearStack(auxiliary);

    if (stack->size == 1)
        return pop(stack, point);

    while (pop(stack, &p))
        push(auxiliary, p);

    result = pop(auxiliary, point);

    while (pop(auxiliary, &p))
        push(stack, p);

    return result;
}

int isEmptyStack(Stack *stack) {
    return !stack->top;
}

void destroyStack(Stack *stack) {
    clearStack(stack);

    free(stack);
}

void clearStack(Stack *stack) {
    Node *node;

    while (stack->top) {
        node = stack->top;
        stack->top = stack->top->next;
        free(node);
    }

    stack->size = 0;
}