#include "main.h"

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