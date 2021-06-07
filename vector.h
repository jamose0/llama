/*
 * Vectors
 */
#ifndef LLAMA_VECTOR_H
#define LLAMA_VECTOR_H

/* A string vector will start with a capacity defined here */
#define STRING_VEC_START_CAP 8

/* Vector of strings. Can be used to represent FIRST and FOLLOW sets as well
 * as parts of parse rules */
struct StringVec {
    char **vec;
    int len;
    int cap;
};

/* Sets cap to STRING_VEC_START_CAP and len to 0 */
void initStringVec(struct StringVec *sv);

/* Appends a to sv */
void appendStringVec(struct StringVec *sv, char *a);

#endif
