#include "main.h"

/**
 * get_input - read a line of input from the standard input
 * @buffer: buffer to write the input to
 * 
 * Return: number of bytes read
 * 
*/

ssize_t get_input(char *buffer, size_t size)
{
    return (getline(&buffer, &size, stdin));
}