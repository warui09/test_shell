#include "main.h"

/**
 * free_memory - free allocated memory
 * @buffer: memory to free
 * 
 * Return: nothing
 * 
*/

void free_memory(char *buffer)
{
    free(buffer);
}