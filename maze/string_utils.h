#ifndef MAZE_STRING_UTILS_H
#define MAZE_STRING_UTILS_H

#include <string.h>

/**
 * Checks whether the string is ending with user-specified substring or not. Based on this comparison it will return 1 or 0.
 *
 * @param s the string to be checked.
 * @param suffix this is a suffix.
 * @return 1 if character sequence supplied in "suffix" matches the end sequence of the string, 0 otherwise.
 */
int endsWith(const char *s, const char *suffix);

/**
 * Checks if the sequence consists of numbers only.
 *
 * @param s the string to be checked.
 * @return 1 if is only numbers, 0 otherwise.
 */
int isOnlyNumbers(const char *s);

#endif //MAZE_STRING_UTILS_H
