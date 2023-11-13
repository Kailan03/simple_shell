#include "shell.h"
/**
 * executeCommand - main command execution here
 * @args: arguments to factor in
 * @env: environment variable to be included
 * @lsPATH: path to find the execution
 *
 * Return: nothing
 */
void executeCommand(char *args[], char **env, char *lsPATH)
{
	pid_t pid = fork();
	char *input = NULL;

	if (pid == -1)
	{
		perror("fork");
		free(input);
		exit(1);
	}
	else if (pid == 0)
	{
		if (access("/bin/ls", X_OK) == 0)
		{
			if (execve(lsPATH, args, env) == -1)
			{
				perror("execve");
				free(input);
				exit(1);
			}
		}
		else
		{
			write(2, "ls is not accessible\n", 22);
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
}
