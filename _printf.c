#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int count = 0;

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					{
						count += _putchar(va_arg(args, int));
						break;
					}

				case 's':
					{
						const char *str = va_arg(args, const char *);
						int i, len = 0;

						if (str == NULL)
						{
							return (len);
						}
						else
						{
							len = strlen(str);
							for (i = 0; i < len; i++)
							{
								_putchar(str[i]);
								count++;
							}
						}

						break;
					}

				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						int digits = num_digits(num);
						char *buffer = (char*) malloc((digits + 1) *sizeof(char));
						if (buffer == NULL)
						{
							va_end(args);
							return (-1);
						}

						int_to_str(num, buffer, digits + 1);	// Convert int to string
						const char *str = buffer;
						while (*str != '\0')
						{
							count += _putchar(*str);
							str++;
						}

						free(buffer);
						break;
					}

				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					break;
			}
		}
		else
		{
			count += _putchar(*ptr);
		}
	}

	va_end(args);
	return count;
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 * int_to_str - Convert an integer to a string representation.
 * @num: The integer to convert.
 * @str: Pointer to the character array to store the string representation.
 * @buffer_size: Size of the character array (including space for null terminator).
 *
 * This function converts an integer to its string representation.
 * It stores the result in the provided character array.
 */

void int_to_str(int num, char *str, int buffer_size)
{
    int i = 0;
    int is_negative = 0;

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    do
    {
        if (i < buffer_size - 1)
        {
            str[i++] = num % 10 + '0';
            num /= 10;
        }
    } while (num > 0 && i < buffer_size - 1);

    if (is_negative && i < buffer_size - 1)
        str[i++] = '-';

    int j;
    for (j = 0; j < i / 2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    str[i] = '\0';
}

/**
 * num_digits - Calculates the number of digits in an integer.
 * @num: The integer for which we want to count the digits.
 *
 * Return: The number of digits in the integer.
 */

int num_digits(int num)
{
    int digits = 1;

    while (num / 10 != 0)
    {
        num /= 10;
        digits++;
    }

    return digits;
}