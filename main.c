/*
 *  LL(1) Parser Generator!
 *  Generates a table driven LL(1) parser.
 */

#include "scanner.h"
#include "tokentype.h"

#include <stdio.h>
#include <stdlib.h>

extern char lltext[];

int main(int argc, char *argv[])
{
    printf("llama parser generator by JM!\n");

    initScanner(fopen("test", "r"));
    enum TokenType t = scanNextToken();
    printf("lltext = %s\n", lltext);
    printf("%d\n", t);
    return 0;
}
