#include "shell.h"

/**
 * _cd - change directory function
 * @args: check for arguments
 *
 * Return: returns and integer
 */

int _cd(char *args[]);
int _cd(char *args[])
{
	char *dir;
	char *currentDir = getcwd(NULL, 0);
	char *newDir = getcwd(NULL, 0);

	/* If no argument is given to cd, interpret it like cd $HOME */
	if (args[1] == NULL)
	{
		dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		/* Handle cd - */
		dir = getenv("OLDPWD");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (1);
		}
	}
	else
	{
		dir = args[1];
	}

	if (currentDir == NULL)
	{
		perror("cd");
		return (1);
	}

	/* Save the current directory in OLDPWD */
	if (setenv("OLDPWD", currentDir, 1) != 0)
	{
		perror("cd");
		free(currentDir);
		return (1);
	}

	/* Change the current directory */
	if (chdir(dir) != 0)
	{
		perror("cd");
		free(currentDir);
		return (1);
	}

	/* Update the environment variable PWD */
	if (newDir == NULL)
	{
		perror("cd");
		free(currentDir);
		return (1);
	}

	if (setenv("PWD", newDir, 1) != 0)
	{
		perror("cd");
		free(currentDir);
		free(newDir);
		return (1);
	}

	free(currentDir);
	free(newDir);
	return(0);
}
