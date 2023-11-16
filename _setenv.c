#include "shell.h"
/**
 * _setenv - set environment variable function
 * @args: array of arguments
 *
 * Return: void
 */
int _setenv(char *args[])
{
	if (args[1] != NULL && args[2] != NULL && args[3] == NULL)
	{
		if (setenv(args[1], args[2], 1) == 1)
		{
			perror("setenv");
			fprintf(stderr, "setenv: Failed to set the environment variable.\n");
			return (1);
		}
	}
	else
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (0);
	}
	return (0);
}
