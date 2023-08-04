#include "main.h"

/*
 *search_path - Search for the absolute path to the command
 * @command: Command to search complete path
 * Return - Full path of the command if it exists
*/

char *search_path(char *command){
    char *path_env = getenv("PATH");
    char *path, *path_copy, *full_path;

    if(!path_env){
        fputs("FATAL: Could not retrieve PATH!\n", stderr);
        return(NULL);
    }

    path_copy = (char *)malloc(strlen(path_env) +1);
    if (!path_copy){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(path_copy, path_env);
    path = strtok(path_copy, ":");
    do {
        full_path = (char *)malloc(strlen(path) + strlen(command) + 2);
        if (!full_path){
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        sprintf(full_path, "%s/%s", path, command);
        if (access(full_path, X_OK) == 0){
            free(path_copy);
            return (full_path);
        }
        free(full_path);
        path = strtok(NULL, ":");
    }while (path != NULL);

    free (path_copy);
    return NULL;
}