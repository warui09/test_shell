
#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>

/*Signal Handlers*/
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;


/**
 * struct builtins - Handles builtins
 * @env: First fxn
 * @exit: The other fxn
 * Function: Built-in cmds
 */
struct builtins
{
	char *env;
	char *exit;

} builtins;

/**
 * struct flags - Flags
 * @interactive: First member
 * Function: Handling Bool switch
 */
struct flags
{
	bool interactive;
} flags;

/*Our Current Main Functions*/
int main(int argc, char **argv, char **envp);

/*Working with standard library functions*/

int _strlen(const char *str);
char *_strchr(char *str, int c);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *first, const char *second, int n);
char *_strdup(char *str);

/*Handling Memory Management*/
void free_args(char **c);

/*Handling command Execution & Tokenization*/
char **token_maker(char *str);
void exec_cmd(char *command, char **args);

/*Handliing Buit-in command functions*/
void exiter(char **arr, char *line);
void print_env(void);
int is_builtin(char **command, char *line);

/*Handling of the Paths*/
char *pathcat(char *path, char *command); /*Concats a dir path with cmd name to form a file path*/
char *ver_paths(char **p, char *command); /*Verifies if commnds can be available in selected directories*/
char *_getpath(void);

/*Handling our main helpers*/
int check_type(char **args, char *line); /*Used in checking the type of commands upon input*/
void init_shell(void); /*Handles Initialization tasks of the shell*/
void checkD(char *buf, int len);
void checkC(int c); /*Handles the function to check over a specific char 'c'*/

#endif /* SHELL_H */