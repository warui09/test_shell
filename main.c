#include "main.h"

/**
 * main - main function
 * @env: environment
 * 
 * Return: 0
 * 
*/

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
    int status = 0;

    if (isatty(STDIN_FILENO))
    {
        while (1)
        {
            prompt();
            shell_loop(status, env);
        }
    }
    else
    {
        shell_loop(status, env);
    }

    return (status);
}