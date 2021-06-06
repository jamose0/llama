#ifndef LLAMA_TOKENTYPE_H
#define LLAMA_TOKENTYPE_H

/* Token types for Llama's scanner */
enum TokenType {
    TOK_EOF,

    /* Anything in all caps */
    TOK_NONTERM,

    /* Anything in all lowercase */
    TOK_TERM,

    /* ::= */
    TOK_PRODUCTION,
};

#endif
