/*
 *  The user must specify a 'term' variable at the beginning of an input file
 */

#include "scanner.h"
#include "tokentype.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    scanner.offset = 0;
}

static int matchNext(const char *s)
{
    for (scanner.offset = 0; scanner.offset < strlen(s); scanner.offset++) {
        if (s[scanner.offset] != fgetc(scanner.file))
            return 0;
    }

    if (isalpha(fgetc(scanner.file))) {
        scanner.offset++;
        return 0;
    } else {
        return 1;
    }
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

    switch (c) {
        case 't':
            if (matchNext("erm")) {
                printf("matched term\n");
                return TOK_K_TERM;
            }
            break;
        default:
            printf("matched none\n");
    }
    // Just a placeholder for now
    return TOK_EOF;
}
