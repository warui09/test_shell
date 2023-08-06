#include "main.h"

/**
 * shell_loop - main shell loop responsible for reading input, parsing it and executing it
 * @env: environment
 * 
 * Return: exit status
 * 
*/

int shell_loop(status, env)
{
    char buffer[BUFSIZE];
    char **tokens;
    ssize_t bytes_read;

    bytes_read = get_input(buffer);

    if (bytes_read == -1)
    {
        perror("could not read input");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read - 1] = '\0'; /* Remove the newline character */

    tokens = parse_line(buffer);
        
    execute_command(tokens, env);

    free_tokens(tokens);

    return (status);
}