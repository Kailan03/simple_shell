#include "shell.h"
/**
 * tokenize_command - tokenize command function
 * @cmd: command to tokenize
 * @args: arguments to include
 *
 * Return: nothing
 */
void tokenize_command(char *cmd, char *args[])
{
	const char delimiters[] = " \t\n";
	char *token = strtok(cmd, delimiters);
	int i = 0;

	while (token != NULL && i < 42)
	{
		args[i++] = token;
		token = strtok(NULL, delimiters);
	}

	args[i] = NULL;
}
