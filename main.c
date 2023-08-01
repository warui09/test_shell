#include "main.h"

/**
 * main - main function
 * @env: environment
 * 
 * Return: 0
 * 
*/

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
    char buffer[BUFSIZE];
    char tokens[TOK_BUFSIZE];
    int status = 0;

    if (isatty(STDIN_FILENO))
    {
        while (1)
        {
            prompt();
            shell_loop(buffer, tokens);
        }
    }
    else
    {
        shell_loop(buffer, tokens);
    }

    free_tokens();

    return (status);
}