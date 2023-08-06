#include "main.h"

/**
 * shell_loop - shell loop responsible for getting input, parsing and
 *              executing commands
 * Return: exit status
 * 
*/

int shell_loop(int status, char **env)
{
    char *buffer = NULL;
    size_t size = BUFSIZE;
    ssize_t bytes_read;

    if (!env)
    {
        perror("env");
        exit(EXIT_FAILURE);
    }

    bytes_read = get_input(buffer, size);
    if (bytes_read == -1)
    {
        perror("getline");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read - 1] = '\0'; /* remove newline character */

    trim_whitespace(buffer);

    printf("%s\n", buffer);

    return (status);
}
