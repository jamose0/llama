#ifndef LLAMA_SCANNER_H
#define LLAMA_SCANNER_H

#include <stdio.h>

#include "tokentype.h"

enum TokenType scanNextToken();

void initScanner(FILE *file);

#endif
