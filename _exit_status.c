#include "shell.h"

/**
 * exit_status - shell exiting with status code
 *
 * Return: nothing to return
 */

void _exit_status(char *args[], int i)
{
	char *input = NULL;

	if (i > 1)
	{
		/* If an argument is provided, try to convert it to an integer */
		int exit_status;

		if (sscanf(args[1], "%d", &exit_status) == 1)
		{
			printf("Exiting the shell with status: %d\n", exit_status);
			free(input); /* Free allocated memory */
			exit(exit_status); /* Terminate the shell with the specified status */
		}
		else
		{
			printf("Invalid exit status. Exiting the shell with status 1.\n");
			free(input); /* Free allocated memory */
			exit(1); /* Default to exit with status 1 */
		}
	}
}
