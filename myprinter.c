#include "shell.h"


/**
 * eprint- fxn to print, writes to the STDOUT.
 * @string: ptr to array of xter.
 * Return: void, NULL
 */
void eprint(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
