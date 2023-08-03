#include "main.h"

void free_tokens(char **tokens)
{
    int i;
    
    if (!tokens)
        return;

    for (i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }

    free(tokens);
}
