#include "main.h"

/**
 * shell_loop - shell loop responsible for getting input, parsing and
 *              executing commands
 * Return: exit status
 * 
*/

int shell_loop(int status,__attribute__((unused)) char **env)
{
    char *buffer;
    size_t size = BUFSIZE;
    ssize_t bytes_read;

    buffer = malloc(size);
    if (!buffer)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    bytes_read = get_input(buffer, size);
    if (bytes_read == -1)
    {
        perror("getline");
        free_memory(buffer);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read - 1] = '\0'; /* remove newline character */

    trim_whitespace(buffer);

    if (strcmp(buffer, "exit") == 0)
    {
        free_memory(buffer);
        exit(status);
    }
    else
    {
        printf("%s\n", buffer);
    }

    free_memory(buffer);

    return (status);
}
