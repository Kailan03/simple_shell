#include "shell.h"
/**
 * _strtok - this function tokenizes
 * @str: the string to tokenize
 * @delim: delimiter to separate tokens
 *
 * Return:  a character pointer is returned
 */
char *_strtok(char *str, const char *delim)
{
	/* char *token; */
	static char *last;
	char *end;

	if (str == NULL)
		str = last;

	if (str == NULL)
		return (NULL);
	/* Skip leading delimiters */
	str += strspn(str, delim);

	/* If we've reached the end of the string, return NULL */
	if (*str == '\0')
	{
		last = NULL;
		return (NULL);
	}

	/* Find the end of the token */
	end = str + strcspn(str, delim);
	if (*end != '\0')
	{
		*end = '\0';
		last = end + 1;
	}
	else
	{
		last = NULL;
	}
	return (str);
}
