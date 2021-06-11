#ifndef LLAMA_TOKENTYPE_H
#define LLAMA_TOKENTYPE_H

/* Token types for Llama's scanner */
enum TokenType {
    TOK_EOF = 0,

    TOK_NAME,

    /* keyword */
    TOK_K_TERM,

    /* ::= */
    TOK_PRODUCTION,

    TOK_ERR,
};

#endif
