#ifndef MAIN_H
#define MAIN_H

/* header files */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

/* macros */
#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* prototypes */
void prompt();
ssize_t get_input(char *buffer, size_t size);
void trim_whitespace(char *buffer);

#endif /* MAIN_H */