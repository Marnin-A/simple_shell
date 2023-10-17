#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - read a line of text from the stdin.
 *
 * Return: if success the pointer to the line retrieved,
 * if failed NULL.
 */

char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	int position = 0, buffer_size = 0, line_length = 0;
	char *line = NULL, current_char;

	while (1)
	{
		if (position >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)
				return (NULL);
			position = 0;
		}

		current_char = buffer[position++];
		if (current_char == '\n' || current_char == '\0')
		{
			line[line_length] = '\0';
			return (line);
		}

		if (line_length == 0)
			line = (char *)malloc(sizeof(char));
		else
			line = (char *)realloc(line, (line_length + 1) * sizeof(char));

		line[line_length++] = current_char;
	}
}
