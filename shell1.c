#include "shell.h"

#define _GNU_SOURCE
#define BUFFER_SIZE 128
#define REALLOC_INCREMENT 128
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* some function and prototype s here */

#define BUFFER_SIZE 128
#define REALLOC_INCREMENT 128
int main(void);
int main(void)
{
	/* first */
	char *input = NULL;
	size_t len = 0;
	pid_t pid;
	char *args[42];
	int i = 0;
	char *token;
	ssize_t read;
	extern char **environ;
	char **env;

	while (1)
	{
		printf("SimpleShell> ");
		fflush(stdout);
		read = _getline(&input, &len, stdin);

		if (read == -1)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		token = strtok(input, " ");

		while (token != NULL && i < 41)
		{
			args[i++] = token;
			token = strtok(NULL, " ");

			/* i++; */
		}
		args[i] = NULL;

		if (i == 0)
		{
			printf("No command entered.\n");

			/* continue; */
		}

		if (strcmp(args[0], "exit") == 0)
		{
			if (i > 1)
			{
				int exit_status;

				if (sscanf(args[1], "%d", &exit_status) == 1)
				{
					printf("Exiting the shell with status: %d\n", exit_status);
					free(input);
					exit(exit_status);
				}
				else
				{
					printf("Invalid exit status. Exiting the shell with status 1.\n");
					free(input);
					exit(1);
				}
			}
			else
			{
				printf("Disconnecting...\n");
				free(input);
				exit(0);
			}
		}

		if (strcmp(args[0], "env") == 0)
		{
			env = environ;
			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
			continue;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve("/bin/ls", args, NULL) == -1)
			{
				perror("/bin/ls");
				exit(1);
			}
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}
	free(input);
	return (0);
}
