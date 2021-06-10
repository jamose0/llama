#ifndef LLAMA_SCANNER_H
#define LLAMA_SCANNER_H

#include <stdio.h>

#include "tokentype.h"

/* The maximum lenght (in chars) of a token */
#define MAX_TOKEN_LENGTH 1000

enum TokenType scanNextToken();

void initScanner(FILE *file);

#endif
