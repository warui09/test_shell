#include "main.h"

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
