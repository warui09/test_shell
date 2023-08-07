#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "shell.h"

/* main - Handling command arguments
 * argc - Holds number of command line arguments
 * **argv - Pointer to array of pointers
 * Return Value: On success (0)
 *               Else on error (1)
*/

int main(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");
	return 0;
}

/*Command to free arguments*/
/*
 * free_args - Takes pointer to the array of pointers as its parameter
 * @c : The array which is pointed to
 * It will iterate through through the array of pointers until it
 * 		encounters a NULL pointer indicating the end of an array
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