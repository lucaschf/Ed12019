#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <stdlib.h>

#include "list.h"
#include "stack.h"


/**
 * Specifies constants defining the error codes.
 */
typedef enum {
    ERR_CODE_INVALID_DIMENSIONS = -1,
    ERR_CODE_INVALID_BOARD_DOORS = -2,
    ERR_CODE_MEMORY_ALLOCATION = -3,
    ERR_CODE_INPUT_NOT_ACCEPTED = -4,
    ERR_CODE_NO_WAY_IN = -5,
    ERR_CODE_NO_WAY_OUT = -6,
    ERR_CODE_OUT_OF_BOUNDS = -7,
    ERR_CODE_OBSTACLE_FOUND = -8,
    ERR_CODE_CANNOT_TURN_BACK = -9,
    ERR_CODE_INVALID_SOURCE = -10,
    ERR_CODE_INVALID_MAZE = -11,
} ErrorCode;

/**
 * The maze structure
 */
typedef struct {
    Point entrance;
    Point exit;
    char **board;
    unsigned int rows;
    unsigned int columns;
} Maze;

/**
 * Gets the error message based on a given error code.
 *
 * @param errorCode the code of error occurred.
 * @return a string with a description of error.
 */
char *getErrorMessage(int errorCode);

/**
 * Tries to create a maze board
 *
 * @param lines the lines number of the matrix.
 * @param columns the columns number of the matrix.
 * @return a board if successful created, NULL otherwise.
 */
char **createBoard(unsigned int lines, unsigned int columns);

/**
 * Checks if a point is a safe place to move by checking that it is within bounds and is a clear area.
 *
 * @param maze the maze where the movement is performed.
 * @param point the point to be checked.
 * @return 1 if it is a free area, an ErrorCode otherwise.
 */
int isSafe(Maze maze, Point point);

/**
 * Checks if the point is the exit of the maze
 *
 * @param maze the maze where the movement is performed.
 * @param point the point to be checked.
 * @return 1 if is the exit, 0 otherwise.
 */
int isExitPoint(Maze maze, Point point);

/**
 * Checks for an acceptable character
 *
 * @param entry the character to be checked.
 * @return 1 if is acceptable, 0 otherwise.
 */
int isAcceptedCharEntry(char entry);

/**
 * Checks if the maze has a valid exit
 *
 * @param maze the maze to be checked.
 * @return 1 if is a valid exit, 0 otherwise.
 */
int isValidExit(Maze maze);

/**
 * Checks if the maze has a valid entrance
 *
 * @param maze the maze to be checked.
 * @return 1 if is a valid entrance, 0 otherwise.
 */
int isValidEntrance(Maze maze);

/// Debug purposes only
/// Shows the maze data
void showMaze(Maze maze);

/**
 * Displays the movement to be performed.
 *
 * @param source the origin point.
 * @param destination the destination point.
 */
void logMovement(Point source, Point destination);

/**
 * Search the exit route of the maze always looking for the shortest way.
 *
 * @param maze the maze to be crossed.
 * @return a list with the shortest path if found, an empty list if no route found or NULL if the list allocation fails.
 */
List *walkTroughMaze(Maze maze);

#endif //MAZE_MAZE_H


