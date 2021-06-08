/*
 *  The user must specify a 'term' variable at the beginning of an input file
 */

#include "scanner.h"
#include "tokentype.h"

#include <stdio.h>
#include <stdlib.h>

struct Scanner {
    FILE *file;

    /* offset from beginning of last token */
    int offset;
};

struct Scanner scanner;

void initScanner(FILE *file)
{
    if (!file) {
        fprintf(stderr, "Could not open file! terminating...\n");
        exit(1);
    }

    scanner.file = file;
}

/* Scans the next token on input */
enum TokenType scanNextToken()
{
    int c;

    /* Skip whitespace. After loop, c should have the first char that is not
     * whitespace */
    do {
        c = fgetc(scanner.file);
    } while (c == ' ' || c == '\n' || c == '\t');

    printf("%c\n", c);
    // Just a placeholder for now
    return TOK_EOF;
}
