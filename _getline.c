#include "shell.h"
/**
 * _getline - it gets line commands from user
 * @lineptr: points to line
 * @n: points to bufsize
 * @stream: stdin
 *
 * Return: length of line
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line;
	char *new_line; 
	size_t bufsize = *n;
	size_t len = 0;
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos = 0;
	static size_t buffer_len = 0;
	
	if (lineptr == NULL || n == NULL)
        {
                return (-1);
        }
	line = *lineptr;
	while (1)
	{
		if (len + 1 >= bufsize) {
		bufsize += REALLOC_INCREMENT;
		new_line = (char *)realloc(line, bufsize);
		if (new_line == NULL)
		{
			free(line);
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
			line[len - 1] = '\0'; /* Null-terminate the line*/
			*lineptr = line;
			*n = bufsize;
			return (len); /* Return the length of the line (excluding newline)*/
		}
	}
}
					      if (len == 0) {
						              return (-1); /* No characters read*/
							          }

					          line[len] = '\0';
						      *lineptr = line;
						          *n = bufsize;
							      return (len);
  }
