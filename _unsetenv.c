#include "shell.h"
/**
 * _unsetenv - function to unset environment variable
 * @args: an array of arguments
 *
 * Return: void
 */
int _unsetenv(char *args[])
{
	if (args[1] != NULL && args[2] == NULL)
	{
		if (unsetenv(args[1]) == -1)
		{
			perror("unsetenv");
			fprintf(stderr, "unsetenv: Failed to unset the environment variable.\n");
			return (1);
		}
	}
	else
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}
	return (0);
}
