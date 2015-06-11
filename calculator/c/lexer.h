#ifndef LEXER_H_INCLUDE
#define LEXER_H_INCLUDE

#include "token.h"

/**
 * get token from st_line.
 * @param token token to get result
 */
void get_token(Token *token);

/**
 * pass one line string to static variables.
 * @param line string value of a line
 */
void set_line(char *line);

#endif /* LEXER_H_INCLUDE */
