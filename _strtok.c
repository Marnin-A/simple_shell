#include <string.h>
#include "shell.h"

/**
 * _strtok -  breaks a string into a sequence of zero or more nonempty tokens.
 *
 * @str: the string to be parsed.
 * @delim: argument specifies a set of bytes that delimit the tokens in
 * the parsed string.
 *
 * Return: a pointer to a null-terminated string
 */

char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start, *token_end;

	if (str != NULL)
		next_token = str;

	if (next_token == NULL || *next_token == '\0')
		return (NULL);

	token_start = next_token;
	token_end = strpbrk(next_token, delim);

	if (token_end != NULL)
	{
		*token_end = '\0';
		next_token = token_end + 1;
	}
	else
	{
		next_token = NULL;
	}

	return (token_start);
}
