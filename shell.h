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
/* some function and prototype s here */ 

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
