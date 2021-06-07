/*
 *  LL(1) Parser Generator!
 *  Generates a table driven LL(1) parser.
 */

#include "scanner.h"
#include "tokentype.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    enum TokenType t = scanNextToken();
    printf("%d\n", t);
    printf("llama parser generator by JM!\n");

    initScanner(fopen("test", "r"));
    return 0;
}
