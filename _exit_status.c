#include "shell.h"
#include <linux/kernel.h>
#include <linux/string.h>

/**
 * _exit_status - shell exiting with status code
 * @args: arguments to handle
 * @i: exit status code
 *
 * Return: nothing to return
 */

void _exit_status(char *args[], int i);
void _exit_status(char *args[], int i)
{
	char *input = NULL;

	if (i > 1)
	{
		char *endptr;
		int exit_status = strtol(args[1], &endptr, 10);

		/* if (sscanf(args[1], "%d", &exit_status) == 1) */
		/* if (strtof32(args[1], 10, &exit_status) == 0) */
		if (*endptr == '\0')
		{
			printf("Exiting the shell with status: %d\n", exit_status);
			free(input); /* Free allocated memory */
			exit(exit_status); /* Terminate the shell with the specified status */
		}
		else
		{
			/* perror(__progname); */
			/* fprintf(stderr, "%s: %d: exit: Illegal number: %s\n", */
					/* __progname, i, args[1]); */
			printf("Invalid exit status. Exiting the shell with status 1.\n");
			free(input); /* Free allocated memory */
			exit(1); /* Default to exit with status 1 */
		}
	}
}
