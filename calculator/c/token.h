#ifndef TOKEN_H_INCLUDE
#define TOKEN_H_INCLUDE

typedef enum {
    BAD_TOKEN,
    NUMBER_TOKEN,
    ADD_OPERATOR_TOKEN,
    SUB_OPERATOR_TOKEN,
    MUL_OPERATOR_TOKEN,
    DIV_OPERATOR_TOKEN,
    END_OF_LINE_TOKEN
} TokenKind;

#define MAX_TOKEN_SIZE (100)

typedef struct {
    TokenKind kind; // token type
    double value; // used for number
    char str[MAX_TOKEN_SIZE]; //save the string value like '+', '12.3'
} Token;

#endif /* TOKEN_H_INCLUDE */
