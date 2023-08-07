#include "main.h"

char *search_path(const char *command) {
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

void execute_command(char **command, char **env) {
    char *full_path;
    pid_t pid;
    int status;

    if (command[0] == NULL) {
        return; /* Empty input, nothing to execute */
    }

    full_path = search_path(command[0]);
    if (full_path) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            /* Child process */
            if (execve(full_path, command, env) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process */
            waitpid(pid, &status, 0);
        }

        free(full_path);
    } else {
        fprintf(stderr, "Command not found: %s\n", command[0]);
    }
}
