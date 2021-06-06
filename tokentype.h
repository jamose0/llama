#ifndef LLAMA_TOKENTYPE_H
#define LLAMA_TOKENTYPE_H

/* Token types for Llama's scanner */
enum TokenType {
    TOK_EOF,

    TOK_NONTERM,

    TOK_TERM,

    /* ::= */
    TOK_PRODUCTION,
};

#endif
