#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "string_utils.h"
#include "constants.h"
#include "maze.h"
#include "persistence.h"

/**
 * Checks if the program syntax is correct.
 *
 * @param argc the parameters count.
 * @param argv the parameters.
 * @return 1 if syntax is correct, 0 otherwise.
 */
int checkSyntax(int argc, char **argv);

/**
 * Reads the maze data from the file
 *
 * @param maze pointer to a maze where the data will be stored.
 * @param source the file containing the maze data.
 * @return 1 if success, a error code otherwise.
 */
int readMazeData(Maze *maze, FILE *source);

/**
 * Displays the result in the console and exports the output to the file.
 *
 * @param maze the maze data.
 * @param path the found path.
 * @param output the file in which the output will be generated.
 */
void onExitFound(Maze maze, List *path, FILE *output);

int main(int argc, char **argv) {
    FILE *fInput;
    FILE *fOutput;

    Maze maze;

    List *path;

    char *errorMessage;

    setlocale(LC_ALL, "pt-BR");

    if (!checkSyntax(argc, argv))
        return EXIT_FAILURE;

    if (!(fInput = openReadOnlyFile(argv[1]))) {
        printf("\n%s: %s", ERR, UNABLE_TO_OPEN_FILE);
        return EXIT_FAILURE;
    }

    if (!(fOutput = fopen(OUTPUT_FILE_NAME, "w+"))) {
        printf("\n%s: %s", ERR, UNABLE_TO_CREATE_OUTPUT_FILE);
        return EXIT_FAILURE;
    }

    errorMessage = getErrorMessage(readMazeData(&maze, fInput));

    if (errorMessage)
        printf("\n%s: %s", ERR, errorMessage);
    else {
        showMaze(maze);
        path = walkTroughMaze(maze);

        if (path) {
            if (!isEmptyList(path)) {
                onExitFound(maze, path, fOutput);
            } else
                printf("\n%s: %s", INFO, SOLUTION_DOES_NT_EXIST);

            destroyList(path);
        } else
            printf("\n%s: %s", ERR, ALLOCATION_FAILURE);
    }

    fclose(fInput);
    fclose(fOutput);

    return EXIT_SUCCESS;
}

int checkSyntax(int argc, char **argv) {
    if (argc != 2) {
        printf("\n%s: %s %s", ERR, INCORRECT_SYNTAX, INFORM_THE_INPUT_FILE);
        return 0;
    }

    if (!endsWith(argv[1], EXT_TXT)) {
        printf("\n%s: %s %s", ERR, INCORRECT_SYNTAX, ONLY_TEXT_FILES_ARE_ACCEPTED);
        return 0;
    }

    return 1;
}

int readMazeData(Maze *maze, FILE *source) {
    unsigned int i;
    unsigned int j;

    Point *entrance;
    Point *exit;

    if (!source)
        return ERR_CODE_INVALID_SOURCE;

    if (!maze)
        return ERR_CODE_INVALID_MAZE;

    entrance = &maze->entrance;
    exit = &maze->exit;

    rewind(source);

    // reading the board dimensions
    if (!readUnsignedInts(source, &maze->rows, &maze->columns, NULL))
        return ERR_CODE_INVALID_DIMENSIONS;

    // creating the board matrix
    if (!(maze->board = createBoard(maze->rows, maze->columns)))
        return ERR_CODE_MEMORY_ALLOCATION;

    // reading the entry and exit points
    if (!readUnsignedInts(source, &entrance->x, &entrance->y, &exit->x, &exit->y, NULL))
        return ERR_CODE_INVALID_BOARD_DOORS;

    // reading the board matrix
    for (i = 0; i < maze->rows; i++) {
        fscanf(source, "%s\n", &maze->board[i][0]);

        for (j = 0; j < maze->columns; j++) {
            if (!maze->board[i][j] || !isAcceptedCharEntry(maze->board[i][j]))
                return ERR_CODE_INPUT_NOT_ACCEPTED;
        }
    }

    // checking if there is an entrance point
    if (!isValidEntrance(*maze))
        return ERR_CODE_NO_WAY_IN;

    // checking if there is an exit point
    if (!isValidExit(*maze))
        return ERR_CODE_NO_WAY_OUT;

    return 1;
}

void onExitFound(Maze maze, List *path, FILE *output) {
    Point point;

    unsigned int i;
    unsigned int j;

    int index;

    printf("\n\n%s: %s\n\n", INFO, FOUND_A_SOLUTION);

    const Point *p = peekList(path);

    printf("%d %s %s \n%s '%c' %s\n\n", p->distance, STEPS, ARE_NECESSARY_TO_CROSS_THE_MAZE,
           SEE_THE_SEQUENCE_MARKED_WITH, VISITED_AREA, IN_MATRIX_BELOW);
    fprintf(output, "%d %s %s\n%s '%c' %s\n\n", p->distance, STEPS, ARE_NECESSARY_TO_CROSS_THE_MAZE,
            SEE_THE_SEQUENCE_MARKED_WITH, VISITED_AREA, IN_MATRIX_BELOW);

    for (index = 0; index < getListSize(path); index++) {
        if (getItem(path, index, &point)) {
            maze.board[point.x][point.y] = VISITED_AREA;
        }
    }

    for (i = 0; i < maze.rows; i++) {
        for (j = 0; j < maze.columns; ++j) {
            fprintf(output, "%c ", maze.board[i][j]);
            printf("%c ", maze.board[i][j]);
        }

        printf("\n");
        fprintf(output, "\n");
    }

    printf("\n%s:\n", ESCAPE_ROUTE);
    fprintf(output, "\n%s:\n", ESCAPE_ROUTE);
    for (index = 0; index < getListSize(path); index++) {
        if (getItem(path, index, &point)) {
            printf("\n%d %d", point.x, point.y);
            fprintf(output, "\n%d %d", point.x, point.y);
        }
    }

    printf("\n\n%s: %s %s", INFO, PATH_SAVED_IN, OUTPUT_FILE_NAME);
}


