#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "maze.h"
#include "constants.h"

char *getErrorMessage(int errorCode) {
    switch (errorCode) {
        case 0:
            return AN_ERROR_HAS_OCCURRED;
        case ERR_CODE_INVALID_DIMENSIONS:
            return INVALID_BOARD_DIMENSIONS;
        case ERR_CODE_INVALID_BOARD_DOORS:
            return INVALID_BOARD_ENTRANCE_AND_EXIT;
        case ERR_CODE_MEMORY_ALLOCATION:
            return ALLOCATION_FAILURE;
        case ERR_CODE_INPUT_NOT_ACCEPTED:
            return INVALID_INPUT;
        case ERR_CODE_NO_WAY_IN:
            return NO_WAY_IN;
        case ERR_CODE_NO_WAY_OUT:
            return NO_WAY_OUT;
        case ERR_CODE_OUT_OF_BOUNDS:
            return OUT_OF_BOUNDS;
        case ERR_CODE_OBSTACLE_FOUND:
            return OBSTACLE_FOUND;
        case ERR_CODE_CANNOT_TURN_BACK:
            return CANNOT_TURN_BACK;
        case ERR_CODE_INVALID_SOURCE:
            return INVALID_INPUT;
        case ERR_CODE_INVALID_MAZE:
            return INVALID_MAZE;
        default:
            return NULL;
    }
}

char **createBoard(unsigned int lines, unsigned int columns) {
    char **board;
    unsigned int i;
    unsigned int j;

    if (columns == 0 || lines == 0)
        return 0;

    board = (char **) malloc(lines * sizeof(char *));

    if (board) {
        for (i = 0; i < lines; i++) {
            board[i] = (char *) malloc(columns * sizeof(char));

            if (!board[i]) {
                for (j = 0; j < i; j++)
                    free(board[j]);

                free(board);
                board = NULL;

                break;
            }
        }
    }

    return board;
}

int isSafe(Maze maze, Point point) {
    if (point.y >= maze.columns || point.x >= maze.rows || point.x < 0 || point.y < 0)
        return ERR_CODE_OUT_OF_BOUNDS;

    return maze.board[point.x][point.y] != OBSTACLE ? 1 : ERR_CODE_OBSTACLE_FOUND;
}

int isExitPoint(Maze maze, Point point) {
    return isSamePoint(maze.exit, point);
}

int isAcceptedCharEntry(char entry) {
    return entry == FREE_AREA || entry == OBSTACLE;
}

int isEdge(Maze maze, Point point) {
    return (point.x == 0 || point.x == maze.rows - 1) || (point.y == 0 || point.y == maze.columns - 1);
}

int isValidExit(Maze maze) {
    return isSafe(maze, maze.exit) == 1 && isEdge(maze, maze.exit);
}

int isValidEntrance(Maze maze) {
    return isSafe(maze, maze.entrance) == 1 && isEdge(maze, maze.entrance);
}

// Debug purposes only
void showMaze(Maze maze) {
    unsigned int i;
    unsigned int j;

    printf("\n%s: %d X %d", DIMENSIONS, maze.rows, maze.columns);
    printf("\n%s: %d %d", ENTRANCE, maze.entrance.x, maze.entrance.y);
    printf("\n%s: %d %d\n", EXIT, maze.exit.x, maze.exit.y);

    printf("\n  ");
    for (i = 0; i < maze.columns; i++)
        printf(" %d", i);

    for (i = 0; i < maze.rows; i++) {
        if (i < 10)
            printf("\n %d ", i);
        else
            printf("\n%d ", i);

        for (j = 0; j < maze.columns; j++) {
            if (j < 10)
                printf("%c ", maze.board[i][j]);
            else
                printf("%c  ", maze.board[i][j]);
        }
    }

    printf("\n");
}

// Debug purposes only
void logMovement(Point source, Point destination) {
    printf("\n%s: %s %s %d %d %s %d %d", INFO, TRYING_TO_MOVE, FROM, source.x, source.y, TO, destination.x,
           destination.y);
}

List *walkTroughMaze(Maze maze) {
    int visited[maze.rows][maze.columns];
    int result;
    int direction;
    int isCurrentPointOnList;

    List *path;
    Stack *steps;
    Stack *auxiliary;

    Point current;
    Point destination;

    memset(visited, 0, sizeof visited);

    steps = createStack();
    if (!steps)
        return NULL;

    auxiliary = createStack();
    if (!auxiliary) {
        destroyStack(steps);
        return NULL;
    }

    path = createList();
    if (!path) {
        destroyStack(auxiliary);
        destroyStack(steps);
        return NULL;
    }

    current = maze.entrance;
    current.distance = 0;
    current.parent = NULL;

    visited[current.x][current.y] = 1;
    push(steps, current);

    insertStart(path, current);

    const int movements[][2] = {
            {-1, 0},
            {0,  -1},
            {0,  1},
            {1,  0}
    };

    while (!isEmptyStack(steps)) {
        if (!poll(steps, auxiliary, &current))
            break;

        if (isExitPoint(maze, current)) {
            insertEnd(path, current);
            break;
        }

        isCurrentPointOnList = contains(path, current);
        for (direction = 0; direction < 4; direction++) {
            destination.x = current.x + movements[direction][0];
            destination.y = current.y + movements[direction][1];

            logMovement(current, destination);
            result = isSafe(maze, destination);

            if (result == 1) {
                result = !visited[destination.x][destination.y];
                printf(" - %s", result ? OK : CANNOT_TURN_BACK);

                if (result) {
                    if (!isCurrentPointOnList) {
                        insertEnd(path, current);
                        isCurrentPointOnList = 1;
                    }

                    visited[destination.x][destination.y] = 1;
                    destination.distance = current.distance + 1;
                    destination.parent = peekList(path);

                    push(steps, destination);
                }
            } else
                printf(" - %s", getErrorMessage(result));
        }
    }

    if (getItem(path, getListSize(path) - 1, &current)) {
        if (!isExitPoint(maze, current))
            clearList(path);
    }

    clearStack(steps);

    const Point *last = peekList(path);
    while (last) {
        push(steps, *last);
        last = last->parent;
    }

    clearList(path);

    while (pop(steps, &current))
        insertEnd(path, current);

    destroyStack(steps);
    destroyStack(auxiliary);

    return path;
}