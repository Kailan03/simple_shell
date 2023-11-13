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
	char *args[42];
	int i = 0;
	char *token;
	ssize_t read;
	char **env;
	char *lsPATH;

	env = environ;
	lsPATH = "/bin/ls";
	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Check if running in interactive mode */
			printf("$ ");
		fflush(stdout);
		read = getline(&input, &len, stdin);

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

		/* check for pipe */
		if (strchr(input, '|') != NULL)
		{
			_pipe(input, env, lsPATH);
			continue;
		}
		/*.................*/

		token = _strtok(input, " ");

		while (token != NULL && i < 41)
		{
			args[i++] = token;
			token = _strtok(NULL, " ");
		}
		args[i] = NULL;
		if (i == 0)
		{
			continue; /*no command entered */
		}

			if (args[0] != NULL && strcmp(args[0], "exit") == 0)
			{
				_exit_status(args, i);
				/* printf("Disconnecting...\n"); */
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

		executeCommand(args, env, lsPATH);

		i = 0;
	}
	free(input);
	return (0);
}
