#ifndef shell_h
#define shell_h

#define _GNU_SOURCE
#define BUFFER_SIZE 128
#define REALLOC_INCREMENT 128
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/kernel.h>
#include <linux/string.h>

/* some function and prototype s here */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
void _exit_status(char *args[], int i);
void tokenize_command(char *cmd, char *args[]);
void _pipe(char *input, char **env, char *lsPATH);
void executeCommand(char *args[], char **env, char *lsPATH);

#endif
