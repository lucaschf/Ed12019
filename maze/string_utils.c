#include <string.h>
#include <ctype.h>

#include "string_utils.h"

int endsWith(const char *s, const char *suffix) {
    char *comparator;
    char *anotherComparator;

    comparator = strstr(s, suffix);//gets the final suffixed string.

    if (!comparator)
        return 0;

    anotherComparator = strstr(comparator, suffix); //splits again to check if the suffix is at the end of last word.

    return !strcmp(suffix, anotherComparator);
}

int isOnlyNumbers(const char *s) {
    size_t i;

    for (i = 0; s[i] && s[i] != '\0' && s[i] != '\n'; i++) {
        if (!isdigit(s[i]))
            return 0;
    }

    return 1;
}