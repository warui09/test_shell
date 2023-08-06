#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "shell.h"

/* main - Handling command arguments
 * argc - Argument count
 * **argv - Pointer to the argument vector
 * Return Value: On success (0)
 *               Else on error (1)
*/

int main(int argc, char **argv[]){
    int i = 0;
    do {
        printf("%s ", argv[1]);
        i++;
    } while (argv[1]);
    printf("\n");
    return(0);
}

/*Command to free arguments*/
/*
 * free_args - frees an array 
 * @c : The array which is pointed to
 * 
 * Return : void
*/
void free_args(char **c)
{
	int index = 0;

	if (c == NULL)
	{
		return;
	}
	while (c[index])
	{
		free(c[index]);
		index++;
	}
	free(c);
}