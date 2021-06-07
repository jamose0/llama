#include "vector.h"

#include <stdlib.h>

void initStringVec(struct StringVec* sv)
{
    sv->len = 0;
    sv->cap = STRING_VEC_START_CAP;
    sv->vec = calloc(sizeof(char*), sv->cap);
}

void appendStringVec(struct StringVec* sv, char* a)
{
    if (sv->len >= sv->cap) {
        sv->cap *= 2;
        sv->vec = (char**)realloc(sv->vec, sv->cap);
    }

    sv->vec[sv->len++] = a;
}
