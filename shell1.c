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
	/*char **environ;*/
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

			if (args[0] != NULL && strcmp(args[0], "exit") == 0)
			{
				printf("Disconnecting...\n");
				free(input);
				exit(0);
			}

		if (strcmp(args[0], "env") == 0)
		{
			/*env = environ;*/
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

			waitpid(pid, &status, 0);
		}
	}
	free(input);
	free(env);
	return (0);
}
