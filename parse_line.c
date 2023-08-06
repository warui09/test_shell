#include "main.h"

/**
 * parse_line - parse a line of input
 * @buffer: address of the line of input
 * 
 * Return: array of strings containing the parsed input
 * 
*/

char **parse_line(char *buffer)
{
    char *token;
    int token_idx = 0;
    char **tokens = (char **)malloc(TOK_BUFSIZE * sizeof(char *));

    if (!tokens)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(buffer, TOK_DELIM);

    while (token && token_idx < TOK_BUFSIZE - 1)
    {
        tokens[token_idx] = (char *)malloc(strlen(token) + 1);
        if (!tokens[token_idx])
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(tokens[token_idx], token);
        token_idx++;
        token = strtok(NULL, TOK_DELIM);
    }

    tokens[token_idx] = NULL;
    return (tokens);
}
