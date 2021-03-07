#include <stdlib.h>
#include <stdarg.h>

#include "persistence.h"
#include "string_utils.h"
#include "constants.h"

FILE *openReadOnlyFile(const char *fileName) {
    return fopen(fileName, endsWith(fileName, EXT_TXT) ? "r" : "r+");
}

int readUnsignedInt(FILE *stream, unsigned int *out) {
    char strOut[12];
    char *next;

    if (!fscanf(stream, "%s", strOut))
        return 0;

    if (!isOnlyNumbers(strOut))
        return 0;

    *out = strtol(strOut, &next, 10);

    return 1;
}

int readUnsignedInts(FILE *stream, unsigned int *out, ...) {
    va_list args;
    unsigned int *pointer;
    int read = 0;

    va_start(args, out);

    pointer = out;
    while (pointer) {
        read = readUnsignedInt(stream, pointer);
        if (!read)
            break;

        pointer = va_arg(args, unsigned int *);
    }

    va_end(args);

    return read;
}