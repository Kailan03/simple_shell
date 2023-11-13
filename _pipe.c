#include "shell.h"
/**
 * _pipe - pipe command
 * @input: input
 * @env: pointer to environment variable
 * @lsPATH: where the file its executable
 *
 * Return: nothing
 */
void _pipe(char *input, char **env, char *lsPATH);
void _pipe(char *input, char **env, char *lsPATH)
{
	pid_t pid1 = fork();
	pid_t pid2 = fork();

	/* Split the command into two parts based on the pipe character */
	char *cmd1 = strtok(input, "|");
	char *cmd2 = strtok(NULL, "|");

	/* Tokenize each part to get the command and its arguments */
	char *args1[42];
	char *args2[42];
	int pipe_fd[2];

	tokenize_command(cmd1, args1);
	tokenize_command(cmd2, args2);

	/* Create two pipes */

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		free(input);
		exit(1);
	}


	/* Fork the first child process */
	if (pid1 == -1)
	{
		perror("fork");
		free(input);
		exit(1);
	}
	else if (pid1 == 0)
	{
		/* Close the write end of the pipe */
		close(pipe_fd[1]);
		/* Redirect stdin to read from the pipe */
		dup2(pipe_fd[0], STDIN_FILENO);

		/* Close the read end of the pipe */
		close(pipe_fd[0]);

		/* Execute the first command */
		executeCommand(args1, env, lsPATH);

		exit(0);
	}

	/* Fork the second child process */
	if (pid2 == -1)
	{
		perror("fork");
		free(input);
		exit(1);
	}
	else if (pid2 == 0)
	{
		/* Close the read end of the pipe */
		close(pipe_fd[0]);

		/* Redirect stdout to write to the pipe */
		dup2(pipe_fd[1], STDOUT_FILENO);

		/* Close the write end of the pipe */
		close(pipe_fd[1]);

		/* Execute the second command */
		executeCommand(args2, env, lsPATH);

		exit(0);
	}

	/* Close both ends of the pipe in the parent process */
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	/* Wait for both child processes to finish */
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
