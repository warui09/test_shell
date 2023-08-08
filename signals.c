#include "main.h"

/**
 * handle_sigint - handle sigint
 * 
*/

void handle_sigint(int sig)
{
    if (sig == SIGINT)
    {
        write(STDOUT_FILENO, "\n", 1);
        prompt();
    }
}
