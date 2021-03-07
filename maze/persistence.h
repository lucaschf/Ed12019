#ifndef MAZE_PERSISTENCE_H
#define MAZE_PERSISTENCE_H

#include <stdio.h>

/**
 * Opens a  file in read mode
 *
 * @param fileName the name of the file.
 * @return A pointer to FILE if successful opened, NULL otherwise.
 */
FILE *openReadOnlyFile(const char *fileName);

/**
 * Reads an unsigned int from a stream
 *
 * @param stream
 * @param out pointer to unsigned int where the read value will be stored.
 * @return 1 if successful read, 0 otherwise.
 */
int readUnsignedInt(FILE *stream, unsigned int *out);

int readUnsignedInts(FILE *stream, unsigned int *out, ...);

#endif //MAZE_PERSISTENCE_H
