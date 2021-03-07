#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "point.h"

typedef struct {
    Node *top;
    int size;
} Stack;

/**
 * Creates an empty Stack.
 */
Stack *createStack();

/**
 * Tests if the stack is empty
 *
 * @param stack the stack to be tested.
 * @return 1 if empty, 0 otherwise.
 */
int isEmptyStack(Stack *stack);

/**
 * Pushes an item onto the top of the stack.
 *
 * @return 1 if successful pushed, 0 otherwise.
 */
int push(Stack *, Point);

/**
 *  Removes the item at the top of this stack and stores it in the variable pointed by point
 *
 * @param stack
 * @param point variable where the removed item will be stored.
 * @return 1 if removed, 0 otherwise
 */
int pop(Stack *stack, Point *point);

/**
 * Retrieves and removes the first inserted element from the stack by simulating a queue.
 *
 * @param stack the stack containing the element to be retrieved.
 * @param auxiliary an auxiliary stack to manipulate a queue.
 * @param point the pointer to var where the retrieved element will be stored.
 * @return 1 if retrieved 0 otherwise
 */
int poll(Stack *stack, Stack *auxiliary, Point *point);

/**
 * Removes all elements from the stack and release the allocated memory.
 *
 * @param stack the stack to be destroyed.
 */
void destroyStack(Stack *stack);

/**
 * Removes all elements from the stack and sets its size to zero.
 *
 * @param stack the stack to be cleared.
 */
void clearStack(Stack *stack);

#endif // STACK_H_INCLUDED
