#include "main.h"

/**
 * _printf_string - A function that prints a string to the standard output.
 *
 * @s: The string to be printed.
 * @len: A pointer to an integer variable that will store the length of the
 * output string.
 */
void _printf_string(char *s, int *len)
{
	if (s == NULL)
		_printf_string("(null)", len);
	while (s && *s)
	{
		_printf_char(*s, len);
		s++;
	}
}
