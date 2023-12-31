#include "shell.h"
/**
 * _getline - it gets line commands from user
 * @lineptr: points to line
 * @n: points to bufsize
 * @stream: stdin
 *
 * Return: length of line
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line;
	char *new_line;
	static size_t buffer_len;
	static size_t buffer_pos;
	static char buffer[BUFFER_SIZE];
	size_t len = 0;
	size_t bufsize = *n;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}
	line = *lineptr;

	while (1)
	{
		if (len + 1 >= bufsize)
		{
			bufsize += REALLOC_INCREMENT;
			new_line = (char *)realloc(line, bufsize);
			if (new_line == NULL)
			{
				free(line);
				*lineptr = NULL;
				return (-1);
			}
			line = new_line;
		}
		if (buffer_pos == buffer_len)
		{
			buffer_len = read(fileno(stream), buffer, BUFFER_SIZE);
			if (buffer_len <= 0)
			{
				break;
			}
			buffer_pos = 0;
		}

		while (buffer_pos < buffer_len)
		{
			line[len++] = buffer[buffer_pos++];

			if (line[len - 1] == '\n')
			{
				line[len - 1] = '\0'; /* Null-terminate the line */
				*lineptr = line;
				*n = bufsize;
				return (len - 1); /* Return the length of the line (excluding newline) */
			}
		}
	}

	if (len == 0)
	{
		return (-1);
	}
	line[len - 1] = '\0'; /* Null-terminate the line*/
	*lineptr = line;
	*n = bufsize;
	return (len); /* Return the length of the line (excluding newline)*/
}
