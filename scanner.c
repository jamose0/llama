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
    while (scanner.offset < strlen(s)) {
        if (s[scanner.offset++] != fgetc(scanner.file)) {
            return 0;
        }
    }

    return 1;
}

static int matchKw(const char *s)
{
    if (matchNext(s)) {
        if (isalpha(fgetc(scanner.file))) {
            scanner.offset++;
            return 0;
        } else {
            return 1;
        }
    }

    return 0;
}

static void resetToken()
{
    fseek(scanner.file, -(scanner.offset), SEEK_CUR);
    scanner.offset = 0;
}

static enum TokenType matchName()
{
    return TOK_NAME;
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
    scanner.offset++;

    printf("%c\n", c);

    switch (c) {
        case 't':
            if (matchKw("term")) {
                printf("matched term\n");
                return TOK_K_TERM;
            } else {
                resetToken();
                break;
            }
            break;
        case ':':
            if (matchNext(":=")) {
                printf("Matched '::='\n");
                return TOK_PRODUCTION;
            } else {
                resetToken();
                break;
            }
        default:
            printf("matched none\n");
    }

    printf("%c\n", fgetc(scanner.file));
    // Just a placeholder for now
    return TOK_EOF;
}
