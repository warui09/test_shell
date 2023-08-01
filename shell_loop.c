#include "main.h"

/**
 * shell_loop - main shell loop responsible for reading input, parsing it and executing it
 * 
 * Return: exit status
 * 
*/

int shell_loop(buffer, status)
{
    ssize_t bytes_read;

    bytes_read = getline(buffer);
    if (bytes_read == -1)
    {
        perror("getline");
        exit(0);
    }

    /* remove new line character */

    parse_line(buffer);

    execute_command(buffer);

    free_tokens();

    return (status);

}