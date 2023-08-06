#include "main.h"

/**
 * is_whitespace - check if a character is whitespace
 * @c: character to check
 * 
 * Return: 1 if character is whitespace, 0 otherwise
 * 
*/

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t');
}

/**
 * trim_whitespace - remove starting and trailing white spaces from the input string
 * 
 * Return: nothing
*/

void trim_whitespace(char *buffer)
{
    char *end;

    /* Remove leading whitespace */
    while (is_whitespace(*buffer))
    {
        buffer++;
    }

    /* Remove trailing whitespace */
    end = buffer + strlen(buffer) - 1;
    while (end > buffer && is_whitespace(*end))
    {
        end--;
    }

    /* Null-terminate the trimmed string */
    *(end + 1) = '\0';
}