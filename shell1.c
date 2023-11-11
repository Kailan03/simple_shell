#include "shell.h"
/**
 * main - Entry point
 *
 * Return: 0 for success
 */

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
	char **env;

	env = environ;
	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Check if running in interactive mode */
			printf("$ ");
		fflush(stdout);
		read = _getline(&input, &len, stdin);

		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			break;
		}
		if (input[0] == '\n' && (isatty(STDIN_FILENO)))
		{
			continue; /* don't process empty input */
		}
		input[strcspn(input, "\n")] = '\0';
		token = _strtok(input, " ");

		while (token != NULL && i < 41)
		{
			args[i++] = token;
			token = _strtok(NULL, " ");
		}
		args[i] = NULL;

			if (args[0] != NULL && strcmp(args[0], "exit") == 0)
			{
				printf("Disconnecting...\n");
				free(input);
				exit(0);
			}

		if (strcmp(args[0], "env") == 0)
		{
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
			free(input);
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve("/bin/ls", args, NULL) == -1)
			{
				perror("/bin/ls");
				free(input);
				exit(1);
			}
		}
		else
		{
			int status;
			/* free(input); */
			waitpid(pid, &status, 0);
		}
		i = 0;
	}
	free(input);
	return (0);
}
