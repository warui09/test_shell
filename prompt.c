#include "main.h"

/**
 * propmt - print a prompt
 * 
 * Return: nothing
 * 
*/

void prompt()
{
    write(STDOUT_FILENO, "$ ", 2);
}