#include "main.h"

/**
 * propmt - prints a prompt
 * 
 * Return: nothing
 * 
*/

void prompt()
{
    write(STDOUT_FILENO, "$ ", 2);
}